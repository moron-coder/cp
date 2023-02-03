#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& ar, int t) {
        priority_queue<int> rems;
        int n=ar.size(),ans=0;
        int *fq=new int[26]();
        for(auto it:ar) fq[it-'A']++;
        for(int i=0;i<26;i++) if(fq[i]) rems.push(fq[i]);
        while (rems.size()){
            vector<int> execs;
            int curCycleTime=0;
            for(int i=0;i<=t;i++){
                if(rems.empty()){
                    if(execs.size()) curCycleTime=t+1; 
                    break;
                }
                int cur=rems.top();
                rems.pop();
                curCycleTime++;
                if(cur-1>0) execs.push_back(cur-1);
            }
            ans+=curCycleTime;
            for(auto it:execs) rems.push(it);
        }
        return ans;
    }
};

/*
implement redis cache having key-value pairs and expiration time
- deleteKey() : This method should delete expired keys in less than O(n) time
- getKey(string key) : Fetched key in O(logn) time
- putKey(string key,string val,int expirationTime) : Puts key in O(logn) time along with updating/setting the expiration time and value
*/