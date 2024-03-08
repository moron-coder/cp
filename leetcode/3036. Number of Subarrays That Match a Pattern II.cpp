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
    int countMatchingSubarrays(vector<int>& ar, vector<int>& pat) {
        int n=ar.size(),m=pat.size(),ans=0;
        //  make lps array of pat
        vector<int> lps(m,0);
        int i=0,j=1;
        while(j<m){
            if(pat[j]==pat[i]){
                i++;
                lps[j]=i;
                j++;
            }else if(i){
                i=lps[i-1];
            }else{
                j++;
            }
        }
        vector<int> dels;
        for(int itr=0;itr+1<n;itr++){
            dels.push_back(max(min(ar[itr+1]-ar[itr],1),-1));
        }
        i=0,j=0;

        while (i<dels.size()){
            if(dels[i]==pat[j]){
                i++,j++;
            }
            if(j==pat.size()){
                ans++,j=lps[j-1];
            }else if(i<dels.size() && dels[i]!=pat[j]){
                if(j) j=lps[j-1];
                else i++;
            }
        }
        return ans;
    }
};