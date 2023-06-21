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
    Node *next,*prev;
    int data;
    public:

    Node(int data){
        this->data = data;
        next=nullptr;
        prev=nullptr;
    }

    void setData(int newData){
        this->data = newData;
    }

    void setNext(Node *newNext){
        this->next = newNext;
    }

    void setPrev(Node *newPrev){
        this->prev = newPrev;
    }

    int getData(){
        return data;
    }

    Node * getNext(){
        return next;
    }

    Node * getPrev(){
        return prev;
    }
};

class EvictionStrategy{
    public:
    virtual string evictKey();
    virtual void insertKey(string key);
};

class LRUStrategy:public EvictionStrategy{
    Node *head,*tail;
    public:

    string evictKey(){

    }

    void insertKey(){

    }
};

const string RedisCache::KEY_NOT_FOUND = "Key not found";

class RedisCache{
    const static string KEY_NOT_FOUND;
    unordered_map<string,string> keyVals;
    int capacity,curKeyCount;
    EvictionStrategy evictionStrategy;
    public:

    RedisCache(int capacity){
        this->curKeyCount = 0;
        this->capacity = capacity;
        keyVals.clear();
        evictionStrategy = LRUStrategy();
    }

    void put(string key,string val){
        if(curKeyCount==capacity){
            string evictedKey = evictionStrategy.evictKey();
            keyVals.erase(evictedKey);
        }
        evictionStrategy.insertKey(key);
        keyVals[key]=val;
    }

    string get(string key){
        if(keyVals.count(key)) return keyVals[key];
        return KEY_NOT_FOUND;
    }
};