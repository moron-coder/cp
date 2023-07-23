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
    int minimumIndex(vector<int>& ar) {
        int fq=0,n=ar.size(),maxEl=-1,maxFq=0;
        unordered_map<int,int> mp;
        for(auto it:ar) mp[it]++;
        for(auto it:mp){
            if(it.second>maxFq){
                maxFq=it.second;
                maxEl=it.first;
            }
        }
        int *pre=new int[n](),*suf=new int[n]();
        for(int i=0;i<n;i++){
            fq+=(ar[i]==maxEl);
            pre[i]=fq;
        }
        fq=0;
        for(int i=n-1;i>=0;i--){
            fq+=(ar[i]==maxEl);
            suf[i]=fq;
        }
        for(int i=0;i<n-1;i++){
            if((pre[i]<<1)>i+1 && (suf[i+1]<<1)>n-i-1){
                return i;
            }
        }
        return -1;
    }
};