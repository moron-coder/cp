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

//  5:58

class Trie {
public:
    bool isEnd;
    char ch;
    Trie **children;
    Trie() {
        isEnd=false;
        ch='.';
        children=NULL;
    }
    
    void insert(string word) {
        Trie *cur=this;             //  cur is a pointer which stores the address of the current Trie object
        for(int i=0,n=word.size();i<n;i++){
            int cPos=word[i]-'a';
            if((cur->children)==NULL){
                cur->children=new Trie*[26]();
            }
            if(cur->children[cPos]==NULL){
                // make new Trie object of the character word[i]
                cur->children[cPos]=new Trie();
            } 
            cur=(cur->children[cPos]);
            cur->ch=word[i];
            if(i==n-1){
                cur->isEnd=true;
            }
        }
    }
    
    bool search(string &word,int stPos,int endPos) {
        Trie *cur=this;
        for(int i=stPos;i<=endPos;i++){
            int curPos=word[i]-'a';
            if(!(cur->children) || !(cur->children[curPos])){
                return false;
            }
            cur=(cur->children[curPos]);
            if(i==endPos){
                return cur->isEnd;
            }
        }
        return false;   //  won't reach here
    }
    
    bool startsWith(string word) {
        Trie *cur=this;
        for(int n=word.size(),i=0;i<n;i++){
            int curPos=word[i]-'a';
            if(!(cur->children) || !(cur->children[curPos])){
                return false;
            }
            cur=(cur->children[curPos]);
        }
        return true;   //  won't reach here
    }
};

class Solution {
public:
    int dp[31][31];

    bool help(Trie &tr,string &s,int st,int en){
        if(dp[st][en]!=-1) return dp[st][en];
        if(tr.search(s,st,en)) return dp[st][en]=true;
        for(int i=st+1;i<=en;i++){
            if(help(tr,s,st,i-1) && tr.search(s,i,en)) return dp[st][en]=true;
        }
        return dp[st][en]=false;
    }

    bool isConc(Trie &tr,string &s){
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<n;i++){
            // s[i]~s[n-1] is in trie and s[0]~s[i-1] is made up of ATLEAST one string
            if(help(tr,s,0,i-1) && tr.search(s,i,n-1)){
                return true;
            }
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& ar) {
        Trie tr;
        for(auto it:ar){
            tr.insert(it);
        }
        vector<bool> isAns;
        for(auto it:ar){
            isAns.push_back(isConc(tr,it));
        }
        vector<string> ans;
        for(int i=0;i<ar.size();i++) if(isAns[i]) ans.push_back(ar[i]);
        return ans;
    }
};

int main(){
    return 0;
}