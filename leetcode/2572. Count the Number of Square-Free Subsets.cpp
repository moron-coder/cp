#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int

class Solution {
public:
    const static int MAX_PRIME=30;

    bool *isComposite;
    vector<int> primesAllowed;
    int dp[1001][2049];

    int help(vector<int> &ar,int pos,int usedPrimes){
        int n=ar.size();
        if(pos>=n) return 1;
        if(dp[pos][usedPrimes]!=-1) return dp[pos][usedPrimes];
        int ans=help(ar,pos+1,usedPrimes),curPrimes=0;
        bool canTake=true;
        for(int i=0;i<primesAllowed.size() && canTake;i++){
            if(ar[pos]%primesAllowed[i]) continue;
            if((1<<i)&usedPrimes) canTake=false;                //  this prime is already taken
            if(((ar[pos]/primesAllowed[i])%primesAllowed[i])==0) canTake=false; //  ar[pos] is square of prime
            curPrimes^=(1<<i);
        }
        if(canTake || ar[pos]==1){
            ans=(ans+help(ar,pos+1,usedPrimes^curPrimes))%mod;
        }
        return dp[pos][usedPrimes]=ans;
    }

    int squareFreeSubsets(vector<int>& ar){
        primesAllowed.clear();
        isComposite=new bool[MAX_PRIME+1]();
        isComposite[1]=true;    //  Ik its false
        for(int i=2;i<=30;i++){
            if(isComposite[i]) continue;
            for(int j=2;j*i<=MAX_PRIME;j++){
                isComposite[i*j]=true;
            }
        }
        for(int i=2;i<=MAX_PRIME;i++) if(!isComposite[i]) primesAllowed.push_back(i);
        memset(dp,-1,sizeof(dp));
        return (help(ar,0,0)-1+mod)%mod;
    }
};