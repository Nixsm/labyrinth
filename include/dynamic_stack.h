#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include <iostream>
#include <sstream>

namespace de {

    template<class T> struct StackNode {
        T value;
        StackNode<T>* next;
    };
    
    template<class T> class Stack {
    public:
        ~Stack() {
            while (_begin) {
                auto next = _begin->next;
                delete _begin;
                _begin = next;
            }
        }
        bool isEmpty();
        unsigned int size();
        
        bool elementExists(const T& element) const;
        bool posExists(const unsigned int& index) const;
        T at(const unsigned int& index) const;
        unsigned int getIndex(const T& element) const;

        void insert(const T& element);
        void remove();

        T getTopElement() const;
        
        friend std::ostream& operator<<(std::ostream& os, const Stack<T>& stack){
            StackNode<T>* curr = stack._begin;
            std::stringstream ss;
            while (curr) {
                ss << curr->value << " ";
                curr = curr->next;
            }

            std::string sString = ss.str();
            std::string rev(sString.rbegin(), sString.rend());

            os << rev;
            
            
            return os;
        }

    private:
        unsigned int _size = 0;
        StackNode<T>* _begin = nullptr;
    };
}



#endif//DYNAMIC_STACK_H
