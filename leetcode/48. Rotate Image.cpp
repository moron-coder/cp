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
    void rotate(vector<vector<int>>& ar) {
        int n=ar.size();
        int I1=0,J1=0,I2=n-1,J2=n-1;
        while(I2>I1){
            int len = I2-I1+1;
            queue<int> q;
            for(int dis=0;dis<len-1;dis++){
                int k=dis+J1;
                q.push(ar[k][J2]);
                ar[k][J2]=ar[I1][k];
                q.push(ar[I2][J1+J2-k]);
                ar[I2][J1+J2-k]=q.front();
                q.pop();

                q.push(ar[I2+J1-k][J1]);
                ar[I2+J1-k][J1]=q.front();
                q.pop();

                ar[I1][k]=q.front();
                q.pop();
            }
            I1++,J1++;
            I2--,J2--;
        }
    }
};