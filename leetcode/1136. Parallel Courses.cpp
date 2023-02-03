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
    bool isCyc(vector<vector<int>> &edges,int pos,vector<int> &states){
        int n=states.size();
        for(auto it:edges[pos]){
            if(states[it]==2){
                // no need to go
            }else if(states[it]==1){
                // cycle detected
                return true;
            }else {
                states[it]=1;
                if(isCyc(edges,it,states)) return true;
            }
        }
        states[pos]=2;
        return false;
    }

    int minimumSemesters(int n, vector<vector<int>>& ar) {
        vector<vector<int>> edges(n);
        vector<int> ins(n,0);
        int ans=0;
        for(auto it:ar){
            edges[it[0]-1].push_back(it[1]-1);
            ins[it[1]-1]++;
        }
        vector<int> states(n,0);
        for(int i=0;i<n;i++){
            if(states[i]==0 && isCyc(edges,i,states)) return -1;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(ins[i]) continue;
            q.push(i);
        }
        q.push(-1);
        while (q.size()){
            int cur=q.front();
            q.pop();
            if(cur==-1){
                if(q.empty()) break;
                q.push(-1);
                cout<<"\nans becomes "<<ans+1<<endl;
                ans++;
            }else{
                cout<<cur<<" : ";
                for(auto it:edges[cur]){
                    if((--ins[it])==0){
                        q.push(it);
                    }
                }
            }
        }
        return ans+1;
    }
};