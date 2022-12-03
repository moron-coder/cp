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
    string p1,p2;

    void getPath(TreeNode* r,int des,string &dir,bool strt){
        if(!r) return;
        if(r->val==des){
            if(strt) p1=dir;
            else p2=dir;
            return;
        }
        dir.push_back('L');
        getPath(r->left,des,dir,strt);
        dir.pop_back();
        dir.push_back('R');
        getPath(r->right,des,dir,strt);
        dir.pop_back();
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        p1="",p2="";
        string dir="";
        getPath(root,startValue,dir,true);
        getPath(root,destValue,dir,false);
        int endPt=-1;
        for(int i=0;i<min(p1.size(),p2.size());i++){
            if(p1[i]==p2[i]){
                endPt=i;
                continue;
            }else break;
        }
        string ans;
        for(int i=endPt+1;i<p1.size();i++) ans.push_back('U');
        for(int i=endPt+1;i<p2.size();i++) ans.push_back(p2[i]);
        return ans;
    }
};