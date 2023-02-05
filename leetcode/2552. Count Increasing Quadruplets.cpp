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
    long long countQuadruplets(vector<int>& ar) {
        long long n=ar.size(),ans=0;
        long long *jCounts=new long long[n]();
        for(long long j=0;j<n;j++){
            long long preMinCt=0;
            for(long long i=0;i<j;i++){
                if(ar[i]<ar[j]){
                    preMinCt++;             //  will be used when 'j' will act as (2)
                    ans+=jCounts[i];        //  will be used when 'j' will act as (4)
                }else if(ar[i]>ar[j]){
                    jCounts[i]+=preMinCt;   //  will be used when 'j' will act as (2) and 'i' as (3) and preMinCt as (1)
                }
            }
        }
        return ans;
    }
};