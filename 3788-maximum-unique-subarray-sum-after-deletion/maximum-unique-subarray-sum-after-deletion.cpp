class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        set<int> st;
        int maax=INT_MIN;
        int neg=0;
        for(int i=0; i<n ;i++){
            if(nums[i]>0 && st.find(nums[i])==st.end()){
                sum+=nums[i];
                st.insert(nums[i]);
            } else if(nums[i]<0){
                maax=max(maax,nums[i]);
                neg++;
            }
        }

        if(neg==n){
            return maax;
        }

        return sum;
    }
};