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
    long long countSubarrays(vector<int>& ar, int k) {
        long long n=ar.size(),i=0,maxEl=ar[0],fq=0,ans1=0;
        for(auto it:ar) maxEl=max(maxEl,(long long)it);
        for(int j=0;j<n;j++){
            if(ar[j]==maxEl) fq++;
            while(fq>=k){
                if(ar[i]==maxEl) fq--;
                i++;
            }
            ans1+=j-i+1;
        }
        long long tot = (1LL*n*(n+1))/2;
        return tot-ans1;
    }
};