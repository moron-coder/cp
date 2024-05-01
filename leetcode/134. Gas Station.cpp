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
    int canCompleteCircuit(vector<int>& ar, vector<int>& cost) {
        int n=ar.size();
        if(n<=1) return ar[0]>=cost[0]?0:-1;
        vector<int> del(n,0);
        for(int i=0;i<n;i++){
            del[i] = ar[i]-cost[i];
        }

        int ptr=-1, sum=0;

        for(int it=0;it<2*n;it++){
            int idx = it%n;
            sum+=del[idx];
            if(sum>0){
                if(ptr==-1){
                    ptr=idx;
                }
            }else if(sum<0){
                ptr=-1;
                sum=0;
            }
            if(sum>=0 && (it+1+n)%n==ptr){
                return ptr;
            }
        }
        return -1;
    }
};