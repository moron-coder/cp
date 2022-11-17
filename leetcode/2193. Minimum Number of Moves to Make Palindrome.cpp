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
    int minMovesToMakePalindrome(string s) {
        int n=s.size(),lf=0,ans=0,central_char=-1;
        // I'll move right to left, for each position pos, I'll find its corresponding character in its mirror img
        // check for odd size s has to be applied
        for(int i=n-1;i>(n/2);i--){
            int leftPos=0;
            for(int it=lf;it<=i;it++){
                if(s[it]==s[i]){
                    leftPos=it;
                    break;
                }
            }
            if(i==leftPos){
                // skip this character
                central_char=i;
                continue;
            }
            ans+=leftPos-lf;
            for(int it=leftPos;it>lf;it--){
                swap(s[it-1],s[it]);
            }
            lf++;
        }
        return (central_char==-1)?ans:ans+(central_char-(n/2));
    }
};
