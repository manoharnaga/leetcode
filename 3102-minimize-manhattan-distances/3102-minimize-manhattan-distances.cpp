class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        auto [_,i,j] = maxDist(points);
        return min(maxDist(points,i)[0],maxDist(points,j)[0]);
    }
    
    array<long long, 3> maxDist(vector<vector<int>>& ps,int skip=-1){
        int n = ps.size();
        int sum[2] = {INT_MAX,INT_MIN},sum_i[2] = {0,0};
        int diff[2] = {INT_MAX,INT_MIN},diff_i[2] = {0,0};
        for(int i=0;i<n;i++){
            if(i==skip) continue;
            if(sum[0]>(ps[i][0]+ps[i][1])){
                sum[0] = ps[i][0]+ps[i][1];
                sum_i[0] = i;
            }
            if(sum[1]<(ps[i][0]+ps[i][1])){
                sum[1] = ps[i][0]+ps[i][1];
                sum_i[1] = i;
            }
            if(diff[0]>(ps[i][0]-ps[i][1])){
                diff[0] = ps[i][0]-ps[i][1];
                diff_i[0] = i;
            }
            if(diff[1]<(ps[i][0]-ps[i][1])){
                diff[1] = ps[i][0]-ps[i][1];
                diff_i[1] = i;
            }
        }
        if((sum[1]-sum[0])>(diff[1]-diff[0])){
            return {sum[1]-sum[0],sum_i[0],sum_i[1]};
        }
        return {diff[1]-diff[0],diff_i[0],diff_i[1]};
    }
};
