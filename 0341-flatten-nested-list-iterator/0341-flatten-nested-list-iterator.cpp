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

private:

    void dfs(vector<NestedInteger> &nestedList, int n, int i, vector<int> &res){
        if(i == n) return;

        cout << "here " << i << endl;

        NestedInteger nestedListItem = nestedList[i];
        if(nestedListItem.isInteger()){
            // So, it is an integer.
            res.push_back(nestedListItem.getInteger());
        }else{
            // So, it is another list.
            vector<NestedInteger> newList = nestedListItem.getList();
            dfs(newList, newList.size(), 0, res);
        }

        dfs(nestedList, n, i + 1, res);

    }

public:
    vector<int> res;
    int pointer;

    NestedIterator(vector<NestedInteger> &nestedList) {
        pointer = 0;
        int n = nestedList.size();
        int i = 0;

        dfs(nestedList, n, i, res);
        cout << " done " << endl;
    }
    
    int next() {
        // return 0;
        return res[pointer++];
    }
    
    bool hasNext() {
        // return false;
        return pointer < res.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */