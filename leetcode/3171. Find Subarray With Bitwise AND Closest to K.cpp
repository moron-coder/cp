#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

class Solution {
    const static int LAST_INDEX_POS = 30;

    int fetchSubarrayAnd(int i, int j, vector<vector<int>> &zeros){
        int ans=0;
        for(int bitPos=0;bitPos<LAST_INDEX_POS;bitPos++){
            int pos = lower_bound(zeros[bitPos].begin(), zeros[bitPos].end(), i)-zeros[bitPos].begin();
            if(pos==zeros[bitPos].size() || zeros[bitPos][pos]>j){
                ans|=(1<<bitPos);
            }
        }
        return ans;
    }

    pii findLastIndex(vector<int> &ar, int k, int i, vector<vector<int>> &zeros){
        int n=ar.size();
        int lo=i,hi=n-1,ans=-1,optimalSubAnd=-1;
        while (lo<=hi){
            int mid = lo+(hi-lo)/2;
            int subAnd = fetchSubarrayAnd(i, mid, zeros);
            if(subAnd>=k){
                ans=mid;
                optimalSubAnd = subAnd;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return {ans, optimalSubAnd};
    }
public:
    int minimumDifference(vector<int>& ar, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);


        int n = ar.size(),ans=INT_MAX; 
        vector<vector<int>> zeros(LAST_INDEX_POS);

        for(int i=0;i<LAST_INDEX_POS;i++){
            for(int j=0;j<n;j++){
                int isZero = ((1<<i)&ar[j])==0;
                if(isZero){
                    zeros[i].push_back(j);
                }
            }
        }

        for(int i=0;i<n;i++){
            pii small = findLastIndex(ar,k,i,zeros);
            int lastIdx = small.first, optimalSubAnd = small.second;
            int dif1=INT_MAX,dif2=INT_MAX;
            if(lastIdx!=-1){
                dif1 = optimalSubAnd-k;
                if(lastIdx+1<n){
                    dif2 = k-(optimalSubAnd&ar[lastIdx+1]);
                }
            }else{
                dif2 = k-ar[i];
            }
            ans = min({ans,dif1,dif2});
        }
        return ans;
    }
};