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

int dp[1001][3][2];

class Solution {
    unordered_map<TreeNode*,int> mp;
    //  if a node is not covered by its parent cam, we can either put a cam on the node
    //  or on ONE of its child nodes

    int help(TreeNode *r, int dis, bool camHere){
        if(r==NULL){
            return 0;
        }
        int rVal = mp[r];
        if(dp[rVal][dis][camHere]!=-1) return dp[rVal][dis][camHere];
        int lfAns = (r->left!=NULL) ? 1+help(r->left, 2, true)+help(r->right, max(0,dis-1), false) : INT_MAX;
        int rtAns = (r->right!=NULL) ? help(r->left, max(0,dis-1), false)+1+help(r->right, 2, true) : INT_MAX;
        int curAns = help(r->left, 1, false)+help(r->right, 1, false)+1;
        int ans = min({lfAns, rtAns, curAns});
        if(dis>0){
            int skipAns = help(r->left, max(0,dis-1), false)+help(r->right, max(0,dis-1), false);
            ans=min(ans, skipAns);
        }
        return dp[rVal][dis][camHere]=ans;
    }

public:
    int minCameraCover(TreeNode* r) {
        int ctr=0;
        mp.clear();
        queue<TreeNode*> q;
        q.push(r);

        while (q.size()){
            TreeNode* cur = q.front();
            q.pop();
            mp[cur]=ctr++;

            if(cur->left!=NULL){
                q.push(cur->left);
            }
            if(cur->right!=NULL){
                q.push(cur->right);
            }
        }        

        memset(dp,-1,sizeof(dp));
        return help(r,0,false);
    }
};