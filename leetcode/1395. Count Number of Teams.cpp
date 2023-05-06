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

class segTree{
    public:
    int *treeAr;
    segTree(int n){
        treeAr=new int[4*n+1]();
    }

    int getSum(int tIdx,int treeLo,int treeHi,int arLo,int arHi){
        if(treeLo>=arLo && treeHi<=arHi) return treeAr[tIdx];
        if(treeHi<arLo || treeLo>arHi) return 0;
        int mid=treeLo+(treeHi-treeLo)/2;
        return getSum(2*tIdx,treeLo,mid,arLo,arHi)+getSum(2*tIdx+1,mid+1,treeHi,arLo,arHi);
    }

    void update(int tIdx,int treeLo,int treeHi,int arIdx,int arVal){
        if(arIdx>treeHi || arIdx<treeLo) return;
        if(arIdx==treeLo && arIdx==treeHi){
            treeAr[tIdx]=arVal;
            return;
        }
        int treeMid = treeLo+(treeHi-treeLo)/2;
        if(arIdx<=treeMid){
            update(tIdx*2,treeLo,treeMid,arIdx,arVal);
        }else{
            update(2*tIdx+1,treeMid+1,treeHi,arIdx,arVal);
        }
        treeAr[tIdx]=treeAr[tIdx*2]+treeAr[tIdx*2+1];
    }
};

class Solution {
    const static int MAX_AR_VAL = 100000;
public:

    int processAr(vector<int> &ar){
        int n=ar.size(),ans=0;
        segTree treeSuf(MAX_AR_VAL),treePre(MAX_AR_VAL);
        int *preGr=new int[n](),*sufSm=new int[n]();
        for(int i=n-1;i>=0;i--){
            sufSm[i]=treeSuf.getSum(1,0,MAX_AR_VAL,0,ar[i]-1);
            int curFq = treeSuf.getSum(1,0,MAX_AR_VAL,ar[i],ar[i]);
            treeSuf.update(1,0,MAX_AR_VAL,ar[i],curFq+1);
        }
        for(int i=0;i<n;i++){
            preGr[i]=treePre.getSum(1,0,MAX_AR_VAL,ar[i]+1,MAX_AR_VAL);
            int curFq = treePre.getSum(1,0,MAX_AR_VAL,ar[i],ar[i]);
            treePre.update(1,0,MAX_AR_VAL,ar[i],curFq+1);
        }
        for(int i=0;i<n;i++){
            ans=(ans+preGr[i]*sufSm[i]);
        }
        return ans;
    }

    int numTeams(vector<int>& ar) {
        int x=processAr(ar);
        reverse(ar.begin(),ar.end());
        int y=processAr(ar);
        return x+y;
    }
};