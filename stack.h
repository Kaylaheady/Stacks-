#ifndef STACK_H
#define STACK_H


#include <iostream>
#include <cctype>
#include <stack>

namespace cop4530 {

    template <typename T>
    class Stack {
    private:
        std::stack<T> data;

    public:
        Stack();
        ~Stack();
        Stack(const Stack<T>& other);
        Stack<T>& operator=(const Stack<T>&);
        Stack<T>& operator=(Stack<T>&&) noexcept;


        bool empty();
        void clear();
        void push(const T& x);
        int size() const;


        void pop();
        T& top();

        void print(std::ostream& os, char ofc = ' ') const;
        std::ostream& operator<<(std::ostream& os) const;
        bool operator==(const Stack<T>& rhs) const;
        bool operator!=(const Stack<T>& rhs) const;
        bool operator<=(const Stack<T>& rhs) const;


    };

}

#include "stack.hpp"
#endif
