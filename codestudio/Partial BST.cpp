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

class BinaryTreeNode 
{
public : 
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

class tpl{
    public:
    int mx,mn;
    bool ok;
    tpl(int mx,int mn,bool ok){
        this->mx=mx;
        this->mn=mn;
        this->ok=ok;
    }
};

tpl isPartBST(BinaryTreeNode *r){
    int curMn=r->data,curMx=r->data;
    if(r->left){
        tpl lf=isPartBST(r->left);
        curMn=lf.mn;
        if(!lf.ok || lf.mx>r->data) return {INT_MIN,INT_MIN,false};
    }
    if(r->right){
        tpl rt=isPartBST(r->right);
        curMx=rt.mx;
        if(!rt.ok || rt.mn<r->data) return {INT_MIN,INT_MIN,false};
    }
    return {curMx,curMn,true};
}

bool validateBST(BinaryTreeNode *r){
    if(!r) return true;
    return isPartBST(r).ok;
}