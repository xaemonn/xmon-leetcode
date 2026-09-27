class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int len = s.length();
        for(int i=0; i<len; i++){
            if(s[i] == ')'){
               string temp = "";
               while(st.top()!='('){
                temp += st.top();
                st.pop();
               }
               st.pop();
               for(int j=0; j<temp.length(); j++){
                st.push(temp[j]);
               }
            }
            else{
                st.push(s[i]);
            }
        }
        
        string temp = "";
        while(!st.empty()){
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};