class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        int r=0;
        int n=nums.size();

        for(int i=0; i<n ;i++){
            if(nums[i]==key){
                int l=max(r,i-k);
                r=min(n-1,i+k)+1;

                for(int j=l; j<r; j++){
                    res.push_back(j);
                }
            }
        }

        return res;
    }
};