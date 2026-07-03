#stack

class MyQueue:

    def __init__(self):
        self.input = []
        self.output = []
        
    def push(self, x: int) -> None:
        #push to back of queue
        self.input.append(x)

    def pop(self) -> int:
        #remove element from front of queue, return it 
        #transfer from input to output
        self.peek()
        return self.output.pop()
        
    def peek(self) -> int:
        #return element at front
        #if output stack is empty transfer all elements from input to output
        if not self.output: 
            while self.input: 
                self.output.append(self.input.pop())
        return self.output[-1]

    def empty(self) -> bool:
        #true if empty (input and output)
        return not self.input and not self.output
        
# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()