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
#define ll long long int
#define pii pair<int, int>
#define mod 1000000007

#define ll long long int
#define pii pair<int, int>
#define mod 1000000007

class Solution {
public:
    int totalStrength(vector<int>& ar) {
        int n=ar.size(),ans=0;
        vector<int> sumEndingAtI(n,ar[0]),pSum(n,ar[0]),sumStartingAtI(n,ar.back()),sSum(n,ar.back());
        for(int i=1;i<n;i++){
            pSum[i]=(pSum[i-1]+ar[i])%mod;
            sumEndingAtI[i]=(sumEndingAtI[i-1]+1LL*ar[i]*(i+1))%mod;
        }
        for(int i=n-2;i>=0;i--){
            sSum[i]=(sSum[i+1]+ar[i])%mod;
            sumStartingAtI[i]=(sumStartingAtI[i+1]+1LL*(n-i)*ar[i])%mod;
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

        for(int i=0;i<n;i++){
            int lfSum1 = (bdr[i].first==-1)?0:sumEndingAtI[bdr[i].first];
            int sum1 = sumEndingAtI[i]-lfSum1;
            int lfSum2 = (bdr[i].first==-1)?0:pSum[bdr[i].first];
            int factor = bdr[i].first+1;
            int sum2 = (pSum[i]-lfSum2)*factor;

            int rtSum1 = (bdr[i].second==n)?0:sumStartingAtI[bdr[i].second];
            int sum3 = sumStartingAtI[i]-rtSum1;
            int rtSum2 = (bdr[i].second==n)?0:sSum[bdr[i].second];
            int factor2 = (n-bdr[i].second);
            int sum4 = (sSum[i]-rtSum2)*factor2;

            int preCount = i-bdr[i].first, sufCount = bdr[i].second-i;
            
            int preCountContri = (sum3-sum4)%mod*preCount;
            int sufCountContri = (sum1-sum2)%mod*sufCount;
            int repetitionContri = (ar[i]*preCount*sufCount);

            int totSum = (preCountContri%mod + sufCountContri%mod - repetitionContri%mod + mod)%mod;

            ans = (ans + 1LL*ar[i]*totSum)%mod;

        }
        return ans;
    }
};