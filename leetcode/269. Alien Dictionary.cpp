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
    bool addLetterOrder(string &s1, string &s2,vector<vector<bool>> &adj){
        int i=0,j=0;
        while (i<s1.size() && j<s2.size() && s1[i]==s2[j]){
            i++,j++;
        }
        if(i<s1.size() && j<s2.size()){
            adj[s1[i]-'a'][s2[j]-'a']=true;
        }
        if(i!=s1.size() && j==s2.size()){
            return false;
        }
        return true;
    }

    bool topSort(vector<vector<bool>> &adj, int pos, int *vis, stack<int> &stk){
        vis[pos]=1;
        for(int i=0;i<adj[pos].size();i++){
            if(adj[pos][i]){
                if(vis[i]==1){
                    return false;           //  cycle found
                }else if(vis[i]==0 && !topSort(adj, i, vis, stk)){
                    return false;
                }
            }
        }
        vis[pos]=2;
        stk.push(pos);
        return true;
    }

public:
    string alienOrder(vector<string>& ar) {
        vector<vector<bool>> adj(26,vector<bool>(26,false));
        bool *charPresentInAr = new bool[26]();
        for(auto word:ar){
            for(auto letter:word){
                charPresentInAr[letter-'a']=true;
            }
        }
        int n=ar.size();
        for(int i=0; i<n; i++){
            for(int j=i+1;j<n;j++){
                if(!addLetterOrder(ar[i], ar[j], adj)){
                    return "";
                }
            }
        }        

        int *vis = new int[26]();
        stack<int> stk;
        for(int i=0;i<26;i++){
            if(charPresentInAr[i] && vis[i]==0 && !topSort(adj, i, vis, stk)){
                return "";
            }
        }
        string ans;
        while (stk.size()){
            ans.push_back('a'+stk.top());
            stk.pop();
        }
        return ans;
    }
};