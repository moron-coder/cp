#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution {
public:
    long long minimumTime(vector<int>& ar, int k) {
        ll hi=100000000000000,lo=0,ans=hi;
        while (lo<=hi){
            ll mid=lo+(hi-lo)/2,cur=0;
            for(auto it:ar) cur+=mid/it;
            if(cur>=k) ans=mid,hi=mid-1;
            else lo=mid+1;
        }
        return ans;
    }
};