class MyCalendar {
public:
    vector<vector<int>> v;
    MyCalendar() {
        // v.resize(0);
    }
    
    bool book(int start, int end) {
        for(auto it: v){
            if(max(it[0],start)<min(it[1],end)) return false;
        }
        v.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */