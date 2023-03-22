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

class car{
    int num;
    public:
    car(int x){
        num=x;
        cout<<"inside car "<<num<<" constructor\n";
    }

    ~car(){
        cout<<"inside car "<<num<<" destructor\n";
    }
};

int main(){
    car *c1=new car(1);
    car c2(2);
    if(1){
        car c3(3);
    }
    cout<<"outside if\n";
    {
        car c4(4);
    }
    cout<<"outside block\n";
    delete c1;
    return 0;
}