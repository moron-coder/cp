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
    void ino(TreeNode *r,vector<int> &ar){
        if(!r) return;
        ino(r->left,ar);
        ar.push_back(r->val);
        ino(r->right,ar);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        vector<int> ar;
        // inorder
        ino(root,ar);
        for(auto it:queries){
            int lo=lower_bound(ar.begin(),ar.end(),it)-ar.begin();
            if(lo<ar.size() && ar[lo]==it) ans.push_back({it,it});
            else{
                vector<int> tmp;
                if(lo==0) tmp.push_back(-1);
                else tmp.push_back(ar[lo-1]);
                if(lo==ar.size()) tmp.push_back(-1);
                else tmp.push_back(ar[lo]);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};