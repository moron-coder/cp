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

int minSubsetSumDifference(vector<int>& ar, int n){
    int *sums=new int[10001]();
    int sum=0;
    for(auto it:ar) sum+=it;
    sums[sum]=1;
    for(auto it:ar){
        for(int i=0;i<=10000;i++){
            if(ar[i] && i-it>=0) sums[i-it]=1;
        }
    }
    for(int i=0;i<=10000;i++) if(ar[i]==1) return i;
    return -1;  //  not possible
}