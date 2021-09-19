#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;

class AllOne {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int> nummap;      /*保存所有key-value*/
    list<string> keylist;                   /*双向链表存储所有key 用于取最大最小值 front存最大 back存最小*/
    AllOne() {

    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(nummap.find(key) == nummap.end()){
            keylist.push_back(key);
            nummap[key] = 1;
        }else{
            nummap[key] += 1;
            if(nummap[key] >= nummap[keylist.front()]){
                keylist.remove(key);
                keylist.push_front(key);
            }else if(key == keylist.back()){
                keylist.pop_back();
                if(nummap[key] > nummap[keylist.back()]){
                    list<string>::iterator it = keylist.end();
                    --it;
                    keylist.insert(it, key);
                }else
                    keylist.push_back(key);
            }
        }  
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(nummap.find(key) == nummap.end())
            return;
        if(nummap[key] == 1){
            nummap.erase(key);
            keylist.remove(key);
        }else{
            nummap[key] -= 1;
            if(nummap[key] < nummap[keylist.back()]){
                keylist.remove(key);
                keylist.push_back(key);
            }else if(key == keylist.front()){
                keylist.pop_front();
                if(nummap[key] < nummap[keylist.front()]){
                    list<string>::iterator it = keylist.begin();
                    ++it;
                    keylist.insert(it, key);
                }else
                    keylist.push_front(key);
            }
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(keylist.empty())
            return "";
        else 
            return keylist.front(); 
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(keylist.empty())
            return "";
        else 
            return keylist.back();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */

int main(){
    AllOne obj = AllOne();
    obj.inc("world");
    obj.inc("hello");
    cout << obj.getMaxKey();
    return 0;
}