class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& x) {
        if(intervals.empty()){
            intervals.push_back(x);
            return intervals;
        }
        int n = intervals.size();
        int ind = n;
        for(int i=0;i<n;i++){
            if(intervals[i][0]>x[0]){
                ind = i-1;
                break;
            }
        }
        if(ind==n){
            if(intervals[n-1][1]>=x[0]){
                intervals[n-1][1] = max(intervals[n-1][1],x[1]);
            }
            else{
                intervals.push_back(x);
            }
            return intervals;
        }
        vector<vector<int>> ans;
        int start,end;
        if(ind==-1){
            start = x[0],end = x[1];
            ind = 0;
            while(ind<n && end>=intervals[ind][0]){
                end = max(end,intervals[ind][1]);
                ind++;
            }
            ans.push_back({start,end});
            while(ind<n){
                ans.push_back({intervals[ind][0],intervals[ind][1]});
                ind++;
            }
        }  
        else{
            for(int i=0;i<ind;i++) ans.push_back({intervals[i][0],intervals[i][1]});
            start = intervals[ind][0];
            end = intervals[ind][1];
            if(end>=x[0]){
                end = max(end,x[1]);
                // cout<<ind<<end<<"df\n";
            }
            else{
                ans.push_back({start,end});
                start = x[0];
                end = x[1];
            }
            ind++;
            // cout<<start<<" "<<end<<"\n";
            while(ind<n && end>=intervals[ind][0]){
                end = max(end,intervals[ind][1]);
                ind++;
            }
            ans.push_back({start,end});
            while(ind<n){
                ans.push_back({intervals[ind][0],intervals[ind][1]});
                ind++;
            }
        }
        return ans;
    }
};