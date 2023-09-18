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
    const static int MAX_BIT_COUNT = 30;
public:
    int minOperations(vector<int>& ar, int tg){
        int *arrayBits = new int[31]();
        bool *tgBits = new bool[31]();
        for(int i=0;i<=MAX_BIT_COUNT && (1<<i)<=tg;i++){
            if((1<<i)&tg) tgBits[i]=true;
        }
        for(auto it:ar){
            for(int i=0;i<=MAX_BIT_COUNT && (1<<i)<=it;i++){
                if((1<<i)&it) arrayBits[i]++;
            }
        }
        int currentBitCount=0,ans=0;
        for(int i=0;i<=MAX_BIT_COUNT;i++){
            currentBitCount+=arrayBits[i];
            if(tgBits[i]){
                if(!currentBitCount){
                    bool foundNextSetBit=false;
                    for(int j=i+1;j<=MAX_BIT_COUNT;j++){
                        if(arrayBits[j]){
                            arrayBits[j]--;
                            foundNextSetBit=true;
                            ans+=j-i;
                            break;
                        }else{
                            arrayBits[j]++;
                        }
                    }
                    if(foundNextSetBit) currentBitCount++;
                    else{
                        return -1;
                    }
                }else{
                    currentBitCount--;
                }
            }
            currentBitCount/=2;
        }
        return ans;
    }
};