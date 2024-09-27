class Node{
    public:
    int first;
    int second;
    Node *left;
    Node *right;
    Node(int start, int end){
        first = start;
        second = end;

        left = NULL;
        right = NULL;
    }
};

class MyCalendar {
public:
    Node* root;

    MyCalendar() {
        root = NULL;
    }

    bool insertIntoBST(Node* &root, int start, int end){
        if(root == NULL){
            root = new Node(start, end);
            // By default left and right are NULL.
            return true;
        }

        // If we have (15,25) and we hit a node (10,20), we should not insert.
        if( !(start >= root->second or end <= root->first) ) return false;

        if(start >= root->second){
            // start >= t.second by default means start > t.first as start < end always.
            // So, insertion should be in the right if possible.
            return insertIntoBST(root->right, start, end);
        }

        if(end <= root->first){
            return insertIntoBST(root->left, start, end);
        }

        // By keep on doing above recursion we will reach leaf i.e., root == NULL
        // and will insert. If nodes are not given in already sorted order, then
        // chance of getting a skewed tree is less likely. Ex. (10,20), (20,30),
        // (30,40) will give Righr Skewed tree.
        return false; // Dummy.
    }
    
    bool book(int start, int end) {
        // Given a meeting, we need to check what is the
        // end time of last meeting and start time of the next meeting.
        // Say we have [15,25]. So, check if all the meetings are having
        // end time <= 15 and all meetings have start time >= 25. In such
        // case only we can successfully book this meeting.

        // Brute Force is O(N^2). Even if we use Binary Search + Insertion
        // Sort logic: It is O(N^2). We may think to use LL, but search is O(N).
        // So, a great way is to use BBST. But its very complicated, so use
        // BST only. (Although in worst case insertion is O(N) in a skewed tree).

        return insertIntoBST(root, start, end);

        // Node *parent = NULL;
        // Node *t = root;
        // while(t != NULL){
        //     if(start < t.second or end > t.first) return false; // We can't add it.
        //     parent = t;
        //     if(start >= t.second) t = t->right; // Need to check the right part.
        //     if(end <= t.first) t = t->left;
        // }

        // // We are 

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */