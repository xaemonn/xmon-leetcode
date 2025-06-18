class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
          sort(nums.begin(), nums.end());
     
          int n=nums.size();
          int arr=n/3;
          vector<vector<int>> v(arr,vector<int>(3));
           
           vector<vector<int>> temp;
           int j=0;
          for(int i=0; i<n ;i+=3){
               v[j][0]=nums[i];
               if(nums[i+1]-nums[i]<=k){
                v[j][1]=nums[i+1];
               }else{
                 return temp;
               }
               if(nums[i+2]-nums[i+1]<=k  && nums[i+2]-nums[i]<=k){
                v[j][2]=nums[i+2];
               }else{
                 return temp;
               }
               j++;
          }

          return v;
    }
};