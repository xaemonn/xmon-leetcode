class Solution {
public:
    bool check(int diff, int p , vector<int>& nums){
        int n=nums.size();
        int cnt=0;
        int idx=0;
        while(idx<n-1){
            if((nums[idx+1]-nums[idx])<=diff){
                cnt++;
                idx+=2;
            }else
            {idx++;}
            
        }

        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums[n-1]-nums[0];

        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid,p,nums)){
                  ans=min(ans,mid);
                  high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};