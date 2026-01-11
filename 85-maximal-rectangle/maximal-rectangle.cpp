class Solution {
public:
    int area(vector<int>& ht){
        //largest rect in histogram code
        int n=ht.size();
        stack<int> st;
        int maxx=0;

        for(int i=0; i<=n ;i++){
             int h=0;
             if(i!=n){
                h=ht[i];
             }

             while(!st.empty() && h< ht[st.top()]){
                int height=ht[st.top()];
                st.pop();
                int width=st.empty()? i : i-st.top()-1;
                maxx=max(maxx,height*width);
             }
             st.push(i);

        }

        return maxx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
           int n=matrix.size();
           int m=matrix[0].size();

           vector<int> hist(m,0); //columns
            
           int ans=0;
           for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='1'){
                    hist[j]++;
                }else{
                    hist[j]=0;
                }
            }
            ans=max(ans,area(hist));
           }


           return ans;
              
              
              
    }
};