class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int summ = 0;
        for(int i = 0; i < gas.size(); i++){
            summ += gas[i]-cost[i];
        }
        if(summ < 0) return -1;
        
        int current = 0;
        int start = 0;

        for(int i = 0; i < gas.size(); i++){
            current += gas[i] - cost[i];
            if(current < 0){
                start = i+1;
                current = 0;
            }
        }

        return start;
    }
};