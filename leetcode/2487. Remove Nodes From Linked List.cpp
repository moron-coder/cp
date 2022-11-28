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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stk;
        for(ListNode* ptr=head;ptr!=NULL;ptr=ptr->next){
            while (stk.size() && stk.top()->val<ptr->val){
                stk.pop();
            }
            stk.push(ptr);
        }
        ListNode* ans=stk.top();
        stk.pop();
        while (stk.size()){
            stk.top()->next=ans;
            ans=stk.top();
            stk.pop();
        }
        return ans;
    }
};