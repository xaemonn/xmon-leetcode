class Solution {
public:
    typedef long long ll;
     const ll MOD=1e9+7;
    ll recur(vector<vector<int>>& grid, int k, vector<vector<vector<ll>>>& dp, ll i, ll j, ll rem){
        ll n=grid.size();
        ll m=grid[0].size();

        if(i>=n || j>=m){
            return 0;    //out of bound
        }

        if(i==n-1 && j==m-1){
            ll newrem=rem+grid[i][j];
            newrem=newrem%k;
            if(newrem==0){
                return 1;
            }else{
                return 0;
            }
        }

        if(dp[i][j][rem]!=-1){
            return dp[i][j][rem];
        }

        ll down=recur(grid,k,dp,i+1,j,(rem+grid[i][j])%k)%MOD;
        ll right=recur(grid,k,dp,i,j+1,(rem+grid[i][j])%k)%MOD;
      
        return dp[i][j][rem]=(down+right)%MOD;
        
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
         int n = grid.size();
        int m = grid[0].size();

        // dp[i][j][rem]
        vector<vector<vector<ll>>> dp(n,
            vector<vector<ll>>(m, vector<ll>(k, -1)));

        return recur(grid, k, dp, 0, 0, 0);
    }
};