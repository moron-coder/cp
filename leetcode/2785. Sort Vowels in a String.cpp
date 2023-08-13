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
    bool isCapVowel(char it,int vowels){
        return (it>='A' && it<='Z' && (vowels&(1<<(it-'A'))));
    }

    bool isSmallVowel(char it,int vowels){
        return (it>='a' && it<='z' && (vowels&(1<<(it-'a'))));
    }

    int getNextPos(int *ar,int pos){
        if(pos>=26) return -1;
        if(ar[pos]){
            ar[pos]--;
            return pos;
        }
        return getNextPos(ar,pos+1);
    }

    string sortVowels(string s) {
        int vowels=0;
        vowels|=1;
        vowels|=(1<<4);
        vowels|=(1<<8);
        vowels|=(1<<14);
        vowels|=(1<<20);
        
        int *fqCaps = new int[26](),*fqSmalls = new int[26]();
        int capPos=0,smallPos=0;
        for(auto it:s){
            if(isCapVowel(it,vowels)) fqCaps[it-'A']++;
            if(isSmallVowel(it,vowels)) fqSmalls[it-'a']++;
        }
        for(int i=0;i<s.size();i++){
            if(isCapVowel(s[i],vowels) || isSmallVowel(s[i],vowels)){
                // try replacing with caps first, then small
                int nextCapPos = getNextPos(fqCaps,capPos);
                if(nextCapPos!=-1){
                    s[i]='A'+nextCapPos;
                    continue;
                }
                int nextSmallPos = getNextPos(fqSmalls,smallPos);
                if(nextSmallPos!=-1){
                    s[i]='a'+nextSmallPos;
                }
            }
        }
        return s;
    }
};