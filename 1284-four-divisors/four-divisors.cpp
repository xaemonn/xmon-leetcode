class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        vector<set<int>> mp(n);
        for(int i=0; i<n ;i++){
            int num=nums[i];
            
            for(int j=1; j*j<=num; j++){
                if(num%j==0){
                    mp[i].insert(j);
                    mp[i].insert(num/j);
                }
            }
        }

        int sum=0;
        for(int i=0; i<n ;i++){
            if(mp[i].size()==4){
               
                for(auto& x:mp[i]){
                    sum+=x;
                }
            }
        }

        return sum;
    }
};