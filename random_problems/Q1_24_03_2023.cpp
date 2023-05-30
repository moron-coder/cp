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

int solve(int n, vector<long long> wealth){
    vector<long long> powersOfThree;
    long long lMax = LONG_MAX, cur=3;
    while (cur<=lMax/3){
        powersOfThree.push_back(cur);
        cur*=3;
    }
    int ans=0;
    map<long long, long long> mp;
    for(auto curNum:wealth){
        for(auto it:powersOfThree){
            long long req = it-curNum;
            if(req>0){
                ans+=mp[req];
            }
        }
        mp[curNum]++;
    }
    return ans;
}

int main(){
    vector<long long> v1 = {1,2,3};
    cout<<solve(v1.size(),v1)<<endl;
    return 0;
}