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

class uf{
   public:
   int *par,*rank;
   uf(int n){
    par=new int[n];
    rank=new int[n]();
    for(int i=0;i<n;i++) par[i]=i;
   } 

    int getPar(int x){
        if(par[x]==x) return x;
        return par[x]=getPar(par[x]);
    }

    void uni(int x,int y){
        x=getPar(x),y=getPar(y);
        if(rank[x]>rank[y]){
            par[y]=x,rank[x]+=rank[y];
        }
        else if(rank[y]>rank[x]){
            par[x]=y,rank[y]+=rank[x];
        }
        else{
            par[x]=y;
            rank[y]++;
        }
    }

};

vector<int> KMP(string s) {
    vector<int> lps(s.size(), 0);
    for (int i = 1; i < s.length(); i++) {
        int j = lps[i - 1];
        while (j > 0 && s[j] != s[i]) j = lps[j - 1];
        if (s[i] == s[j]) j++;
        lps[i] = j;
    }
    return lps;
}

class deb{
	public:
	void disp(int **ar,int n,int m){
		cout<<"displaying ar :\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++) cout<<ar[i][j]<<" ";
			cout<<endl;
		}
	}
};

void solve() {
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}