class Solution {
public:  
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        int ans=INT_MAX;
        for(int i=0; i<n ;i++){
            int val=nums[i];
            string s=to_string(val);
         
            reverse(s.begin(),s.end());
            auto it=s.find_first_not_of('0');
            
            if(it==string::npos){
                s="0";
            }else{
                s.erase(0,it);
            }
            int rev=stoi(s);

            if(mp.count(val)){
                cout<<rev<<" "<<mp[val]<<endl;
                ans=min(ans, abs(i-mp[val]));
            }
            mp[rev]=i;
        }

        if(ans==INT_MAX) return -1;
        return ans;

        
    }
};