#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pll pair<ll, ll>

class Solution {
    void emptyRooms(priority_queue<ll,vector<ll>,greater<ll>> &freeRooms,
                priority_queue<pll,vector<pll>,greater<pll>> &busyRooms,
                ll timer
    ){
        while (busyRooms.size() && busyRooms.top().first<=timer){
            pll cur = busyRooms.top();
            busyRooms.pop();

            freeRooms.push(cur.second);
        }
    }

public:
    int mostBooked(int n, vector<vector<int>>& ar) {
        priority_queue<ll,vector<ll>,greater<ll>> freeRooms;     //  {room_id}
        priority_queue<pll,vector<pll>,greater<pll>> busyRooms;     //  {meeting_end_time, room_id}
        for(ll i=0;i<n;i++) freeRooms.push(i);
        ll *meetingsCount = new ll[n]();
        ll timer=0;
        sort(ar.begin(), ar.end());

        for(auto it:ar){
            timer = max(timer, (ll)it[0]);
            emptyRooms(freeRooms, busyRooms, timer);
            
            if(freeRooms.empty()){
                timer = busyRooms.top().first;
                emptyRooms(freeRooms, busyRooms, timer);
            }
            ll curRoom = freeRooms.top();
            freeRooms.pop();

            busyRooms.push({timer+it[1]-it[0], curRoom});
            meetingsCount[curRoom]++;
        }
        ll ans=0,mxMeetingCt=0;
        for(ll i=0;i<n;i++){
            if(meetingsCount[i]>mxMeetingCt){
                mxMeetingCt = meetingsCount[i];
                ans=i;
            }
        }
        return ans;
    }
};
