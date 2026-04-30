class Solution {
public:
    typedef long long ll;
    int cost(int val){
        if(val==0){
            return 0;
        }
        return 1;
    }
    
    ll score(vector<vector<int>>& g, ll total, ll c, ll i, ll j,vector<vector<vector<ll>>>& dp){
        ll n=g.size();
        ll m=g[0].size();
        if(i>=n || j>=m) return -1e9;
        int costnew=c+cost(g[i][j]);
        if(costnew>total){
            return -1e9;
        }
        if(i==n-1 && j==m-1){
            return g[i][j];
        }

        if(dp[i][j][costnew]!=-1){
            return dp[i][j][costnew];
        }

        ll rt=score(g,total,costnew,i,j+1,dp);
         ll down=score(g,total,costnew,i+1,j,dp);

        ll best=max(rt,down);
        if(best<0){
            return dp[i][j][costnew]=-1e9;
        }

        return dp[i][j][costnew]=g[i][j]+best;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        ll n=grid.size();
        ll m=grid[0].size();
        vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(m,vector<ll>(k+1,-1)));

        ll ans= score(grid,k,0,0,0,dp);
        if(ans<0){
            return -1;
        }
        return ans;
    }
};