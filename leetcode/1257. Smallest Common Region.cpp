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
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string,int> regToNum;
        unordered_map<int,string> numToReg;
        int num=0;
        unordered_map<int,int> mp;
        unordered_set<int> regs;
        for(auto it:regions){
            if(!regToNum.count(it[0])){
                regToNum[it[0]]=num;
                mp[num]=num;
                numToReg[num]=it[0];
                num++;
            }
            for(int i=1;i<it.size();i++){
                if(!regToNum.count(it[i])){
                    regToNum[it[i]]=num;
                    numToReg[num]=it[i];
                    num++;
                }
                int fromIdx=regToNum[it[i]],toIdx=regToNum[it[0]];
                mp[fromIdx]=toIdx;
            }
        }
        int itr=regToNum[region1];
        regs.insert(itr);
        while (mp.count(itr)){
            regs.insert(mp[itr]);
            if(mp[itr]==itr) break;
            itr=mp[itr];
        }
        itr=regToNum[region2];
        while (mp.count(itr)){
            if(regs.count(itr)){
                return numToReg[itr];
            }
            if(itr==mp[itr]) break;
            itr=mp[itr];
        }
        return "";
    }
};

/*
["Earth", "North America", "South America"]
["North America", "United States", "Canada"]
["United States", "New York", "Boston"]
["Canada", "Ontario", "Quebec"]
["South America", "Brazil"]
*/