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
    string ans;

    bool bigContainsSmall(string &big,string &small){
        if(big.size()<small.size()) return bigContainsSmall(small,big);
        int bs=big.size(),ss=small.size();
        for(int i=0;i+ss-1<bs;i++){
            if(small==big.substr(i,ss)) return true;
        }
        return false;
    }

    string mergeOptim(string &a,string &b){
        if(bigContainsSmall(a,b)){
            return (a.size()>=b.size())?a:b;
        }
        int n=a.size(),m=b.size(),minLen = min(n,m);
        // a+b case
        string ab=a+b,ba=b+a;
        for(int mergeLen=minLen;mergeLen>0;mergeLen--){
            if(a.substr(n-mergeLen)==b.substr(0,mergeLen)){
                ab=a+b.substr(mergeLen);
                break;
            }
        }
        // b+a case

        for(int mergeLen=minLen;mergeLen>0;mergeLen--){
            if(b.substr(m-mergeLen)==a.substr(0,mergeLen)){
                ba=b+a.substr(mergeLen);
                break;
            }
        }
        return (ab.size()<ba.size() || (ab.size()==ba.size() && ab<ba))?ab:ba;
    }

    void mergeInOrder(string &a,string &b,string &c){
        string s1 = mergeOptim(a,b);
        string s2 = mergeOptim(s1,c);
        if(ans.size()==0 || ans.size()>s2.size() || (ans.size()==s2.size() && ans>s2)) ans=s2;

        string s3=mergeOptim(b,c);
        string s4=mergeOptim(a,s3);
        if(ans.size()==0 || ans.size()>s4.size() || (ans.size()==s4.size() && ans>s4)) ans=s4;
    }

    string minimumString(string a, string b, string c) {
        ans="";
        mergeInOrder(a,b,c);
        mergeInOrder(a,c,b);
        mergeInOrder(b,c,a);
        mergeInOrder(b,a,c);
        mergeInOrder(c,a,b);
        mergeInOrder(c,b,a);
        return ans;
    }
};