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
    int maxLen;
    vector<int> ansIdx;
    int dp[101][3][101];

    int help(vector<int> &groups,vector<string> &words,int &n,int pos,int prevGroup,vector<int> indexes){
        // for(auto it:indexes){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // if(indexes.size()==2 && indexes[0]==0 && indexes[1]==1){
        //     cout<<"prevGroup : "<<prevGroup<<endl;
        // }
        if(pos>=n){
            if(maxLen<indexes.size()){
                ansIdx = indexes;
                maxLen = indexes.size();
            }
            return 0;
        }
        // if(indexes.size()==2 && indexes[0]==0 && indexes[1]==1){
        //     cout<<"prevGroup : "<<prevGroup<<endl;
        // }
        if(dp[pos][prevGroup+1][indexes.size()]!=-1) return dp[pos][prevGroup+1][indexes.size()];
        int notTakeAns = help(groups,words,n,pos+1,prevGroup,indexes);
        int takeAns = 0;
        if(prevGroup!=groups[pos]){
            // if(pos==0){
            //     cout<<"pushing 0\n";
            // }
            indexes.push_back(pos);
            takeAns = help(groups,words,n,pos+1,groups[pos],indexes)+1;
            indexes.pop_back();
        }
        return dp[pos][prevGroup+1][indexes.size()]=max(takeAns,notTakeAns);
    }

    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        memset(dp,-1,sizeof(dp));
        maxLen=0;
        while (ansIdx.size()) ansIdx.pop_back();
        vector<int> indexes;
        help(groups,words,n,0,-1,indexes);
        // cout<<"maxLen = "<<maxLen<<endl;
        vector<string> ret;
        for(auto it:ansIdx) ret.push_back(words[it]);
        return ret;
    }
};