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
    int kBigIndices(vector<int>& ar, int k) {
        int ans=0,n=ar.size();
        vector<bool> prefs(n,false),sufs(n,false);
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            if(pq.size() && pq.top()<ar[i] && pq.size()==k) prefs[i]=true;
            pq.push(ar[i]);
            if(pq.size()>k) pq.pop();
        }
        while (pq.size()) pq.pop();
        for(int i=n-1;i>=0;i--){
            if(pq.size() && pq.top()<ar[i] && pq.size()==k) sufs[i]=true;
            pq.push(ar[i]);
            if(pq.size()>k) pq.pop();
        }
        for(int i=0;i<n;i++) if(prefs[i] && sufs[i]) ans++;
        return ans;
    }
};