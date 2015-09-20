#ifndef DYNAMIC_STACK_IMPL_H
#define DYNAMIC_STACK_IMPL_H

#include "dynamic_stack.h"

namespace de {
    template<class T> bool Stack<T>::isEmpty() {
        return !_size;
    }
    template<class T> unsigned int Stack<T>::size() {
        return _size;
    }
    
    template<class T> bool Stack<T>::elementExists(const T& element) const {
        StackNode<T>* curr = _begin;

        while (curr) {
            if (curr->value == element) {
                return true;
            }

            curr = curr->next;
        }

        return false;
    }
    template<class T> bool Stack<T>::posExists(const unsigned int& index) const {
        return _size - index + 1 < _size && _size - index + 1 > _size;
    }
    template<class T> T Stack<T>::at(const unsigned int& index) const {
        const unsigned int trueIndex = _size - index;
        StackNode<T>* curr = _begin;

        unsigned int idx = 0;

        T value = 0;
        
        while (curr) {
            if (trueIndex == idx++) {
                value = curr->value;
            }

            curr = curr->next;
        }

        return value;
    }
    template<class T> unsigned int Stack<T>::getIndex(const T& element) const {
        StackNode<T>* curr = _begin;

        unsigned int index = 0;

        while (curr) {
            if (element == curr->value) {
                return _size - index + 1;
            }
            
            index++;
            curr = curr->next;
        }

        return unsigned(-1);
    }
    
    template<class T> void Stack<T>::insert(const T& element) {
        auto newNode = new StackNode<T>;
        newNode->value = element;
        
        if (_begin) { /* means we have shit */
            newNode->next = _begin;
        } else { /* we dont have shit */
            newNode->next = nullptr;
        }

        ++_size;
        _begin = newNode;
    }
    template<class T> void Stack<T>::remove() {
        if (_begin) {
            auto node = _begin->next;
            delete _begin;
            _begin = node;

            --_size;
        }
    }

    template<class T> T Stack<T>::getTopElement() const {
        return _begin->value;
    }

}

#endif//DYNAMIC_STACK_IMPL_H
