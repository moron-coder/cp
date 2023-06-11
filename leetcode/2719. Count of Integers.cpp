#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

class Solution {
public:
    void substractOne(string &s){
        int n=s.size();
        if(s.back()=='0'){
            bool done=false;
            for(int i=n-2;i>=0;i--){
                if(s[i]!='0'){
                    for(int j=i+1;j<n;j++) s[j]='9';
                    s[i]--; 
                    done=true;
                    break;
                }
            }
            if(!done) s = "0";
        }else{
            s[n-1]--;
        }
    }

    long long getAns(string &num,long long min_sum,long long max_sum){
        long long dp[23][2][401];
        memset(dp,0,sizeof(dp));
        int n=num.size();
        dp[n][1][0]=1;
        dp[n][0][0]=1;
        for(int i=n-1;i>=0;i--){
            for(int tight=0;tight<2;tight++){
                for(int sum=0;sum<=max_sum;sum++){
                    if(tight){
                        for(int d=0;d<=num[i]-'0';d++){
                            if(d==(num[i]-'0')){
                                if(sum-d>=0) dp[i][tight][sum]=(dp[i][tight][sum]+dp[i+1][1][sum-d])%mod;
                            }else{
                                if(sum-d>=0) dp[i][tight][sum]=(dp[i][tight][sum]+dp[i+1][0][sum-d]+mod)%mod;
                            }
                        }
                    }else{
                        for(int d=0;d<10;d++){
                            if(sum-d>=0) dp[i][tight][sum]=(dp[i][tight][sum]+dp[i+1][0][sum-d]+mod)%mod;
                        }
                    }
                }
            }
        }
        long long ans=0;
        for(int curSum=min_sum;curSum<=max_sum;curSum++){
            ans=(ans+dp[0][1][curSum]+mod)%mod;
        }
        return ans%mod;
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        substractOne(num1);
        long long ret1 = (getAns(num2,min_sum,max_sum)+mod)%mod, ret2 = (getAns(num1,min_sum,max_sum)+mod)%mod;
        return (ret1-ret2+mod)%mod;
    }
};