#ifndef STACK_HPP
#define STACK_HPP

#include "stack.h"
#include <stack>
#include <cctype>

namespace cop4530 {

    template <typename T>
    Stack<T>::Stack() {
        data = std::stack<T>();
    }

    template <typename T>
    Stack<T>::~Stack() {
        clear();
    }

    template <typename T>
    Stack<T>::Stack(const Stack<T>& other) {
        std::stack<T> tempStack = other.data;
        while (!tempStack.empty()) {
            data.push(tempStack.top());
            tempStack.pop();
        }
    }



    template <typename T>
    Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
        if (this != &other) {

            clear();


            std::stack<T> tempStack = other.data;
            while (!tempStack.empty()) {
                data.push(tempStack.top());
                tempStack.pop();
            }
        }
        return *this;
    }

    template <typename T>
    Stack<T>& Stack<T>::operator=(Stack<T>&& other) noexcept {
        if (this != &other) {

            data = std::move(other.data);
        }
        return *this;
    }

    template <typename T>
    bool Stack<T>::empty() {
        return data.empty();
    }


    template <typename T>
    void Stack<T>::clear() {
        while (!data.empty()) {
            data.pop();
        }
    }


    template <typename T>
    void Stack<T>::push(const T& x) {
        data.push(x);
    }




    template <typename T>
    void Stack<T>::pop() {
        if (!empty()) {
            data.pop();
        }
    }

    template <typename T>
    T& Stack<T>::top() {
        if (!empty()) {
            return data.top();
        } else {
            throw std::out_of_range("Stack is empty");
        }
    }




    template <typename T>
    void Stack<T>::print(std::ostream& os, char ofc) const {
        std::stack<T> tempStack = data;
        while (!tempStack.empty()) {
            os << tempStack.top() << ofc;
            tempStack.pop();
        }
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Stack<T>& a) {
        a.print(os);
        return os;
    }

    template <typename T>
    bool operator==(const Stack<T>& lhs, const Stack<T>& rhs) {
        // Compare the size of the stacks first
        if (lhs.size() != rhs.size()) {
            return false;
        }

        // Iterate through each element of both stacks and compare them
        auto it_lhs = lhs.data.begin();
        auto it_rhs = rhs.data.begin();
        while (it_lhs != lhs.data.end() && it_rhs != rhs.data.end()) {
            if (*it_lhs != *it_rhs) {
                return false; // Elements are different, stacks are not equal
            }
            ++it_lhs;
            ++it_rhs;
        }

        // If we reach here, all elements are equal
        return true;
    }
    template <typename T>
    std::ostream& cop4530::Stack<T>::operator<<(std::ostream& os) const {
        std::stack<T> tempStack = data;
        while (!tempStack.empty()) {
            os << tempStack.top() << " ";
            tempStack.pop();
        }
        return os;
    }


    template <typename T>
    bool cop4530::Stack<T>::operator!=(const Stack<T>& rhs) const {
        return !(*this == rhs);
    }

    template <typename T>
    bool cop4530::Stack<T>::operator==(const Stack<T>& rhs) const {
        if (size() != rhs.size()) {
            return false;
        }

        std::stack<T> temp1 = data;
        std::stack<T> temp2 = rhs.data;

        while (!temp1.empty()) {
            if (temp1.top() != temp2.top()) {
                return false;
            }
            temp1.pop();
            temp2.pop();
        }

        return true;
    }

    template <typename T>
    bool cop4530::Stack<T>::operator<=(const Stack<T>& rhs) const {
        std::stack<T> temp1 = data;
        std::stack<T> temp2 = rhs.data;

        while (!temp1.empty() && !temp2.empty()) {
            if (temp1.top() > temp2.top()) {
                return false;
            }
            temp1.pop();
            temp2.pop();
        }

        return temp1.empty() || (!temp2.empty() && temp1.top() <= temp2.top());
    }

    template <typename T>
    int Stack<T>::size() const {
        return data.size(); // Implementation of size function
    }

}

#endif
