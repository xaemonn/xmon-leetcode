class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum=0;
        long long avoid=LLONG_MAX;
        long long count=0;
        vector<int> vis(nums.size(),false);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];

            int xorr_u=nums[u]^k;
            int xorr_v=nums[v]^k;

            if(!vis[u]){
                if(xorr_u> nums[u]){
                    count++;
                }
                long long diff=abs(nums[u]-xorr_u);
                avoid=min(diff,avoid);
                vis[u]=true;
                sum+=max(xorr_u, nums[u]);
            }

            if(!vis[v]){
                if(xorr_v> nums[v]){
                    count++;
                }
                long long diff=abs(nums[v]-xorr_v);
                avoid=min(diff,avoid);
                vis[v]=true;
                sum+=max(xorr_v, nums[v]);
            }
                 
            
            

        }

        if(count%2){
            sum-=avoid;
        }

        return sum;

        
        
    }
};