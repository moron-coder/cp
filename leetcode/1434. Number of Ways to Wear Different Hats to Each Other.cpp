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
    int dp[40][1025];

    int help(vector<int> &ar,int persons,int pos,map<int,set<int>> &unqHatsMap,int personCt){
        // persons : person's 0th bit 0 = 1 : impliers 0th person has worn the hat and vice versa
        // pos : denotes the hat position regarding which we are taking decision
        int ans=0,n=ar.size();
        if(pos>=n){
            for(int i=0;i<personCt;i++){
                if(persons&(1<<i)) continue;
                return 0;
            }
            return 1;
        }
        if(dp[pos][persons]!=-1) return dp[pos][persons];
        ans=help(ar,persons,pos+1,unqHatsMap,personCt)%mod;
        for(int i=0;i<personCt;i++){
            if((persons&(1<<i)) || !unqHatsMap[ar[pos]].count(i)){
                continue;
            }
            persons^=(1<<i);
            int smallAns = help(ar,persons,pos+1,unqHatsMap,personCt);
            ans=(ans+smallAns)%mod;
            persons^=(1<<i);
        }
        return dp[pos][persons]=ans;
    }

    int numberWays(vector<vector<int>>& hats) {
        memset(dp,-1,sizeof(dp));
        int personCount = hats.size();
        map<int,set<int>> unqHatsMap;           //  hats: persons who like this hat
        for(int i=0;i<hats.size();i++){
            for(auto it:hats[i]){
                unqHatsMap[it].insert(i);
            }
        }
        vector<int> ar;
        for(auto it:unqHatsMap) ar.push_back(it.first);
        return help(ar,0,0,unqHatsMap,personCount);
    }
};