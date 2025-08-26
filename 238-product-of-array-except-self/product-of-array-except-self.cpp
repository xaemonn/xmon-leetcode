class Solution {
public:
    typedef long long ll;
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        ll prod = 1;
        int cnt0 = 0;

       
        for (auto i : nums) {
            if (i != 0) prod *= i;
            else cnt0++;
        }

        vector<int> ans;
        ans.reserve(n);

        for (auto i : nums) {
            if (cnt0 > 1) {
                ans.push_back(0);
            } 
            else if (cnt0 == 1) {
                if (i == 0) ans.push_back(prod);
                else ans.push_back(0);
            } 
            else {
                ans.push_back(prod / i);
            }
        }

        return ans;
    }
};
