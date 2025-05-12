class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
          map<int,int> mp;
          for(auto i:digits){
            mp[i]++;
          }

          vector<int> res;

          for(int i=100; i<999;i++){
            if(i%2==0){
               int a=i%10;
               int b=(i/10)%10;
               int c=i/100;

               map<int,int> temp=mp;
               if(temp[a]>0){
                temp[a]--;
                if(temp[b]>0){
                    temp[b]--;
                    if(temp[c]>0){
                        res.push_back(i);
                    }
                }
               }
                
            }
          }

          return res;
    }
};