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
    int minMeetingRooms(vector<vector<int>>& ar) {
        int *dp = new int[1000001]();
        for(auto it:ar){
            dp[it[0]]++;
            dp[it[1]]--;
        }
        int sum=0,ans=0;
        for(int i=0;i<=1000000;i++){
            sum+=dp[i];
            ans=max(ans,sum);
        }
        return ans;
    }
};