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

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "List.hpp"
#include <exception>
#include <iostream>
#include <vector>

template<typename T>
class Array : public List<T> {
    public:
    /**
     * @brief Construct a new Array object
     * 
     */
    Array();
    /**
     * @brief Destroy the Array object
     * 
     */
    ~Array();
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
    T* mpArr;
};

template<typename T>
Array<T>::Array() {
    mpArr = new T[this->mSize];
}

template<typename T>
Array<T>::~Array() {
    delete[] mpArr;
    mpArr = nullptr;
    this->mSize = 0;
}

template<typename T>
T Array<T>::get(const int POS) const {
    // check if given POS is valid and not out of range
    if (POS >= 0 && POS < this->mSize) {
        return mpArr[POS];
    } else {
        throw std::exception();
    }
}

template<typename T>
void Array<T>::set(const int POS, const T VALUE) {
    // only sets a value in an array if POS is valid
    if (POS >= 0 && POS < this->mSize) {
        mpArr[POS] = VALUE;
    }
}

template<typename T>
void Array<T>::insert(const int POS, const T VALUE) {
    // create a copy vector of the current pointer array passed by reference
    std::vector<int> temp;
    for (int i = 0; i < this->mSize; i++) {
        temp.push_back(mpArr[i]);
    }
    // delete current array and assign it to a new integer array with size + 1
    delete[] mpArr;
    mpArr = new int[this->mSize+1];
    if (POS >= this->mSize) {
        // pushes back values for POS that are greater than size 
        temp.push_back(VALUE);
    } else if (POS < 0) {
        // inserts value at beginning of array if POS is less than index 0
        temp.insert(temp.begin(), VALUE);
    } else {
        // insert value as usual if POS is not out of range
        temp.insert(temp.begin()+POS, VALUE);
    }
    // copies new values in temp vector into array 
    for (int i = 0; i < this->mSize + 1; i++) {
        mpArr[i] = temp[i];
    }
    this->mSize++; // update size
}

template<typename T>
void Array<T>::remove(const int POS) {
    // create a copy vector of the current pointer array passed by reference
    std::vector<int> temp;
    for (int i = 0; i < this->mSize; i++) {
        temp.push_back(mpArr[i]);
    }
    if (mpArr != nullptr && this->mSize != 0) {
        // removes value from given POS if the POS is not out of range
        if (POS < this->mSize && POS >= 0) {
            for (int i = POS; i < this->mSize; i++) {
                temp[i] = temp[i+1];
            }
        } else if (POS < 0) {
            // removes first element in array if given POS is less than index 0
            for (int i = 0; i < this->mSize; i++) {
                temp[i] = temp[i+1];
            }
        }
        temp.pop_back();
        // copies values in temp vector into current array 
        for (int i = 0; i < this->mSize - 1; i++) {
            mpArr[i] = temp[i];
        }
        this->mSize--; // update size
    }
}

#endif