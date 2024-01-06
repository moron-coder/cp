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
    int getDig(int n){
        if(n<=1) return 0;
        int ans=0;
        while (n){
            ans++;
            n/=10;
        }
        return ans;
    }

    int compress(vector<char>& ar) {
        int ans=0;
        vector<string> v;
        for(int i=0;i<ar.size();){
            int fq=0;
            for(int j=i;j<ar.size() && ar[j]==ar[i];j++){
                fq++;
            }
            string tmpS;
            tmpS.push_back(ar[i]);
            v.push_back(tmpS);
            if(fq>1){
                v.push_back(to_string(fq));
            }
            ans += 1+getDig(fq);
            i+=fq;
        }
        vector<char> tmpAns;
        for(auto it:v){
            for(auto it1:it){
                tmpAns.push_back(it1);
            }
        }
        ar=tmpAns;
        return ans;
    }
};