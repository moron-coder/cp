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

int getMinTime(vector<int> &taskMemory,vector<int> &taskType,int max_memory){
    vector<pii> v;
    for(int i=0;i<taskMemory.size();i++){
        v.push_back({taskType[i],taskMemory[i]});
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(int taskIdx=0;taskIdx<taskMemory.size();){
        int i=taskIdx,j=taskIdx;
        while (j<v.size() && v[j].first==v[i].first) j++;
        int nextTaskIdx=j+1;
        while (i<=j){
            if(v[i].first+v[j].first<=max_memory){
                i++,j--;
            }else{
                j--;
            }
            ans++;
        }
        taskIdx=nextTaskIdx;
    }
    return ans;
}

bool test(vector<int> &v1,vector<int> &v2,int k,int expectedAns){
    return getMinTime(v1,v2,k)==expectedAns;
}

int main(){

    vector<int> v1 = {7,2,3,9}, v2 = {1,2,1,3};
    int k = 10;

    cout<<test(v1,v2,k,3)<<endl;

    v1 = {1,2,3,4,2};
    v2 = {1,2,1,2,3};
    k = 4;

    cout<<test(v1,v2,k,4)<<endl;
    
    return 0;
}