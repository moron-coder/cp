#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pii pair<int,int>
class Solution {
    int fact[100001],invMod[100001];

    int modPow(int x,int p){
        if(!p) return 1;
        int ans=(p&1)?x:1,sm = modPow(x,p/2);
        return (1LL*ans*sm)%mod*sm%mod;
    }

    int calcInvMod(int x,int md){
        return modPow(x,md-2)%md;
    }

    int ncr(int n,int r){
        return ((1LL*fact[n]%mod*invMod[fact[r]%mod]%mod)%mod*invMod[fact[n-r]%mod]%mod)%mod;
    }

public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        fact[0]=1;
        for(int i=1;i<=100000;i++) fact[i]=(1LL*i*fact[i-1]%mod)%mod;
        invMod[0]=1;
        for(int i=1;i<=100000;i++) invMod[i]=calcInvMod(i,mod);

        sort(s.begin(),s.end());
        unordered_map<int,int> totalFqMap,takenFqMap;
        int *fq = new int[26]();
        for(auto it:s) fq[it-'a']++;
        vector<pii> v;
        for(int i=0;i<26;i++) if(fq[i]){
            v.push_back({fq[i],i});     //  fq, char
            totalFqMap[fq[i]]++;
        }
        if(k>v.size()) return 0;
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());     //  hi->lo
        vector<int> frequenciesTaken;
        for(int i=0;i<k;i++){
            frequenciesTaken.push_back(v[i].first);
            takenFqMap[v[i].first]++;
        }
        int ans=1;
        for(auto it:takenFqMap){
            int m1 = ncr(totalFqMap[it.first],takenFqMap[it.first])%mod;
            ans = (ans*m1*modPow(it.first%mod,takenFqMap[it.first]%mod)%mod)%mod;
        }
        return ans;
    }
};