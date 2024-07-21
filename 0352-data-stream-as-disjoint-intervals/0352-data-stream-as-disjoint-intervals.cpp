class SummaryRanges {
    set<int> st;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> v;
        if(st.empty()) return v;
        int left = -1,right = -1;
        for(int val: st){
            if(left<0){
                left = right = val;
            }
            else if(val == right+1) right = val;
            else{
                v.push_back({left,right});
                left = right = val;
            }
        }
        v.push_back({left,right});
        return v;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */