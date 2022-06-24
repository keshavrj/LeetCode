class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum= accumulate(target.begin(), target.end(), 0LL);
        for(int i:target)
            pq.push(i);
        
        while(pq.top()!=1){
            int x= pq.top(); pq.pop();
            sum-=x;
            if(x<=sum || sum<1)
                return false;
                
            x%=sum;
            if(sum!=1 && x==0)return false;
            pq.push(x);
            sum+=x;
        }
        return true;
    }
};