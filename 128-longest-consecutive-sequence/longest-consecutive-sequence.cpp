class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        

        int cnt=0;
        
        for(auto i:st){
            if(st.find(i-1)==st.end()){
                int curr=i;
                int len=1;

                while(st.find(curr+1)!=st.end()){
                       curr++;
                       len++;
                }

                cnt=max(cnt,len);
            }
            

            
        }

        return cnt;
    }
};