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
    long long minimumPossibleSum(int n, int target) {
        set<long long> cantTake;
        long long fq=0,sum=0;
        for(int i=1;fq<n;i++){
            if(cantTake.count(i)){
                
            }else{
                fq++,sum+=i;
                if(target-i>=0 && target-i<=100000) cantTake.insert(target-i);
            }
        }
        return sum;
    }
};