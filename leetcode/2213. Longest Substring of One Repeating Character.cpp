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

int n;

class Solution {
public:
    class inf{
    public:
    int pLen,pChar,sLen,sChar,tLen;
    inf(int pLen=0,int sLen=0,int tLen=0,int pChar=-1,int sChar=-1){
        this->pLen=pLen,this->sLen=sLen,this->tLen=tLen,this->pChar=pChar,this->sChar=sChar;
    }
};



class segTree{
    public:
    inf *t;                                 //  stores the tree
    string s;
    segTree(string s){
        t=new inf[4*n+1]();
        this->s=s;
    }

    void update(int aidx,int val,int tidx=0,int tlf=0,int trt=n-1){
        if(aidx<tlf || aidx>trt) return;
        if(tlf>trt) return;
        if(tlf==trt){
            s[aidx]='a'+val;
            t[tidx]={1,1,1,val,val};
            return;
        }
        int mid=tlf+(trt-tlf)/2;
        update(aidx,val,2*tidx+1,tlf,mid);
        update(aidx,val,2*tidx+2,mid+1,trt);
        inf lf=t[2*tidx+1],rt=t[2*tidx+2];
        if((lf.pLen+lf.sLen)>=(mid-tlf+1) && lf.pChar==lf.sChar){
            lf.pLen=lf.sLen=min(mid-tlf+1,lf.pLen+lf.sLen);
            //  lf.pLen can extend more
            if(lf.pChar==rt.pChar){
                lf.pLen+=rt.pLen;
            }
        }
        if((rt.pLen+rt.sLen)>=(trt-mid) && rt.pChar==rt.sChar){
            rt.pLen=rt.sLen=min(trt-mid,rt.pLen+rt.sLen);
            //  rt.sLen can extend more
            if(lf.sChar==rt.sChar){
                rt.sLen+=lf.sLen;
            }
        }
        t[2*tidx+1]=lf;
        t[2*tidx+2]=rt;
        int newTLen = max({lf.pLen,lf.sLen,rt.pLen,rt.sLen,lf.tLen,rt.tLen});
        if(lf.sChar==rt.pChar){
            newTLen=max(newTLen,lf.sLen+rt.pLen);
        }
        t[tidx]={lf.pLen,rt.sLen,newTLen,lf.pChar,rt.sChar};
    }

    int q(){
        return t[0].tLen;
    }
};
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n=(int)s.size();
        segTree st(s);
        for(int i=0;i<(int)s.size();i++){
            st.update(i,s[i]-'a');
        }
        vector<int> ans;
        for(int i=0;i<(int)queryCharacters.size();i++){
            st.update(queryIndices[i],queryCharacters[i]-'a');
            ans.push_back(st.q());
        }
        return ans;
    }
};