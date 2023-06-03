#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution {
public:
    long long maxStrength(vector<int>& ar){
        int n=ar.size();
        bool pos=false;
        sort(ar.begin(),ar.end());
        if(ar.back()>0) pos=true;
        ll ans=1;
        while (ar.size() && ar.back()>0){
            ans*=ar.back();
            ar.pop_back();
        }
        while (ar.size() && ar.back()==0) ar.pop_back();
        int negSz = ar.size();
        if(negSz<2 && !pos){
            if(negSz<n) return 0;
            return ar[0];
        }
        for(int i=1;i<ar.size() && ar[i]<0;i+=2){
            ans*=(ar[i-1]*ar[i]);
        }
        return ans;
    }
};