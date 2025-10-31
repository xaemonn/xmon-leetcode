class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        set<int> st;
        for(int i=0; i<n ;i++){
            if(!st.empty() && st.find(nums[i])!=st.end()){
                ans.push_back(nums[i]);
            }else{
                st.insert(nums[i]);
            }
        }

        return ans;
    }
};