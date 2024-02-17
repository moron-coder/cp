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
    int minOrAfterOperations(vector<int>& ar, int k) {
        int n=ar.size(),ans=0,offBits=0;
        for(int j=30;j>=0;j--){
            int ctr=0;
            
            for(int i=0;i<n;i++){
                int pos=i,curAnds=offBits|(1<<j);
                while(pos<n && curAnds&ar[pos]){
                    //  check how many continuous numbers can be handled
                    curAnds&=ar[pos++];
                }
                ctr+=pos-i;
                i=pos;
            }

            if(ctr>k) ans|=(1<<j);
            else offBits|=(1<<j);
        }
        return ans;
    }
};