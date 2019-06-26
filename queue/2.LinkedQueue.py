"""
    1. 链表头结点可以插入删除，尾节点只能插入，所以让头结点作为队头，尾节点作为队尾
    2. 链表需要维护一个头结点和一个尾节点，头结点负责删除，尾节点负责插入
    3. 可以从插入第一个节点开始思考
"""

class LinkedQueue:
    class Node:
        def __init__(self, e, next):
            self.element = e
            self.next = next
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0
    def __len__(self):
        return self.size
    def is_empty(self):
        return self.size == 0
    def first(self):
        if self.is_empty():
            print("Queue is empty.")
            return
        return self.head.element
    def enqueue(self, e):
        newnode = self.Node(e, None)
        if self.is_empty():
            self.head = newnode
        else:
            self.tail.next = newnode
        self.tail = newnode
        self.size += 1
    def dequeue(self):
        if self.is_empty():
            print("Queue is empty.")
            return
        answer = self.head.element
        self.head = self.head.next
        self.size -= 1
        if self.is_empty():
            self.tail = None
        return answer
