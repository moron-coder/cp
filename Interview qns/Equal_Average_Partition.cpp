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

class Solution{
    public:
    vector<vector<int>> avgset(vector<int> &ar);
};


vector<int> ansIdx;

//  s1/n1 = (s-s1)/(n-n1)
//  s1*(n-n1) = n1*(s-s1)
//  s1*n = s*n1

bool help(vector<int> &ar,int s,int n,int pos,int s1,int n1){
    // cout<<s1<<" "<<n1<<" "<<pos<<endl;
    if(pos>=n) return false;
    if(n1>0 && 1LL*s1*n==1LL*s*n1){
        return true;
    }
    // cout<<"reg 1\n";

    if(help(ar,s,n,pos+1,s1,n1)){
        return true;
    }

    ansIdx.push_back(pos);
    if(help(ar,s,n,pos+1,s1+ar[pos],n1+1)){
        return true;
    }
    ansIdx.pop_back();
    // cout<<"reg 2\n";
    // cout<<"reg 3\n";
    return false;
}

vector<vector<int> > Solution::avgset(vector<int> &ar) {
    sort(ar.begin(),ar.end());
    while (ansIdx.size()) ansIdx.pop_back();
    int sum=0,n=ar.size();
    for(auto it:ar) sum+=it;
    if(help(ar,sum,n,0,0,0)){
        // cout<<"possible!!!\n";
        // for(auto it:ansIdx) cout<<it<<" ";
        // cout<<endl;
        vector<int> lf,rt;
        vector<vector<int>> ans;
        int ptr=0;
        for(int i=0;i<n;i++){
            if(ptr<ansIdx.size() && ansIdx[ptr]==i){
                // cout<<"push "<<ar[i]<<" on left\n";
                lf.push_back(ar[i]);
                ptr++;
            }else{
                // cout<<"push "<<ar[i]<<" on right\n";
                rt.push_back(ar[i]);
            }
        }
        sort(lf.begin(),lf.end());
        sort(rt.begin(),rt.end());
        if(lf.size()<=rt.size()){
            ans.push_back(lf);
            ans.push_back(rt);
        }else{
            ans.push_back(rt);
            ans.push_back(lf);
        }
        // for(auto it:ans){
        //     for(auto it1:it) cout<<it1<<" ";
        //     cout<<endl;
        // }
        return ans;
    }
    return {};
}

int main(){
    vector<int> ar = { 1, 7, 15, 29, 11, 9};
    Solution s;
    vector<vector<int>> ans = s.avgset(ar);

    for(auto it:ans){
        for(auto it1:it) cout<<it1<<" ";
        cout<<endl;
    }

    return 0;
}