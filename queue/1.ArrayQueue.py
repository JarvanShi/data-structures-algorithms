"""
队列：插入和删除操作遵循先进先出（FIFO），在队尾插入，在队头删除
队列的操作集：
    1. 队尾插入 
    2. 队头删除 
    3. 是否为空
    4. 队头元素 
    5. 队列中元素的数量
"""

"""
实现队列的两个问题：
    1. 队列满时，扩充底层数组
        创建新的更大的列表，将旧列表的内容复制到新列表，并且索引又开始从0开始
    2. 删除队列元素时，缩减数组
        当队列实际长度小于底层数组的1/4时，也通过新建1/2底层数组大小的列表，将旧列表复制到新列表，索引从0开始
"""

class ArrayQueue:
    DEFAULT_CAPACITY = 10  # 设置底层数组默认长度为10
    def __init__(self):
        self.data = [None] * ArrayQueue.DEFAULT_CAPACITY
        self.size = 0  # 队列实际长度
        self.front = 0  # 队头元素的索引
    def __len__(self):
        return self.size
    def is_empty(self):
        return self.size == 0
    def first(self):
        if self.is_empty():
            print("Queue is empty.")
            return
        return self.data[self.front]
    def dequeue(self):
        if self.is_empty():
            print("Queue is empty.")
            return
        answer = self.data[self.front]
        self.data[self.front] = None  # 让对象的引用计数为0，释放内存空间
        self.front = (self.front + 1) % len(self.data)
        self.size -= 1
        if 0 < self.size < len(self.data) // 4:  # 如果队列太小了，缩减底层数组
            self.resize(len(self.data) // 2)
        return answer
    def enqueue(self, element):
        if self.size == len(self.data):  # 队列存满
            self.resize(2 * len(self.data))  # 将底层数组扩展2倍
        rear = (self.front + self.size) % len(self.data)
        self.data[rear] = element
        self.size += 1
    def resize(self, capacity):
        old = self.data
        self.data = [None] * capacity
        walk = self.front
        for k in range(self.size):
            self.data[k] = old[walk]
            walk = (walk + 1) % len(old)
        self.front = 0

if __name__ == "__main__":
    Q = ArrayQueue()
    Q.enqueue(5)
    Q.enqueue(3)
    print(len(Q))
    print(Q.dequeue())
    print(Q.is_empty())
    print(Q.first())
