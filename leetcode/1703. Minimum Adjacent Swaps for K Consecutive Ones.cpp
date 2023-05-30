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
    void makePrefs(vector<int> &onePos,int k,vector<int> &prefs){
        int n=onePos.size(),baseCost=0,basePos=onePos[k];
        for(int i=k-1;i>=0;i--){
            baseCost+=basePos-1-onePos[i];
            basePos--;
        }
        for(int i=k;i<n-1;i++){
            prefs[i]=baseCost;
            int excludingLastOne = onePos[i]-k-onePos[i-k];
            int goTillNext = (onePos[i+1]-onePos[i]-1)*k;
            baseCost=(baseCost-excludingLastOne+goTillNext);
        }
        prefs.back()=baseCost;
    }

    void makeSufs(vector<int> &onePos,int k,vector<int> &sufs){
        int n=onePos.size(),basePos=onePos[n-k-1],baseCost=0;
        for(int i=n-k;i<n;i++){
            baseCost+=onePos[i]-(basePos+1);
            basePos++;
        }
        for(int i=n-k-1;i>0;i--){
            sufs[i]=baseCost;
            int excludeLastOne = onePos[i+k]-(onePos[i]+k);
            int goTillPrev = (onePos[i]-onePos[i-1]-1)*k;
            baseCost = (baseCost-excludeLastOne+goTillPrev);
        }
        sufs[0]=baseCost;
    }

    int minMoves(vector<int>& ar, int k) {
        int n=ar.size(),ans=INT_MAX;
        vector<int> onePos;
        for(int i=0;i<n;i++) if(ar[i]) onePos.push_back(i);
        if(onePos.size()<k) return -1;
        vector<int> prefs(onePos.size(),-1),sufs(onePos.size(),-1);
        makePrefs(onePos,(k-1)/2,prefs);
        makeSufs(onePos,k/2,sufs);
        for(int i=0;i<onePos.size();i++){
            if(prefs[i]!=-1 && sufs[i]!=-1){
                ans=min(ans,prefs[i]+sufs[i]);
            }
        }
        return ans;
    }
};