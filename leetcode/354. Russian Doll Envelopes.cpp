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
    int getLis(vector<vector<int>> &ar1){
        vector<vector<int>> ar;
        map<int,int> mp;
        for(auto it:ar1){
            if(!mp.count(it[0])) mp[it[0]]=it[1];
            else mp[it[0]]=min(mp[it[0]],it[1]);
        }
        for(auto it:mp) ar.push_back({it.first,it.second});
        vector<int> lis;
        for(int i=0;i<ar.size();i++){
            if(lis.empty() || (ar[lis.back()][1]<ar[i][1])){
                lis.push_back(i);
            }else{
                int bestPos=-1,lo=0,hi=lis.size()-1;
                while (lo<=hi){
                    int mid = lo+(hi-lo)/2;
                    if(ar[lis[mid]][0]<ar[i][0] && ar[lis[mid]][1]<ar[i][1]){
                        bestPos=mid;
                        hi=mid-1;
                    }else lo=mid+1;
                }
                if(bestPos!=-1) lis[bestPos]=i;
            }
        }
        return lis.size();
    }

    int maxEnvelopes(vector<vector<int>>& ar) {
        sort(ar.begin(),ar.end());
        return getLis(ar);
    }
};