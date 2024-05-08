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
    trie *chilren[26];
    public:

    trie(){
        this->fq=0;
        for(int i=0;i<26;i++) this->chilren[i]=nullptr;
    }

    int insert(string &s){
        int n=s.size(),last=-1;
        trie *cur=this;
        for(int i=0;i<n;i++){
            int nxt = s[i]-'a';
            if(cur->chilren[nxt]==nullptr){
                cur->chilren[nxt]=new trie();
            }
            cur = cur->chilren[nxt];
            cur->fq++;
            last=cur->fq;
        }
        return last;
    }
};

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string s, int k) {
        int mx=-1;
        trie t;
        int n=s.size();
        for(int i=0;i<s.size();i+=k){
            string tmp;
            for(int j=i;j<i+k;j++){
                tmp.push_back(s[j]);
            }
            mx=max(mx,t.insert(tmp));
        }
        return n/k-mx;
    }
};