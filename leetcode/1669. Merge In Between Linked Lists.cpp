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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ptr=list1,*prev=NULL;
        for(int i=0;i<=b;i++){
            if(i<a) prev=ptr;
            ptr=ptr->next;
            if(i==a-1){
                prev->next = list2;
                while (prev->next!=NULL){
                    prev = (prev->next);
                }
            }
        }
        prev->next = ptr;
        return list1;
    }
};