#include<stack>
#include<iostream>
using namespace std;

class MyQueue {
private:
    stack<int> inStack, outStack;

    void in2out() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        if (outStack.empty()) {
            in2out();
        }
        int x = outStack.top();
        outStack.pop();
        return x;
    }

    int peek() {
        if (outStack.empty()) {
            in2out();
        }
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
int main(){
    int t = 0, n = 0;
    MyQueue myQueue = MyQueue();
    cout << "number of nums: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        myQueue.push(t);
    }
        
    myQueue.peek(); // 返回 2
    myQueue.pop(); // 返回 2
    cout << boolalpha << myQueue.empty();
    return 0;
}
// number of nums: 4
// 1 2 3 4
// false