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
    int minOperations(vector<int>& ar1, vector<int>& ar2) {
        int max1 = ar1.back(),max2 = ar2.back(), globalMax = ar1[0];
        for(auto it:ar1) globalMax=max(globalMax,it);
        for(auto it:ar2) globalMax=max(globalMax,it);
        if(globalMax>max(max1,max2)) return -1;
        int smallMax = min(max1,max2), biggerMax = max(max1,max2);
        //  assuming smallMax is in 1st
        int ans1=0;
        for(int i=0;i<ar1.size()-1;i++){
            if(ar1[i]>smallMax){
                if(ar2[i]>smallMax){
                    return -1;
                }else{
                    ans1++;
                }
            }
        }
        //  assuming smallMax is in 2nd
        int ans2=0;
        for(int i=0;i<ar2.size()-1;i++){
            if(ar2[i]>smallMax){
                if(ar1[i]>smallMax){
                    return -1;
                }else{
                    ans2++;
                }
            }
        }
        int pos1 = ans1+(max1!=smallMax), pos2 = ans2+(max2!=smallMax);
        return min(pos1,pos2);
    }
};