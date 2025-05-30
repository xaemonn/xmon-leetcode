class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);
        }


        int req=(n1+n2+1)/2;  //in one half

        int low=0;
        int high=n1;

        
        while(low<=high){
            int first=(low+high)/2;
            int second=req-first;

            int l1=-1e9,l2=-1e9;
            int r1=1e9,r2=1e9;

            if(first<n1){
                r1=nums1[first];
            }
            if(second<n2){
                r2=nums2[second];
            }
            if(first-1>=0){
                l1=nums1[first-1];
            }
            if(second-1>=0){
                l2=nums2[second-1];
            }

            if(l1<=r2 && l2<=r1 ){
                if(n%2){
                    return max(l1,l2);
                }else{
                    return (double)(max(l1,l2)+min(r1,r2))/2.0;
                }
            }

            if(l1>r2){
                high=first-1;
            }else{
                low=first+1;
            }

        }

        return 0;
    }
};