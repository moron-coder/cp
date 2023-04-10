#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int help(vector<int> &ar,bool *isTaken,int k,int pos){
        int n=ar.size(),curAns=0;
        if(pos>=n) return 1;
        curAns=help(ar,isTaken,k,pos+1);
        if(!(ar[pos]+k<=1000 && isTaken[ar[pos]+k]) && !(ar[pos]-k>=0 && isTaken[ar[pos]-k])){
            // take ar[pos]
            bool prev=isTaken[ar[pos]];
            isTaken[ar[pos]]=true;
            curAns=curAns+help(ar,isTaken,k,pos+1);
            isTaken[ar[pos]]=prev;
        }
        return curAns;
    }

    int beautifulSubsets(vector<int>& ar, int k) {
        bool *isTaken=new bool[1001]();
        return help(ar,isTaken,k,0)-1;      //  -1 to exlude empty set
    }
};