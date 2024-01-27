#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mii map<int, int>
#define mll map<ll, ll>
#define pic pair<int, char>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define vvi vector<vector<int>>
#define ull unsigned long long int
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>

class Solution {
public:
    int totalStrength(vector<int>& ar) {
        int n=ar.size(),ans=0;
        vector<int> sumEndingAtI(n,ar[0]),pSum(n,ar[0]),sumStartingAtI(n,ar.back()),sSum(n,ar.back());
        for(int i=1;i<n;i++){
            pSum[i]=pSum[i-1]+ar[i];
            sumEndingAtI[i]=sumEndingAtI[i-1]+ar[i]*(i+1);
        }
        for(int i=n-2;i>=0;i--){
            sSum[i]=sSum[i+1]+ar[i];
            sumStartingAtI[i]=sumStartingAtI[i+1]+(n-i)*ar[i];
        }
        vector<pii> bdr(n);
        stack<int> stk;
        for(int i=0;i<n;i++){
            while(stk.size() && ar[stk.top()]>ar[i]){
                stk.pop();
            }
            bdr[i].first = (stk.size())?stk.top():-1;
            stk.push(i);
        }
        while (stk.size()) stk.pop();
        for(int i=n-1;i>=0;i--){
            while (stk.size() && ar[stk.top()]>=ar[i]){
                stk.pop();
            }
            bdr[i].second = (stk.size())?stk.top():n;
            stk.push(i);
        }
        //  debug
        for(auto it:bdr){
            cout<<"{"<<it.first<<" - "<<it.second<<"} ";
        }
        cout<<endl;
        //  debug

        //  debug
        // for(auto it:sumEndingAtI){
        //     cout<<"{"<<it<<"} ";
        // }
        cout<<endl;
        //  debug

        for(int i=0;i<n;i++){
            int lfSum1 = (bdr[i].first==-1)?0:sumEndingAtI[bdr[i].first];
            int sum1 = sumEndingAtI[i]-lfSum1;
            // cout<<"sum1 : "<<sum1<<endl;
            int lfSum2 = (bdr[i].first==-1)?0:pSum[bdr[i].first];
            int factor = bdr[i].first+1;
            // cout<<"factor : "<<factor<<endl;
            int sum2 = (pSum[i]-lfSum2)*factor;
            // cout<<"sum2 : "<<sum2<<endl;
            cout<<"Required sum of all subarrays ending at "<<i<<" = "<<sum1-sum2<<endl;

            // cout<<"sumStartingAtI[i] : "<<sumStartingAtI[i]<<endl;
            int rtSum1 = (bdr[i].second==n)?0:sumStartingAtI[bdr[i].second];
            int sum3 = sumStartingAtI[i]-rtSum1;
            // cout<<"sum3 : "<<sum3<<endl;
            int rtSum2 = (bdr[i].second==n)?0:sSum[bdr[i].second];
            int factor2 = (n-bdr[i].second);
            // cout<<"factor 2 : "<<factor2<<endl;
            int sum4 = (sSum[i]-rtSum2)*factor2;
            // cout<<"sum4 : "<<sum4<<endl;
            cout<<"Required sum of all subarrays starting at "<<i<<" = "<<sum3-sum4<<endl;
        }
        return ans;
    }
};