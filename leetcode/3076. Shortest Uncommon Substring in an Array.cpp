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
    int fq;
    trie *children[26];
    public:

    trie(){
        fq=0;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }

    void insert(string &s){
        int n=s.size();
        trie *tmp = this;
        for(int i=0;i<n;i++){
            int nxt = s[i]-'a';
            if(tmp->children[nxt]==NULL){
                tmp->children[nxt]=new trie();
            }
            tmp = tmp->children[nxt];
            tmp->fq++;
        }
    }

    bool isWordPresent(string &s){
        int n=s.size();
        trie *tmp = this;
        for(int i=0;i<n;i++){
            int nxt = s[i]-'a';
            if(tmp->children[nxt]==NULL){
                return false; 
            }
            tmp = tmp->children[nxt];
            if(tmp->fq==0){
                return false;
            }
        }
        return true;
    }

    void deleteWord(string &s){
        int n=s.size();
        trie *tmp=this;
        for(int i=0;i<n;i++){
            int nxt = s[i]-'a';
            if(tmp->children[nxt]==NULL){
                cout<<"error!!!\n";
                return;
            }
            tmp = tmp->children[nxt];
            tmp->fq--;
        }
    }

};

class Solution {
    void insertAllCombinations(trie &t,string &s){
        int n=s.size();
        for(int i=0;i<n;i++){
            string tmp;
            for(int j=i;j<n;j++){
                tmp.push_back(s[j]);
                t.insert(tmp);
            }
        }
    }

    void deleteAllCombinations(trie &t,string &s){
        int n=s.size();
        for(int i=0;i<n;i++){
            string tmp;
            for(int j=i;j<n;j++){
                tmp.push_back(s[j]);
                t.deleteWord(tmp);
            }
        }
    }

    string getAns(string &s, trie &t){
        string ans;
        int n=s.size();
        for(int i=0;i<n;i++){
            string tmp;
            for(int j=i;j<n;j++){
                tmp.push_back(s[j]);
                if(!t.isWordPresent(tmp) && (ans.size()==0 || ans.size()>tmp.size() || (ans.size()==tmp.size() && tmp<ans))){
                    ans=tmp;
                }
            }
        }
        return ans;
    }

public:
    vector<string> shortestSubstrings(vector<string>& ar) {
        trie t;
        int n=ar.size();
        for(int i=0;i<n;i++){
            insertAllCombinations(t,ar[i]);
        }

        vector<string> ans;

        for(int i=0;i<n;i++){
            deleteAllCombinations(t,ar[i]);
            ans.push_back(getAns(ar[i],t));
            insertAllCombinations(t,ar[i]);
        }
        return ans;
    }
};