class Solution {
public:
   vector<int> nums;
    Solution(vector<int>& w) {
        nums.resize(w.size());
        nums[0]=w[0]-1;
        for(int i=1; i<w.size(); i++){
            nums[i]=nums[i-1]+w[i];
        }
    }
    
    int pickIndex() {
        int low=0;
        int n=nums.size();
        int sum=nums[n-1]+1;
        int high=n;
        int pick=rand()% sum;

        while(low<high){
            int mid=(low+high)/2;
              if(pick>nums[mid]){
                low=mid+1;
              }else if(pick<nums[mid]){
                high=mid;
              }else{
                return mid;
              }
        }
         

         return low;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */