#ifndef XOR_NODE
#define XOR_NODE

#include <ostream>

/**
 * XorNode.h
 * 
 * Node implementation for a xor linked list
 * (it's in a header file because templated classes can't have connected .h and .cpp files apparently)
 */
template <class T>
class XorNode{
    
    T value;
    XorNode *next_xor_prev;

    /**
     * Xor operation between two XorNode references
     * Used internally to get previous or next node when xor'ed with next_xor_prev
     * @param two references to XorNodes
     */
    XorNode* xorPtrs(XorNode *n1, XorNode *n2){
        return (XorNode*) ((unsigned long)n1^(unsigned long)n2);
    }

public:

    XorNode(T val, XorNode *prev, XorNode *next):value(val), next_xor_prev(xorPtrs(next, prev)){}

    /**
     * Gets a reference to the previous node
     * @param next is the next node
     * @return A reference to the previous node
     */
    XorNode* prev(XorNode *next){
        return xorPtrs(next, next_xor_prev);
    }

    /**
     * Gets a reference to the next node
     * @param prev is the previous node
     * @return A reference to the next node
     */
    XorNode* next(XorNode *prev){
        return xorPtrs(prev, next_xor_prev);
    }

    /**
     * Updates the pointer to the previous node
     * @param newPrev a reference to the new previous node
     * @param next a reference to the current next node
     */
    void updatePrev(XorNode *newPrev, XorNode *next){
        next_xor_prev = xorPtrs(next, newPrev);
    }

    /**
     * Updates the pointer to the next node
     * @param prev a reference to the current previous node
     * @param newNext a reference to the new next node
     */
    void updateNext(XorNode *prev, XorNode *newNext){
        next_xor_prev = xorPtrs(newNext, prev);
    }

    /**
     * Checks if the node passed contains the given element
     * @param node is the node to be checked
     * @param element is the element to be compared
     */
    friend bool operator==(const XorNode& node, const T& element){
        return node.value == element;
    }

    /**
     * Checks if the node passed does not contain the given element
     * @param node is the node to be checked
     * @param element is the element to be compared
     */
    friend bool operator!=(const XorNode& node, const T& element){
        return node.value != element;
    }

    friend std::ostream& operator<<(std::ostream& os, const XorNode& node){
        os << node.value;
        return os;
    }

};

#endif