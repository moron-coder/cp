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


class Solution{
    public:
    int maxKillerRobots(vector<int> &ar,vector<vector<int>> &q);
};

int Solution::maxKillerRobots(vector<int> &ar, vector<vector<int> > &q) {
    int n=ar.size();
    int *del=new int[n]();
    for(auto it:q){
        int l=it[0],r=it[1],inc=it[2];
        del[l]+=inc;
        if(r+1<n) del[r+1]-=inc;
    }
    int ans=ar[0]+del[0],cur=del[0];
    for(int i=1;i<n;i++){
        cur+=del[i];
        ans=max(ans,cur+ar[i]);
    }
    return ans;
}

int main(){
    Solution s;
    vector<int> ar={4,4,4,3,9,4,5};
    vector<vector<int>> q={{4,5,3},{2,5,10},{4,5,9},{0,5,2},{2,4,5}};
    cout<<s.maxKillerRobots(ar,q)<<endl;
    return 0;
}