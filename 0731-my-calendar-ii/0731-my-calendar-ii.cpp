class MyCalendarTwo {
public:
    vector<vector<int>> v,temp;
    MyCalendarTwo() {
        // nothing
    }
    
    bool book(int start, int end) {
        if(v.size()<=1){
            v.push_back({start,end});
            return true;
        }
        vector<int> l,r;
        l.push_back(start);
        r.push_back(end);
        for(auto it: v){
            l.push_back(it[0]);
            r.push_back(it[1]);
        }
        sort(l.begin(),l.end());
        sort(r.begin(),r.end());
        // for(auto it: l) cout<<it<<" ";
        // cout<<"\n";
        // for(auto it: r) cout<<it<<" ";
        // cout<<"\n";
        int cnt = 0;
        int i=0,j=0;
        while(i<l.size() && j<l.size()){
            if(l[i]<r[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            if(cnt>2) return false;
        }
        // cout<<cnt<<"\n";
        v.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */