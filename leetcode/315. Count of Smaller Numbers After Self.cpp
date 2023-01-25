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
    vector<int> ans;
    void ms(vector<pii> &ar,int st,int en){
        if(st>=en) return;
        int sz=en-st+1,tPtr=0,mid=st+(en-st)/2,p1=st,p2=mid+1;
        // cout<<st<<","<<en<<" calls "<<st<<","<<mid<<" and "<<mid+1<<","<<en<<endl;
        ms(ar,st,mid);
        ms(ar,mid+1,en);
        pii *tmpAr=new pii[sz];
        while (p1<=mid && p2<=en){
            if(ar[p1].first<ar[p2].first){
                tmpAr[tPtr]=ar[p2];
                p2++;
                tPtr++;
            }else{
                // cout<<ar[p1].second<<" se chote "<<p2-mid<<" dikhe\n";
                // cout<<"pos: "<<ar[p1].second<<endl;
                ans[ar[p1].second]+=en-p2+1;
                tmpAr[tPtr]=ar[p1];
                p1++;
                tPtr++;
            }
        }
        while (p1<=mid){
            tmpAr[tPtr]=ar[p1];
            p1++;
            tPtr++;
        }
        while (p2<=en){
            tmpAr[tPtr]=ar[p2];
            p2++;
            tPtr++;
        }
        for(int i=0;i<sz;i++) ar[st+i]=tmpAr[i];
    }

    vector<int> countSmaller(vector<int>& ar) {
        int n=ar.size();
        ans.resize(n,0);
        vector<pii> ar1;
        for(int i=0;i<n;i++) ar1.push_back({ar[i],i});
        ms(ar1,0,n-1);
        for(auto it:ar1) cout<<it.first<<" ";
        cout<<endl;
        return ans;
    }
};