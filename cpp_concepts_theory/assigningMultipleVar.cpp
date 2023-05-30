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

class node{
    int x;
    node *nxt;
    public:
    node(int x){
        this->x=x;
        nxt=nullptr;
    }

    node(node &n1){
        cout<<"copy constructor called and n1 is "<<n1.x<<"\n";
        this->x=n1.x;
        this->nxt=n1.nxt;
    }
};

int main(){
    int x,y;
    cout<<x<<" & "<<y<<endl;
    x=y=7;
    cout<<x<<" & "<<y<<endl;
    y=9;
    cout<<x<<" & "<<y<<endl;
    cout<<(x=10)<<endl;

    node n1(5);
    node n2=n1;
    node n3(-1);
    n3=n2;
    return 0;
}