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
        vector<int> sumEndingAtI(n,ar[0]),pSum(n,ar[0]);
        for(int i=1;i<n;i++){
            pSum[i]=pSum[i-1]+ar[i];
            sumEndingAtI[i]=sumEndingAtI[i-1]+ar[i]*(i+1);
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
        for(auto it:sumEndingAtI){
            cout<<"{"<<it<<"} ";
        }
        cout<<endl;
        //  debug

        for(int i=0;i<n;i++){
            int lfSum1 = (bdr[i].first==-1)?0:sumEndingAtI[bdr[i].first];
            int sum1 = sumEndingAtI[i]-lfSum1;
            cout<<"sum1 : "<<sum1<<endl;
            int lfSum2 = (bdr[i].first==-1)?0:pSum[bdr[i].first];
            int factor = bdr[i].first+1;
            cout<<"factor : "<<factor<<endl;
            int sum2 = (pSum[i]-lfSum2)*factor;
            cout<<"sum2 : "<<sum2<<endl;
            cout<<"Required sum of all subarrays ending at "<<i<<" = "<<sum1-sum2<<endl;
        }
        return ans;
    }
};