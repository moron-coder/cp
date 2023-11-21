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
    int minChanges(string s) {
        vector<int> lens;
        int preChar=-1,preCharLen=0;
        for(auto it:s){
            if(it-'0'==preChar){
                preCharLen++;
            }else{
                if(preCharLen){
                    lens.push_back(preCharLen);
                    preChar=it-'0';
                    preCharLen=1;
                }else{
                    preChar=it-'0';
                    preCharLen=1;
                }
            }
        }
        if(preCharLen) lens.push_back(preCharLen);
        for(auto it:lens) cout<<it<<" ";
        cout<<endl;
        int preOddIdx = -1,ans=0;
        for(int i=0;i<lens.size();i++){
            if(lens[i]&1){
                if(preOddIdx!=-1){
                    ans+=i-preOddIdx;
                    preOddIdx=-1;
                }else{
                    preOddIdx=i;
                }
            }
        }
        return ans;
    }
};