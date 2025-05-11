class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long n1=0;
        long long n2=0;
        long long sum1=0; 
        long long sum2=0;
        for(auto i:nums1){
            sum1+=i;
            if(i==0){
                n1++;
            }
        }
        for(auto i:nums2){
            sum2+=i;
            if(i==0){
                n2++;
            }
        }

        sum1+=n1;
        sum2+=n2;
        if(sum1==sum2){
            return sum1;
        }

        if(sum1<sum2){
            if(n1==0){
                return -1;
            }else{
                return sum2;
            }
        }else{
             if(n2==0){
                return -1;
            }else{
                return sum1;
            }
        }

       return -1;

    }
};