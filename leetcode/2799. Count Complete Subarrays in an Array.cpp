#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

class Solution {
public:
    int countCompleteSubarrays(vector<int>& ar) {
        int n=ar.size(),i=0,subDisCt=0,totDisCt=0,ans=0,jMax=-1;
        int *fq=new int[2001]();
        for(auto it:ar) fq[it]++;
        for(int i=0;i<=2000;i++){
            if(fq[i]) {
                totDisCt++;
                fq[i]=0;
            }
        }
        for(int j=0;j<n;){
            if(jMax<j){
                if(fq[ar[j]]==0) subDisCt++;
                fq[ar[j]]++;
                jMax=j;
            }
            if(subDisCt==totDisCt){
                ans+=n-j;
                if(fq[ar[i]]==1){
                    subDisCt--;
                }
                fq[ar[i]]--;
                i++;
                if(i==j+1) j++;
            }else{
                j++;
            }
        }
        return ans;
    }
};