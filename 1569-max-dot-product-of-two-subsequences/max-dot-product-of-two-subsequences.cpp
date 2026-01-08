class Solution {
public:
typedef long long ll;
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        vector<vector<ll>> dp(n+1,vector<ll>(m+1,-1e9));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                ll take=((ll)nums1[i-1]*(ll)nums2[j-1])+ max(0LL,dp[i-1][j-1]);
                ll nott=max(dp[i-1][j], dp[i][j-1]);
                dp[i][j]=max(take,nott);
            }
        }

        return dp[n][m];
    }
};