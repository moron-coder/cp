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

bool help(vector<int> &tasks,int pos,vector<int> &servers){
    int n=tasks.size();
    if(pos>=n){
        return true;
    }
    for(int i=0;i<servers.size();i++){
        if(servers[i]>=tasks[pos]){
            servers[i]-=tasks[pos];
            if(help(tasks,pos+1,servers)){
                return true;
            }
            servers[i]+=tasks[pos];
        }
    }
    return false;
}

bool scheduleTasks(int n, int m, vector<int> &servers, vector<int> &tasks) {
    return help(tasks,0,servers);
}


