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

#ifndef LIST_HPP
#define LIST_HPP

template<typename T>
class List {
    public:
    /**
     * @brief Construct a new List object
     * sets the size to zero
     * 
     */
    List();
    /**
     * @brief Destroy the List object
     * 
     */
    virtual ~List();
    /**
     * @brief returns the size of the list
     * 
     * @return int 
     */
    int getSize() const;
    /**
     * @brief returns the ith element of the list
     * 
     * @param POS 
     * @return T 
     */
    virtual T get(const int POS) const = 0;
    /**
     * @brief sets the ith element of the list
     * 
     * @param POS 
     * @param VALUE 
     */
    virtual void set(const int POS, const T VALUE) = 0;
    /**
     * @brief inserts the value before the ith element of the list
     * 
     * @param POS 
     * @param VALUE 
     */
    virtual void insert(const int POS, const T VALUE) = 0;
    /**
     * @brief removes the ith element of the list
     * 
     * @param POS 
     */
    virtual void remove(const int POS) = 0;

    protected:
    int mSize; // size of list
};

template<typename T>
List<T>::List() {
    mSize = 0;
}

template<typename T>
List<T>::~List() {
}

template<typename T>
int List<T>::getSize() const {
    return mSize;
}

#endif