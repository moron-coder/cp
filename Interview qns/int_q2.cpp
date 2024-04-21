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
    ll dfs(vector<vector<int>> &edges,vector<bool> &isFilled,int pos,int prev,int m,int parFilledCt,int grandParFilledCt){ 
        isFilled[pos]=true;
        ll ct=parFilledCt+grandParFilledCt,ans=1,curChildrenFilledCt=0;
        // cout<<"ct = "<<ct<<" for pos = "<<pos<<endl;
        ll allowed = max(0LL,m-ct);
        for(auto it:edges[pos]){
            if(it!=prev){
                ll smallAns = dfs(edges,isFilled,it,pos,m,1,parFilledCt+curChildrenFilledCt);
                curChildrenFilledCt++;
                ans = (ans*smallAns)%mod;
            }
        }
        // cout<<pos<<" can use "<<ans<<" * "<<allowed<<endl;
        return (ans*allowed)%mod;
    }

    int solve(int m,int n,vector<int> froms,vector<int> tos){
        vector<vector<int>> edges(n,vector<int>());      //  {index, is_filled (bool)}
        for(int i=0;i<n-1;i++){
            edges[froms[i]-1].push_back(tos[i]-1);
            edges[tos[i]-1].push_back(froms[i]-1);
        }
        vector<bool> isFilled(n,0); 
        return dfs(edges,isFilled,0,-1,m,0,0);
    }
};

int main() {
	// vector<int> froms1 = {1,1};
	// vector<int> tos1 = {2,3};

    // Solution s;

    // cout<<s.solve(4,3,froms1,tos1)<<endl;
    ///////////////////////////////////////////////////////////
	vector<int> froms1 = {1,1,2};
	vector<int> tos1 = {2,3,4};

    Solution s;

    cout<<s.solve(3,4,froms1,tos1)<<endl;
    return 0;
}

