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
    ListNode* doubleIt(ListNode* head) {
        stack<ListNode*> stk;
        ListNode *itr = head;
        while (itr!=nullptr){
            stk.push(itr);
            itr=itr->next;
        }
        int dig=0,carry=0;
        while (stk.size()){
            int newDig = ((stk.top()->val)<<1)+carry;
            carry=newDig/10;
            newDig%=10;
            stk.top()->val = newDig;
            stk.pop();
        }
        ListNode *ans = head;
        if(carry){
            ans = new ListNode(carry);
            ans->next = head;
        }
        return ans;
    }
};