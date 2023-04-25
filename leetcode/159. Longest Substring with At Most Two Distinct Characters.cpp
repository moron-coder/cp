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
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n=s.size(),i=0,ans=min(2,(int)s.size());
        deque<pii> chars;       //  {ascii, fq}
        for(int j=0;j<n;j++){
            // debug
            // cout<<"chars:\n";
            // cout<<chars.size()<<" is size\n";
            // if(chars.size()) cout<<"    "<<(char)chars.front().first<<" with fq "<<chars.front().second<<endl;
            // if(chars.size()>1) cout<<"  "<<(char)chars.back().first<<" with fq "<<chars.back().second<<endl;
            // debug
            while(chars.size()==2 && (s[j]!=chars.front().first && s[j]!=chars.back().first)){
                if(s[i]==chars.front().first){
                    chars.front().second--;
                    if(chars.front().second==0) chars.pop_front();
                }else{
                    chars.back().second--;
                    if(chars.back().second==0) chars.pop_back();
                }
                i++;
            }
            if(chars.empty()) chars.push_back({s[j],1});
            else if(chars.back().first==s[j]){
                chars.back().second++;
            }else if(chars.front().first==s[j]){
                chars.front().second++;
            }else{
                chars.push_back({s[j],1});
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};