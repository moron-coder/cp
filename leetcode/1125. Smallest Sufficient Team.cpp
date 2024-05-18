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
    int dp[(1<<17)][61];
    int actionIdx[(1<<17)][61];
    int peopleSkillMask[61];            //  save some calculations

    int getSkillMask(map<string,int> &skillMap, vector<vector<string>> &people,int pos){
        if(peopleSkillMask[pos]!=-1) return peopleSkillMask[pos];
        int cur=0;
        for(auto it:people[pos]){
            int i=skillMap[it];
            cur|=(1<<i);
        }
        return peopleSkillMask[pos] = cur;
    }
public:
    int help(map<string,int> &skillMap, int currentSkills, vector<vector<string>> &people, int pos){
        int n=people.size();
        if(pos>=n){
            return (currentSkills==((1<<skillMap.size())-1))?0:-2;
        }
        if(dp[currentSkills][pos]!=-1) return dp[currentSkills][pos];
        int curSkillMask = getSkillMask(skillMap, people, pos);
        int ans=-2;
        int incAns = help(skillMap, currentSkills|curSkillMask, people, pos+1);
        int notIncAns = help(skillMap, currentSkills, people, pos+1);
        if(incAns==-2 && notIncAns==-2){
            //  no possible ans
        }else if(incAns==-2){
            //  notIncAns preferred
            actionIdx[currentSkills][pos]=0;
            ans=notIncAns;
        }else if(notIncAns==-2){
            //  incAns preferred
            actionIdx[currentSkills][pos]=1;
            ans=incAns+1;
        }else{
            actionIdx[currentSkills][pos]=(incAns+1<notIncAns);
            ans = (incAns+1<notIncAns)?incAns+1:notIncAns;
        }
        return dp[currentSkills][pos]=ans;
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        memset(dp,-1,sizeof(dp));
        memset(peopleSkillMask,-1,sizeof(peopleSkillMask));
        map<string,int> skillMap, peopleMap;
        for(auto it:req_skills){
            skillMap[it]=skillMap.size();
        }
        int sz = help(skillMap, 0, people, 0);
        vector<int> ans;
        int x=0,y=0;
        while (y<people.size()){
            if(actionIdx[x][y]==0){
                y++;
            }else if(actionIdx[x][y]==1){
                ans.push_back(y);
                int skillMask = getSkillMask(skillMap, people, y);
                x|=skillMask;
                y++;
            }else{
                cout<<"error\n";
                return {};
            }
        }
        return ans;
    }
};