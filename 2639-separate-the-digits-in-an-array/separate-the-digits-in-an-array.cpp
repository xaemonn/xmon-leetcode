class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int n:nums){
            vector<int> temp;
            while(n){
                int d=n%10;
                temp.push_back(d);
                n=n/10;
            }
            reverse(temp.begin(),temp.end());
            for(auto i:temp){
                ans.push_back(i);
            }
        }

        return ans;
    }
};