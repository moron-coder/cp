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
    bool lessThanDExistsHelper(vector<int> &ar,int d,int x){
        set<int> st;
        for(int i=x;i<ar.size();i++){
            st.insert(ar[i-x]);
            set<int>::iterator it = st.upper_bound(ar[i]);
            if(it!=st.begin()){
                --it;
                if(abs(ar[i]-(*it))<=d){
                    return true;
                }
            }
        }
        return false;
    }

    bool lessThanDExists(vector<int> &ar,int d,int x){
        bool ans = lessThanDExistsHelper(ar,d,x);
        if(!ans){
            reverse(ar.begin(),ar.end());
            ans = lessThanDExistsHelper(ar,d,x);
        }
        return ans;
    }

    int minAbsoluteDifference(vector<int>& ar, int x) {
        int lo=0,hi=abs(ar[x]-ar[0]),ans=hi;
        while (lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(lessThanDExists(ar,mid,x)){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
};