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
    bool isOk(vector<string> &words,vector<int> &groups,int i,int j){
        if(groups[i]==groups[j] || words[i].size()!=words[j].size()){
            return false;
        }
        int dif=0,n=words[i].size();
        for(int it=0;it<n;it++){
            if(words[i][it]!=words[j][it]) dif++;
        }
        return dif==1;
    }

    unordered_map<int,pii> mp;

    int dp[1001];

    int help(vector<string> &words,vector<int> &groups,int pos){
        int n=words.size(), ans=0;
        if(pos>=n) return 0;
        if(dp[pos]!=-1) return dp[pos];
        for(int i=pos+1;i<n;i++){
            if(isOk(words,groups,pos,i)){
                int small = help(words,groups,i);
                if(small+1>ans){
                    ans = small+1;
                    mp[pos] = {i,small+1};
                }
            }
        }
        return dp[pos] = ans;
    }

    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        mp.clear();   
        memset(dp,-1,sizeof(dp));
        int maxLen = 0;

        for(int i=0;i<n;i++){
            maxLen = max(maxLen,help(words,groups,i));
        }
        
        vector<int> ansIdx;

        int startIdx = -1;
        for(auto it:mp){
            if(it.second.second==maxLen){
                startIdx=it.first;
            }
        }

        if(startIdx==-1){
            return {words[0]};
        }

        while (1){
            ansIdx.push_back(startIdx);
            if(!mp.count(startIdx)) break;
            startIdx = mp[startIdx].first;
        }

        vector<string> ans;
        for(auto it:ansIdx) ans.push_back(words[it]);
        return ans;
    }
};