#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& ar) {
        long long n = ar.size(),i=0,ans=0;
        set<int> st;
        unordered_map<int,queue<int>> numToIdx;
        for(int i=0;i<ar.size();i++) numToIdx[ar[i]].push(i);
        for(int j=0;j<n;){
            st.insert(ar[j]);
            int bigEl = *st.rbegin(), smallEl = *st.begin();
            if(bigEl-smallEl>2){
                numToIdx[ar[i]].pop();
                if(numToIdx[ar[i]].empty() || numToIdx[ar[i]].front()>j) st.erase(ar[i]);
                i++;
            }else{
                ans = (ans+j-i+1);
                j++;
            }
        }
        return ans;
    }
};