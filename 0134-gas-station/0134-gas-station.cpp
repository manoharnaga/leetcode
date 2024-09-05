class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0;
        int total_gas = 0;
        int total_cost = 0;
        int left_gas = 0;
        for(int i=0;i<n;i++){
            total_gas += gas[i];
            total_cost += cost[i];
            left_gas += (gas[i]-cost[i]);
            if(left_gas<0){
                start = i+1;
                left_gas = 0;
            }
        }
        return (total_gas>=total_cost ? start: -1);
    }
};