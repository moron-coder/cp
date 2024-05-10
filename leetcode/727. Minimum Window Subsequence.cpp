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
	const static int MAX_ANS = 100000000;
	int dp[20001][101];
public:
	int help(string &s1,string &s2,int prevIdx,int j){
		int n=s1.size(),m=s2.size();
		if(j==m) return prevIdx-1;
        if(prevIdx==s1.size()) return -10;
		if(dp[prevIdx][j]!=-1) return dp[prevIdx][j];
		if(s1[prevIdx]==s2[j]){
			return dp[prevIdx][j] = help(s1,s2,prevIdx+1,j+1);		//	returns last index of s1 such that
			//	s2 is subsequence of s1[firstIdx ~ lastIdx]
		}else{
			return dp[prevIdx][j] = help(s1,s2,prevIdx+1,j);
		}
		return dp[prevIdx][j] = -10;
	}

    string minWindow(string s1, string s2) {
		memset(dp,-1,sizeof(dp));
        int n =  s1.size();
        int m = s2.size();
		int ansLen=INT_MAX,ansIdx=-1;
		for(int i=0;i<n;i++){
            if(s1[i]!=s2[0]) continue;
			int tmp = help(s1,s2,i,0);
			if(tmp!=-10 && ansLen>tmp-i+1){
				ansLen=tmp-i+1;
				ansIdx=i;
			}
		}
		if(ansIdx==-1) return "";
		return s1.substr(ansIdx,ansLen);
    }
};