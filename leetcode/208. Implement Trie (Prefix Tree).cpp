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

class Trie {
    char ch;
    bool ends;
    Trie **children;
public:
    Trie() {
        ch='.';
        ends=false;
        children=NULL;
    }
    
    void insert(string word) {
        Trie *ptr=this;
        for(int i=0;i<word.size();i++){
            int nextCh = word[i]-'a';
            if(ptr->children==NULL){
                ptr->children=new Trie*[26]();
            }
            if(ptr->children[nextCh]==NULL){
                ptr->children[nextCh]=new Trie();
            }
            ptr=ptr->children[nextCh];
            if(i==word.size()-1){
                ptr->ends=true;
            }
        }
    }
    
    bool search(string word) {
        Trie *ptr=this;
        for(int i=0;i<word.size();i++){
            int nextCh = word[i]-'a';
            if(ptr->children==NULL){
                // ptr->children=new Trie*[26]();
                return false;
            }
            if(ptr->children[nextCh]==NULL){
                // ptr->children[nextCh]=new Trie();
                return false;
            }
            ptr=ptr->children[nextCh];
            if(i==word.size()-1){
                return ptr->ends;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Trie *ptr=this;
        for(int i=0;i<prefix.size();i++){
            int nextCh = prefix[i]-'a';
            if(ptr->children==NULL){
                // ptr->children=new Trie*[26]();
                return false;
            }
            if(ptr->children[nextCh]==NULL){
                // ptr->children[nextCh]=new Trie();
                return false;
            }
            ptr=ptr->children[nextCh];
            if(i==prefix.size()-1){
                return true;
            }
        }
        return false;
    }
};