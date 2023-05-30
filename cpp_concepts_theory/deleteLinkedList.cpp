#include <bits/stdc++.h>
using namespace std;
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

class node{
    public:
    int val;
    node *nxt;

    node(int x){
        val=x;
        nxt=nullptr;
    }

    void pb(int x){
        node *itr=this;
        while (itr->nxt) itr=(itr->nxt);
        itr->nxt=new node(x);
    }

    void disp(){
        node *itr=this;
        while (itr){
            cout<<itr->val<<" --> ";
            itr=itr->nxt;
        }
        cout<<endl;
    }
};

int main(){
    node * hd = new node(53);
    hd->pb(5);
    hd->pb(2);
    hd->pb(3);

    node *delNode = hd;
    cout<<"displaying old head\n";
    hd->disp();
    hd=(hd->nxt);
    cout<<"head is now at "<<hd->val<<endl;

    cout<<"deleting "<<delNode->val<<endl;
    delete delNode;
    cout<<"deleted node is: "<<(delNode->val)<<endl;

    cout<<"displaying new head\n";
    hd->disp();
    return 0;
}