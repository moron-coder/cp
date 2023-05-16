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
    int getPos(vector<int> &lis,vector<int> &ar,int i){
        int ans=0,lo=0,hi=lis.size()-1;
        while (lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(ar[lis[mid]]>=ar[i]){
                ans=mid;
                hi=mid-1;
            }else lo=mid+1;
        }
        return ans;
    }

    int lengthOfLIS(vector<int>& ar) {
        vector<int> lis;
        for(int i=0,n=ar.size();i<ar.size();i++){
            if(lis.empty() || ar[lis.back()]<ar[i]){
                lis.push_back(i);
            }else{
                lis[getPos(lis,ar,i)]=i;
            }
        }
        return lis.size();
    }
};