class Solution {
public:

    pair<int,string> solve(string& s, string x, int score){
         int len=s.length();

         stack<char> st;

         int ans=0;

         for(int i=0; i<len;i++){
            char ch=s[i];
            if(ch==x[1] && (!st.empty() && st.top()==x[0])){
                 ans+=score;
                 st.pop();
            }else{
                st.push(ch);
            }
         }

          string t="";
          while(!st.empty()){
            t+=st.top();
            st.pop();
          }

          reverse(t.begin(),t.end());

         return {ans,t};
    }
    int maximumGain(string s, int x, int y) {
          int maxx=max(x,y);
          int mini=min(x,y);
           
           string first,second;

          if(maxx==x){
               first="ab";
               second="ba";
          }else{
                first="ba";
                second="ab";
          }

          int score=0;
          auto [val1,rem]=solve(s, first, maxx);
          auto [val2,temp]=solve(rem,second,mini);
          score+=val1;
          score+=val2;

          return score;
    }
};