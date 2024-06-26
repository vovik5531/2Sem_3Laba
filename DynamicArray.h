#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <string>
#include <stdexcept>

template <class T>
class DynamicArray 
{
    private:
        T* elements;
        size_t size; 
    public:
        DynamicArray(T* input_elements, size_t darray_size_input)
        {
            if(darray_size_input<=0) throw std::out_of_range("W size");

            elements = new T[darray_size_input];
            size = darray_size_input;
            size_t a{0};
            for( auto& value : input_elements)
            {
                elements[a] = value;
                a++; 
            }
        } 
        DynamicArray(std::initializer_list<T> input_list)
        {
            elements = new T[input_list.size()];
            this->size = input_list.size();
            size_t i{0}; 
            for( auto& value : input_list)
            {
                (*this)[i] = value; 
                i++; 
            }
        }
        DynamicArray()
        {
            elements = new T[0]; 
            this->size = 0; 
        }
        DynamicArray(size_t size_input)
        {
            if(size_input<=0) throw std::out_of_range("W size ");
            elements = new T[size_input];
            this->size = size_input; 
        }
        T Get(size_t index) const 
        {
            if(index >= this->size) throw std::out_of_range("IndexOutOfRange ");
            return elements[index];
        }
        size_t GetSize() const 
        {
            return this->size;
        }
        void Set (size_t index, T value) 
        {
            if(index >= this->size) throw std::out_of_range("IndexOutOfRange ");
            elements[index] = value; 
        }
        void Resize(size_t newSize)
        {
            if(newSize > this->size) throw std::length_error("IndexOutOfRange ");
            T* copy = new T[newSize]; 
            for(size_t i=0; i< newSize; ++i)
            {
                copy[i] = elements[i];
            }
            this->size = newSize;
            elements = new T[newSize]; 
            for(size_t i=0; i< newSize; ++i)
            {
                elements[i] = copy[i];
            }
            delete[] copy;
        }
        DynamicArray<T>* GetSubArray(size_t startIndex, size_t endIndex)
        {
            if(endIndex > this->size || startIndex > this->size) 
                throw std::out_of_range("IndexOutOfRange");
            DynamicArray<T>* Sub_DynamicArray = new DynamicArray<T>(endIndex - startIndex); 
            for(size_t i = 0; i< endIndex - startIndex; ++i)
            {
                Sub_DynamicArray->Set(i, this->Get(i+startIndex)); 
            }
            return Sub_DynamicArray; 
        }
        ~DynamicArray()
        {
            delete[] elements;
        }
        
};



#endif /*DYNAMICARRAY_H*/