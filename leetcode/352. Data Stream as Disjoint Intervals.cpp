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

class SummaryRanges {
public:
    const static int MAX_VAL=10000;
    int *ar;

    SummaryRanges() {
        ar=new int[MAX_VAL+2]();
    }
    
    void addNum(int value) {
        ar[value]=1;
    }
    
    vector<vector<int>> getIntervals() {
        int prev=-1;
        vector<vector<int>> ans;
        for(int i=0;i<=MAX_VAL+1;i++){
            if(ar[i]==0){
                if(prev!=-1){
                    ans.push_back({prev,i-1});
                }
                prev=-1;
            }else if(prev==-1) prev=i;
        }
        return ans;
    }
};
