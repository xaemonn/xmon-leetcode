class Solution {
public:
   int pairswithmid(vector<int>& nums, int maxx){
     int n=nums.size();
     int cnt=0;

     int l=0;

     for(int r=0; r<n;r++){
        // dist <=maxx
        while(nums[r]-nums[l]>maxx){
            l++;
        }

        cnt+=r-l;

     }

     return cnt;

   }
    int smallestDistancePair(vector<int>& nums, int k) {
         sort(nums.begin(),nums.end());
         int n=nums.size();
         int high=nums[n-1]-nums[0];

         int low=0;

         while(low<=high){
            int mid=(low+high)/2;
            // mid here is the max dist bw any 2 pairs
            int count=pairswithmid(nums,mid);

            if(count<k){
               low=mid+1;
            }else{
                high=mid-1;
            }
         }

         return low;
    }
};