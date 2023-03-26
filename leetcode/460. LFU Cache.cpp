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
    int val;
    Node *prev,*next;

    Node(int x){
        val=x;
        prev=nullptr;
        next=nullptr;
    }
};

class KeyData{
    public:
    int val,fq;
    Node *addr;

    KeyData(){}

    KeyData(int val,int fq,Node *addr){
        this->val=val;
        this->fq=fq;
        this->addr=addr;
    }
};

class LFUCache {
    int maxCap;
    unordered_map<int,KeyData> keyDataMap;
    map<int,pair<Node*,Node*>> fqDataMap;

    void deleteKey(int fq, Node *addr){
        Node *head=fqDataMap[fq].first, *tail=fqDataMap[fq].second;
        if(head==tail){
            fqDataMap.erase(fq);
            return;
        }else if(addr==head){
            head=head->next;
            head->prev=nullptr;
        }else if(addr==tail){
            tail=tail->prev;
            tail->next=nullptr;
        }else{
            Node *prevPtr = addr->prev, *nextPtr = addr->next;
            prevPtr->next=nextPtr;
            nextPtr->prev=prevPtr;
        }
        fqDataMap[fq]={head,tail};
    }

    Node *addKey(int fq, int key){
        if(fqDataMap.count(fq)){
            Node *head=fqDataMap[fq].first, *tail=fqDataMap[fq].second;
            Node *newNode = new Node(key);
            tail->next=newNode;
            newNode->prev=tail;
            tail=tail->next;
            fqDataMap[fq].second=tail;
            return tail;
        }
        Node *head=new Node(key), *tail=head;
        fqDataMap[fq]={head,tail};
        return tail;
    }

    void increaseFrequencyOfKey(int key){
        KeyData keyData = keyDataMap[key];
        Node *addr=keyData.addr;
        int fq=keyData.fq;
        deleteKey(fq,addr);
        Node *newAddr = addKey(fq+1,key);
        keyDataMap[key].fq++;
        keyDataMap[key].addr=newAddr;
    }
public:
    LFUCache(int capacity) {
        maxCap=capacity;
        keyDataMap.clear();
        fqDataMap.clear();
    }
    
    int get(int key) {
        if(!keyDataMap.count(key)){
            return -1;
        }
        increaseFrequencyOfKey(key);
        return keyDataMap[key].val;
    }
    
    void put(int key, int value) {
        if(keyDataMap.count(key)){
            increaseFrequencyOfKey(key);
            keyDataMap[key].val=value;
        }else if(keyDataMap.size()<maxCap){
            Node *newAddr = addKey(1,key);
            keyDataMap[key].fq=1;
            keyDataMap[key].val=value;
            keyDataMap[key].addr=newAddr;
        }else{
            Node *addr=fqDataMap.begin()->second.first;
            int fq=fqDataMap.begin()->first, deletedKey=addr->val;
            deleteKey(fq,addr);
            keyDataMap.erase(deletedKey);
            Node *newAddr = addKey(1,key);
            keyDataMap[key].fq=1;
            keyDataMap[key].val=value;
            keyDataMap[key].addr=newAddr;
        }
    }
};