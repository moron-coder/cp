#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& ar) {
        int n=ar.size(),lf=0,rt=n-1;
        while (lf<=rt){
            int mid=lf+(rt-lf)/2;
            cout<<"lf: "<<lf<<" rt: "<<rt<<endl;
            cout<<mid<<" is mid\n";
            cout<<max(ar[mid-1],ar[mid+1])<<" is the max ngb\n";
            cout<<ar[mid]<<" is the pt\n";
            cout<<(ar[mid]>max(ar[mid-1],ar[mid+1]))<<" is true?\n";
            if(mid && mid+1<n && ar[mid]>max(ar[mid-1],ar[mid+1])){
                cout<<"hereeeee\n";
                return mid;
            }else if(!mid || ar[mid-1]<ar[mid] && ar[mid]<ar[mid+1]){
                lf=mid+1;
            }else rt=mid-1;
        }
        return -1;
    }
};