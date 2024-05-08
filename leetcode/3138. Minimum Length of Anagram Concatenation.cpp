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
    bool checkMultiples(int *fq,int *cur){
        int fac=-1;
        for(int i=0;i<26;i++){
            if(cur[i] && (fac==-1 || fac==fq[i]/cur[i])){
                fac=fq[i]/cur[i];
            }else if(fq[i]!=0 && cur[i]==0){
                return false;
            }else if(cur[i]!=0){
                return false;
            }
        }
        return true;
    }

    bool isOk(int *fq,int segLen, string &s){
        int *cur = new int[26]();
        for(int i=0;i<s.size();i++){
            cur[s[i]-'a']++;
            if(((i+1)%segLen)==0){
                if(!checkMultiples(fq,cur)){
                    return false;
                }
            }
        }
        return true;
    }

public:
    int minAnagramLength(string s) {
        int n=s.size();
        int *fq = new int[26]();
        for(auto it:s){
            fq[it-'a']++;
        }
        queue<int> q;
        for(int i=0;i<26;i++){
            if(fq[i]) q.push(fq[i]);
        }
        int tmp=q.front();
        while (q.size()){
            tmp = __gcd(tmp,q.front());
            q.pop();
        }
        int minSegLen=n/tmp;
        vector<int> lengths;
        for(int i=1;i*minSegLen<=n;i++){
            lengths.push_back(i*minSegLen);
        }
        for (auto it:lengths){
            int curSegLen=it;
            cout<<"check for curSegLen = "<<curSegLen<<endl;
            if(isOk(fq,curSegLen,s)){
                return curSegLen;
            }
        }
        return n;
    }
};