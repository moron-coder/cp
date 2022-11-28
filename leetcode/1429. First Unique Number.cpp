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

class FirstUnique {
public:
    unordered_map<int,int> mp;
    vector<int> v;
    int ptr;
    FirstUnique(vector<int>& ar) {
        mp.clear();
        v=ar;
        for(auto it:ar) mp[it]++;
        ptr=0;
    }
    
    int showFirstUnique() {
        while (ptr<v.size() && mp[v[ptr]]!=1) ptr++;
        if(ptr<v.size()) return v[ptr];
        return -1;
    }

    void add(int value) {
        v.push_back(value);    
        mp[value]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */