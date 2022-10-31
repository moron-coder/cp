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
    int l[100001]={},d1[100001]={},d2[100001]={},d[100001]={};
    int getDepth(TreeNode *cur,int lvl){
        if(!cur) return 0;
        l[cur->val]=lvl;
        d[cur->val]=max(getDepth(cur->left,lvl+1),getDepth(cur->right,lvl+1));
        if(d1[lvl]<d[cur->val]){
            d2[lvl]=d1[lvl];
            d1[lvl]=d[cur->val];
        }else if(d2[lvl]<d[cur->val]){
            d2[lvl]=d[cur->val];
        }
        return d[cur->val]+1;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        memset(d1,-1,sizeof(d1));
        memset(d1,-1,sizeof(d2));
        getDepth(root,0);
        vector<int> ans;
        for(auto it:queries){
            int lvl=l[it];
            if(d[it]==d1[lvl]) ans.push_back(d2[lvl]+l[it]);
            else ans.push_back(d1[lvl]+l[it]);
        }
        return ans;
    }
};