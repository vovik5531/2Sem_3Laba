#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <cstddef>


template <class T>
 class Sequence
 {
    public: 
        virtual T GetFirst() = 0; 
        virtual T GetLast()=0; 
        virtual T Get(size_t index) =0; 
        virtual Sequence<T>* GetSubsequence(size_t startindex, size_t endindex) = 0; 
        virtual size_t GetLength() = 0;
        virtual Sequence<T>* Append(T item) = 0; 
        virtual Sequence<T>* Prepend(T item) = 0; 
        virtual Sequence<T>* InsertAt(T item, size_t index) = 0; 
        virtual Sequence<T>* Concat(Sequence<T>* list) = 0; 
        virtual Sequence<T>* Set(size_t index, T item) = 0; 

 };
#endif /* SEQUENCE */