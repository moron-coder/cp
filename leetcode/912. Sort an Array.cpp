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

/**
* @author : Utkarsh Kumar
* @date : 2024-07-08
*/

class Solution {
    long long int OFFSET_VAL = 500001;

    void ins(long long int &orig, long long int &toIns, long long int &md){
        orig = orig + (toIns%md)*md;
    }
    
    void ms(vector<long long int> &ar, int st, int en,long long int &md){
        if(st>=en){
            return;
        }
        int mid = st+(en-st)/2;
        ms(ar,st,mid,md);
        ms(ar,mid+1,en,md);
        int i=st,j=mid+1,ptr=i;;
        while (i<=mid && j<=en){
            if((ar[i])%md>(ar[j])%md){
                ins(ar[ptr],ar[j],md);
                j++;
            }else{
                ins(ar[ptr],ar[i],md);
                i++;
            }
            ptr++;
        }
        while (i<=mid){
            ins(ar[ptr],ar[i],md);
            i++;
            ptr++;
        }
        while (j<=en){
            ins(ar[ptr],ar[j],md);
            j++;
            ptr++;
        }
        for(int it=st;it<=en;it++) ar[it]/=md;
    }

public:
    vector<int> sortArray(vector<int>& ar) {
        long long int n=ar.size(),md=ar[0]+OFFSET_VAL;
        vector<long long int> sortedAr;
        for(auto it:ar){
            sortedAr.push_back(it+OFFSET_VAL);
            md=max((long long int)md,it+OFFSET_VAL);
        }
        md++;
        ms(sortedAr,0,n-1,md);
        for(int i=0;i<n;i++){
            ar[i]=sortedAr[i]-OFFSET_VAL;
        }
        return ar;
    }
};