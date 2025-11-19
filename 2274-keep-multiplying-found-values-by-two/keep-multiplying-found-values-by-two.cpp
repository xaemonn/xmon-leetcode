class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n=nums.size();
        set<int> st;
        for(auto i:nums){
            st.insert(i);
        }

        int og=original;
        while(true){
            if(st.find(og)!=st.end()){
                og*=2;
            }else{
                return og;
            }
        }

        return 0;
    }
};