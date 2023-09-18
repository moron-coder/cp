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
    bool checkStrings(string s1, string s2) {
        int *fqOdd = new int[26](),*fqEven = new int[26]();
        for(int i=1;i<s1.size();i+=2){
            fqOdd[s1[i]-'a']++;
            fqOdd[s2[i]-'a']--;
        }
        for(int i=0;i<s1.size();i+=2){
            fqEven[s1[i]-'a']++;
            fqEven[s2[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(fqOdd[i]!=0 || fqEven[i]!=0) return false;
        }
        return true;
    }
};