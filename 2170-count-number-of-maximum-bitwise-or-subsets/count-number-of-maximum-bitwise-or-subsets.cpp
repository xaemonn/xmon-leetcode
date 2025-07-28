class Solution {
public:
    int recur(vector<int>& nums, int curr, int idx, int& req){
       
        if(idx==nums.size()){
            if(curr==req){
                return 1;
            }else{
                return 0;
            }
        }
      
       int pick=recur(nums,curr|nums[idx],idx+1,req);
       int nott=recur(nums,curr,idx+1,req);
        
        

        return pick+nott;

    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
         int maxx=0;
        for(int i=0; i<n;i++){
            maxx=(maxx | nums[i]);
        }

        return recur(nums,0,0,maxx);

    }
};