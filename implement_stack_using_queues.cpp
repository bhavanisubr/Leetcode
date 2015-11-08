/**
 * Implement the following operations of a stack using queues.
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 * 
 * Notes:
 * You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and 
 * is empty operations are valid.Depending on your language, queue may not be supported natively. You may simulate a 
 * queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
 * 
 * You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 */

class Stack {
public:
  queue<int> queue1, queue2;
  // Push element x onto stack.
  void push(int x) {
    queue1.push(x);
  }

  // Removes the element on top of the stack.
  void pop() {
    while (queue1.size() > 1) {
      int front = queue1.front();
      queue2.push(front);
      queue1.pop();
    }
    queue1.pop();
    while (!queue2.empty()) {
      int front = queue2.front();
      queue1.push(front);
      queue2.pop();
    }
  }

  // Get the top element.
  int top() {
    return queue1.back();
  }

  // Return whether the stack is empty.
  bool empty() {
    return (queue1.empty() && queue2.empty());
  }
};
