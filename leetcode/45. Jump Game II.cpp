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
    int jump(vector<int>& ar) {
        int n=ar.size(),steps=0, maxPtReachable=0;
        queue<int> q;
        q.push(0);
        q.push(-1);

        while (q.size()){
            int cur=q.front();
            q.pop();
            
            if(cur==-1){
                if(q.empty()) break;
                steps++;
                q.push(-1);
            }else{
                if(cur==ar.size()-1){
                    return steps;
                }
                for(int i=maxPtReachable+1;i<=ar[cur]+cur;i++){
                    maxPtReachable=i;
                    q.push(i);
                }
            }
        }
        return -1;
    }
};