#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLastReachableIndex(vector<vector<int>> &ar,int idx,int k){
        int lo=idx+1,hi=ar.size()-1,ans=idx;
        while (lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(ar[mid][0]-ar[idx][0]+1<=k){
                if(idx==1){
                    cout<<"mid= "<<mid<<" is ok\n";
                }
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans;
    }

    int maximumWhiteTiles(vector<vector<int>>& ar, int k) {
        sort(ar.begin(),ar.end());
        // for(auto it:ar) cout<<"["<<it[0]<<","<<it[1]<<"] ";
        // cout<<endl;
        int n=ar.size(),ans=0;
        vector<int> pSum;
        for(auto it:ar){
            int cur=it[1]-it[0]+1;
            if(pSum.size()) cur+=pSum.back();
            pSum.push_back(cur);
        }
        for(int i=0;i<n;i++){
            // cout<<"at i= "<<i<<endl;
            int lastReachableIndex = getLastReachableIndex(ar,i,k);
            // cout<<"for i= "<<i<<" lastReachableIndex: "<<lastReachableIndex<<endl;
            int prev = 0;
            if(i) prev=pSum[i-1];
            int lastReachablePoint = min(ar[lastReachableIndex][1],ar[i][0]+k-1);
            int midSums = 0; 
            if(lastReachableIndex) midSums = pSum[lastReachableIndex-1];
            int lastIdxTiles = lastReachablePoint-ar[lastReachableIndex][0]+1;
            ans=max(ans,midSums+lastIdxTiles-prev);
            // cout<<"for i= "<<i<<" midSums: "<<midSums<<" lastIdxTiles: "<<lastIdxTiles<<" prev: "<<prev<<endl;
        }
        return ans;
    }
};