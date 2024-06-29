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

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& ar){
        int *mp = new int[n+1]();
        for(auto it:ar){
            mp[it[0]]++;
            mp[it[1]]++;
        }
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            if(mp[i]) pq.push(mp[i]);
        }
        long long ans=0;
        while (pq.size()){
            ans+=1LL*n*pq.top();
            pq.pop();
            n--;
        }
        return ans;
    }
};