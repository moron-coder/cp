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
    int minimumKeypresses(string s) {
        int *fq=new int[26](),*charPos=new int[26]();
        for(auto it:s) fq[it-'a']++;
        int nptr=0,ans=0;
        vector<vector<int>> keys(9);
        priority_queue<pii> pq;       //  {high pq} {fq,char}
        for(int i=0;i<26;i++) if(fq[i]) pq.push({fq[i],i});
        while (pq.size()){
            pii tp=pq.top();
            pq.pop();
            charPos[tp.second]=keys[nptr].size()+1;
            keys[nptr].push_back(tp.second);
            nptr=(nptr+1)%9;
        }
        for(int i=0;i<26;i++) if(fq[i]) ans+=fq[i]*charPos[i];
        return ans;
    }
};