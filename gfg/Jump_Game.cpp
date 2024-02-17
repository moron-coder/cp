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

const static int MAX_ANS=1000000000;

int jumpGame(vector<int> &ar){
    int n=ar.size(),ans=0,maxReach=0,prevPtToMaxReach=0;
    for(int i=0;i<n;i++){
        if(i==n-1) return ans;
        maxReach=max(maxReach,min(n-1,i+ar[i]));
        if(i>maxReach) return -1;
        if(i==prevPtToMaxReach){
            prevPtToMaxReach=maxReach;
            ans++;
        }
    }
    return -1;
}

int main(){
    vector<int> ar={1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout<<jumpGame(ar)<<endl;
    return 0;
}