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
    string minWindow(string s, string t) {
        int *fqT=new int[128](),*fqS=new int[128]();
        for(auto it:t) fqT[it]++;
        int ct=0,p1=0,n=s.size(),head=-1,len=-1;
        for(int p2=0;p2<n;p2++){
            fqS[s[p2]]++;
            if(fqS[s[p2]]<=fqT[s[p2]]) ct++;    //  it can still contribute
            while (ct==t.size()){
                if(len==-1 || len>p2-p1+1){
                    len=p2-p1+1;
                    head=p1;
                }
                fqS[s[p1]]--;
                if(fqT[s[p1]]>0 && fqS[s[p1]]<fqT[s[p1]]) ct--;
                p1++; 
            }
        }
        return (head==-1)?"":s.substr(head,len);
    }
};