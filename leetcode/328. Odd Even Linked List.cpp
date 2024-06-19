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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    void incrementPtr(ListNode *&head, ListNode *&tail, ListNode *&tmp){
        if(tmp==NULL){
            return;
        }
        if(head==NULL){
            head = tmp;
            tail = tmp;
        }else{
            tail->next = tmp;
            tail = tmp;
        }

        tmp = tmp->next;
    }    

public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oddStart=NULL, *oddEnd=NULL, *eventStart=NULL, *evenEnd=NULL;
        ListNode *tmp = head;
        while (tmp!=NULL){
            incrementPtr(oddStart, oddEnd, tmp);
            incrementPtr(eventStart, evenEnd, tmp);
        }
        if(oddEnd!=NULL) oddEnd->next = eventStart;
        if(evenEnd!=NULL) evenEnd->next=NULL;
        return oddStart;
    }
};