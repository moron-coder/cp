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
    void setMinGrpCount(int n,int *sToCtMap){
        for(int i=2;i<=n+1;i++){
            int rem = n%i, del = (i-rem)%i;         //  rem<i => i-rem>0 => del>0
            int bigGroupCt = (n/i)-del+((rem>0)?1:0), smallGroupCt = del;
            if(sToCtMap[i-1]!=-1){
                if(smallGroupCt==-1 || bigGroupCt<0) sToCtMap[i-1]=-1;
                else sToCtMap[i-1]+=smallGroupCt+bigGroupCt;
            }
        }
    }
 
    int minGroupsForValidAssignment(vector<int>& ar) {
        int minFq = INT_MAX;
        int *sToCtMap = new int[100001]();  //  stores if size of smaller grp is i, what is the ans
        unordered_map<int,int> mp;
        for(auto it:ar) mp[it]++;

        for(auto it:mp){
            minFq = min(minFq,it.second);
            setMinGrpCount(it.second,sToCtMap);
        }
        int ans=INT_MAX;
        for(int i=1;i<=minFq;i++){
            if(sToCtMap[i]==0) break;
            if(sToCtMap[i]!=-1) ans=min(ans,sToCtMap[i]);
        }
        return ans;
    }
};