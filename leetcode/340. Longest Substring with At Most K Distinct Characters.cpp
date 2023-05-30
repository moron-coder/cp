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
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int disCt=0,i=0,ans=0;
        int *fq = new int[256]();
        for(int j=0;j<s.size();j++){
            if(fq[s[j]]==0){
                disCt++;
            }
            fq[s[j]]++;
            while (disCt>k){
                fq[s[i]]--;
                if(fq[s[i]]==0) {
                    disCt--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};