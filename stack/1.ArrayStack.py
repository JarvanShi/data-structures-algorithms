"""
抽象数据类型：
    1. 数据对象集
    2. 操作集
栈：插入和删除操作遵循后进先出（LIFO），且只能在一端操作
栈的操作集：
    1. 入栈
    2. 出栈
    3. 是否为空
    4. 栈顶元素
    5. 栈中元素的数量
"""

# 基于python列表的栈实现
class ArrayStack:
   def __init__(self):
        self.data = []
    def __len__(self):
        return len(self.data)
    def is_empty(self):
        return len(self.data) == 0
    def top(self):
        if self.is_empty():
            raise Empty("Stack is empty")
        return self.data[-1]
    def push(self, element):
        self.data.append(element)
    def pop(self):
        if self.is_empty():
            raise Empty("Stack is empty")
        return self.data.pop()

if __name__ == "__main__":
    S = ArrayStack()
    S.push(5)            # [5]
    S.push(3)            # [5, 3]
    print(len(S))        # 2
    print(S.pop())       # 3
    print(S.is_empty())  # False
    S.push(7)            # [5, 7]
    print(S.top())       # 7
