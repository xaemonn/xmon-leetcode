class MyCalendar {
public:
    set<pair<int,int>> st;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        if(st.empty()){
            st.insert({startTime,endTime});
            return true;
        }

        for(auto it:st){
            int s=it.first;
            int e=it.second;
            if(endTime>s && startTime<e){
                return false;
            }
        }

        st.insert({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */