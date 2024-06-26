#ifndef ARRAY_SEQUENCE_H
#define ARRAY_SEQUENCE_H
#include "Sequence.h"
#include "DynamicArray.h"
#include <cstddef>

template <class T>
class ArraySequence : public Sequence<T>
{
private:
    DynamicArray<T> arrseq_Array;
    size_t  capacity; 
public:
    ArraySequence<T>* copiedList () 
    {
        ArraySequence<T>* newList = new ArraySequence<T>(*this);
        return newList;
    }
    /* Копировать элементы из переданного массива: */
    ArraySequence(T* items, size_t count)
    {
        DynamicArray<T> temporary_array( items, count); 
        this->arrseq_Array = temporary_array; 
    }
    /* Создать пустой список: */
    ArraySequence()
    { 
        this->arrseq_Array = DynamicArray<T>(); 
    }
    ArraySequence(size_t size)
    {
        DynamicArray<T> temporary_array(size); 
        this->arrseq_Array = temporary_array;
    }
    ArraySequence( const ArraySequence<T>& list)
    {
        this->arrseq_Array = list.arrseq_Array;  
    }
    T GetFirst() 
    {
        return arrseq_Array.Get(0);
    }
    T GetLast() 
    {
        return arrseq_Array.Get(arrseq_Array.GetSize()-1);
    }
    T Get(size_t index)
    {
        return arrseq_Array.Get(index);
    }
    size_t GetLength()
    {
        return arrseq_Array.GetSize();
    }
    /* Получить список из всех элементов, начиная с startIndex и заканчивая endIndex */
    ArraySequence<T>* GetSubsequence(size_t startIndex, size_t endIndex)
    {
        ArraySequence<T>* New_Array_Sequence = new ArraySequence(endIndex - startIndex); 
        New_Array_Sequence->arrseq_Array = *(this->arrseq_Array.GetSubArray(startIndex, endIndex));
        return New_Array_Sequence; 
    }
    Sequence<T>* Append(T item)
    {   
        size_t newSize = arrseq_Array.GetSize()+1; 
        arrseq_Array.Set(arrseq_Array.GetSize()-1, item); 
        if(newSize == capacity)
        {
            arrseq_Array.Resize(arrseq_Array.GetSize()*2);
        }
        return this; 
    }

    Sequence<T>* Prepend(T item)
    {   
        this->InsertAt(item, 0); 
        return this; 
    }
    Sequence<T>* InsertAt(T item, size_t index) //TODO
    {   
        for(size_t i = arrseq_Array.GetSize()-1; i > index; --i)
        {
            arrseq_Array.Set(i, arrseq_Array.Get(i-1)); 
        }
        arrseq_Array.Set(index, item); 
        if (arrseq_Array.GetSize()+1 == capacity)
        {
            arrseq_Array.Resize(arrseq_Array.GetSize()*2); 
        }
        return this; 
    }
    Sequence<T>*Set(size_t index, T item)
    {
            arrseq_Array.Set(index,item);
            return this;
    }
    Sequence<T>* Concat(Sequence<T>* array)
    {
        ArraySequence<T> *temporary_array = static_cast<ArraySequence<T>*>(array); 
        for(size_t i = 0 ; i < temporary_array->GetLength(); ++i)
        {
            this->Append(temporary_array->Get(i)); 
        }
        return this; 
    }
    ~ArraySequence()
    {
        delete[] arrseq_Array; 
    }
};




#endif /* ARRAY_SEQUENCE */