class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact=1;

        for(int i=1; i<n ;i++){
            fact=fact*i;
            nums.push_back(i);
        }
        nums.push_back(n);
        string ans="";

        k=k-1;   //0 based index

        while(true){
            int idx=k/fact;
            ans+=to_string(nums[idx]);

            nums.erase(nums.begin()+idx);

            if(nums.size()==0){
                break;
            }

            k=k%fact;
            fact=fact/nums.size();
        }


        return ans;

    }
};