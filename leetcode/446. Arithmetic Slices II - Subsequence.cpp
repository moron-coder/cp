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

    void disp(vector<pair<unordered_map<ll, ll>, unordered_map<ll, ll>>> &v){
        int n=v.size();
        for(int i=0;i<n;i++){
            cout<<"first:\n";
            for(auto it:v[i].first){
                if(it.second) cout<<it.first<<" -> "<<it.second<<endl;
            }
            cout<<"second:\n";
            for(auto it:v[i].second){
                if(it.second) cout<<it.first<<" -> "<<it.second<<endl;
            }
        }
    }

    int numberOfArithmeticSlices(vector<int>& ar) {
        ll n = ar.size(), ans = 0;
        vector<pair<unordered_map<ll, ll>, unordered_map<ll, ll>>> v(n);  //  {difference_counts,frequency_counts}
        for (ll i = 1; i < n; i++) {
            for (ll j = i - 1; j >= 0; j--) {
                ll curDif = (ll)ar[i] - (ll)ar[j];
                if (v[j].first.count(curDif)) {
                    // (some_element) (ar[j]) (ar[i]) form one subsequence
                    v[i].second[curDif] += v[j].first[curDif];
                    // account for the remaining subsequences (of size >3)
                    v[i].second[curDif] += v[j].second[curDif];
                }
                v[i].first[curDif]++;  //  (v[j]) (v[i])
            }
        }
        for (auto it : v) {
            for (auto keySet : it.second) {
                ans = (ans + keySet.second);
            }
        }
        disp(v);
        return ans;
    }
};
