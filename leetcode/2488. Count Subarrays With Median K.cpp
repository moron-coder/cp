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
public:
    int countSubarrays(vector<int>& ar, int k) {
        int sum=0,n=ar.size(),ans=0,kPos=-1;
        unordered_map<int,pii> pre,suf;         //  {sum->{frequency of odd length,frequency of even length}}
        for(int i=0;i<n && kPos==-1;i++) if(ar[i]==k) kPos=i;
        for(int len=1;kPos-len>=0;len++){
            sum+=(ar[kPos-len]>k)?1:-1;
            if(len&1) pre[sum].first++;
            else pre[sum].second++;
        }
        sum=0;
        for(int len=1;kPos+len<n;len++){
            sum+=(ar[kPos+len]>k)?1:-1;
            if(len&1){
                suf[sum].first++;
            }
            else{
                suf[sum].second++;
            }
        }
        for(auto it:suf){
            int sufEvenLenFq=it.second.second,sufOddLenFq=it.second.first;
            // case-1 
            int preSum=-it.first;
            if(pre.count(preSum)){
                int preEvenLenFq=pre[preSum].second,preOddLenFq=pre[preSum].first;
                ans=(ans+sufEvenLenFq*preEvenLenFq);
                ans=(ans+sufOddLenFq*preOddLenFq);
            }
            // case-2
            preSum=1-it.first;
            if(pre.count(preSum)){
                int preEvenLenFq=pre[preSum].second,preOddLenFq=pre[preSum].first;
                ans=(ans+sufEvenLenFq*preOddLenFq);
                ans=(ans+sufOddLenFq*preEvenLenFq);
            }
        }
        return ans+pre[1].first+pre[0].second+suf[1].first+suf[0].second+1;
    }
};