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

int ct(int x){
    int ans=0;
    while (x){
        ans+=(x&1);
        x=(x>>1);
    }
    return ans;
}

int solution(vector<string> &v,int k){
    int n=v.size();
    vector<int> ar(n,0);
    for(int i=0;i<n;i++){
        string s = v[i];
        for(auto it:s){
            int num = it-'a';
            ar[i]|=(1<<num);
        }
    }
    int ret=0;
    for(int i=0;i<(1<<10);i++){
        if(ct(i)<=k){
            int curRet=0;
            for(auto it:ar){
                if((it|i)<=i){
                    curRet++;
                }
            }
            ret=max(ret,curRet);
        }
    }
    return ret;
}

int main(){
    vector<string> ar = {"abc","abb","cb","a","bbb"};
    int k=2;
    cout<<solution(ar,k)<<endl;

    return 0;
}