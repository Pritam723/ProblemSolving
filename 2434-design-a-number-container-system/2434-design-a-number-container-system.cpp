class NumberContainers {
public:
    map<int, int> mp1;
    map<int, set<int>> mp2;

    NumberContainers() {

    }
    
    void change(int index, int number) {
        if(mp1.find(index) == mp1.end()){
            mp1[index] = number;
            mp2[number].insert(index);
        }else{
            int oldNum = mp1[index];
            mp1[index] = number;

            auto it = mp2[oldNum].find(index);
            mp2[oldNum].erase(it);
            mp2[number].insert(index);
        }
    }
    
    int find(int number) {
        if(mp2.find(number) == mp2.end() or mp2[number].empty()) return -1;
        return *(mp2[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */