class Solution {
public: 
    double recur(int row, int glass, double water,vector<vector<double>>& dp){
         if(glass<0 || glass>row) return 0.0;
         if(glass==0 && row==0) return water;
         if(dp[row][glass]!=-1.0) return dp[row][glass];

         double prev1=recur(row-1,glass-1, water,dp);
         
         double prev2=recur(row-1,glass,water,dp);
         double curr=0.0;
         if(prev1>1){
            prev1--;
            curr+=prev1/2.0;
         }
         if(prev2>1){
            prev2--;
            curr+=prev2/2.0;
         }
         return dp[row][glass]=curr;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>dp(101,vector<double>(101,-1.0));
        return min(1.0,recur(query_row, query_glass, poured,dp));
    }
};