#pragma once

#include <iostream>
#include <fstream>
#include <stdlib.h>

//error value
static const size_t npos = -1;

//Datatype
template<class T>
struct darray
{
    private:
    T *arr = nullptr;
    size_t len = 0;
    size_t cap = 0;
    public:
    //default constructor
    darray();
    //constructor with initial value
    darray(size_t n, T initVal);
    //constructor without initial value
    darray(size_t n);
    //get element
    T at(size_t n);
    //assign element
    void at(size_t n, T val);
    //return the array
    T* at();
    //get size()
    size_t size();
    //get capacity
    size_t capacity();
    //insert
    void insert(T val, size_t pos);
    //print
    void print(std::ostream& of);
    void print(std::ostream& of, const char* seperator);
    //erase
    void erase(size_t pos);
    void erase(size_t start, size_t end);
    //push_back
    void push_back(T val);
    //pop_back
    void pop_back(T val);
    //free
    void free();
    //find
        //find element
    size_t find(T val);
        //find subarray
    size_t find(darray<T> subarr);
    size_t find(const T* arr, size_t arrSz);
    //resize
    void resize(size_t n);
    //subarr
    darray subarr(size_t pos);
    darray subarr(size_t start, size_t end);
    //cmp
    bool operator==(darray<T> arr);
};
#include "vector.tpp"