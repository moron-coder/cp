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
    int getJ(string &s,int i,int j,vector<int> &pi){
        if(s[j]==s[i]){
            return j;
        }
        if(j==0){
            return -1;
        }
        return getJ(s,i,pi[j-1],pi);
    }

    void calcLPS(string &s,vector<int> &pi){
        int n=s.size();
        for(int i=1;i<n;i++){
            int j=getJ(s,i,pi[i-1],pi);
            pi[i]=j+1;
        }
    }

    set<int> bolds;
    
    void kmp(string &text, string &word){
        string mergedStr = word + "#" + text;
        int n=mergedStr.size();
        vector<int> pi(n,0);
        calcLPS(mergedStr,pi);
        vector<int> ends;
        for(int i=word.size()+1;i<mergedStr.size();i++){
            if(pi[i]==word.size()){
                ends.push_back(i-word.size()-1);
            }
        }
        for(int i=0;i<ends.size();i++){
            for(int ct=0;ct<word.size();ct++){
                bolds.insert(ct+ends[i]-word.size()+1);
            }
        }
    }

public:
    string addBoldTag(string s, vector<string>& words) {
        bolds.clear();
        for(auto it:words){
            kmp(s,it);
        }
        string ans;
        for(int i=0;i<s.size();){
            if(bolds.count(i)){
                ans+="<b>";
                while (bolds.count(i)){
                    ans.push_back(s[i]);
                    i++;
                }
                ans+="</b>";
            }else{
                ans.push_back(s[i]);
                i++;
            }
        }
        return ans;
    }
};