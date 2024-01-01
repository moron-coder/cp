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
    long long incremovableSubarrayCount(vector<int>& ar) {
        long long n=ar.size();
        long long p1=0,p2=n-1;
        for(long long i=1;i<n;i++){
            if(ar[i]>ar[p1]){
                p1=i;
            }else{
                break;
            }
        }
        for(long long i=n-2;i>=0;i--){
            if(ar[p2]>ar[i]){
                p2=i;
            }else{
                break;
            }
        }
        if(p2==0){
            return (n*(n+1))/2;
        }
        vector<long long> prefs,sufs;
        for(long long i=0;i<=p1;i++){
            prefs.push_back(ar[i]);
        }
        for(long long i=p2;i<n;i++){
            sufs.push_back(ar[i]);
        }
        long long sSize=sufs.size();
        long long ans=sSize;    //     only sufs taken
        for(long long i=0;i<prefs.size();i++){
            long long pos=upper_bound(sufs.begin(),sufs.end(),prefs[i])-sufs.begin();
            long long optionsCt = sSize-pos+1;
            ans+=(optionsCt);
        }
        return ans+1;
    }
};
