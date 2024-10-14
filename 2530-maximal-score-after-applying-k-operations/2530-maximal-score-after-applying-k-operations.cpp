class Solution {
public:
    typedef long long ll;
    long long maxKelements(vector<int>& a, int k) {
        priority_queue<int> pq;
        for(int val: a) pq.push(val);
        ll res = 0;
        for(int i=0;i<k;i++){
            ll top = pq.top();
            pq.pop();
            res += top;
            top = ceil(top/3.0);
            pq.push(top);
        }
        return res;
    }
};