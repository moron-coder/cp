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
    int calculateTime(string s, string word) {
        int ans=0,cur=0;
        int *pos=new int[26]();
        for(int i=0;i<s.size();i++) pos[s[i]-'a']=i;
        for(int i=0;i<word.size();i++){
            ans=ans+abs(cur-pos[word[i]-'a']);
            cur=pos[word[i]-'a'];
        }
        return ans;
    }
};