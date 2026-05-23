class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0;
        if(is_sorted(nums.begin(),nums.end())) return true;

        int idx=-1;

        for(int i=1; i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                cnt++;
                idx=i;
            }
        }

        

        if(cnt>1) return false;
         vector<int> temp(nums.begin()+idx, nums.end());
         vector<int> temp2(nums.begin(), nums.begin()+idx);
         if(is_sorted(temp.begin(),temp.end())&& is_sorted(temp2.begin(),temp2.end())){
             return temp2[0]>=temp[temp.size()-1];
         }
        return false;
    }
};