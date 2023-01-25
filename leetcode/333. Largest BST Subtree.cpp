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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct trp{
    int mx,mn,ct;
    bool isBT;

    trp(int mx,int mn,bool isBST,int ct){
        this->mx=mx;
        this->mn=mn;
        this->ct=ct;
        this->isBT=isBST;
    }
};

class Solution {
public:
    int ans;
    trp help(TreeNode* r){
        if(!r) return {INT_MIN,INT_MAX,true,0};
        trp lf=help(r->left),rt=help(r->right);
        bool c1=true,c2=true;
        if(r->right) c1=(rt.mn>r->val);
        if(r->left) c2=(lf.mx<r->val); 
        if(c1 && c2 && lf.isBT && rt.isBT){
            ans=max(ans,1+lf.ct+rt.ct);
            return {(r->right)?(rt.mx):r->val,(r->left)?(lf.mn):r->val,true,1+lf.ct+rt.ct};
        }
        return {INT_MAX,INT_MIN,false,0};
    }

    int largestBSTSubtree(TreeNode* r) {
        ans=0;
        help(r);
        return ans;
    }
};