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
    static bool cmp(string &s1,string &s2){
        return (s1+s2)<(s2+s1);
    }

    string largestNumber(vector<int>& ar){
        int n=ar.size();
        vector<string> v;
        for(auto it:ar) v.push_back(to_string(it));
        sort(v.begin(),v.end(),cmp);
        reverse(v.begin(),v.end());
        string ans;
        for(auto it:v) ans+=it;
        int i=0,N=ans.size();
        for(i=0;i<ans.size();i++){
            if(ans[i]!='0') break;
        }
        if(i==N) return "0";
        return ans;
    }
};
