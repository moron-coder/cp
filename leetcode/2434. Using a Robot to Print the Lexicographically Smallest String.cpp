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

// class Solution {
// public:
//     string robotWithString(string s) {
//         int n=s.size();
//         vector<int> sufMin(n,s.back()-'a');         //  sufMin[i]=> s[i]~s[n-1] has the minimum character = sufMin[i]
//         for(int i=n-2;i>=0;i--) sufMin[i]=min(s[i]-'a',sufMin[i+1]);
//         // to make smallest lexicographical string, I'll first save the smallest characters in my answer set
//         // but, while filling the smallest character I should also see if the t.back() is smaller than 
//         // the current suffix smaller character. If that is the case, I should push t.back() into the answer 
//         // after the last smallest character is filled, 
//         string t,ans;
//         cout<<"sufMin\n";
//         for(auto it:sufMin) cout<<it<<" ";
//         cout<<endl;
//         for(int i=0;i<n;i++){
//             while (t.size() && (t.back()-'a')<sufMin[i]){
//                 cout<<t.back()<<" inserted in ans\n";
//                 ans.push_back(t.back());
//                 t.pop_back();
//             }
//             if((s[i]-'a')==sufMin[i]){
//                 cout<<t.back()<<" inserted_ in ans\n";
//                 ans.push_back(s[i]);
//             }
//             else{
//                 cout<<s[i]<<" inserted in t\n";
//                 t.push_back(s[i]);
//             }
//         }
//         while (t.size()){
//             ans.push_back(t.back());
//             t.pop_back();
//         }
//         return ans;
//     }
// };

class Solution {
public:
    string robotWithString(string s) {
        int n=s.size();
        vector<int> sufMin(n,n-1);         
        for(int i=n-2;i>=0;i--){
            if(s[i]<s[sufMin[i+1]]) sufMin[i]=i;
            else sufMin[i]=sufMin[i+1];
        }
        // cout<<"sufMin\n";
        // for(auto it:sufMin) cout<<it<<" ";
        // cout<<endl;
        string ans;
        vector<int> t;
        for(int i=0;i<n;i++){
            // if s[sufMin[i]]>=t.back() then put t.back() in ans;
            while (t.size() && s[sufMin[i]]>=s[t.back()]){
                // cout<<t.back()<<" pushed in ans\n";
                ans.push_back(s[t.back()]);
                t.pop_back();
            }
            // cout<<i<<" pushed in t\n";
            t.push_back(i);
        }
        while(t.size()){
            // cout<<t.back()<<" pushed in ans\n";
            ans.push_back(s[t.back()]);
            t.pop_back();
        }
        return ans;
    }
};
/*
"vzhofnpo"
*/