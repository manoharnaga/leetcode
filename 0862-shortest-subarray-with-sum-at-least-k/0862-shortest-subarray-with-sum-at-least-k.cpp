class Solution {
public:
    typedef long long ll;
    int shortestSubarray(vector<int>& a, int k) {
        int n = a.size();int res = n+1;
        vector<ll> p(n);
        for(int i=0;i<n;i++)p[i]=a[i];
        deque<int> d;
        for(int i=0;i<n;i++){
            if(i>0) p[i]+=p[i-1];
            if(p[i]>=k) res = min(res,i+1);
            while(!d.empty() && (p[i]-p[d.front()])>=k){
                res = min(res,i-d.front());d.pop_front();
            }
            while(!d.empty() && p[i]<=p[d.back()]) d.pop_back();
            // cout<<d.front()<<" "<<p[i]<<"\n";
            d.push_back(i);
        }
        return (res>n ? -1:res);
    }
};