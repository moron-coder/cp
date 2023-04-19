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

    int inf=1e8;

public:

    int addMinimum(string ar) {
        int ans=0;
        if(ar[0]!='a'){
            ans++;
            ar.insert(ar.begin(),'a');
        }
        if(ar.back()!='c'){
            ans++;
            ar.push_back('c');
        }
        int n=ar.size();
        int **dp=new int*[n];
        for(int i=0;i<n;i++) dp[i]=new int[n]();
        for(int len=1;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                dp[i][j]=inf;
                for(int k=i;k<=j;k++){
                    int curChar=ar[k]-'a',pChar=0,sChar=2,lf=0,rt=0;
                    if(k>i){
                        pChar=ar[k-1]-'a';
                        lf=dp[i][k-1]+(curChar-pChar+2)%3;
                    }
                    if(k<j){
                        sChar=ar[k+1]-'a';
                        rt=dp[k+1][j]+(sChar-curChar+2)%3;
                    }
                    dp[i][j]=min(dp[i][j],lf+rt);
                }
            }
        }
        return ans+dp[0][n-1];
    }
};