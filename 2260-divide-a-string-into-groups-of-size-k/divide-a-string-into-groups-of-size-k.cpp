class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.length();
        vector<string> ans;
        for(int i=0; i<n;i+=k){
            string t="";
            for(int j=i; j<i+k && j<n; j++){
                  t.push_back(s[j]);
            }

           while(t.length()!=k){
             t.push_back(fill);

           }
            ans.push_back(t);
        }
        return ans;
    }
};