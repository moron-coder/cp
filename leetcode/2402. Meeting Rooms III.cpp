#include <bits/stdc++.h>
using namespace std;
#define pll pair<ll, ll>
#define ll long long int

class Solution {
public:
    map<int,int> mp;

    void allotRoom(set<int> &freeRooms,priority_queue<pll,vector<pll>,greater<pll>> &rooms_busy,ll &time,vector<int> &meeting){


        if(freeRooms.size()){
            // allot room
            int roomId = *freeRooms.begin();
            freeRooms.erase(roomId);
            rooms_busy.push({time+meeting[1]-meeting[0],roomId});
            mp[roomId]++;
        }else{
            // wait for a room to be free
            time=rooms_busy.top().first;
            while (rooms_busy.size() && rooms_busy.top().first<=time){
                pll tp = rooms_busy.top();
                rooms_busy.pop();
                freeRooms.insert(tp.second);
            }
            allotRoom(freeRooms,rooms_busy,time,meeting);
        }
    }

    int mostBooked(int n, vector<vector<int>>& meetings) {
        mp.clear();
        ll time=0;
        set<int> freeRooms;
        for(int i=0;i<n;i++) freeRooms.insert(i);
        priority_queue<pll,vector<pll>,greater<pll>> rooms_busy;        //  {end_time, room_id}
        sort(meetings.begin(),meetings.end());
        for(auto it:meetings){
            if(it[0]<=time){
                allotRoom(freeRooms,rooms_busy,time,it);
            }else{
                // increase time
                time=it[0];
                while (rooms_busy.size() && rooms_busy.top().first<=time){
                    pll tp = rooms_busy.top();
                    rooms_busy.pop();
                    freeRooms.insert(tp.second);
                }
                allotRoom(freeRooms,rooms_busy,time,it);
            }
        }
        int maxFq=0,maxFqRoom=-1;
        for(auto it:mp){
            if(it.second>maxFq){
                maxFqRoom=it.first;
                maxFq=it.second;
            }
        }
        return maxFqRoom;
    }
};