class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_cost = 0;
        int total_gas = 0;
        int cur_gas = 0;
        int start = 0;
        for(int i=0;i<n;i++){
            total_cost += cost[i];
            total_gas += gas[i];
            cur_gas += (gas[i]-cost[i]);
            if(cur_gas<0){
                start = i+1;
                cur_gas = 0;
            }
        }
        return (total_gas>=total_cost ? start: -1);
    }
};