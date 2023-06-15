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
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
void dfs(Node *curNode,unordered_set<Node*> &vis,unordered_map<Node*,Node*> &mp){
    vector<Node*> curNbrs;
    if(curNode!=nullptr && curNode->neighbors.size()){
        for(auto it:curNode->neighbors){
            if(!vis.count(it)){
                vis.insert(it);
                dfs(it,vis,mp);
            }
            curNbrs.push_back(mp[it]);
        }
    }
    Node *replicatedNode = mp[curNode];
    replicatedNode->neighbors = curNbrs;
} 

void makeMap(Node *cur,unordered_map<Node*,Node*> &mp,unordered_set<Node*> &vis){
    vis.insert(cur);
    Node *newNode = new Node(cur->val);
    mp[cur]=newNode;
    if(cur!=nullptr && cur->neighbors.size()){
        for(auto it:cur->neighbors){
            if(it!=nullptr && !vis.count(it)){
                makeMap(it,mp,vis);
            }
        }
    }
}

Node *cloneGraph(Node *node){
    if(node==nullptr) return nullptr;
    unordered_map<Node*,Node*> mp;
    unordered_set<Node*> vis;
    makeMap(node,mp,vis);
    vis.clear();
    vis.insert(node);
    dfs(node,vis,mp);
    return mp[node];
}
};