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
    void getMinAns(unordered_map<int,set<int>> &lf,unordered_map<int,set<int>> &rt,int totSum,int &ans,int n){
            for(auto it:lf){
            int curSz = it.first;
            for(auto lfSum:it.second){
                int nextHalfSz = n/2-curSz;
                auto lb = lower_bound(rt[nextHalfSz].begin(),rt[nextHalfSz].end(),(totSum-2*lfSum)/2);
                if(lb!=rt[nextHalfSz].end()){
                    int rtSum = *lb;
                    ans=min(ans,abs(totSum - 2*rtSum-2*lfSum));
                }
            }
        }
    }

    void help(vector<int> &ar,int pos,int end,int ctTaken,int sum,unordered_map<int,set<int>> &mp){
        if(pos>=end){
            mp[ctTaken].insert(sum);
            return;
        }
        help(ar,pos+1,end,ctTaken,sum,mp);
        help(ar,pos+1,end,ctTaken+1,sum+ar[pos],mp);
    }

    int minimumDifference(vector<int>& ar) {
        // check(ar,13);
        int n=ar.size(),totSum=0,ans=INT_MAX;
        for(auto it:ar) totSum+=it;
        unordered_map<int,set<int>> lf,rt;
        help(ar,0,n/2,0,0,lf);
        help(ar,n/2,n,0,0,rt);

        getMinAns(lf,rt,totSum,ans,n);
        getMinAns(rt,lf,totSum,ans,n);

        return ans;
    }
};