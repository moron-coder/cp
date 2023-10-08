#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mii map<int, int>
#define mll map<ll, ll>
#define pii pair<int, int>
#define pic pair<int, char>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define vvi vector<vector<int>>
#define ull unsigned long long int
#define mod 1000000007
#define ll long long int

class Solution {
    void makeJustSmallerIdxPre(vector<int> &ar,vector<long long> &justSmallerIdxPre){
        stack<int> stk;
        int n=ar.size();
        for(int i=0;i<n;i++){
            while (stk.size() && ar[stk.top()]>ar[i]) stk.pop();
            if(stk.size()) justSmallerIdxPre[i]=stk.top();
            stk.push(i);            
        }
    }

    void makeJustSmallerIdxSuf(vector<int> &ar,vector<long long> &justSmallerIdxSuf){
        stack<int> stk;
        int n=ar.size();
        for(int i=n-1;i>=0;i--){
            while (stk.size() && ar[stk.top()]>ar[i]) stk.pop();
            if(stk.size()) justSmallerIdxSuf[i]=stk.top();
            stk.push(i);            
        }
    }

    void calcPre(vector<int> &ar,vector<long long> &pre,vector<long long> &justSmallerIdxPre){
        int n=ar.size();
        for(int i=1;i<n;i++){
            int justSmallerPrefixIndex = justSmallerIdxPre[i];
            long long preExtra = 0, preAns=0;
            if(justSmallerPrefixIndex!=-1){
                preAns = pre[justSmallerPrefixIndex];
                preExtra = 1LL*(i-justSmallerPrefixIndex-1)*ar[i];
            }else{
                preExtra = 1LL*i*ar[i];
            }
            pre[i]=preExtra+preAns+ar[i];
        }
    }

    void calcSuf(vector<int> &ar,vector<long long> &suf,vector<long long> &justSmallerIdxsuf){
        int n=ar.size();
        for(int i=n-2;i>=0;i--){
            int justSmallerSuffixIndex = justSmallerIdxsuf[i];
            long long sufExtra = 0, sufAns=0;
            if(justSmallerSuffixIndex!=-1){
                sufAns = suf[justSmallerSuffixIndex];
                sufExtra = 1LL*(justSmallerSuffixIndex-i-1)*ar[i];
            }else{
                sufExtra = 1LL*(n-i-1)*ar[i];
            }
            suf[i]=sufExtra+sufAns+ar[i];
        }
    }
public:
    long long maximumSumOfHeights(vector<int>& ar) {
        int n=ar.size();
        vector<long long> justSmallerIdxPre(n,-1),justSmallerIdxSuf(n,-1);
        makeJustSmallerIdxPre(ar,justSmallerIdxPre);
        makeJustSmallerIdxSuf(ar,justSmallerIdxSuf);

        vector<long long> pre(n,ar[0]),suf(n,ar.back());
        calcPre(ar,pre,justSmallerIdxPre);
        calcSuf(ar,suf,justSmallerIdxSuf);

        long long ans=max(pre.back(),suf[0]);  

        for(int i=1;i<n;i++){
            int justSmallerPrefixIndex = justSmallerIdxPre[i];
            int justSmallerSuffixIndex = justSmallerIdxSuf[i];
            long long preAns=0,sufAns=0,curAns=ar[i];
            if(justSmallerPrefixIndex!=-1){
                preAns = pre[justSmallerPrefixIndex];
                long long preExtra = 1LL*(i-justSmallerPrefixIndex-1)*ar[i];
                preAns+=preExtra;
            }
            if(justSmallerSuffixIndex!=-1){
                sufAns = suf[justSmallerSuffixIndex];
                long long sufExtra = 1LL*(justSmallerSuffixIndex-i-1)*ar[i];
                sufAns+=sufExtra;
            }
            ans=max(ans,curAns+preAns+sufAns);
        }
        return ans;
    }
};