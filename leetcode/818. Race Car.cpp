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
    pbi isOkAndCtBit(int n){
        bool ok=true;
        int ct=0;
        while (n){
            if(!(n&1)) ok=false;
            ct++;
            n/=2;
        }
        return {ok,ct};
    }

    int racecar(int n) {
        int *dp=new int[n+1]();
        for(int i=1;i<=n;i++){
            cout<<"i= "<<i<<endl;
            dp[i]=INT_MAX;
            pbi small = isOkAndCtBit(i);
            if(small.first) dp[i]=small.second;
            else{
                int lo=(1<<(small.second-1))-1,hi=(1<<small.second)-1;
                cout<<lo<<","<<hi<<endl;
                for(int tmp=0;lo-((1<<tmp)-1)>=0;tmp++){
                    cout<<"tmp = "<<tmp<<endl;
                    cout<<i-(lo-((1<<tmp)-1))<<" is the one\n";
                    cout<<small.second-1<<" : "<<tmp<<" : "<<dp[i-(lo-((1<<tmp)-1))]<<"\n";
                    dp[i]=max({dp[i],small.second+1+dp[hi-i],small.second-1+1+tmp+1+dp[i-(lo-((1<<tmp)-1))]});
                }
            }
            cout<<"dp["<<i<<"] = "<<dp[i]<<endl;
        }
        return dp[n];
    }
};