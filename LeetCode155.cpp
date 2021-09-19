#include<stack>
#include<iostream>
using namespace std;

class MinStack {
    stack<int> x_stack;
    stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int x) {
        x_stack.push(x);
        min_stack.push(min(min_stack.top(), x));
    }
    
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
int main(){
    int t = 0, n = 0;
    MinStack minStack = MinStack();
    cout << "number of nums: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        minStack.push(t);
    }
    cout << minStack.top();
    minStack.pop();
    cout << minStack.getMin();
    return 0;
}
// number of nums: 4
// 1 2 3 4
// 4
// 1