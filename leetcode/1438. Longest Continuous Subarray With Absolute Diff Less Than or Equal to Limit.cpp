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
    void insertInMaxQ(vector<int> &ar,deque<int> &qg,int i){
        while (qg.size() && ar[qg.back()]<=ar[i]){
            qg.pop_back();
        }
        qg.push_back(i);
    }

    void insertInMinQ(vector<int> &ar,deque<int> &qs,int i){
        while (qs.size() && ar[qs.back()]>=ar[i]){
            qs.pop_back();
        }
        qs.push_back(i);
    }

    void clearOutOfRange(deque<int> &dq, int len, int i){
        while (dq.front()<=i-len){
            dq.pop_front();
        }
    }
    
    bool isOk(vector<int> &ar,int len,int limit){
        deque<int> qg,qs;
        for(int i=0;i<len-1;i++){
            insertInMaxQ(ar,qg,i);
            insertInMinQ(ar,qs,i);
        }
        for(int i=len-1;i<ar.size();i++){
            insertInMaxQ(ar,qg,i);
            insertInMinQ(ar,qs,i);
            clearOutOfRange(qg,len,i);
            clearOutOfRange(qs,len,i);
            if(ar[qg.front()]-ar[qs.front()]<=limit){
                return true;
            }
        }
        return false;
    }

public:
    int longestSubarray(vector<int>& ar, int limit) {
        int n=ar.size(),i=0,hi=n,lo=1,ans=1;
        while (lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(isOk(ar,mid,limit)){
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans;
    }
};