#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution {
public:
    vector<long long> distance(vector<int>& ar) {
        unordered_map<long long,vector<long long>> mp;      //  {pre[i] => prefix sum of indexes}
        long long n=ar.size();
        for(long long i=0;i<n;i++){
            if(mp.count(ar[i])){
                long long prev = mp[ar[i]].back();
                mp[ar[i]].push_back(prev+i);
            }else{
                mp[ar[i]].push_back(i); 
            }
        }
        vector<long long> ans(n,0);
        for(auto it:mp){
            if(it.second.size()>1){
                ll totSum=it.second.back(),pSum=0;
                for(int i=0;i<it.second.size();i++){
                    ll xi=it.second[i];
                    pSum=xi;
                    ll sSum=totSum-pSum;
                    if(i) xi-=it.second[i-1];
                    ll curAns=sSum-pSum+((i<<1)+2-it.second.size())*(xi);
                    if(i==it.second.size()-1) curAns-=sSum;
                    // cout<<"for index: "<<xi<<" pSum: "<<pSum<<" sSum: "<<sSum<<" i: "<<i<<endl;
                    ans[xi]=curAns;
                    // cout<<"index : "<<xi<<" ans: "<<ans[xi]<<endl;
                }
            }
        }
        return ans;
    }
};