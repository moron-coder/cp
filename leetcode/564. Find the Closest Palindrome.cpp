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
    string getMirror(int lf,string &s){
        string ans;
        for(int i=0;i<=lf;i++) ans.push_back(s[i]);
        for(int i=lf+1;i<s.size();i++) ans.push_back(s[s.size()-1-i]);
        return ans;
    }

    string getDecremented(int mid,string &s){
        string ans=s;
        int i=mid;
        while (i>=0 && ans[i]=='0'){
            ans[i]='9';
            i--;
        }
        if(i<0){
            return "-1";
        }
        ans[i]--;
        string tmp;
        for(auto it:ans) if(it!='0' || tmp.size()) tmp.push_back(it);
        return tmp;
    }

    string getIncremented(int mid,string &s){
        string ans=s;
        int i=mid;
        while (i>=0 && ans[i]=='9'){
            ans[i]='0';
            i--;
        }
        string tmp;
        if(i<0){
            tmp.push_back('1');
        }else{
            ans[i]++;
        }
        for(auto it:ans) if(it!='0' || tmp.size()) tmp.push_back(it);
        return tmp;
    }

    string nearestPalindromic(string s) {
        int n=s.size();
        int rt=(n+1)/2,lf=n-1-rt,mid=n/2;
    }
};

int main(){
    Solution s;
    
    vector<string> v={"103","101","2094","4094"};
    for(auto it:v){
        int n=it.size();
        int mid=(n-1)/2,lf=n-1-((n+1)/2);
        cout<<"mirror : "<<s.getMirror(lf,it)<<endl;
        cout<<"increment : "<<s.getIncremented(mid,it)<<endl;
        cout<<"decrement : "<<s.getDecremented(mid,it)<<endl;
    }
    return 0;
}