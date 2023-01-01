#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

class Solution
{
public:
    vector<int> sieveOfEratosthenes(int n){
        vector<int> ans;
        bool *isNotP=new bool[10001]();
        isNotP[1]=true;
        for(int i=2;i<=10000;i++){
            for(int j=2;j*i<=10000;j++){
                isNotP[i*j]=true;
            }
        }
        for(int i=2;i<=n;i++) if(!isNotP[i]) ans.push_back(i);
        //debug
        for(int i=1;i<=10;i++) cout<<isNotP[i]<<" ";
        cout<<endl;
        //debug
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> ans=s.sieveOfEratosthenes(5);
    // cout<<"ans is\n";
    // for(auto it:ans) cout<<it<<" ";
    // cout<<endl;
    return 0;
}