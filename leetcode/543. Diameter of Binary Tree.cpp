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
    int ans;

    int help(TreeNode* r){
        if(!r) return 0;
        int lf=help(r->left),rt=help(r->right);
        ans=max({ans,lf+rt+1,lf,rt});
        return max(lf,rt)+1;
    }

    int diameterOfBinaryTree(TreeNode* r) {
        ans=0;
        help(r);
        return ans;
    }
};
