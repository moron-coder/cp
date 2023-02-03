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

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *deleteNode(Node *head, int pos){
    if(!pos){
        if(head==nullptr) return head;
        return head->next;
    }
    Node *ptr=head;
    for(int i=0;i<pos-1;i++){
		if(ptr==nullptr) return head;
        ptr=ptr->next;
    }
    Node *nxt=ptr;
    if(nxt==nullptr) return head;
    nxt=nxt->next;  //  to the node that is deleted
    if(nxt==nullptr) return head;
    nxt=nxt->next;  //  to the node that is after the deleted node
    ptr->next=nxt;
    return head;
}
