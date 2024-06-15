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
 * @author : Utkarsh
 * @date : 2024-06-15 3:33 AM 
*/

class Node{
    public:
    Node *left,*right;
};

class LRUCache {
    int cap,size;
    Node *head, *tail;
    unordered_map<int,Node*> keyToAddress;
    unordered_map<Node*,int> addressToKey;
    unordered_map<int,int> keyVal;

    void insertNode(Node *cur){
        if(head==NULL){
            head = cur;
            tail = cur;
            return;
        }
        head->left = cur;
        cur->right = head;
        head = cur;
    }

    void evictNode(Node *cur){
        Node *lf = cur->left, *rt = cur->right;
        if(lf!=NULL){
            lf->right = rt;
        }else{
            head = rt;
            if(head) head->left = NULL;
        }
        if(rt!=NULL){
            rt->left = lf;
        }else{
            tail = lf;
            if(tail) tail->right = NULL;
        }
        cur->left=NULL;
        cur->right=NULL;
    }

    void deleteLRUNode(){
        Node* lruNode = tail;
        evictNode(lruNode);
        int key = addressToKey[lruNode];
        keyToAddress.erase(key);
        addressToKey.erase(lruNode);
        keyVal.erase(key);
        delete lruNode; 
    }

    void updateKeyPos(int key){
        Node *keyAddr = keyToAddress[key];
        evictNode(keyAddr);
        insertNode(keyAddr);
    }
public:

    LRUCache(int capacity) {
        this->cap = capacity;
        size=0;
        head=NULL;
        tail=NULL;
    }
    
    int get(int key) {
        if(keyVal.count(key)){
            updateKeyPos(key);
            return keyVal[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(keyVal.count(key)){
            updateKeyPos(key);
        }else{
            if(size==cap){
                deleteLRUNode();
            }else{
                size++;
            }
            Node *newNode = new Node();
            keyToAddress[key] = newNode;
            addressToKey[newNode] = key;
            insertNode(newNode);
        }
        keyVal[key]=value;
    }
};