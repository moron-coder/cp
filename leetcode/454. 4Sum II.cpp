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
    int nSumCountGeneral(vector<vector<int>> &ar,int sum){
        int n=ar.size(),m=ar[0].size();
        vector<unordered_map<int,int>> lwrs(n),uprs(n);

        for(int ir=0;ir<n;ir++){
            for(int jr=ir+1;jr<n;jr++){
                for(int ic=0;ic<m;ic++){
                    for(int jc=0;jc<m;jc++){
                        lwrs[ir][ar[ir][ic]+ar[jr][jc]]++;
                        uprs[jr][ar[ir][ic]+ar[jr][jc]]++;
                    }
                }
            }
        }

        int ans=0;

        for(int ir=0;ir<n;ir++){
            unordered_map<int,int> mp = uprs[ir];
            for(auto it:mp){
                for(int jr=ir+1;jr<n;jr++){
                    ans+=lwrs[jr][sum-it.first]*it.second;
                }
            }
        }

        return ans;
    }

public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        vector<vector<int>> ip;
        ip.push_back(nums1);
        ip.push_back(nums2);
        ip.push_back(nums3);
        ip.push_back(nums4);
        return nSumCountGeneral(ip,0);
    }
};