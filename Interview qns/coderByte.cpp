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

const static int MAX_ANS=100000000;

int dp[(1<<16)+1];
unordered_map<int,int> mp;

int minAns(vector<vector<int>> &ar,int pos,int state){
    int n=ar.size(),ans=MAX_ANS,setCol=-1;
    if(pos>=n) return 0;
    if(dp[state]!=-1) return dp[state];
    for(int j=0;j<n;j++){
        if(state&(1<<j)) continue;
        int sm = minAns(ar,pos+1,state^(1<<j))+ar[pos][j]; 
        if(sm<ans){
            // use jth column at ith row
            ans=sm;
            setCol=j;
        }
    }
    mp[state] = setCol;
    return dp[state] = ans;
}

vector<pair<int,int>> arrayChallenge(vector<vector<int>> &ar){
    memset(dp,-1,sizeof(dp));
    mp.clear();
    int ans = minAns(ar,0,0);
    vector<pair<int,int>> ret;
    int n=ar.size(),curState=0,rowCt=0;
    while (mp.count(curState)){
        int nextCol = mp[curState];
        ret.push_back({rowCt+1,nextCol+1});
        rowCt++;
        curState^=(1<<nextCol);
    }
    return ret;
}

void dispAns(vector<vector<int>> &ar){
    vector<pair<int,int>> ans = arrayChallenge(ar);
    for(auto it:ans){
        cout<<it.first<<" - "<<it.second<<endl;
    }
    cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
}

int main(){
    vector<vector<int>> ar1 = {{1,2,1},{4,1,5},{5,2,1}};
    vector<vector<int>> ar2 = {{13,4,7,6},{1,11,5,4},{6,7,2,8},{1,3,5,9}};
    dispAns(ar1);
    dispAns(ar2);
    return 0;
}