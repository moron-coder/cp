#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mii map<int, int>
#define mll map<ll, ll>
#define pii pair<int, int>
#define pbi pair<bool, int>
#define pic pair<int, char>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define vvi vector<vector<int>>
#define ull unsigned long long int
#define mod 1000000007
#define ll long long int

class Solution {
public:
    bool isCircularSentence(string s) {
        char ls=s.back();
        bool isF=true;
        for(auto it:s){
            if(it==' '){
                isF=true;
            }else{
                if(isF && it!=ls) return false;
                ls=it;
                isF=false;
            }
        }
        return true;
    }
};