class LinkedStack:
    # ------------定义一个节点类---------------
    class Node:
        __slots__ = 'element', 'next'  # 该变量限定成员变量的定义
        def __init__(self, element, next):
           self.element = element
           self.next = next
    # ------------定义一个节点类---------------

    def __init__(self):
        self.head = None
        self.size = 0
    def __len__(self):
        return self.size
    def is_empty(self):
        return self.size == 0
    def push(self, element):
        self.head = self.Node(element, self.head)
        self.size += 1
    def top(self):
        if self.is_empty():
            print("Stack is empty.")
            return
        return self.head.element
    def pop(self):
        if self.is_empty():
            print("Stack is empty.")
            return
        answer = self.head.element
        self.head = self.head.next
        self.size -= 1
        return answer

if __name__ == "__main__":
    S = LinkStack()
    S.pop()
    S.push(10)
    S.push(20)
    len(S)
    print(S.top())
    print(S.pop())
    print(S.top())
