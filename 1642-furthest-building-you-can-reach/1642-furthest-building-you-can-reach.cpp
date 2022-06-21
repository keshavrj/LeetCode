class Solution {
public:
    int furthestBuilding(vector<int>& arr, int bricks, int ladders) {
        priority_queue<int, vector<int> , greater<int>> pq;
        for(int i=0;i<arr.size()-1;i++){
            int diff=arr[i+1]-arr[i];
            if(diff>0){
            pq.push(diff);
                if(pq.size()>ladders){
                    bricks-=pq.top();
                    pq.pop();
                    if(bricks<0)return i;
                }
            }
        }
        return arr.size()-1;

    }
};