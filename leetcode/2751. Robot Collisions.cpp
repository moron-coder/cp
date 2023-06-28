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
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<vector<int>> v;      //  {pos, health, dir(0->left, 1->right),index}
        for(int i=0;i<positions.size();i++){
            vector<int> tmp;
            tmp.push_back(positions[i]);
            tmp.push_back(healths[i]);
            if(directions[i]=='L') tmp.push_back(0);
            else tmp.push_back(1);
            tmp.push_back(i);
            v.push_back(tmp);
        }
        sort(v.begin(),v.end());
        vector<pii> rightBots,leftBots;         //  {index,health}
        for(int i=0;i<v.size();i++){
            //  rightBots contains healths of thos robots which are going right 
            if(v[i][2]==0){
                while (rightBots.size() && rightBots.back().second<v[i][1]){
                    rightBots.pop_back();
                    v[i][1]--;
                }
                if(rightBots.size() && rightBots.back().second==v[i][1]){
                    rightBots.pop_back();
                    continue;
                }
                if(rightBots.size()){
                    rightBots.back().second--;
                }else{
                    leftBots.push_back({v[i][3],v[i][1]});
                }
            }else{
                rightBots.push_back({v[i][3],v[i][1]});
            }
        }
        sort(leftBots.begin(),leftBots.end());
        sort(rightBots.begin(),rightBots.end());
        int ir=0,il=0;
        vector<int> ans;
        while (ir<rightBots.size() && il<leftBots.size()){
            if(rightBots[ir].first<leftBots[il].first){
                ans.push_back(rightBots[ir].second);
                ir++;
            }else{
                ans.push_back(leftBots[il].second);
                il++;
            }
        }
        while (ir<rightBots.size()){
            ans.push_back(rightBots[ir].second);
            ir++;
        }
        while (il<leftBots.size()){
            ans.push_back(leftBots[il].second);
            il++;
        }
        return ans;
    }
};