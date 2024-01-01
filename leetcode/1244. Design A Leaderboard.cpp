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

class Leaderboard {
    int *playerScr;
    priority_queue<pii> pq;     //  {score,playerId}
    bool *taken;
public:
    Leaderboard() {
        playerScr = new int[10001]();
        taken = new bool[10001]();
        while (pq.size()){
            pq.pop();
        }
    }
    
    void addScore(int playerId, int score) {
        playerScr[playerId]+=score;
        pq.push({playerScr[playerId],playerId});
    }
    
    int top(int k) {
        int ans=0;
        queue<pii> q;
        while (pq.size() && k){
            pii cur=pq.top();
            pq.pop();
            if(taken[cur.second] || playerScr[cur.second]!=cur.first){
                continue;
            }
            taken[cur.second]=true;
            ans+=cur.first;
            q.push(cur);
            k--;
        }
        while (q.size()){
            taken[q.front().second]=false;
            pq.push(q.front());
            q.pop();
        }
        return ans;
    }
    
    void reset(int playerId) {
        playerScr[playerId]=0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */