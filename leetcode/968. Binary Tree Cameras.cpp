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
    int dp[1001][2][2];
    unordered_map<TreeNode*,int> posOfRoot;

    void markPos(TreeNode *r,int &pos){
        if(!r) return;
        posOfRoot[r]=pos;
        pos++;
        markPos(r->left,pos);
        markPos(r->right,pos);
    }

    int rec(TreeNode *r,bool isMonitoredByParent,bool hasToMonitorParent){
        if(!r) return (hasToMonitorParent)?1001:0;
        int ans=INT_MAX,curPos=posOfRoot[r];
        if(dp[curPos][isMonitoredByParent][hasToMonitorParent]!=-1) return dp[curPos][isMonitoredByParent][hasToMonitorParent];
        if(isMonitoredByParent){
            // we don't need to monitor parent
            ans=min({
                rec(r->left,true,false)+rec(r->right,true,false)+1,
                rec(r->left,false,false)+rec(r->right,false,false)
                }); 
        }else{
            //  we can skip putting cam IF one of its child has cam
            if(hasToMonitorParent){
                // can't skip cam
                ans=rec(r->left,true,false)+rec(r->right,true,false)+1;
            }else{
                ans=min({
                    rec(r->left,true,false)+rec(r->right,true,false)+1,
                    rec(r->left,false,true)+rec(r->right,false,false),
                    rec(r->left,false,false)+rec(r->right,false,true)
                });
            }
        }
        return dp[curPos][isMonitoredByParent][hasToMonitorParent]=ans;
    }

    int minCameraCover(TreeNode* r) {
        //  Let's say we are at a node 'r'. The camera which is monitoring 'r' can be at :
        // 1) 'r' itself
        // 2) Parent of 'r'
        // 3) child of 'r'
        // We'll send a parameter to describe whether it is monitored by a camera on parent node or not
        // The recursive function returns how many cameras are used in the subtree rooted at 'r'
        memset(dp,-1,sizeof(dp));
        int pos=0;
        markPos(r,pos);
        return rec(r,false,false);
    }
};