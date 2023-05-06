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
    // segment tree is basically division of an array into sorted segments
    // every segment stores an info which is updated in each UPDATION query
    // and fetched using FETCH query
    segTree *lf,*rt;
    int lfIdxTree,rtIdxTree;
    int infoStored;
    public:

    segTree(int lfIdxTree,int rtIdxTree){
        this->lfIdxTree=lfIdxTree;
        this->rtIdxTree=rtIdxTree;
        lf=nullptr;
        rt=nullptr;
        infoStored=0;
        if(lfIdxTree==rtIdxTree) return;
        int mid=lfIdxTree+(rtIdxTree-lfIdxTree)/2;
        if(mid>=lfIdxTree) this->lf = new segTree(lfIdxTree,mid);
        if(mid+1<=rtIdxTree) this->rt = new segTree(mid+1,rtIdxTree);
    }

    void modifyInfo(){
        this->infoStored=0;
        if(this->lf!=nullptr) this->infoStored += this->lf->infoStored;
        if(this->rt!=nullptr) this->infoStored += this->rt->infoStored;
    }

    void updateInfo(int valAr){
        this->infoStored = valAr;
    }

    void update(int idxAr,int valAr){
        if(idxAr<lfIdxTree || idxAr>rtIdxTree) return;
        if(idxAr==lfIdxTree &&idxAr==rtIdxTree){
            updateInfo(valAr);
            return;
        }
        int mid=lfIdxTree+(rtIdxTree-lfIdxTree)/2;
        if(this->lf!=nullptr && idxAr<=mid) this->lf->update(idxAr,valAr);
        else if(this->rt!=nullptr) this->rt->update(idxAr,valAr);
        modifyInfo();
    }

    int fetchInfo(int lfAr,int rtAr){
        if(this->lfIdxTree>=lfAr && this->rtIdxTree<=rtAr) return this->infoStored;
        if(this->rtIdxTree<lfAr || this->lfIdxTree>rtAr) return 0;
        int ans=0;
        if(this->lf) ans+=this->lf->fetchInfo(lfAr,rtAr);
        if(this->rt) ans+=this->rt->fetchInfo(lfAr,rtAr);
        return ans;
    }

};

class NumArray {
public:
    segTree *tree;

    NumArray(vector<int>& ar) {
        tree = new segTree(0,ar.size()-1);
        for(int i=0;i<ar.size();i++) tree->update(i,ar[i]);
    }
    
    void update(int index, int val) {
        tree->update(index,val);
    }
    
    int sumRange(int left, int right) {
        return tree->fetchInfo(left,right);
    }
};
