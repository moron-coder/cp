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

/**
* @author : Utkarsh Kumar
* @date : 2024-07-16
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    ll help(TreeNode *r, ll tg, ll rSum, unordered_map<ll,ll> &mp){
        if(r==nullptr){
            return 0;
        }

        ll ans=0;

        //  count of paths ending at current node with root as global root and sum==tg 
        if(rSum+r->val==tg){
            ans++;
        }
        //  count of paths ending at current node and root other than global root and sum==tg
        ans+=mp[r->val+rSum-tg];

        mp[r->val+rSum]++;
        int lf = help(r->left, tg, rSum+r->val, mp);
        ans+=lf;
        int rt = help(r->right, tg, rSum+r->val, mp);
        ans+=rt;
        mp[rSum+r->val]--;
        return ans;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<ll,ll> mp;
        return help(root, targetSum, 0, mp);
    }
};