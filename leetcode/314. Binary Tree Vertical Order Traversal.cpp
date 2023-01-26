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
    vector<vector<int>> verticalOrder(TreeNode* r) {
        queue<pair<TreeNode*,int>> q; 
        if(r) q.push({r,0});
        map<int,vector<int>> mp;
        while (q.size()){
            pair<TreeNode*,int> cur=q.front();
            mp[cur.second].push_back(cur.first->val);
            q.pop();
            if(cur.first->left) q.push({cur.first->left,cur.second-1});
            if(cur.first->right) q.push({cur.first->right,cur.second+1});
        }
        vector<vector<int>> ans;
        for(auto keySet:mp){
            vector<int> sm;
            for(auto it:keySet.second) sm.push_back(it);
            ans.push_back(sm);
        }
        return ans;
    }
};