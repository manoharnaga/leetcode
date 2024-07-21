class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> v(n,0);
        vector<long long> a(n,0);
        sort(meetings.begin(),meetings.end());
        for(auto it:meetings){
            int start = it[0];
            int end = it[1];
            int f = 0;
            for(int j=0;j<n;j++){ // first available room
                if(a[j]<=start){
                    a[j] = end;
                    v[j]++;
                    f=1;
                    break;
                }
            }
            if(f) continue;
            int k = 0;
            for(int j=0;j<n;j++){
                if(a[k]>a[j]) k=j;
            }
            a[k] += (end-start);
            v[k]++;
        }
        int idx = max_element(v.begin(),v.end())-v.begin();
        return idx;
    }
};