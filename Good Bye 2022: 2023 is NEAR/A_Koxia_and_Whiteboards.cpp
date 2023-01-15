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
 
void solve() {
    ll n,m;
    cin>>n>>m;
    priority_queue<ll,vector<ll>,greater<ll>> ai;
    vector<ll> bi(m,-1);
    for(ll i=0;i<n;i++){
        ll tmp;
        cin>>tmp;
        ai.push(tmp);
    }
    for(ll i=0;i<m;i++) cin>>bi[i];
    for(auto it:bi){
        ll cur=ai.top();
        ai.pop();
        ai.push(it);
    }
    ll ans=0;
    while (ai.size()){
        ans+=ai.top();
        ai.pop();
    }
    cout<<ans<<endl;
}
 
int main() {
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}