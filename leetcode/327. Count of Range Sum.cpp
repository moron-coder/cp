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
    // segmenting should be done on the basis of index due to constraints. Each index has a given prefixSum
    // starting from index n-1, I'll store its sum in the segTree. To store the sum, I need the segmentation
    // on the basis of prefix sums. The info stored in the tree is the count of prefixSums which lie in the given
    // range
    ll lfIdxTree,rtIdxTree,infoStored;
    segTree *lf,*rt;
    void modifyInfo(ll valAr){
        this->infoStored = (this->infoStored+valAr);
    }

    void updateInfo(){
        this->infoStored=0;
        if(lf!=nullptr) this->infoStored += this->lf->infoStored;
        if(rt!=nullptr) this->infoStored += this->rt->infoStored;
    }
    public:

    segTree(ll lfIdxAr,ll rtIdxAr,vector<ll> &ar){
        lf=nullptr;
        rt=nullptr;
        this->lfIdxTree = ar[lfIdxAr];
        this->rtIdxTree = ar[rtIdxAr];
        infoStored=0;
        if(lfIdxAr==rtIdxAr) return;
        ll mid=lfIdxAr+(rtIdxAr-lfIdxAr)/2;
        if(mid>=lfIdxAr) this->lf = new segTree(lfIdxAr,mid,ar);
        if(mid+1<=rtIdxAr) this->rt = new segTree(mid+1,rtIdxAr,ar);
    }


    void update(ll idxAr,ll valAr){
        if(idxAr<lfIdxTree || idxAr>rtIdxTree) return;
        // should I go left or  right? idxAr will tell
        if(((this->lf)!=nullptr) && idxAr<=(this->lf->rtIdxTree)){
            this->lf->update(idxAr,valAr);
        }
        else if((this->rt!=nullptr) && idxAr>=(this->rt->lfIdxTree)){
            this->rt->update(idxAr,valAr);
        }
        // updateInfo();    
        modifyInfo(valAr);
    }

    ll getInfo(ll lfIdxAr,ll rtIdxAr){
        if(lfIdxTree>=lfIdxAr && rtIdxTree<=rtIdxAr){
            return this->infoStored;
        }
        if(lfIdxAr>rtIdxTree || rtIdxAr<lfIdxTree) return 0;
        ll curAns=0;
        if(lf!=nullptr) curAns+=this->lf->getInfo(lfIdxAr,rtIdxAr);
        if(rt!=nullptr) curAns+=this->rt->getInfo(lfIdxAr,rtIdxAr);
        return curAns;
    }

};

class Solution {
public:
    int countRangeSum(vector<int>& ar, int lower, int upper) {
        if(ar.size()==0) return 0;
        vector<ll> pSumsSorted;
        pSumsSorted.push_back(ar[0]);
        for(ll i=1;i<ar.size();i++) pSumsSorted.push_back(pSumsSorted.back()+ar[i]);
        ll totSum=pSumsSorted.back(),ans=0;
        sort(pSumsSorted.begin(),pSumsSorted.end());
        segTree tree(0,pSumsSorted.size()-1,pSumsSorted);
        for(ll i=ar.size()-1;i>=0;i--){
            ans+=tree.getInfo(lower+totSum,upper+totSum);
            tree.update(totSum,1);
            if(totSum>=lower && totSum<=upper) ans++;
            totSum-=ar[i];
        }
        return ans;
    }
};