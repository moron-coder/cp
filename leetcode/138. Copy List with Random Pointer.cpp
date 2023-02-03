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
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* h) {
        if(h==nullptr) return nullptr;
        Node *ptr=h,*ans=new Node(ptr->val),*ansEnd=ans;
        ptr=(ptr->next);
        while(ptr!=nullptr){
            ansEnd->next = new Node(ptr->val);
            ansEnd=ansEnd->next;
            ptr=ptr->next;
        }
        // reset and start again to form grid
        ptr=h;
        ansEnd=ans;
        while(ptr!=nullptr){
            Node *ptrNext = ptr->next,*ansEndNext=ansEnd->next;
            ptr->next=ansEnd;
            ansEnd->next=ptrNext;
            ansEnd=ansEndNext;
            ptr=ptrNext;
        }
        // reset and start again and adjust the random pointer of ans
        ptr=h;
        ansEnd=ans;
        while(ptr!=nullptr){
            if(ptr->random!=nullptr) ansEnd->random=(ptr->random->next);
            ptr=ansEnd->next;
            if(ptr==nullptr) break;
            ansEnd=ptr->next;
        }        
        // reset and start again and reset ptr to original
        ptr=h;
        ansEnd=ans;
        while(ptr!=nullptr){
            ptr->next=ansEnd->next;
            if(ptr->next==nullptr) break;
            ansEnd->next=ptr->next->next;
            ptr=ptr->next;
            ansEnd=ansEnd->next;
        }
        return ans;
    }
};