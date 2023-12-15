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
    long long beautifulSubstrings(string s, int k) {
        map<int,map<int,int>> mp;
        mp[0][0]=1;
        int v=0,len=1,ans=0;
        while ((len*len)%(k<<2)) len++;
        string vowels = "aeiou";
        for(int i=0;i<s.size();i++){
            if(s[i]==vowels[0] || s[i]==vowels[1] || s[i]==vowels[2] || s[i]==vowels[3] || s[i]==vowels[4]){
                v++;
            }else{
                v--;
            }
            ans+= mp[v][(i+1)%len];
            mp[v][(i+1)%len]++;
        }
        return ans;
    }
};