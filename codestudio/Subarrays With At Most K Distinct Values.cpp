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

int kDistinctSubarrays(vector<int> &ar, int n, int k){
    int i=0,ans=0;
    unordered_map<int,int> mp;
    for(int j=0;j<n;j++){
        mp[ar[j]]++;
        while (mp.size()>k){
            mp[ar[i]]--;
            if(mp[ar[i]]==0) mp.erase(ar[i]);
            i++;
        }
        ans+=j-i+1;
    }
    return ans;
}
