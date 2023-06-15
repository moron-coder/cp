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
public:
    ListNode* mergeKLists(vector<ListNode*>& ar) {
        ListNode *ansHead=nullptr,*ansTail=nullptr;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(int i=0;i<ar.size();i++){
            if(ar[i]!=nullptr) pq.push({ar[i]->val,ar[i]});
        }
        while (pq.size()){
            pair<int,ListNode*> cur=pq.top();
            pq.pop();
            ListNode *ptr=cur.second;
            if(ansHead==nullptr){
                ansHead=ptr;
                ansTail=ptr;
            }
            else{
                ansTail->next = ptr;
                ansTail = ptr;
            }
            if((ptr->next)!=nullptr){
                pq.push({ptr->next->val,ptr->next});
            }
        }
        return ansHead;
    }
};