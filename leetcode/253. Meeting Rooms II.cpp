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
        int *tm=new int[1000001]();
        int cur=0,ans=0;
        for(auto it:ar) tm[it[0]]++,tm[it[1]+1]--;
        for(int i=0;i<=1000000;i++) cur+=tm[i],ans=max(ans,cur);
        return ans; 
    }
};