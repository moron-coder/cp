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

class Node{
    public:
    bool isEnd;
    int val;
    Node **children;

    Node(){
        this->isEnd=false;
        this->val=-1;
        this->children=nullptr;
    }

    Node(int val,bool isEnd=false){
        this->val=val;
        this->children=nullptr;
        this->isEnd=isEnd;
    }
};

class Trie {
    Node *root;
public:
    Trie() {
        this->root=nullptr;
    }
    
    void insert(string word) {
        if(root==nullptr){
            root=new Node();
        }
        Node *tmp=root;
        for(int i=0;i<word.size();i++){
            int cur=word[i]-'a';
            //  root's value is -1
            if(tmp->children==nullptr){
                tmp->children = new Node*[26]();
            }
            if(tmp->children[cur]==nullptr){
                tmp->children[cur]=new Node(cur);
            }
            tmp=(tmp->children[cur]);
            if(i==word.size()-1){
                tmp->isEnd=true;
            }
        }
    }
    
    bool search(string word) {
        Node *tmp=this->root;
        for(int i=0;i<word.size();i++){
            if(tmp==nullptr){
                return false;
            }
            if(tmp->children==nullptr){
                return false;
            }
            int cur=word[i]-'a';
            if(tmp->children[cur]==nullptr){
                return false;
            }
            tmp=(tmp->children[cur]);
            if(i==word.size()-1){
                return tmp->isEnd;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Node *tmp=this->root;
        for(int i=0;i<prefix.size();i++){
            if(tmp==nullptr){
                return false;
            }
            if(tmp->children==nullptr){
                return false;
            }
            int cur=prefix[i]-'a';
            if(tmp->children[cur]==nullptr){
                return false;
            }
            tmp=(tmp->children[cur]);
        }
        return true;
    }
};