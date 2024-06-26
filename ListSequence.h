#ifndef LIST_SEQUENCE_H
#define LIST_SEQUENCE_H
#include "Sequence.h"
#include "LinkedList.h"

template <class T>
class ListSequence : public Sequence<T>
{
    private:
        LinkedList<T> linkedList_List; 
    public:
        ListSequence<T> * copiedList ()
        {
            ListSequence<T> * newList = new ListSequence<T>(*this);
            return newList;
        }
        ListSequence (T* items, size_t count)
        {
            if (count <= 0) throw std::out_of_range("Size is wrong!");
            linkedList_List = LinkedList<T>(items, count);
        }
        ListSequence(const ListSequence<T> & list)
        {
            this->linkedList_List = list.linkedList_List;
        }
        ListSequence()
        {
            this->linkedList_List = LinkedList<T>();
        }
        ListSequence(size_t count)
        {
            this->linkedList_List = LinkedList<T>(count);
        }
        T GetFirst() 
        {
            return linkedList_List.GetFirst();
        }
        T GetLast()  
        {
            return linkedList_List.GetLast();
        }
        T Get(size_t index) 
        {
            if (index >= this->GetLength()) throw std::out_of_range("IndexOutOfRange");
            return linkedList_List.Get(index);
        }
        ListSequence<T> *GetSubsequence(size_t startIndex, size_t endIndex) 
        {
            if (endIndex >= this->GetLength() || startIndex >= this->GetLength()) throw std::out_of_range("IndexOutOfRange");
            LinkedList<T> *newList = this->linkedList_List.GetSubList(startIndex, endIndex);
            ListSequence<T> *newSeq = new ListSequence<T>;
            newSeq->linkedList_List = *newList;
            return newSeq;
        }
        size_t GetLength()
        {
            return linkedList_List.GetLength();
        }
        Sequence<T>* Append(T item) 
        {
            linkedList_List.Append(item);
            return this;
        }
        Sequence<T>* Set(size_t index, T item) 
        {
            linkedList_List.Set(item, index);
            return this;
        }
        Sequence<T>* Prepend(T item)
        {
            linkedList_List.Prepend(item);
            return this;
        }
        Sequence<T>* InsertAt(T item, size_t index)
        {
            if (index >= this->GetLength()) throw std::out_of_range("IndexOutOfRange");
            linkedList_List.InsertAt(item, index);
            return this;
        }

        ListSequence<T>* Concat(Sequence<T>* list)
        {
            ListSequence<T>* temporaryList = static_cast<ListSequence<T>*>(list);
            this->linkedList_List.Concat(temporaryList->linkedList_List);
            return this;
        }
        ~ListSequence()
        {
            linkedList_List.Clear(); 
            linkedList_List.head = nullptr; 
            linkedList_List.tail = nullptr; 
        }
};


#endif /* LIST_SEQUENCE_H */