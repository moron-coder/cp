#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>


vector<int> loadBalancing(int k,vector<int> &arrival,vector<int> &load){
    int *devices = new int[k]();
    int *loads = new int[k]();
    int devicePtr=0;
    vector<pii> rqs;
    for(int i=0;i<arrival.size();i++){
        rqs.push_back({arrival[i],load[i]+arrival[i]-1});
    }
    sort(rqs.begin(),rqs.end());
    int maxLoad = -1;
    for(int i=0;i<rqs.size();i++){
        //  check if devices[devicePtr] is available
        for(int j=0;j<k;j++){
            if(devices[(devicePtr+j)%k]<=rqs[i].first){
                devices[(devicePtr+j)%k]=rqs[i].second;
                loads[(devicePtr+j)%k]+=rqs[i].second-rqs[i].first+1;
                // cout<<"load of server "<<(devicePtr+j)%k<<" becomes "<<loads[(devicePtr+j)%k]<<endl;
                maxLoad=max(maxLoad,loads[(devicePtr+j)%k]);
                // cout<<rqs[i].first<<"-"<<rqs[i].second<<" is handled by server "<<(devicePtr+j)%k<<endl;
                devicePtr = (devicePtr+j)%k;
                break;
            }
        }
    }
    vector<int> ans;
    for(int i=0;i<k;i++){
        if(loads[i]==maxLoad){
            ans.push_back(i+1);
        }
    }
    return ans;
}

int main(){
    int k=3;
    vector<int> arrival = {1,2,3,4,5};
    vector<int> loads = {6,3,4,4,4};
    vector<int> ans = loadBalancing(k,arrival,loads);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}