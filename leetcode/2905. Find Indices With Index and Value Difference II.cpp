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
    vector<int> findIndices(vector<int>& ar, int indexDifference, int valueDifference) {
        int n=ar.size();
        vector<int> preMin(n,0),sufMin(n,n-1),preMax(n,0),sufMax(n,n-1);
        for(int i=1;i<n;i++){
            // preMin[i]=min(preMin[i-1],ar[i]);
            if(ar[i]<ar[preMin[i-1]]){
                preMin[i]=i;
            }else{
                preMin[i]=preMin[i-1];
            }
            if(ar[i]>ar[preMax[i-1]]){
                preMax[i]=i;
            }else{
                preMax[i]=preMax[i-1];
            }

            if(ar[n-1-i]<ar[n-i]){
                sufMax[n-1-i]=n-1-i;
            }else{
                sufMax[n-1-i]=sufMax[n-i];
            }
        }
        for(int i=0;i<n;i++){
            int preIdx = i-indexDifference, sufIdx = i+indexDifference;

            if(preIdx>=0 && abs(ar[i]-ar[preMin[preIdx]])>=valueDifference){
                return {preMin[preIdx],i};
            }
            if(preIdx>=0 && abs(ar[i]-ar[preMax[preIdx]])>=valueDifference){
                return {preMax[preIdx],i};
            }
            if(sufIdx<n && (abs(ar[i]-ar[sufMin[sufIdx]])>=valueDifference)){
                return {i,sufMin[sufIdx]};
            }
            if(sufIdx<n && (abs(ar[i]-ar[sufMax[sufIdx]])>=valueDifference)){
                return {i,sufMax[sufIdx]};
            }
        }
        return {-1,-1};
    }
};