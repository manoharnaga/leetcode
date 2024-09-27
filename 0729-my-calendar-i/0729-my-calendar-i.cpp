class MyCalendar {
public:
    map<int,int> mp;
    MyCalendar() {
        mp.clear();
    }
    
    bool book(int start, int end) {
        end--;
        if(mp.empty()){
            mp[start] = end;
            return true;
        }
        auto it = mp.lower_bound(end);
        if(it==mp.begin()){
            if(max(start,it->first)<=min(end,it->second)) return false;
        }
        else if(it==mp.end()){
            it--;
            if(max(start,it->first)<=min(end,it->second)) return false;
        }
        else{
            if(max(start,it->first)<=min(end,it->second)) return false;
            it--;
            if(max(start,it->first)<=min(end,it->second)) return false;
        }
        mp[start] = end;
        return true;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */