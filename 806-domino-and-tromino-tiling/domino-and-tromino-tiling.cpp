class Solution {
public:
    int numTilings(int n) {

        int MOD=1e9+7;
        if(n<=1) return 1;
        if(n==2) return 2;
        if(n==3) return 5;

        vector<int> dp(n+1,0);
        dp[1]=1; dp[2]=2; dp[3]=5;
        for(int i=4; i<=n;i++){
            dp[i]=((dp[i-3]%MOD)+(2LL*dp[i-1]%MOD))%MOD;
        }

        return dp[n];
    }
};