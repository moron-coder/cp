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
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int ans=INT_MAX;
        unordered_set<int> r1,r2;
        queue<int> q1,q2;
        q1.push(node1);
        r1.insert(node1);
        q2.push(node2);
        r2.insert(node2);
        while (q1.size() || q2.size()){
            int cur1=-1,cur2=-1;
            if(q1.size()){
                cur1=q1.front();q1.pop();
                if(edges[cur1]!=-1 && !r1.count(edges[cur1])) {
                    q1.push(edges[cur1]);
                    r1.insert(edges[cur1]);
                }
            }

            if(q2.size()){
                cur2=q2.front();q2.pop();
                if(edges[cur2]!=-1 && !r2.count(edges[cur2])) {
                    q2.push(edges[cur2]);
                    r2.insert(edges[cur2]);
                }
            }
            if(cur1!=-1 && r2.count(cur1)){
                ans=min(ans,cur1);
            }
            if(cur2!=-1 && r1.count(cur2)){
                ans=min(ans,cur2);
            }
            if(ans!=INT_MAX) return ans;
        }
        return -1;
    }
};