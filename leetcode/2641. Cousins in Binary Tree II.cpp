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
    void getLevelSums(TreeNode *root,vector<int> &levelSums){
        queue<TreeNode*> q;
        int sum=0;
        q.push(root);
        q.push(nullptr);
        while (q.size()){
            TreeNode *cur=q.front();
            q.pop();
            if(cur==nullptr){
                levelSums.push_back(sum);
                if(q.empty()) break;
                q.push(nullptr);
                sum=0;
            }else{
                sum+=cur->val;
                if(cur->left!=nullptr) q.push(cur->left);
                if(cur->right!=nullptr) q.push(cur->right);
            }
        }
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> levelSums;
        getLevelSums(root,levelSums);
        queue<pair<TreeNode*,int>> q;             //  {curNodeAddr,parentNodeChildrenVal}
        q.push({root,root->val});
        q.push({nullptr,-1});
        int sum=0,lvl=0;
        while (q.size()){
            TreeNode *curNodeAddr=q.front().first;
            int siblingNodeVal = q.front().second;
            q.pop();
            if(curNodeAddr==nullptr){
                if(q.empty()) break;
                lvl++;
                sum=0;
                q.push({nullptr,-1});
            }else{
                int childrenNodeVals=0;
                if(curNodeAddr->left!=nullptr) childrenNodeVals+=curNodeAddr->left->val;
                if(curNodeAddr->right!=nullptr) childrenNodeVals+=curNodeAddr->right->val;
                if(curNodeAddr->left!=nullptr) q.push({curNodeAddr->left,childrenNodeVals});
                if(curNodeAddr->right!=nullptr) q.push({curNodeAddr->right,childrenNodeVals});
                curNodeAddr->val=(levelSums[lvl]-siblingNodeVal);
            }
        }
        return root;
    }
};