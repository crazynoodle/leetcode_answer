 /*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
  *
  *  push(x) -- Push element x onto stack.
  *  pop() -- Removes the element on top of the stack.
  *  top() -- Get the top element.
  *  getMin() -- Retrieve the minimum element in the stack.
  */

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        vector<int> a;
        _stack.swap(a);
        _min.swap(a);
        size = 0;
    }
    
    void push(int x) {
        _stack.push_back(x);
        if(size == 0 || x < _min[size-1])
            _min.push_back(x);
        else
            _min.push_back(_min[size-1]);
            
        size++;
    }
    
    void pop() {
        if(size>0){
            _stack.erase(_stack.begin()+size-1);
            _min.erase(_min.begin()+size-1);
            size--;
        }
    }
    
    int top() {
        if(size > 0)
            return _stack[size-1];
        else
            return -1;
    }
    
    int getMin() {
        if(size>0)
            return _min[size-1];
        else
            return -1;
    }
private:
    vector<int> _stack;
    vector<int> _min;
    int size;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
