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
int dp[301];

bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        unordered_map<string,int> m;
        for(int i=0;i<wordDict.size();i++)
        {
            m[wordDict[i]]++;
        }

        return f(0,s,m);

    }

    bool f(int ind,string &s,unordered_map<string,int> &m )
    {
        if(ind>=s.size())
        {
            return true;
        }
        if(dp[ind]!=-1) return dp[ind];
        for(int j=ind;j<s.size();j++)
        {
            if(m.find(s.substr(ind,j-ind+1))!=m.end() && f(j+1,s,m) )
            {
                return dp[ind]=true;
            }

        }
        return dp[ind]=false;
    }
};

/*
select Emp_ID,Emp_name from Emp_data 
where Email like '%bcd%' and Dept in ('D3','D4') and HomeTown NOT in ('Himachal','Guwahati')

select Emp_ID,Emp_name from Emp_data
where Email like '%bcd%' and Dept in ('D3','D4') and HomeTown NOT IN ('Himachal','Guwahati');
*/