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
    void makeNums(vector<vector<int>> &ar,vector<int> &arNums){
        for(auto it:ar){
            int num=0;
            for(int i=it.size()-1;i>=0;i--){
                num=(num<<1);
                num+=it[i];
            }
            arNums.push_back(num);
        }
    }

    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& ar) {
        vector<int> arNums;
        makeNums(ar,arNums);
        int *firstIndexOfNum = new int[33]();
        for(int i=0;i<=32;i++) firstIndexOfNum[i]=-1;
        for(int i=0;i<arNums.size();i++){
            if(arNums[i]==0) return {i};
            for(int j=0;j<=32;j++){
                if(firstIndexOfNum[j]!=-1 && !(arNums[i]&j)){
                    return {firstIndexOfNum[j],i};
                }
            }
            firstIndexOfNum[arNums[i]]=i;
        }
        return {};
    }
};