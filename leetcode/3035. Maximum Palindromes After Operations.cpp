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
    static bool cmp(int len1,int len2){
        int leftWt = (len1&1)?len1-1:len1, rightWt = (len2&1)?len2-1:len2;
        return leftWt<rightWt;
    }

    int maxPalindromesAfterOperations(vector<string>& ar) {
        int wordsOddCtr=0,charsOddCtr=0;
        bool *fq = new bool[26]();
        vector<int> wordLengths;
        for(auto it:ar){
            wordLengths.push_back(it.size());
            for(auto ch:it){
                fq[ch-'a']^=1;
            }
            wordsOddCtr+=(it.size()&1);
        }
        for(int i=0;i<26;i++) charsOddCtr+=(fq[i]&1);
        sort(wordLengths.begin(),wordLengths.end(),cmp);
        int extras = max(0,charsOddCtr-wordsOddCtr);
        while(extras && wordLengths.size()){
            if(wordLengths.back()&1){
                extras=max(0,extras-wordLengths.back()+1);
            }else{
                extras=max(0,extras-wordLengths.back());
            }
            wordLengths.pop_back();
        }
        return wordLengths.size();
    }
};