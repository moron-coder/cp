#include <bits/stdc++.h>
using namespace std;

class base{
    public:
    virtual void disp()=0;
};

class child:public base{
    public:

    void disp(){
        cout<<"child\n";
    }
};

int main(){
    child c;
    base *b = new child;
    cout<<"hello ! compiled successfully";
    return 0;
}