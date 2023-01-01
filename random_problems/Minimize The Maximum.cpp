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

int help(vector<int> ar,int n){
    sort(ar.begin(),ar.end());
    // debug
//     cout<<"ar is :\n";
//     for(auto it:ar) cout<<it<<" ";
//     cout<<endl;
    // debug
    return ar[n-1]-ar[0];
}

int minimizeMaximum(int ar[], int n, int k){
    vector<int> v;
    for(int i=0;i<n;i++) v.push_back(ar[i]);
    sort(v.begin(),v.end());
    int i=0,j=n-1,ans=help(v,n);
//     cout<<"ans= "<<ans<<endl;
    while (i<j){
        v[i]+=k,v[j]-=k;
        i++,j--;
    }
    if(i==j){
        v[i]+=k;
        ans=min(ans,help(v,n));
        v[i]-=2*k;
        ans=min(ans,help(v,n));
    }else{
        ans=min(ans,help(v,n));
    }
    return ans;
}


/*
1
6
1 10 14 14 14 15
6

7 14 20 8 8 9
*/