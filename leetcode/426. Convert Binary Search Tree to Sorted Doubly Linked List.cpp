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

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    pair<Node*,Node*> modifyTree(Node *r){
        if(r==nullptr){
            return {nullptr,nullptr};           //  {left end, right end}
        }
        pair<Node*,Node*> lf = modifyTree(r->left);
        pair<Node*,Node*> rt = modifyTree(r->right);

        r->left = lf.second;
        if(lf.second!=nullptr) lf.second->right = r;

        r->right = rt.first;
        if(rt.first!=nullptr) rt.first->left = r;

        Node *leftMost = lf.first, *rightMost = rt.second;
        if(leftMost==nullptr) leftMost = r;
        if(rightMost==nullptr) rightMost = r;

        return {leftMost, rightMost};
    }

    Node* treeToDoublyList(Node* root) {
        pair<Node*,Node*> ans = modifyTree(root);
        if(ans.first == nullptr){
            return nullptr;
        }
        ans.first->left = ans.second;
        ans.second->right = ans.first;

        Node *ret = ans.first, *finalRet = ret;

        for(Node *tmp = ret->right; tmp!=ret; tmp = (tmp->right)){
            if(tmp->val<finalRet->val){
                finalRet = tmp;
            }
        }
        return finalRet;
    }
};