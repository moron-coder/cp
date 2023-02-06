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

// 7:21

class Node{
    int key,val;
    Node *prev,*nxt;
    public:
    
    Node(int key,int val){
        this->key=key;
        this->val=val;
        prev=nullptr;
        nxt=nullptr;
    }

    // Encapsulation (since access specifiers used)
    void setPrev(Node *newPrev){
        this->prev=newPrev;
    }

    void setNxt(Node *newNxt){
        this->nxt=newNxt;
    }

    void setVal(int newVal){
        this->val=newVal;
    }

    Node* getPrev(){
        return this->prev;
    }

    Node* getNxt(){
        return this->nxt;
    }

    int getVal(){
        return this->val;
    }

    int getKey(){
        return this->key;
    }
};

class LRUCache {
    Node *head,*tail;
    int cap,curCap;
    unordered_map<int,Node*> keyMap;

    void setRecentlyUsed(int key,int val){
        if(head==nullptr || head->getKey()==key){
            if(keyMap[key]!=nullptr) keyMap[key]->setVal(val);
            return;
        }
        Node *curPos = keyMap[key];
        if(tail==curPos){
            deleteLeastRecentNode();
        }else{
            Node *lf=curPos->getPrev(),*rt=curPos->getNxt();
            if(lf!=nullptr) lf->setNxt(rt);
            rt->setPrev(lf);
            curPos->setNxt(nullptr);
            curPos->setPrev(nullptr);
            curCap--;
            // delete curPos;
        }
        addNode(key,val);
    }

    void deleteLeastRecentNode(){
        curCap--;
        if(cap==0) return;
        if(cap==1){
            // delete head;
            // delete tail;
            keyMap.erase(tail->getKey());
            head=nullptr;
            tail=nullptr;
            return;
        }
        Node *newTail = tail->getPrev();
        tail->setPrev(nullptr);
        newTail->setNxt(nullptr);
        keyMap.erase(tail->getKey());
        // delete tail;
        tail=newTail;
    }

    void addNode(int key,int val){
        curCap++;
        if(head==nullptr){
            head=new Node(key,val);
            tail=head;
        }else{
            Node *newNode=new Node(key,val);
            head->setPrev(newNode);
            newNode->setNxt(head);
            head=newNode;
        }
        keyMap[key]=head;
    }

public:
    LRUCache(int capacity) {
        this->cap=capacity;
        this->curCap=0;
        head=nullptr;
        tail=nullptr;
        keyMap.clear();
    }
    
    int get(int key) {
        if(!keyMap.count(key)) return -1;
        int ans=keyMap[key]->getVal();
        setRecentlyUsed(key,ans);
        return ans;
    }
    
    void put(int key, int value) {
        if(keyMap.count(key)){
            // rearrange();
            setRecentlyUsed(key,value);
        }else{
            if(curCap<cap){
                // add(key);
                addNode(key,value);
            }else{
                // delete();
                deleteLeastRecentNode();
                // add(key);
                addNode(key,value);
            }
        }
    }
};