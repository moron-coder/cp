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

class Solution {
public:
    TreeNode* lca;

    pair<TreeNode*,TreeNode*> findEl(TreeNode* r,int p,int q){
        // find the first element such that ans.lf!=NULL && ans.rt!=NULL;
        if(!r) return {NULL,NULL};
        pair<TreeNode*,TreeNode*> ans={NULL,NULL},lf=findEl(r->left,p,q),rt=findEl(r->right,p,q);
        if(lca!=NULL) return {lca,lca};
        // ans.first->uppermost node whose subtree(including root) contains p, vice versa for q
        if(r->val==p || lf.first || rt.first) ans.first=r;
        if(r->val==q || lf.second || rt.second) ans.second=r;
        if(ans.first && ans.second) lca=r;
        return ans;
    }

    int getDis(TreeNode *r,int p){
        if(!r) return -1;
        if(r->val==p) return 0;
        int lf=getDis(r->left,p),rt=getDis(r->right,p);
        if(lf!=-1) return lf+1;
        if(rt!=-1) return rt+1;
        return -1;
    }

    int findDistance(TreeNode* r, int p, int q) {
        lca=NULL;
        findEl(r,p,q);
        // if(!lca) cout<<"wrong ans\n";
        // else cout<<lca->val<<" is the lca\n";
        return getDis(lca,p)+getDis(lca,q);
    }
};