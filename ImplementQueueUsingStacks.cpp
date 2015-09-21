class Queue {
public:
    stack<int> stack1, stack2;
    // Push element x to the back of queue.
    void push(int x) {
       stack1.push(x);
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
       while (!stack1.empty()) {
          int top = stack1.top();
          stack2.push(top);
          stack1.pop();
       }
       stack2.pop();
       while (!stack2.empty()) {
          int top = stack2.top();
          stack1.push(top);
          stack2.pop();
       }
    }

    // Get the front element.
    int peek(void) {
       while (!stack1.empty()) {
          int top = stack1.top();
          stack2.push(top);
          stack1.pop();
       }
       int returnValue = stack2.top();
       while (!stack2.empty()) {
          int top = stack2.top();
          stack1.push(top);
          stack2.pop();
       }
       return returnValue;
    }

    // Return whether the queue is empty.
    bool empty(void) {
       return stack1.empty();
    }
};
