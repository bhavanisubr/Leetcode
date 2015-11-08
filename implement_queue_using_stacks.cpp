/**
 * Implement the following operations of a queue using stacks.
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.
 * 
 * Notes:
 * You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, 
 * and is empty operations are valid. Depending on your language, stack may not be supported natively. You may 
 * simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations 
 * of a stack. You may assume that all operations are valid (for example, no pop or peek operations will be called 
 * on an empty queue).
 */
 
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