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
    int help(vector<int> &ar){
        int n=ar.size(),ans=0; 
        for(int i=0;i<n;i++){
            set<int> st;
            int scr=0;
            for(int j=i+1;j<n;j++){
                if(st.count(ar[j])){
                    ans+=scr;
                    continue;
                }
                st.insert(ar[j]);
                auto it = st.lower_bound(ar[j]);
                bool prev=false,nxt=false;
                if(it!=st.begin()){
                    prev=true;
                    --it;
                    int lo = *it;
                    if(ar[j]-lo>1) scr++;
                }
                it = st.upper_bound(ar[j]);
                if(it!=st.end()){
                    nxt=true;
                    int hi = *it;
                    if(hi-ar[j]>1) scr++;
                }
                if(prev && nxt) scr--;
                ans+=scr;
            }
        }
        return ans;
    }

    int sumImbalanceNumbers(vector<int>& ar) {
        int ans = help(ar);
        return ans;
    }
};