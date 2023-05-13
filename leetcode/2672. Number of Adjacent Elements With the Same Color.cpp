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
    segTree *lf,*rt;
    public:
    int lfTreeIdx,rtTreeIdx,infoStored;

    segTree(int lfArIdx,int rtArIdx){
        this->lfTreeIdx=lfArIdx;
        this->rtTreeIdx=rtArIdx;
        infoStored=0;
        if(lfArIdx==rtArIdx) return;
        int mid=lfArIdx+(rtArIdx-lfArIdx)/2;
        if(mid>=lfArIdx){
            lf=new segTree(lfArIdx,mid);
        }
        if(mid+1<=rtArIdx){
            rt=new segTree(mid+1,rtArIdx);
        }
    }

    void updateInfo(int &ans,vector<int> &ar){
        if(this->lf!=nullptr && this->rt!=nullptr){
            int lfRt = this->lf->rtTreeIdx;
            int rtLf = this->rt->lfTreeIdx;
            if(ar[lfRt]>0 && ar[lfRt]==ar[rtLf]) ans++;
        }
    }

    void update(int arIdx,int arVal,vector<int> &ar){
        if(lfTreeIdx==arIdx && rtTreeIdx==arIdx){
            return;
        }
        this->infoStored=0;
        if(lf!=nullptr && arIdx<=(lf->rtTreeIdx)){
            lf->update(arIdx,arVal,ar);
        }else if(rt!=nullptr && arIdx>=(rt->lfTreeIdx)){
            rt->update(arIdx,arVal,ar);
        }
        if(lf!=nullptr){
            infoStored=infoStored+(lf->infoStored);
        }
        if(rt!=nullptr){
            infoStored=infoStored+(rt->infoStored);
        }
        updateInfo(infoStored,ar);
    }
};

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& q) {
        segTree tree(0,n-1);
        vector<int> ar(n,0),ret;
        for(auto it:q){
            ar[it[0]]=it[1];
            tree.update(it[0],it[1],ar);
            ret.push_back(tree.infoStored);
        }
        return ret;
    }
};