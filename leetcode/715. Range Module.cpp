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

class RangeModule {
    map<int,int> mp;
public:
    RangeModule() {
        mp.clear();
    }
    
    void addRange(int left, int right) {
        map<int,int>::iterator nxt = mp.lower_bound(right);
        int fa=-1,fb=-1,la=-1,lb=-1;  
        while (nxt!=mp.begin() && (--nxt)->second>=left){
            if(la==-1 && lb==-1){
                la=nxt->first;
                lb=nxt->second;
            }
            fa=nxt->first;
            fb=nxt->second;
            mp.erase(nxt);
        }
        if(la==-1 && lb==-1){
            mp[left]=right;
        }else{
            mp[min(fa,left)]=max(fb,right);
        }
    }
    
    bool queryRange(int left, int right) {
        map<int,int>::iterator it = mp.upper_bound(right);
        if(it==mp.begin()){
            return false;
        }
        map<int,int>::iterator prev = --it;
        return (prev->first<=left && prev->second>=right);
    }
    
    void removeRange(int left, int right) {
        map<int,int>::iterator nxt = mp.upper_bound(right);
        int fa=-1,fb=-1,la=-1,lb=-1;  
        while (nxt!=mp.begin() && (--nxt)->second>=left){
            if(la==-1 && lb==-1){
                la=nxt->first;
                lb=nxt->second;
            }
            fa=nxt->first;
            fb=nxt->second;
            mp.erase(nxt);
        }
        if(la==-1 && lb==-1){
            return;
        }else{
            if(fa==left){
                //  no need to insert f's. Think about l's
            }else{
                mp[fa]=min(left,fb);
            }

            if(lb==right){
                //  no need to insert l's.
            }else{
                mp[max(right,la)]=lb;
            }
        }
    }
};