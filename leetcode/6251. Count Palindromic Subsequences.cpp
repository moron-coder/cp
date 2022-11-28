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
    ll pre[10][10][10001],suf[10][10][10001];
    ll p1[10][10001],s1[10][10001];

    void ct(string &s){
        int n=s.size();
        for(int i=0;i<=9;i++){
            p1[i][0]=(s[0]-'0'==i);
            for(int pos=1;pos<n;pos++){
                p1[i][pos]=(p1[i][pos-1]+(s[pos]-'0'==i));
            }
            s1[i][n-1]=(s[n-1]-'0'==i);
            for(int pos=n-2;pos>=0;pos--){
                s1[i][pos]=(s1[i][pos+1]+(s[pos]-'0'==i));
            }
        }
        // pre[i][j][k] : no of pair of 'i''j' in s[0]~s[i] and vice versa for suf
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                for(int pos=1;pos<n;pos++){
                    pre[i][j][pos]=pre[i][j][pos-1];
                    if(s[pos]-'0'==j){
                        pre[i][j][pos]=(pre[i][j][pos]+p1[i][pos-1])%mod;
                    }
                }
            }
        }

        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                for(int pos=n-2;pos>=0;pos--){
                    suf[i][j][pos]=suf[i][j][pos+1];
                    if(s[pos]-'0'==i){
                        suf[i][j][pos]=(suf[i][j][pos]+s1[j][pos+1]);
                    }
                }
            }
        }
    }

    int countPalindromes(string s) {
        memset(pre,0,sizeof(pre));
        memset(pre,0,sizeof(suf));
        memset(p1,0,sizeof(p1));
        memset(s1,0,sizeof(s1));
        ll n=s.size(),ans=0;
        ct(s);
        for(int i=2;i+2<n;i++){
            for(int j=0;j<=9;j++){
                for(int k=0;k<=9;k++){
                    // x : how many (j+'0',k+'0') exist in s[0]~s[i-1]
                    // y : how many (k+'0',j+'0') exist in s[i+1]~s[n-1]
                    // ans=(ans+i*j)%mod;
                    ans=(ans+pre[j][k][i-1]*suf[k][j][i+1])%mod;
                }
            }
        }
        return ans;
    }
};