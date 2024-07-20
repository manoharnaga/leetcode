class MyCalendarTwo {
public:
    // simplest way to find the max no of overlapping interval points in a range from say 0 to n
    map<int,int> mp;
    MyCalendarTwo() {
        // nothing
    }
    
    bool book(int start, int end) {
        mp[start]++; // cnt++ (if start[i]<=end[j])
        mp[end]--;   // cnt-- (else)
        int cnt = 0;
        for(auto it: mp){
            cnt += it.second;
            if(cnt==3){
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */