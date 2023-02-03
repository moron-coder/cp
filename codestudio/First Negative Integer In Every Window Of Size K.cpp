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

vector<int> firstNegativeInteger(vector<int> &ar, int k, int n){
    deque<int> dq;
    vector<int> ans;
    for(int i=0;i<ar.size();i++) if(ar[i]<0) dq.push_back(i);
    for(int i=0;i+k-1<ar.size();i++){
        while (dq.front()<i) dq.pop_front();
        if(dq.front()>i+k-1) ans.push_back(0);
        else ans.push_back(ar[dq.front()]);
    }
    return ans;
}

