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
    Node* left;
    Node* right;
    Node* parent;
};

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node *p1=p,*p2=q;
        int c1=0,c2=0;
        while (p1->parent){
            p1=p1->parent;
            c1++;
        }
        while (p2->parent){
            p2=p2->parent;
            c2++;
        }
        if(c1>c2) p1=p,p2=q;
        else p1=q,p2=p;
        int num=abs(c1-c2);
        while (num){
            p1=p1->parent;
            num--;
        }
        // now both are at the same level
        while (p1!=p2){
            p1=p1->parent;
            p2=p2->parent;
        }
        return p1;
    }
};