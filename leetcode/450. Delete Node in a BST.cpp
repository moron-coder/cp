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

    TreeNode* deleteNode(TreeNode* r, int k) {
        if(!r) return NULL;
        if(r->val==k){
            TreeNode *nextGtr = r->right;
            if(nextGtr==nullptr){
                return r->left;
            }
            while (nextGtr->left!=nullptr){
                nextGtr=(nextGtr->left);
            }
            swap(r->val,nextGtr->val);
            TreeNode *newRight = deleteNode(r->right,k);
            r->right = newRight;
        }else if(k<r->val){
            // go left
            TreeNode *newLeft = deleteNode(r->left,k);
            r->left = newLeft;
        }else {
            // go right
            TreeNode *newRight = deleteNode(r->right,k);
            r->right = newRight;
        }
        return r;
    }
};