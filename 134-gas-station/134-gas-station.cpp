class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tot_cost = 0;
        
        int start_index=0, curr_cost=0;
        for(int i=0;i<cost.size();i++)
        {
            
            tot_cost+= gas[i]-cost[i] ;// sum of cost must be <= total gas;
            curr_cost+= gas[i]-cost[i];
            if(curr_cost<0)
                curr_cost=0, start_index= i+1;// we are exhausted so we can't start before it;
        }
        if(tot_cost<0)return -1;
        return start_index;
    }
};