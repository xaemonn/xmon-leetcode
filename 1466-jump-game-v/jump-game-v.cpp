class Solution {
public:
    int solve(vector<int>& arr, int i, int d, vector<int>& dp){
         int n=arr.size();
         if(dp[i]!=-1) return dp[i];
         int res=1;
         //left jump
         for(int j=i-1; j>=max(0,i-d) ; j--){
            if(arr[j]>=arr[i]) break;
            res=max(res,1+solve(arr,j,d,dp));     
         }
          //right jump
         for(int j=i+1; j<=min(n-1,i+d) ; j++){
            if(arr[j]>=arr[i]) break;
            res=max(res,1+solve(arr,j,d,dp));     
         }
         return dp[i]=res;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        int ans=1;
        vector<int> dp(n,-1);
        for(int i=0; i<n ;i++){
            ans=max(ans,solve(arr,i,d,dp));
        }
        return ans;
    }
};