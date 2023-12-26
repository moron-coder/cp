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
    string decreasedStr(string &s){
        //  returns the string after decreasing
        int n=s.size();
        string ans;
        if(s[(n-1)/2]=='0'){
            int i=(n-1)/2;
            while (i>=0 && s[i]=='0'){
                i--;
            }
            if(i<0){
                cout<<"invalid string : "<<s<<endl;
                return s;
            }
            s[i]--;
            for(int j=i+1;j<=(n-1)/2;j++){
                s[j]='9';
            }
        }else{
            s[(n-1)/2]--;
        }
        for(auto it:s){
            if(it!='0' || ans.size()){
                ans.push_back(it);
            }
        }
        return ans;
    }


    string increasedStr(string &s){
        //  returns the string after increasing
        int n=s.size();
        string ans;
        if(s[(n-1)/2]=='9'){
            int i=(n-1)/2;
            while (i>=0 && s[i]=='9'){
                i--;
            }
            if(i<0){
                ans.push_back('1');
            }else{
                s[i]++;
            }
            for(int j=0;j<=i;j++){
                ans.push_back(s[j]);
            }
            for(int j=i+1;j<=(n-1)/2;j++){
                ans.push_back('0');
            }
            for(int j=(n+1)/2;j<n;j++){
                ans.push_back(s[j]);
            }
        }else{
            s[(n-1)/2]++;
            ans=s;
        }
        return ans;
    }

    pair<string,string> getNeighbouringPals(string &n){
        //  returns {just_greater, just_smaller}
    }

public:
    string nearestPalindromic(string n) {
        
    }
};