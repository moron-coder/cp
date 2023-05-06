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

struct SegmentTree {
    SegmentTree* left=NULL;
    SegmentTree* right=NULL;
    int count;
    long min,max;
    
    // ar is sorted
    SegmentTree(vector<long>& ar, int l, int r):left(NULL),right(NULL) {
        if (l>r) return;
        min = ar[l];
        max = ar[r];
        count=0;
       if (l==r) return;
        int m = (l+r)/2;
        if (l<=m) left = new SegmentTree(ar, l,m);
        if (m+1<=r) right = new SegmentTree(ar, m+1, r);
    }
    
    void add(long value) {
        if (value<min || value>max) return;
        count++;
        if (left && value<=left->max) left->add(value);
        else if (right && value>=right->min) right->add(value);
    }
    
    int getCount(long minValue, long maxValue) {
        if (minValue<=min && max<=maxValue) return count;
        if (maxValue<min || minValue>max) return 0;
        int leftCount = left ? left->getCount(minValue, maxValue) : 0;
        int rightCount = right ? right->getCount(minValue, maxValue) : 0;
        return leftCount+rightCount;
    }
};
    
    
public:
    int countRangeSum(vector<int>& ar, int lower, int upper) {
        if (ar.size()==0) return 0;
        long sum=0;
        vector<long> sums;
        for(int i=0;i<ar.size();i++){
            sum+=ar[i];
            sums.push_back(sum);
        }
        sort(sums.begin(), sums.end());
        SegmentTree* tree = new SegmentTree(sums, 0, sums.size()-1);
        int count = 0;
        for(int i=ar.size()-1;i>=0;i--) {
            tree->add(sum);
            sum-=ar[i];
            count += tree->getCount(lower+sum, upper+sum);
        }        
        return count;
    }
};