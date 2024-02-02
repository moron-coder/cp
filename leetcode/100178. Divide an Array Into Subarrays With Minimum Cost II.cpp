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
    long long ans,sum;

    void insertElement(set<pii> &s1,set<pii> &s2,int x,int pos){
        pii bg = *s2.rbegin();
        if(bg.first>x){
            pii tmp = *s2.rbegin();
            auto it = s2.find(tmp);
            sum-=it->first;
            s2.erase(it);
            sum+=x;
            s2.insert({x,pos});
            s1.insert(tmp);
        }else{
            s1.insert({x,pos});
        }
    }

public:
    long long minimumCost(vector<int>& ar, int k, int dist) {
            ios_base::sync_with_stdio(false);
        ans=-1,sum=0;
        set<pii> s1,s2;    //  s1 of length (dist-k)
                                //  s2 of length k
        long long n=ar.size(), curSum=0,ans=-1;
        for(int i=1;i<n;i++){
            if(i-dist-1>0){
                insertElement(s1,s2,ar[i],i);
                //  remove ar[i-dist-1]
                if(s1.count({ar[i-dist-1],i-dist-1})){
                    auto it = s1.find({ar[i-dist-1],i-dist-1});
                    s1.erase(it);
                }else if(s2.count({ar[i-dist-1],i-dist-1})){
                    //  pick an element from s1, insert into s2
                    auto it = s2.find({ar[i-dist-1],i-dist-1});
                    sum-=it->first;
                    s2.erase(it);
                    auto tmp = s1.begin();
                    sum+=tmp->first;
                    s2.insert(*tmp);
                    s1.erase(tmp);
                }
            }else{
                if(s2.size()<k-1){
                    sum+=ar[i];
                    s2.insert({ar[i],i});
                }else{
                    insertElement(s1,s2,ar[i],i);
                }
            }
            if(s2.size()==k-1){
                ans = (ans==-1)?sum+ar[0]:min(ans,sum+ar[0]);
            }
        }  
        return ans;
    }
};