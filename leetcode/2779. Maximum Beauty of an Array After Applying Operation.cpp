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
    int maximumBeauty(vector<int>& ar, int k) {
        int *fq=new int[200002]();
        int maxFrequencyCount=0,sum=0;
        for(auto it:ar){
            fq[max(0,it-k)]++;
            fq[it+k+1]--;
        }
        for(int i=0;i<=200000;i++){
            sum+=fq[i];
            if(sum>maxFrequencyCount){
                maxFrequencyCount=sum;
            }
        }
        return maxFrequencyCount;
    }
};