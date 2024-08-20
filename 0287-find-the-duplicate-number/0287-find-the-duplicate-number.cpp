class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int m = a.size();
        vector<int> v(m);
        for(int val: a) v[val]++;
        for(int i=0;i<m;i++){
            if(v[i]>1) return i;
        }
        return -1;
    }
};