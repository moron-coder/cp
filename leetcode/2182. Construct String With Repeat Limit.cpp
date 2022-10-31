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
   public:
    void ins(string &ans, int ch, int fq) {
        for (int i = 0; i < fq; i++) ans.push_back('a' + ch);
    }

    string repeatLimitedString(string s, int rep) {
        int *fq = new int[26]();
        string ans;
        for (auto it : s) fq[it - 'a']++;
        vector<pii> pq;  //      {char,fq}
        for (int i = 0; i < 26; i++)
            if (fq[i]) pq.push_back({i, fq[i]});
        while (pq.size()) {
            pii cur = pq.back();
            pq.pop_back();
            ins(ans, cur.first, min(rep, cur.second));
            cur.second -= min(cur.second, rep);
            if (cur.second && pq.size()) {
                pii cur2 = pq.back();
                pq.pop_back();
                cur2.second--;
                ins(ans, cur2.first, 1);
                if (cur2.second) {
                    pq.push_back(cur2);
                }
                pq.push_back(cur);
            } else if (cur.second) {
                // no use
                break;
            } else if (pq.size()) {
                continue;
            }
        }
        return ans;
    }
};