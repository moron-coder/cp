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
public:
    int getMaskFromEpTime(int epTime){
        int msk=0;
        int hh=epTime/60, mm=epTime%60;
        if(min(hh,mm)<10) msk=1;        //  '0'
        while (hh){
            msk|=(1<<(hh%10));
            hh/=10;
        }
        while(mm){
            msk|=(1<<(mm%10));
            mm/=10;
        }
        return msk;
    }

    string getTime(int epTime){
        int hh=epTime/60, mm=epTime%60;
        string shh,smm;
        if(hh<10){
            shh="0";
            shh.push_back('0'+hh);
        }else{
            shh=to_string(hh);
        }
        if(mm<10){
            smm="0";
            smm.push_back('0'+mm);
        }else{
            smm=to_string(mm);
        }
        string ret = shh+":"+smm;
        return ret;
    }

    string nextClosestTime(string time) {
        int msk=0,curDif=INT_MAX, hh=(time[0]-'0')*10+time[1]-'0', mm = (time[3]-'0')*10+time[4]-'0';
        for(auto it:time){
            if(it!=':') msk|=(1<<(it-'0'));
        }
        string ans;
        
        for(int ct=1;ct<=24*60;ct++){
            int i=(hh*60+mm+ct)%(24*60);
            int mskCur = getMaskFromEpTime(i);
            if((mskCur|msk)==msk){
                ans=getTime(i);
                return ans;
            }
        }
        return ans;
    }
};