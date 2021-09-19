#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class MyStack {
public:
    queue<int> q;

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int r = q.front();
        q.pop();
        return r;
    }
    
    /** Get the top element. */
    int top() {
        int r = q.front();
        return r;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

int main(){
    int n = 0, t = 0, target;
    MyStack myStack = MyStack();
    cout << "number of nums: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        myStack.push(t);
    }
        
    myStack.top(); // 返回 2
    myStack.pop(); // 返回 2
    cout << boolalpha << myStack.empty();
    return 0;
}
// number of nums: 4
// 1 2 3 4
// false