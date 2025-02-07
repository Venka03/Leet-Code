class Stack:
    def __init__(self):
        self.__stack = []
        self.__size = 0

    def push(self, element):
        self.__stack.append(element)
        self.__size += 1

    def pop(self):
        if self.isEmpty():
            raise "Stack is empty"
        element = self.__stack[-1]
        del self.__stack[-1]
        self.__size -= 1
        return element

    def top(self):
        if self.isEmpty():
            raise "Stack is empty"
        element = self.__stack[-1]
        return element

    def isEmpty(self):
        return not self.__size

class Solution:
    @classmethod
    def isValid(self, s: str) -> bool:
        st = Stack()
        while len(s):
            el = s[0]
            s = s[1:]
            if el in ["(", "[", "{"]:
                st.push(el)
            else:
                if st.isEmpty():
                    return False
                if el == "]" and st.top() == "[":
                    st.pop()
                elif el == ")" and st.top() == "(":
                    st.pop()
                elif el == "}" and st.top() == "{":
                    st.pop()
                elif st.top() in ["(", "[", "{"]:  # one parenthesis are closed before other
                    return False
        return st.isEmpty()


print(Solution.isValid("()"))
print(Solution.isValid("()[]{}"))
print(Solution.isValid("(]"))
