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

int getIdx(vector<vector<int>> &ans,int k){
    // ans is in low to high order (ascending)
    int idx=-1,lo=0,hi=ans.size()-1;
    while (lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(ans[mid].back()>k){
            idx=mid;
            hi=mid-1;
        }else lo=mid+1;
    }
    return idx;
}

int minTowers(vector<int> &ar, int n){
    vector<vector<int>> ans;        //  {{tower[0][0],tower[0][1],..},{tower[1][0],tower[1][1],..},...}
    for(int i=0;i<n;i++){
        int idx=getIdx(ans,ar[i]);
        if(idx==-1){
            ans.push_back({ar[i]});
        }else ans[idx].push_back(ar[i]);
    }
    return ans.size();
}