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

class HitCounter {
public:
    queue<int> q;           //  {time}

    HitCounter() {
        while (q.size()) q.pop();
    }
    
    void hit(int timestamp) { 
        q.push(timestamp);
    }
    
    int getHits(int timestamp) {
        while (q.size() && q.front()+300<=timestamp) q.pop();
        return q.size();
    }
};
