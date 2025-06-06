class Solution {
public:
    string robotWithString(string s) {
        //we use stack here why????
        // t->insert at last
        // t->remove from last
        int len=s.length();
        vector<char> minFromIdx(len);

        minFromIdx[len-1]=s[len-1];
        for(int i=len-2; i>=0; i--){
            minFromIdx[i]=min(s[i], minFromIdx[i+1]);
        }

        stack<char> t;
        string ans="";
        for(int i=0; i<len ;i++){
           t.push(s[i]);
           //if possible to pop
           while(!t.empty() && (i==len-1 || (t.top()<=minFromIdx[i+1]))){
               ans+=t.top();
               t.pop();
           } 
        }

        while(!t.empty()){
            ans+=t.top();
            t.pop();
        }

        return ans;
    }
};