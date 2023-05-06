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

class NumArray {
public:
    int n;
    segTree *treePtr;
    NumArray(vector<int>& ar) {
        n=ar.size();
        treePtr=new segTree(n);
        for(int i=0;i<n;i++){
            treePtr->update(1,0,n-1,i,ar[i]);
        }
    }
    
    void update(int index, int val) {
        treePtr->update(1,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return treePtr->getSum(1,0,n-1,left,right);
    }
};