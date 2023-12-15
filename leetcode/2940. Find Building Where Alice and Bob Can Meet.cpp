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

vector<int> heightsPtr;
vector<vector<int>> queriesPtr;
bool cmp(int x,int y){
    return (queriesPtr[x][1]>queriesPtr[y][1]);
}

class Solution {
public:

    int getBestIdx(vector<int> &v,int ht){
        int lo=0,hi=v.size()-1,idx=-1;
        while (lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(heightsPtr[v[mid]]>ht){
                idx=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return idx;
    }

    vector<int> leftmostBuildingQueries(vector<int>& ar, vector<vector<int>>& queries) {
        for(auto &it:queries){
            int mn=min(it[0],it[1]);
            int mx=max(it[0],it[1]);
            it[0]=mn,it[1]=mx;
        }
        // offline processing queries
        heightsPtr = ar;
        queriesPtr = queries;
        int n = ar.size();
        vector<int> idx,ans(queries.size(),-1),monoStack;
        for(int i=0;i<queries.size();i++){
            if(ar[queries[i][1]]>ar[queries[i][0]] || queries[i][0]==queries[i][1]) ans[i]=queries[i][1];
            else idx.push_back(i);
        }
        sort(idx.begin(),idx.end(),cmp);
        int j=n-1;
        for(auto curIdx:idx){
            while (j>queries[curIdx][1]){
                while(monoStack.size() && ar[j]>=ar[monoStack.back()]){
                    monoStack.pop_back();
                }
                monoStack.push_back(j--);
            }
            int bestIdx = getBestIdx(monoStack,ar[queries[curIdx][0]]);
            ans[curIdx] = (bestIdx!=-1)?monoStack[bestIdx]:-1;
        }
        return ans;
    }
};