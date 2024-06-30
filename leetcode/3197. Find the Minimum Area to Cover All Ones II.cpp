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

/**
* @author : Utkarsh Kumar
* @date : 2024-06-30
*/

class dt{
    public:
    int minI,minJ,maxI,maxJ;

    dt(){
        minI=30,minJ=30,maxI=-1,maxJ=-1;
    }

    void markOne(int i,int j){
        this->minI=i;
        this->maxI=i;
        this->minJ=j;
        this->maxJ=j;
    }

    void processMerge(dt cur, dt prev){
        cur.minI = min(cur.minI, prev.minI);
        cur.minJ = min(cur.minJ, prev.minJ);
        cur.maxI = max(cur.maxI, prev.maxI);
        cur.maxJ = max(cur.maxJ, prev.maxJ);
    }

    int getArea(){
        return (this->maxI-this->minI)*(this->maxJ-this->minJ);
    }

};

class Solution {
    dt **topLeft,**topRight,**bottomLeft,**bottomRight;

    void buildDp(int n, int m){
        topLeft = new dt*[n];
        topRight = new dt*[n];
        bottomLeft = new dt*[n];
        bottomRight = new dt*[n];

        for(int i=0;i<n;i++){
            topLeft[i]=new dt[m]();
        }
        for(int i=0;i<n;i++){
            topRight[i]=new dt[m]();
        }
        for(int i=0;i<n;i++){
            bottomLeft[i]=new dt[m]();
        }
        for(int i=0;i<n;i++){
            bottomRight[i]=new dt[m]();
        }
    }

    void calcTopLeft(vector<vector<int>>& ar){
        int n=ar.size(),m=ar[0].size();  
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ar[i][j]){
                    topLeft[i][j].markOne(i,j);
                }
                if(i){
                    topLeft[i][j].processMerge(topLeft[i][j], topLeft[i-1][j]);
                }
                if(j){
                    topLeft[i][j].processMerge(topLeft[i][j],topLeft[i][j-1]);
                }
            }
        }  
    }

    void calcTopRight(vector<vector<int>>& ar){
        int n=ar.size(),m=ar[0].size();
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                if(ar[i][j]){
                    topRight[i][j].markOne(i,j);
                }
                if(i){
                    topRight[i][j].processMerge(topRight[i][j], topRight[i-1][j]);
                }
                if(j+1<m){
                    topRight[i][j].processMerge(topRight[i][j], topRight[i][j+1]);
                }
            }
        }
    }

    void calcBottomLeft(vector<vector<int>> &ar){
        int n=ar.size(),m=ar[0].size();
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                if(ar[i][j]){
                    bottomLeft[i][j].markOne(i,j);
                }
                if(i+1<n){
                    bottomLeft[i][j].processMerge(bottomLeft[i][j], bottomLeft[i+1][j]);
                }
                if(j){
                    bottomLeft[i][j].processMerge(bottomLeft[i][j], bottomLeft[i][j-1]);
                }
            }
        }        
    }

    void calcBottomRight(vector<vector<int>> &ar){
        int n=ar.size(),m=ar[0].size();
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(ar[i][j]){
                    bottomRight[i][j].markOne(i,j);
                }
                if(i+1<n){
                    bottomRight[i][j].processMerge(bottomRight[i][j], bottomRight[i+1][j]);
                }
                if(j+1<m){
                    bottomRight[i][j].processMerge(bottomRight[i][j], bottomRight[i][j+1]);
                }
            }
        }
    }

public:
    int minimumSum(vector<vector<int>>& ar) {
        int n=ar.size(), m=ar[0].size();
        int minAreaRec=INT_MAX;
        buildDp(n,m);
        calcTopLeft(ar);
        calcTopRight(ar);
        calcBottomLeft(ar);
        calcBottomRight(ar);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //  case 1
                dt x = topLeft[i][j];
                if(j+1<m){
                    dt y = bottomRight[0][j+1];
                    if(i+1<n){
                        dt z = bottomLeft[i+1][j];
                        minAreaRec = min(minAreaRec, x.getArea()+y.getArea()+z.getArea());
                    }
                }
                //  case 2
                if(j+1<m){
                    dt y = topRight[i][j+1];
                    if(i+1<n){
                        dt z = bottomRight[i+1][0];
                        minAreaRec = min(minAreaRec, x.getArea()+y.getArea()+z.getArea());
                    }
                }
                //  case 3
                if(i){
                    dt y = topRight[i-1][0];
                    if(j+1<m){
                        dt z = bottomRight[i][j+1];
                        minAreaRec = min(minAreaRec, x.getArea()+y.getArea()+z.getArea());
                    }
                }
                //  case 4
                if(j){
                    dt y = topLeft[n-1][j-1];
                    if(i+1<n){
                        dt z = bottomRight[i+1][j];
                        minAreaRec = min(minAreaRec, x.getArea()+y.getArea()+z.getArea());
                    }
                }
            }
        }
        return minAreaRec;
    }
};