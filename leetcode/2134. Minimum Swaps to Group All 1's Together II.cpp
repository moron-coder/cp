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

// troy,gladiator

class Solution {
public:
    int minSwaps(vector<int>& ar) {
        int n=ar.size(),ct=0,ans=INT_MAX;
        vector<int> zPre(n,ar[0]==0),zSuf(n,ar.back()==0);
        for(int i=1;i<n;i++) zPre[i]=zPre[i-1]+(ar[i]==0);
        for(int i=n-2;i>=0;i--) zSuf[i]=zSuf[i+1]+(ar[i]==0);
        for(auto it:ar) if(it) ct++;
        if(ct==0) return 0;
         for(int i=0;i<n;i++){
            int stIdx=i,enIdx=(i+ct-1+n)%n;
            if(enIdx<stIdx){
                // count zeroesInSuf(stIdx) and zeroesInPre(enIdx)
                ans=min(ans,zPre[enIdx]+zSuf[stIdx]);
            }else{
                int zCt=zPre[enIdx];
                if(stIdx) zCt-=zPre[stIdx-1];
                ans=min(ans,zCt);
            }
        }
        return ans;
    }
};