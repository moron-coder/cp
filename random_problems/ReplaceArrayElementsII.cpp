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

class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    public:
        TreeNode* insertIntoBST(TreeNode* r, int val) {
        if(r==nullptr){
            return new TreeNode(val);
        }
        if(r->val>val){
            // insert in left subtree
            TreeNode* newLeft = insertIntoBST(r->left,val);
            r->left=newLeft;
        }else{
            TreeNode* newRight = insertIntoBST(r->right,val);
            r->right=newRight;
        }
        return r;
    }

    int getNextGtr(TreeNode* r,int val){
        if(r==nullptr) return INT_MIN;
        if(r->val<=val){
            return getNextGtr(r->right,val);
        }
        int curAns=r->val;
        int sm = getNextGtr(r->left,val);
        if(sm!=INT_MIN) return sm;
        return curAns;
    }
    
	void replace(vector<int> &ar)
	{
        TreeNode* t;
		for(int n=ar.size(),i=n-1;i>=0;i--){
            int res=getNextGtr(t,ar[i]);
            if(res==INT_MIN){
                insertIntoBST(t,ar[i]);
                ar[i]=-1;
                continue;
            }
            int prev=ar[i];
            ar[i] = res;
            insertIntoBST(t,prev);
		}
	}
};
