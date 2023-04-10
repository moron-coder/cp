#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numOfOperations(vector<int> &ar){
        long long n=ar.size(),ans=LONG_MAX;
        sort(ar.begin(),ar.end());
        vector<long long> preSums(n,ar[0]),sufSums(n,ar[n-1]);
        for(long long i=1;i<n;i++) preSums[i]=ar[i]+preSums[i-1];
        for(long long i=n-2;i>=0;i--) sufSums[i]=ar[i]+sufSums[i+1];
        for(long long i=0;i<n;i++){
            long long pCh=0, sCh=0;
            if(i) pCh=i*ar[i]-preSums[i-1];
            if(i+1<n) sCh=sufSums[i+1]-(n-i-1)*ar[i];
            ans=min(ans,pCh+sCh);
        }
        return ans;
    }

    long long makeSubKSumEqual(vector<int>& ar, int k) {
        long long n=ar.size(),ans=0;
        k=__gcd(n,(long long)k);
        for(int i=0;i<k;i++){
            vector<int> makeEqualNums;
            for(int j=i;j<n;j+=k) makeEqualNums.push_back(ar[j]);
            long long smallAns=numOfOperations(makeEqualNums);
            ans+=smallAns;
        }
        return ans;
    }
};