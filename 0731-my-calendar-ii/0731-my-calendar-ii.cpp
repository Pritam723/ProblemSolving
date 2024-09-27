class MyCalendarTwo {
    // The thing is. if we have meetings [50,60],[10,40] and then comes [25,55], then we can see
    // that [25,55] is clashing with [50,60] and [10,40], but by the definition of the question,
    // it is not triple booking as we are concerned with the intersecting region only. So, using
    // 2 BSTs is not a correct solution. Rather use 2 lists. list1 will have all the allowed meetings.
    // List 2 will have intersecting regions. Ex. [10,40] and [25,55] has intersection [25,40], so we push
    // this in list2. Now, if a new meeting comes, we check the list2 first whether they are intersecting with
    // any of the existing intersections. Ex. If we get [30-45] meeting, we can't allow it. But if we get [50,60],
    // although it is clashing with [25, 55], it is not a triple booking. Because it is not clashing with [25,40].
    // So, we can add it in list1 and ofcourse we need the add the intersection([25, 55], [50, 60]) = [55,60] in list2.
    // So, T(N) = O(N) for each entry. 
public:
    vector<pair<int, int>> list1;
    vector<pair<int, int>> list2;
    
    MyCalendarTwo() {
        list1 = {};
        list2 = {};
    }
    
    bool book(int start, int end) {
        for(pair<int, int> p : list2){
            if(!(start >= p.second or end <= p.first)){
                return false; 
            }
        }

        // We are here means [start, end] is not causing triple booking.
        // So, now add it in list1. But before that, check what intersection points
        // it is generating & add those in list2.
        for(pair<int, int> p : list1){
            if(!(start >= p.second or end <= p.first)){
                // So, this is causing an intersection.
                // Add the intersection part in list 2.
                // Ex. [10,40] after [25,55] => [max(10,25), min(40,55)] = [25,40]
                // Ex. Ex. [25,55] after [10,40] => [max(10,25), min(40,55)] = [25,40]
                // So, both cases are same.
                int intersectionStart = max(p.first,start); 
                int intersectionEnd = min(p.second,end);
                list2.push_back({intersectionStart, intersectionEnd});
            }
        }

        list1.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */