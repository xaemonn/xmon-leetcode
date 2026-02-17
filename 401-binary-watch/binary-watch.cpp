class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
         int n=turnedOn;
          vector<string> ans;
         for(int i=0; i<=11; i++){
            for(int j=0; j<=59; j++){
                int total=__builtin_popcount(i);
                total+=__builtin_popcount(j);
                if(total==n){
                     string s="";
                     s+=to_string(i);
                     s+=':';
                     string m="";
                     m+=to_string(j);
                     if(m.size()==2){
                          s+=m;
                          ans.push_back(s);
                     }else if(m.size()==1){
                        s+='0';
                        s+=m;
                        ans.push_back(s);
                     }else{
                        m="00";
                        s+=m;
                        ans.push_back(s);
                     }
                }
            }
         }
         return ans;
    }
};