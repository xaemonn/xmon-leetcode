class Solution {
public:
    int findLucky(vector<int>& arr) {
          map<int,int> mp;
          for(auto i:arr){
            mp[i]++;
          }

          int num=-1;
          for(auto it:mp){
            if(it.first==it.second){
                num=max(num,it.first);
            }
          }

          return num;


    }
};