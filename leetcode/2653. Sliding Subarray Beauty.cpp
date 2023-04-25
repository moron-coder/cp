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
    int getXMin(int *ar,int x){
        int sum=0;
        for(int i=0;i-50<0;i++){
            sum+=ar[i];
            if(sum>=x) return i-50;
        }
        return 0;
    }

    vector<int> getSubarrayBeauty(vector<int>& ar, int k, int x) {
        vector<int> ans;
        int *fq=new int[101]();
        for(int i=0;i<ar.size();i++){
            fq[ar[i]+50]++;
            if(i-k>=0) fq[ar[i-k]+50]--;
            if(i>=k-1) ans.push_back(getXMin(fq,x));
        }
        return ans;
    }
};