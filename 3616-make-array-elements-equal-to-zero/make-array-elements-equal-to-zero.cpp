class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=accumulate(nums.begin(),nums.end(),0);

        int ans=0;
        for(int i=0; i<n ;i++){
            if(nums[i]==0){
                  if(left==right){
                    ans+=2;
                  }else if(abs(left-right)==1){
                    ans++;
                  }
            }else{
                left+=nums[i];
                right-=nums[i];
            }
        }

        return ans;
    }
};