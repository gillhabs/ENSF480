/*
* File Name: iterator.cpp
* Assignment: Lab 3 Exercise B
* Completed by: Gillian Habermehl and Grace Jang
* Submission Date: October 9, 2023
*/

#include <iostream>
#include <assert.h>
#include "mystring2.h"

using namespace std;

template <class T> class Vector;
ostream& operator <<(ostream& os, Mystring& s);
template <class T>
class Vector {
  public:
    class VectIter{
      friend class Vector;
      private:
        Vector<T> *v; // points to a vector object of type T
        int index;    // represents the subscript number of the vector's
                      // array.
      public:
        VectIter(Vector& x);
     
        T& operator++();
        //PROMISES: increments the iterator's indes and return the
        //          value of the element at the index position. If
        //          index exceeds the size of the array it will
        //          be set to zero. Which means it will be circulated
        //          back to the first element of the vector.

        T&  operator++(int);
        // PRIMISES: returns the value of the element at the index
        //           position, then increments the index. If
        //           index exceeds the size of the array it will
        //           be set to zero. Which means it will be circulated
        //           back to the first element of the vector.

        T&  operator--();
        // PROMISES: decrements the iterator index, and return the
        //           the value of the element at the index. If
        //           index is less than zero it will be set to the
        //           last element in the aray. Which means it will be
        //           circulated to the last element of the vector.

        T&  operator--(int);
        // PRIMISES: returns the value of the element at the index
        //           position, then decrements the index. If
        //           index is less than zero it will be set to the
        //           last element in the aray. Which means it will be
        //           circulated to the last element of the vector.

        T& operator *();
        // PRIMISES: returns the value of the element at the current
        //           index position.
      };

    Vector(int sz);
    ~Vector();

    T& operator[](int i);
    // PRIMISES: returns existing value in the ith element of
    //           array or sets a new value to  the ith element in
    //           array.
    
    void ascending_sort();
    // PRIMISES: sorts the vector values in ascending order.
      
  private:
    T *array;               // points to the first element of an array of T
    int size;               // size of array
    void swap(T&, T &);     // swaps the values of two elements in array
};

template <class T>
Vector<T>::VectIter::VectIter(Vector<T> &x)
{
  v = &x;
  index = 0;
}

// Overloading operators for iterators ++ and --
template <class T>
T& Vector<T>::VectIter::operator ++(){
    // Pre-fix
    index++;
    if(index >= v->size) {
        index = 0;
    }
    return **this;
}

template <class T>
T& Vector<T>::VectIter::operator ++(int){
    // Post-fix
    T *ret = &**this;
    index++;
    if(index >= v->size) {
        index = 0;
    }
  return *ret;
}

template <class T>
T& Vector<T>::VectIter::operator --(){
    // Pre-fix
    index--;
    if(index < 0) {
        index = v->size-1;
    }
    return **this;
}

template <class T>
T& Vector<T>::VectIter::operator --(int){
    // Post-fix
    T *ret = &**this;
    index--;
    if(index < 0) {
        index = v->size-1;
    }
    return *ret;
}

template <class T>
T& Vector<T>::VectIter::operator *()
{
  return v -> array[index];
}


// ascending_sort() for <class T>
template <class T>
void Vector<T>::ascending_sort()
{
    for(int i=0; i< size-1; i++) {
        for(int j=i+1; j < size; j++) {
            if(array[i] > array[j]) {
                swap(array[i], array[j]);
            }
        }
    }
}

// ascending_sort() for Mystring type
template <>
void Vector<Mystring>::ascending_sort(){
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(strcmp(array[i].c_str(), array[j].c_str()) > 0) {
                swap(array[i], array[j]);
            }
        }
    }
}

// ascending_sort() for char * type
template<>
void Vector<const char*>::ascending_sort(){
    for(int i = 0; i < size - 1; i++) {
        for(int j = i +1; j < size; j++) {
            if((strcmp(array[i], array[j])) > 0) {
                swap(array[i], array[j]);
            }
        }
    }
}

template <class T>
void Vector<T>::swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <class T>
Vector<T>::Vector(int sz)
{
  size=sz;
  array = new T [sz];
  assert (array != NULL);
}

template <class T>
Vector<T>::~Vector()
{
  delete [] array;
  array = NULL;
}

template <class T>
T& Vector<T>::operator [](int i)
{
  return array[i];
}



int main()
{

 Vector<int> x(3);
 x[0] = 999;
 x[1] = -77;
 x[2] = 88;

 Vector<int>::VectIter iter(x);

 cout << "\n\nThe first element of vector x contains: " << *iter;

 // the code between the  #if 0 and #endif is ignored by
 // compiler. If you change it to #if 1, it will be compiled
 
#if 1
    cout << "\nTesting an <int> Vector: " << endl;
    
    cout << "\n\nTesting sort";
    x.ascending_sort();
    
    for (int i=0; i<3 ; i++)
        cout << endl << iter++;
    
    cout << "\n\nTesting Prefix --:";
    for (int i=0; i<3 ; i++)
        cout << endl << --iter;
    
    cout << "\n\nTesting Prefix ++:";
    for (int i=0; i<3 ; i++)
        cout << endl << ++iter;
    
    cout << "\n\nTesting Postfix --";
    for (int i=0; i<3 ; i++)
        cout << endl << iter--;
    
    cout << endl;
    
    cout << "Testing a <Mystring> Vector: " << endl;
    Vector<Mystring> y(3);
    y[0] = "Bar";
    y[1] = "Foo";
    y[2] = "All";;
    
    Vector<Mystring>::VectIter iters(y);
    
    cout << "\n\nTesting sort";
    y.ascending_sort();
    
    for (int i=0; i<3 ; i++)
        cout << endl << iters++;
    
    cout << "\n\nTesting Prefix --:";
    for (int i=0; i<3 ; i++)
        cout << endl << --iters;
    
    cout << "\n\nTesting Prefix ++:";
    for (int i=0; i<3 ; i++)
        cout << endl << ++iters;
    
    cout << "\n\nTesting Postfix --";
    for (int i=0; i<3 ; i++)
        cout << endl << iters--;
    
    cout << endl; cout << "Testing a <char *> Vector: " << endl;
    Vector<const char*> z(3);
    z[0] = "Orange";
    z[1] = "Pear";
    z[2] = "Apple";;
    
    Vector<const char*>::VectIter iterchar(z);
    
    cout << "\n\nTesting sort";
    z.ascending_sort();
    
    for (int i=0; i<3 ; i++)
        cout << endl << iterchar++;
    
#endif
    cout << "\nPrgram Terminated Successfully." << endl;
    
    return 0;
}












