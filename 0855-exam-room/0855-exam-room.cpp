class ExamRoom {
public:
    int n;
    vector<int> v;
    ExamRoom(int x) {
        n = x;
    }

    int seat() {
        if(v.empty()){
            v.push_back(0);
            return 0;
        }
        int d = max(v[0],n-1-v[v.size()-1]);
        for(int i=0;i<v.size()-1;i++){
            d = max(d,(v[i+1]-v[i])/2);
        }
        if(d==v[0]){
            v.insert(v.begin(),0);
            return 0;
        }
        for(int i=0;i<v.size()-1;i++){
            if(d==((v[i+1]-v[i])/2)){
                v.insert(v.begin()+i+1,(v[i+1]+v[i])/2);
                return v[i+1];
            }
        }
        // n-1
        v.push_back(n-1);
        return n-1;
    }

    
    void leave(int p) {
        auto it = find(v.begin(),v.end(),p);
        if(it!=v.end()) v.erase(it);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */