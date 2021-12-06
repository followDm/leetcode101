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
    // cout << "number of nums: ";
    // cin >> n;
    for (int i = 1; i <= 4; i++){
        // cin >> t;
        minStack.push(5-i);
    }
    cout << minStack.top();
    minStack.pop();
    cout << minStack.getMin();
    return 0;
}
/*设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-stack
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// number of nums: 4
// 1 2 3 4
// 4
// 1