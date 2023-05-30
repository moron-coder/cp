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
    TreeNode *ret;
    int dfs(TreeNode *root,unordered_set<TreeNode*> &nodes){
        int ans=0;
        if(nodes.count(root)){
            ans++;
        }
        if(root->left!=nullptr) ans+=dfs(root->left,nodes);
        if(root->right!=nullptr) ans+=dfs(root->right,nodes);
        if(ans==nodes.size() && ret==nullptr) ret=root;
        return ans;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &ar) {
        unordered_set<TreeNode*> nodes;
        for(auto it:ar) nodes.insert(it);
        ret=nullptr;
        dfs(root,nodes);
        return ret;
    }
};