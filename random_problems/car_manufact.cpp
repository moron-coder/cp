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

class uf {
   public:
    int *size, *par;
    int cap;
    uf(int n) {
        cap = n;
        size = new int[n]();
        par = new int[n]();
        for (int i = 0; i < n; i++) par[i] = i, size[i] = 1;
    }

    int getPar(int x) {
        if (par[x] == x) return x;
        return par[x] = getPar(par[x]);
    }

    void merge(int x, int y) {
        x = getPar(x), y = getPar(y);
        if (x == y) return;
        if (size[x] < size[y])
            par[x] = y, size[y] += size[x];
        else
            par[y] = x, size[x] += size[y];
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* lca;

pair<bool, bool> getLCA(TreeNode *r, int sNode, int dNode) {
    // returns {s found?,d found?}
    if (!r) return {false, false};
    pair<bool, bool> lf = getLCA(r->left, sNode,dNode), rt = getLCA(r->right,sNode, dNode);
    if (lca) return {true, true};
    pair<bool, bool> ans = {(lf.first || rt.first || r->val == sNode), (lf.second || rt.second || r->val == dNode)};
    if (ans.first && ans.second) lca = r;
    return ans;
}

ll dp[1001];

ll help(vector<vector<ll>> &ar,ll dayCt,bool team1){
    ll n=ar.size(),m=ar[0].size();
    if(dayCt>=n) return 0;
    if(dp[dayCt]!=-1) return dp[dayCt];
    int st=-1,en=-1;
    if(team1){
        st=0,en=(m/2)-1;
    }else{
        st=m/2,en=m-1;
    }
    ll cur=0;
    for(int j=st;j<=en;j++){
        cur=max(cur,ar[dayCt][j]+help(ar,dayCt+1,!team1));
    }
    return dp[dayCt]=cur;
}

ll solve() {
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> ar(n,vector<ll>(m,-1));
    for(ll i=0;i<n;i++) for(ll j=0;j<m;j++) cin>>ar[i][j];
    memset(dp,-1,sizeof(dp));
    return max(help(ar,0,true),help(ar,0,false));
}

int main() {
    // int t=1;
    // cin >> t;
    // while (t--) solve();
    return 0;
}