class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        stack<int> st;

        st.push(-1);
        int area=0;

        for(int i=0; i<n;i++){
              while(st.top()!=-1 && heights[i]<=heights[st.top()]){
                    int idx=st.top();
                    st.pop();
                     
                    int h=heights[idx];
                    int w=i-st.top()-1;
                    area=max(area, h*w);

              }
              st.push(i);
        }

        while(st.top()!=-1){
            int idx=st.top();
            st.pop();
            int h=heights[idx];
            int w=n-st.top()-1;
            area=max(area,h*w);
        }

        return area;
    }
};