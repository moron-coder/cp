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
    vector<vector<int>> ans;

    int getDfs(TreeNode* r){
        if(!r) return 0;
        int lf = getDfs(r->left),rt=getDfs(r->right);
        ans[max(lf,rt)].push_back(r->val);
        return max(lf,rt)+1;
    }

    int ct(TreeNode* r){
        if(!r) return 0;
        return max(ct(r->left),ct(r->right))+1;
    }

    vector<vector<int>> findLeaves(TreeNode* r) {
        ans.resize(ct(r));
        getDfs(r);
        return ans;
    }
};