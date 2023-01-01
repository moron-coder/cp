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

class Allocator {
public:
    int *ar;
    int n;

    Allocator(int n) {
        this->n=n;
        ar=new int[n]();
    }
    
    int allocate(int size, int mID) {
        int cts=0;
        for(int i=0;i<n;i++){
            if(!ar[i]){
                cts++;
                if(cts==size){
                    for(int tmp=i;tmp>i-size;tmp--) ar[tmp]=mID;
                    return i-size+1;
                }
            }
            else cts=0;
        }
        return -1;
    }
    
    int free(int mID) {
        int ct=0;
        for(int i=0;i<n;i++){
            if(ar[i]==mID) ar[i]=0,ct++;
        }
        return ct;
    }
};