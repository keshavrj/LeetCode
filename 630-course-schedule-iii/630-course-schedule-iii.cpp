class Solution {
public:
    int scheduleCourse(vector<vector<int>>& arr) {
    sort(arr.begin(), arr.end(), [](vector<int>&a, vector<int> &b){return a[1]<b[1];});
    priority_queue<int> pq;
    int time_taken=0;
    for(int i=0;i<arr.size();i++){
        int dur=arr[i][0], end= arr[i][1];
        if(time_taken+dur<=end){
            pq.push(dur);
            time_taken+=dur;
        }
        else if(!pq.empty() && pq.top()>dur){
            time_taken = time_taken - pq.top() + dur;
            pq.pop();
            pq.push(dur);
        }
    }    
    return pq.size();
    
    }
};