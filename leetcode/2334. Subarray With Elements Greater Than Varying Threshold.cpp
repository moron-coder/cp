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
    int validSubarraySize(vector<int>& ar, int threshold) {
        int n=ar.size();
        vector<int> leftSmall(n,-1),rightSmall(n,n);
        stack<int> stk;
        for(int i=0;i<n;i++){
            while (stk.size() && ar[stk.top()]>=ar[i]){
                rightSmall[stk.top()]=i;
                stk.pop();
            }
            if(stk.size()) leftSmall[i]=stk.top();
            stk.push(i);
        }
        //debug
        cout<<"leftSmall\n";
        for(auto it:leftSmall) cout<<it<<" ";
        cout<<endl;
        cout<<"rightSmall\n";
        for(auto it:rightSmall) cout<<it<<" ";
        cout<<endl;
        //debug
        for(int i=0;i<n;i++){
            int k=rightSmall[i]-leftSmall[i]-1;
            if(ar[i]*k>=threshold){
                cout<<"i= "<<i<<endl;
                return k;
            }
        }
        return -1;
    }
};