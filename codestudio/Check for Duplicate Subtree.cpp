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

template<typename T>

class BinaryTreeNode
{
public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

void getAllNodes(BinaryTreeNode<char> *r,vector<BinaryTreeNode<char>*> &v){
    if(r==nullptr) return;
    queue<BinaryTreeNode<char>*> q;
    q.push(r);
    while (q.size()){
        BinaryTreeNode<char> *cur=q.front();
        v.push_back(cur);
        q.pop();
        if((cur->left)!=nullptr) q.push(cur->left);
        if((cur->right)!=nullptr) q.push(cur->right);
    }
}

bool isLeaf(BinaryTreeNode<char> *r){
    return (r!=nullptr && (r->left==nullptr) && (r->right==nullptr));
}

bool isEqual(BinaryTreeNode<char> *n1,BinaryTreeNode<char> *n2){
    return (n1!=nullptr && n2!=nullptr && (n1->data==n2->data));
}

bool case1(BinaryTreeNode<char> *n1,BinaryTreeNode<char> *n2){
    return (isEqual(n1,n2) && isLeaf(n1->left) && isLeaf(n2->left) && isEqual(n1->left,n2->left)
            && (n1->right==nullptr) && (n2->right==nullptr));
}

bool case2(BinaryTreeNode<char> *n1,BinaryTreeNode<char> *n2){
    return (isEqual(n1,n2) && isLeaf(n1->right) && isLeaf(n2->right) && isEqual(n1->right,n2->right)
            && (n1->left==nullptr) && (n2->left==nullptr));
}

bool case3(BinaryTreeNode<char> *n1,BinaryTreeNode<char> *n2){
    return (isEqual(n1,n2) && isLeaf(n1->right) && isLeaf(n2->right) && isEqual(n1->right,n2->right)
            && isLeaf(n1->left) && isLeaf(n2->left) && isEqual(n1->left,n2->left));
}

bool check(BinaryTreeNode<char> *n1,BinaryTreeNode<char> *n2){
    return (case1(n1,n2) || case2(n1,n2) || case3(n1,n2));
}

bool similarSubtree(BinaryTreeNode<char> *r){
    vector<BinaryTreeNode<char>*> vec;
    getAllNodes(r,vec);
    for(int i=0;i<vec.size();i++){
        for(int j=i+1;j<vec.size();j++){
            if(check(vec[i],vec[j])){
                return true;
            }
        }
    }
    return false;
}