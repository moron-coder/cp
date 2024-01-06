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
    int MAX_ANS=10000000;
    int LIM = 110001;

    int minimumOperationsToMakeEqual(int x, int y) {
        queue<int> q;
        unordered_set<int> vis;
        q.push(x);
        vis.insert(x);
        q.push(-MAX_ANS);
        int steps = 0;
        while (q.size()){
            int cur=q.front();
            q.pop();
            if(cur==-MAX_ANS){
                if(q.empty()){
                    break;
                }
                q.push(-MAX_ANS);
                steps++;
            }else{
                if(cur==y){
                    return steps;
                }
                if(!vis.count(cur-1) && cur-1>=-LIM && cur-1<=LIM){
                    q.push(cur-1);
                    vis.insert(cur-1);
                }
                if(!vis.count(cur+1) && cur+1>=-LIM && cur+1<=LIM){
                    q.push(cur+1);
                    vis.insert(cur+1);
                }
                if((cur%11)==0 && !vis.count(cur/11) && cur/11>=-LIM && cur/11<=LIM){
                    q.push(cur/11);
                    vis.insert(cur/11);
                }
                if((cur%5)==0 && !vis.count(cur/5) && cur/5>=-LIM && cur/5<=LIM){
                    q.push(cur/5);
                    vis.insert(cur/5);
                }
            }
        }
        return steps;
    }
};