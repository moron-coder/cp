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

class SnapshotArray {
public:
    int ct;
    vector<vector<pii>> v;          //  v[i] -> {{count at which val was inserted,
                                    //              value inserted}}

    int getPos(vector<pii> &v,int lb){
        int lo=0,hi=v.size()-1,ans=-1;
        while (lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(v[mid].first<=lb){
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans;
    }

    SnapshotArray(int length) {
        ct=0;
        for(int i=0;i<length;i++) v.push_back(vector<pii>());
    }
    
    void set(int index, int val) {
        v[index].push_back({ct,val});
    }
    
    int snap() {
        return ct++;
    }
    
    int get(int index, int snap_id) {
        int pos = getPos(v[index],snap_id);
        if(pos==-1) return 0;       //  no entries were inserted
        return v[index][pos].second;
    }
};