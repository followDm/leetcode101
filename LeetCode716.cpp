#include<stack>
#include<iostream>
using namespace std;

class MaxStack {
    stack<int> x_stack;
    stack<int> max_stack;
public:
    MaxStack() {
    }
    
    void push(int x) {
        int max = max_stack.empty() ? x : max_stack.top();
        max_stack.push(max > x ? max : x);
        x_stack.push(x);
    }
    
    void pop() {
        max_stack.pop();
        x_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int peekMax() {
        return max_stack.top();
    }

    void popMax(){
        // stack<int> buff;
        // while(top() != max){
        //     buff.push(top());
        //     pop();
        // }
        // pop();
        // while (!buff.empty()){
        //     push(buff.top());
        //     buff.pop();
        // }
        max_stack.pop();
        x_stack.pop();
    }
};
int main(){
    int t = 0, n = 0;
    MaxStack maxStack = MaxStack();
    cout << "number of nums: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        maxStack.push(t);
    }
    cout << maxStack.peekMax();
    maxStack.popMax();
    return 0;
}
// number of nums: 4
// 3 2 1 4
// 4