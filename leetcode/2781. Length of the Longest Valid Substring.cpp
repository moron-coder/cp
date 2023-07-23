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

class trie{
    trie **children;
    bool isEnd;
    public:

    trie(){
        isEnd=false;
        this->children=nullptr;
    }

    void insertWord(string s){
        trie *r = this;
        for(int i=0;i<s.size();i++){
            // cout<<"inserting "<<s[i]<<endl;
            if((r->children)==nullptr){
                r->children = new trie*[26]();
            }
            int nextChar = s[i]-'a';
            if(r->children[nextChar]==nullptr){
                r->children[nextChar]=new trie();
            }
            r=r->children[nextChar];
            if(i==s.size()-1){
                r->isEnd=true;
            }
        }
    }

    bool isWordPresent(string s){
        trie *r=this;
        for(int i=0;i<s.size();i++){
            if(r->children==nullptr) return false;
            int nextChar = s[i]-'a';
            if(r->children[nextChar]==nullptr) return false;
            r=r->children[nextChar];
            if(i==s.size()-1){
                return r->isEnd;
            }
        }
        return false;        //  this line is executed when s is empty
    }
};

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        trie t;
        int ans=0,n=word.size();
        int *dp=new int[n]();
        for(auto it:forbidden) t.insertWord(it);
        for(int i=0;i<n;i++){
            dp[i]=n;
            string s;
            for(int j=i;j<min(n,i+10);j++){
                s.push_back(word[j]);
                if(t.isWordPresent(s)){
                    dp[i]=j;
                    break;
                }
            }
        };
        int nextInvalidIndex=n;
        for(int i=n-1;i>=0;i--){
            nextInvalidIndex=min(nextInvalidIndex,dp[i]);
            ans=max(ans,nextInvalidIndex-i);
        }
        return ans;
    }
};