/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    queue<int> q;
    void solve(vector<NestedInteger> &nestedList)
    {
        int n= nestedList.size();
        for(int i=0;i<n;i++)
        {
            NestedInteger x= nestedList[i];
            if(x.isInteger())
                q.push(x.getInteger());
            else solve(x.getList());
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        solve(nestedList);
    }
    
    int next() {
        int v= q.front();
        q.pop();
        return v;
        
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */