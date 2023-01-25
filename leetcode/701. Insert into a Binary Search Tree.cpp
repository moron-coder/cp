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
    TreeNode* help(TreeNode* r,int val){
        if(r==nullptr){
            return new TreeNode(val);
        }
        if(r->val>val){
            // insert in left subtree
            TreeNode* newLeft = help(r->left,val);
            r->left=newLeft;
        }else{
            TreeNode* newRight = help(r->right,val);
            r->right=newRight;
        }
        return r;
    }

    TreeNode* insertIntoBST(TreeNode* r, int val) {
        return help(r,val);
    }
};