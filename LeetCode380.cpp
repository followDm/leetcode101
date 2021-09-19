#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> m;

public:
    RandomizedSet() {}
    bool insert(int val) {
        if (m.count(val)) return false;
        nums.push_back(val);
        m[val] = nums.size() - 1;
        return true;
    }
    bool remove(int val) {
        if (!m.count(val)) return false;
        int last = nums.back();
        m[last] = m[val];
        nums[m[val]] = last;
        nums.pop_back();
        m.erase(val);
        return true;
    }
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

int main(){
    RandomizedSet obj = RandomizedSet();
    for(int i = 0; i < 15; i++ ){
        obj.insert(i);
    }
    cout << obj.getRandom();
    return 0;
}
