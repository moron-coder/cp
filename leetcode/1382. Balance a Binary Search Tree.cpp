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
    void inorderTravelsal(TreeNode *rt,vector<int> &res){
        if(rt==nullptr){
            return;
        }
        inorderTravelsal(rt->left,res);
        res.push_back(rt->val);
        inorderTravelsal(rt->right,res);
    }

    TreeNode *makeTree(vector<int> &res,int st,int en){
        if(st>en){
            return nullptr;
        }
        int mid = st+(en-st)/2;
        TreeNode *lf = makeTree(res,st,mid-1);
        TreeNode *rt = makeTree(res,mid+1,en);
        TreeNode *cur = new TreeNode(res[mid]);
        cur->left = lf;
        cur->right = rt;
        return cur;
    }

public:
    TreeNode* balanceBST(TreeNode* rt) {
        vector<int> res;
        inorderTravelsal(rt,res);
        return makeTree(res,0,res.size()-1);
    }
};