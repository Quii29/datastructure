#include "vector.h"
//default constructor
template<class T>
darray<T>::darray()
{
    this->arr = nullptr;
    this->len = 0;
    this->cap = 0;
}
//constructor without initial value
template<class T>
darray<T>::darray(size_t n)
{
    (this->arr) = new T[n];
    this->cap = n;
    this->len = 0;    
}
//constructor with initial value
template<class T>
darray<T>::darray(size_t n, T initVal)
{
    (this->arr) = new T[n];
    for (size_t i = 0; i < n; ++i) 
        this->arr[i] = initVal;
    this->len = n;
    this->cap = n;    
}
//get nth element
template<class T>
T darray<T>::at(size_t n)
{
    if(n >= this->len) throw std::out_of_range("Index is out of bounds!");
    return (this->arr)[n];
}
template<class T>
void darray<T>::at(size_t n, T val)
{
    if(n >= this->cap) throw std::exception();
    if(n >= this->len) this->len = n + 1;
    (this->arr)[n] = val;
}
//get size
template<class T>
size_t darray<T>::size()
{
    return this->len;
}
//get capacity
template<class T>
size_t darray<T>::capacity()
{
    return this->cap;
}
//insert 1 element
template<class T>
void darray<T>::insert(T val, size_t pos) {
    if (pos > this->len) {
        throw std::out_of_range("Insert position is out of range");
    }

    if (this->len == this->cap) {
        size_t newCap = (this->cap == 0) ? 1 : this->cap++;
        T* newArr = new T[newCap];

        // Copy elements before the insertion point
        for (size_t i = 0; i < pos; ++i) {
            newArr[i] = this->arr[i];
        }

        // Insert the new value
        newArr[pos] = val;

        // Copy the remaining elements
        for (size_t i = pos; i < this->len; ++i) {
            newArr[i + 1] = this->arr[i];
        }

        // Delete old array and update pointers
        delete[] this->arr;
        this->arr = newArr;
        this->cap = newCap;
    } else {
        // Shift elements to make room for the new value
        for (size_t i = this->len; i > pos; --i) {
            this->arr[i] = this->arr[i - 1];
        }

        // Insert the new value
        this->arr[pos] = val;
    }

    // Update the size of the array
    this->len++;
}

//delete 1 element
template<class T>
void darray<T>::erase(size_t pos) 
{
    if (pos >= len) throw std::out_of_range("Index is out of bounds!");
    // Handle error: index out of bounds
    for (size_t i = pos; i < len - 1; ++i) 
    {
        (this->arr)[i] = (this->arr)[i + 1];
    }
    this->len--;
}
//delete elements from start to end
template<class T>
void darray<T>::erase(size_t start, size_t end) 
{
    if (end > len || start >= end) throw std::range_error("Invalid range!");
    for (size_t i = start; i < end; ++i) 
    {
        arr[i] = arr[i + (end - start)];
    }
    this->len -= (end - start);
}
//push_back an element
template<class T>
void darray<T>::push_back(T val) {
    if (this->arr == nullptr) 
    {
        // Initial allocation
        this->arr = new T[1];
        this->arr[0] = val;
        this->cap = 1;
        this->len = 1;
    } else if (this->len == this->cap) 
    {
        T* newArr = new T[this->cap + 1];
        this->cap++;
        // Copy existing elements to the new array
        for (size_t i = 0; i < this->len; ++i) {
            newArr[i] = this->arr[i];
        }

        // Delete old array and update pointers
        delete[] this->arr;
        this->arr = newArr;
        // Add the new element
        this->arr[this->len] = val;
        this->len++;
    } else {
        // Add the new element without resizing
        this->arr[this->len] = val;
        this->len++;
    }
}

//print
template<class T>
void darray<T>::print(std::ostream& of)
{
    for(size_t i = 0; i < this->len; ++i) {of << (this->arr)[i] << " ";}
}
//print with seperator
template<class T>
void darray<T>::print(std::ostream& of, const char * seperator)
{
    for(size_t i = 0; i < this->len; ++i) {of << (this->arr)[i] << seperator;}
}
template<class T>
void darray<T>::pop_back(T val)
{
    if(this->len == 0) throw std::exception();
    this->len--;
}
template<class T>
//return the arr
T* darray<T>::at()
{
    return this->arr;
}
template<class T>
void darray<T>::free()
{
    delete[] this->arr;
}
//find
//find element
template<class T>
size_t darray<T>::find(T val)
{
    for(size_t i = 0; i < this->len; ++i)
    {
        if((this->arr)[i] == val) return i;
    }
    return npos;
}
//find subarray
template<class T>
size_t darray<T>::find(darray<T> subarr)
{
    for(size_t i = 0; i <= this->len - subarr.size(); ++i)
    {
        for(size_t j = 0; j < subarr.size(); ++j)
            {
                if((this->arr)[i + j] != subarr.at(j)) break;
                if(j == subarr.size() - 1) return i;
            }
    }
    return npos;
}

template <class T>
size_t darray<T>::find(const T* arr, size_t arrSz) 
{
    if (arrSz > this->len) return npos; // Prevent out-of-bounds access

    for (size_t i = 0; i <= this->len - arrSz; ++i) {
        bool match = true;
        for (size_t j = 0; j < arrSz; ++j) {
            if ((this->arr)[i + j] != arr[j]) {
                match = false;
                break;
            }
        }
        if (match) return i;
    }

    return npos; // Not found
}

//resize
template<class T>
void darray<T>::resize(size_t n)
{
    if(n < this->len)
    {
        T* newArr = new T[n];
        for(size_t i = 0; i < n; ++i) newArr[i] = (this->arr)[i];
        delete[] this->arr;
        this->arr = newArr;
        this->cap = n;
        this->len = n;
    }
    else if(n > this->len)
    {
        T* newArr = new T[n];
        for(size_t i = 0; i < this->len; ++i) newArr[i] = (this->arr)[i];
        delete[] this->arr;
        this->arr = newArr;
        this->cap = n;

    }
}
//subarr
template<class T>
darray<T> darray<T>::subarr(size_t pos)
{
    if(pos >= this->len) throw std::exception();
    darray<T> subarr = darray(this->len - pos);
    size_t ind = 0;
    for(size_t i = pos; i < this->len; ++i)
        subarr.at(ind++, (this->arr)[i]);
    return subarr;
}
template<class T>
darray<T> darray<T>::subarr(size_t start, size_t end)
{
    if(end >= this->len || start > end) throw std::out_of_range();
    darray<T> subarr = darray(end - start + 1);
    size_t ind = 0;
    for(size_t i = start; i <= end; ++i)
        subarr.at(ind++, (this->arr)[i]);
    return subarr;
}
//cmp
template<class T>
bool darray<T>::operator==(darray<T> arr)
{
    if(this->len != arr.size()) return false;
    for(size_t i = 0; i < arr.size(); ++i)
    {
        if((this->arr)[i] != arr.at(i)) return false;
    }
    return true;
}

