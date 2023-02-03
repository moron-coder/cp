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

class MedianFinder {
public:
    priority_queue<int> p1;
    priority_queue<int,vector<int>,greater<int>> p2;

    MedianFinder() {
        while (p1.size()) p1.pop();
        while (p2.size()) p2.pop();
    }
    
    void addNum(int n) {
        // p2.size()=p1.size(); OR
        // p2.size()=p1.size()+1;
        if(p2.size() && n<p2.top()){
            p1.push(n);
        }else{
            p2.push(n);
        }
        while(p1.size()>p2.size()){
            int cur=p1.top();
            p1.pop();
            p2.push(cur);
        }
        while(p2.size()>p1.size()+1){
            int cur=p2.top();
            p2.pop();
            p1.push(cur);
        }
    }
    
    double findMedian() {
        if(p2.empty()) return 0;
        if(p2.size()!=p1.size()) return p2.top();
        return (p1.top()+p2.top())/2.0;
    }
};