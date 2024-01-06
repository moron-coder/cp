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
    int missingInteger(vector<int>& ar) {
        int n=ar.size(),sum=ar[0];
        bool sq=true;
        for(int i=1;sq && i<n;i++){
            if(ar[i]!=ar[i-1]+1){
                sq=false;
            }else{
                sum+=ar[i];
            }
        }
        cout<<"sum = "<<sum<<endl;
        sort(ar.begin(),ar.end());
        int pos = lower_bound(ar.begin(),ar.end(),sum)-ar.begin();
        for(auto it:ar){
            if(it>sum){
                return sum;
            }else if(it==sum){
                sum++;
            }
        }
        return sum;
    }
};