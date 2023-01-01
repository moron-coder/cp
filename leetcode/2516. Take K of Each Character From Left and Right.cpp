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
    int getJ(string &s,int i,int k,vector<vector<int>> &pre,vector<vector<int>> &suf){
        int n=s.size(),lo=i+1,hi=n-1,pa=(i!=-1)?pre[0][i]:0,pb=(i!=-1)?pre[1][i]:0,pc=(i!=-1)?pre[2][i]:0,ans=-1;
        if(pa>=k && pb>=k && pc>=k) return n;
        while (lo<=hi){
            bool ok=false;
            int mid=lo+(hi-lo)/2;
            int sa=suf[0][mid],sb=suf[1][mid],sc=suf[2][mid];
            if(sa+pa>=k && sb+pb>=k && sc+pc>=k){
                ans=mid;
                lo=mid+1;
            }else hi=mid-1;
        }
        return ans;
    }

    int takeCharacters(string s, int k) {
        if(!k) return 0;
        //  for every 'i', we'll do a binary search
        int n=s.size(),ans=INT_MAX;
        vector<vector<int>> pre(3,vector<int>(n,0)),suf(3,vector<int>(n,0));
        pre[s[0]-'a'][0]=1;
        for(int j=1;j<n;j++){
            for(int i=0;i<3;i++) pre[i][j]=pre[i][j-1];
            pre[s[j]-'a'][j]++;
        }
        suf[s[n-1]-'a'][n-1]++;
        for(int j=n-2;j>=0;j--){
            for(int i=0;i<3;i++) suf[i][j]=suf[i][j+1];
            suf[s[j]-'a'][j]++;
        }
        int tmpJ=getJ(s,-1,k,pre,suf);
        if(tmpJ!=-1) ans=n-tmpJ;
        for(int i=0;i<n;i++){
            int j=getJ(s,i,k,pre,suf);
            if(j==-1) continue;
            int curT = i+1+n-j;
            ans=min(ans,curT);
        }
        return ans==INT_MAX?-1:ans;
    }
};