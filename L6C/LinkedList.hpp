/* CSCI 200: Lab 6C: L6C - The Abstract List
 *
 * Author: Katrina Ngo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *
 * The goal is to compare the times to perform different operations on arrays and LinkedLists 
 * that are implemented through inheritance from a List class.
 */

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "List.hpp"
#include <exception>
#include <iostream>

/**
 * @brief A single element of a linked list of given type T
 * 
 */
template<typename T>
struct Node {
    /**
     * @brief the value of this Node of given type T
     * 
     */
    T value;
    /**
     * @brief pointer to the next element of the linked list
     * 
     */
    Node<T>* pNext;
    /**
     * @brief pointer to the previous element of the linked list
     * 
     */
    Node<T>* pPrev;
};

template<typename T>
class LinkedList : public List<T> {
    public:
    /**
     * @brief Destroy the Linked List object
     * 
     */
    ~LinkedList();
    /**
     * @brief returns the ith element of the list
     * 
     * @param POS 
     * @return T 
     */
    T get(const int POS) const override;
    /**
     * @brief sets the ith element of the list
     * 
     * @param POS 
     * @param VALUE 
     */
    void set(const int POS, const T VALUE) override;
    /**
     * @brief inserts the value before the ith element of the list
     * 
     * @param POS 
     * @param VALUE 
     */
    void insert(const int POS, const T VALUE) override;
    /**
     * @brief removes the ith element of the list
     * 
     * @param POS 
     */
    void remove(const int POS) override;

    private:
    Node<T>* mpHead; // pointer to the head node of the list
    Node<T>* mpTail; // pointer to the tail node of the list
    /**
     * @brief creates a node with provided value and null next pointer
     * 
     * @param VALUE 
     * @return Node<T>* 
     */
    Node<T>* mMakeNodeForValue(const T VALUE);

};

template<typename T>
LinkedList<T>::~LinkedList() {
    for (int i = 0; i < this->mSize; i++) {
        Node<T>* nodeToDelete = mpHead;
        mpHead = mpHead->pNext;
        delete nodeToDelete;
    }
    mpHead = nullptr;
    mpTail = nullptr;
    this->mSize = 0;
}

template<typename T>
T LinkedList<T>::get(const int POS) const {
    int counter = 0;
    Node<T>* currNode = mpHead;
    while (counter < POS && currNode != nullptr) {
        counter++;
        currNode = currNode->pNext;
    }
    if (currNode != nullptr && POS >= 0) {
        return currNode->value;
    } else {
        throw std::out_of_range("position is out of range");
    }
}

template<typename T>
void LinkedList<T>::set(const int POS, const T VALUE) {
    // if trying to set an invalid spot, or list is empty - do nothing
    if (POS >= 0) {
        Node<T>* pCurrNode = mpHead;
        int counter = 0;
    // advance through list counting number of jumps and continue until position found or at end
        while (counter < POS && pCurrNode != nullptr) {
            counter++;
            pCurrNode = pCurrNode->pNext;
        }
    // if valid position, change value
        if (pCurrNode != nullptr) {
            pCurrNode->value = VALUE;
        }
    }   
}

template<typename T>
void LinkedList<T>::insert(const int POS, const T VALUE) {
    // if position is before the beginning, add to front
    if(POS <= 0 || mpHead == nullptr) {
        // make a new node
        Node<T>* pNewNode = mMakeNodeForValue(VALUE);      
        // if list is initially empty
        if (mpHead == nullptr) {
            // head and tail are the new node                       
            mpHead = pNewNode;
            mpTail = pNewNode;
        } else {
        // otherwise, chain into existing node
            // link new node and head, update head
            pNewNode->pNext = mpHead;
            mpHead->pPrev = pNewNode;
            mpHead = pNewNode;
        }
    } else {
        Node<T>* pCurrNode = mpHead;
        int counter = 0;
        // advance through list counting number of jumps and continue until position found or at end
        while (counter < POS && pCurrNode != nullptr) {
            counter++;
            pCurrNode = pCurrNode->pNext;
        }
        // if we have gone past the end
        if(pCurrNode == nullptr) {
            // add to back
            // make new node
            Node<T>* pNewNode = mMakeNodeForValue(VALUE);
            // if list is initially empty
            if (mpHead == nullptr) {
                // head and tail are the new node                       
                mpHead = pNewNode;
                mpTail = pNewNode;
            } else {
                // otherwise, chain off existing node
                // link new node and tail, update tail
                pNewNode->pNext = nullptr;
                pNewNode->pPrev = mpTail;
                mpTail->pNext = pNewNode;
                mpTail = pNewNode;
            }
        } else {
            // otherwise add before target position
            Node<T>* pNewNode = mMakeNodeForValue(VALUE);
            pNewNode->pNext = pCurrNode;
            pNewNode->pPrev = pCurrNode->pPrev;
            pCurrNode->pPrev = pNewNode;
            pNewNode->pPrev->pNext = pNewNode;
        }
    }
    this->mSize++;
}

template<typename T>
void LinkedList<T>::remove(const int POS) {
    // if list is empty
    if(mpHead == nullptr) {
        // do nothing
        return;
    } 
    // if position is before start of list
    else if(POS <= 0) {
        // remove from front
        // if list is empty - do nothing
        if(mpHead == nullptr) return;                
        // store pointer to current head
        Node<T>* pNodeToDelete = mpHead;
        // advance head
        mpHead = mpHead->pNext;
        // if we're now pointing at nothing, list only had one element
        if (mpHead == nullptr) {
            //  set tail to also be null so it points to nothing
            mpTail = nullptr;
        } else {
            // otherwise, list still has elements
            // set back pointer to be null
            mpHead->pPrev = nullptr;
        }
        // delete former head
        delete pNodeToDelete;
    } else {
        Node<T>* pCurrNode = mpHead;
        int counter = 0;
        // advance through list counting number of jumps and continue until position found or at end
         while (counter < POS-1 && pCurrNode != nullptr) {
            counter++;
            pCurrNode = pCurrNode->pNext;
        }
        // if we have gone to tail or further
        if(pCurrNode == nullptr || pCurrNode == mpTail) {
            // remove from back
            // if list is empty, do nothing
            if(mpTail == nullptr) return;
            // store pointer to current tail
            Node<T>* pNodeToDelete = mpTail;
            // move tail backwards
            mpTail = mpTail->pPrev;
            // if we're now pointing at nothing, list only had one element
            if (mpTail == nullptr) {
                //  set head to also be null so it points to nothing
                mpHead = nullptr;
            } else {
            // otherwise, list still has elements
                // set next pointer to be null
                mpTail->pNext = nullptr;
            }
            // delete former tail
            delete pNodeToDelete;
        } else {
            // unlink current node
            Node<T>* nodeToDelete = pCurrNode->pNext;
            pCurrNode->pNext = pCurrNode->pNext->pNext;
            if (pCurrNode->pNext == nullptr) {
                mpTail = pCurrNode;
            } else {
                pCurrNode->pNext->pPrev = pCurrNode;
            }
            // delete current node
            delete nodeToDelete;
        }
    }
    this->mSize--;
}

template<typename T>
Node<T>* LinkedList<T>::mMakeNodeForValue(const T VALUE) {
    Node<T>* newNode = new Node<T>;
    newNode->value = VALUE;
    newNode->pPrev = nullptr;
    newNode->pNext = nullptr;
    return newNode;
}

#endif