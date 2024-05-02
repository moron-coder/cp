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
    int minimumAddedInteger(vector<int>& ar1, vector<int>& ar2) {
        sort(ar1.begin(),ar1.end());
        sort(ar2.begin(),ar2.end());

        int n=ar1.size(), ans = INT_MAX;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int pt1=0,pt2=0, dif=INT_MAX;
                bool ok=true;

                while (pt2<ar2.size() && ok){
                    while(pt1==i || pt1==j) pt1++;
                    if(pt1>=ar1.size()){
                        cout<<"Malformed input\n";
                    }
                    if(dif==INT_MAX){
                        dif = ar2[pt2]-ar1[pt1];
                    }else if(dif!=ar2[pt2]-ar1[pt1]){
                        ok=false;
                    }
                    pt2++,pt1++;
                }

                if(ok){
                    ans = min(ans, dif);
                }
            }
        }
        return ans;
    }
};