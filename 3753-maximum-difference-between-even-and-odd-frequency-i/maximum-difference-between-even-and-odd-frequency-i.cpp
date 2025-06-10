class Solution {
public:
    int maxDifference(string s) {
        map<char,int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }

        int odd=0;
        int even=0;
        for(auto it:mp){
            int val=it.second;
            if(val%2){
               odd=max(odd,val);
            }else{
                if(even==0){
                    even=val;
                }else{
                    even=min(even,val);
                }
            }
        }

        return odd-even;
    }
};