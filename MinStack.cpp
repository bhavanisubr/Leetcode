/**
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack. 
*/

class MinStack {
public:
  stack<int> myStack;
  deque<int> minStack;
  
  void push(int x) {
    myStack.push(x);
    if (minStack.empty() || x <= minStack.front())  minStack.push_front(x);
    else if (x > minStack.front())  minStack.push_back(x);
  }
  
  void pop() {
    if (!myStack.empty()) {
      int top = myStack.top();
      if (minStack.front() == top)  minStack.pop_front();
      else if (minStack.back() == top)  minStack.pop_back();
    }
    myStack.pop();
  }
  
  int top() {
    return (!myStack.empty() ? myStack.top() : INT_MAX);
  }
  
  int getMin() {
    return (!minStack.empty() ? minStack.front() : INT_MAX);
  }
};