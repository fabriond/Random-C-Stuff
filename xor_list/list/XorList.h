#ifndef XOR_LIST
#define XOR_LIST

#include <ostream>
#include "XorNode.h"

/**
 * XorList.h
 * 
 * Xor linked list implementation 
 * (it's in a header file because templated classes can't have connected .h and .cpp files apparently)
 */
template <class T> 
class XorList{

    XorNode<T> *first;
    XorNode<T> *last;

public:

    XorList():first(NULL), last(NULL){}

    ~XorList(){
        XorNode<T> *prev = NULL;
        XorNode<T> *current = first;
        XorNode<T> *next = current->next(prev);

        do{
            prev = current;
            current = next;
            if(current != NULL) next = current->next(prev);
            delete prev;
        }while(prev != NULL);
    }
    
    /**
     * Adds a given element to the XorList
     * @param element whose value is added to the XorList
     */
    void add(T element){
        if(first == NULL && last == NULL){
            XorNode<T> *node = new XorNode<T>(element, NULL, NULL);
            first = node;
            last = first;
        } else{
            XorNode<T> *node = new XorNode<T>(element, last, NULL);
            last->updateNext(last->prev(NULL), node);
            last = node;
        }
    }

    /**
     * Removes a given element from the XorList
     * @param element whose value is removed from the XorList
     */
    void remove(T element){
        XorNode<T> *prev = NULL;
        XorNode<T> *current = first;
        XorNode<T> *next;

        while(current != NULL && *current != element){
            next = current->next(prev);
            prev = current;
            current = next;
        }

        if(current == NULL) return;
        next = current->next(prev);
        
        if(current == first) first = next;
        else prev->updateNext(prev->prev(current), next);
        
        if(current == last) last = prev;
        else next->updatePrev(prev, next->next(current));

        delete current;
    }

    /**
     * Finds the first node that contains an element in the XorList
     * @param element to find
     * @return Reference to the first node that contains the given element
     * or NULL if there are no nodes that contain the given element
     */
    XorNode<T>* find(T element){
        XorNode<T> *prev = NULL;
        XorNode<T> *current = first;
        XorNode<T> *next;

        while(current != NULL && *current != element){
            next = current->next(prev);
            prev = current;
            current = next;
        }

        return current;
    }

    /**
     * Counts the number of ocurrences of an element in the XorList
     * @param element to find
     * @return Amount of ocurrences of the element in the XorList
     */
    unsigned long findAll(T element){
        unsigned long counter = 0;
        XorNode<T> *prev = NULL;
        XorNode<T> *current = first;
        XorNode<T> *next;

        while(current != NULL){
            if(*current == element) ++counter;
            next = current->next(prev);
            prev = current;
            current = next;
        }

        return counter;
    }

    friend std::ostream& operator<<(std::ostream& os, const XorList& xl){
        XorNode<T> *prev = NULL;
        XorNode<T> *current = xl.first;
        XorNode<T> *next;
        std::string aux = "[";

        while(current != NULL){
            os << aux;
            os << *current;
            next = current->next(prev);
            prev = current;
            current = next;
            aux = ", ";
        }
        os << "]" << std::endl;
        return os;
    }

};

#endif