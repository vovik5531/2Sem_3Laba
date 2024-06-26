#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstddef>
#include <stdexcept>


template <class T>
class LinkedList
{
    private:
        struct Node 
        {
            T value; 
            Node* next; 
            Node* prev; 
            Node(const T& value, Node* next = nullptr, Node* prev = nullptr)
            {
                this->value = value; 
                this->next = next; 
                this->prev = prev; 
            } 
        };
        Node* head {nullptr}; 
        Node* tail {nullptr}; 
        size_t size {0}; 
    public:
        /*Создать пустой список*/
        LinkedList(){}
        /*Создать список заданного размера из 0: */
        LinkedList(size_t size)
        {
            this->size = 0;
            for(size_t i = 0; i< size; ++i)
            {
                (*this).Append(0); 
            }
        }
        /* Копировать элементы из переданного массива: */
        LinkedList(T* items, size_t size)
        {
            this->size = 0; 
            for(size_t i =0; i< size; ++i)
            {
                (*this).Append(items[i]); 
            }
        }

        /* Копирующий конструктор:*/
        LinkedList(const LinkedList<T> & list_input)
        {
            for(size_t i=0; i<list_input.GetLength(); ++i)
            {
                T temporary = list_input.Get(i);
                this->Append(temporary);
            }
        }
        /* Удаление элементов списка: */
        void Clear()
        { 
            for(size_t j = 0; j<this->size; ++j)
            {
                Node* temporary = this->head; 
                this->head = this->head->next; 
                delete temporary; 
                this->size = this->size -1;  
            }
        }
        /* получение превого элемента */
        T GetFirst()  
        {
            return head->value; 
        }
        /* получение последнего элемента*/
        T GetLast() 
        {
            return head->value; 
        }
        /* получение  длины */
        size_t GetLength() const 
        {
            return this->size; 
        }
        /* получение значения по индексу */
        T Get (size_t index_input) const 
        {
            if(index_input > this->size ) throw std::out_of_range("IndexOutOfRange"); 
             Node* temporary = this->head; 
            for(size_t j=0; j<index_input; ++j)
            {   
                temporary = temporary->next;

            }
            return temporary->value; 
        }
        /* Получить список из всех элементов, начиная с startIndex и заканчивая endIndex */
        LinkedList<T>* GetSubList(size_t startIndex, size_t endIndex)
        {
            LinkedList<T>* temporary_list = new LinkedList<T>; 
            Node* temporary = this->head;
            for(size_t i=0; i< startIndex; ++i)
            {
                
                temporary = temporary->next;//сдвигаемся до точки startIndex
            }
            for(size_t j = startIndex; j< endIndex; ++j)
            {
                temporary_list->Append(temporary->value); //копируем значения с точки startIndex до endIndex 
                temporary = temporary->next; 
            }
            return temporary_list; 
        }
        void Append(T item)
        {
            if(this->size == 0 )
            {
                Node* newNode = new Node(item);
                this->size++; 
                this->head = newNode; 
                this->tail = newNode; 
                return; 
            }
            Node* newNode = new Node(item); 
            tail->next = newNode; 
            newNode->prev = tail; 
            tail = newNode;
            this->size++; 
        }
        void Prepend(T item)
        {
            if(this->size == 0 )
            {
                Node* newNode = new Node(item);
                this->size++; 
                this->head = newNode; 
                this->tail = newNode; 
                return; 
            }
            Node* newNode = new Node(item);
            head->prev = newNode;
            newNode->next = head; 
            head = newNode; 
            this->size++; 
        }
        void InsertAt(T item, size_t index)
        {
            if(index > this->size) throw std::out_of_range("IndexOutOfRange"); 
            if(index == this->size)
            {
                this->Append(item); 
                this->size++;
                return; 
            }
            if(index == 0)
            {
                this->Prepend(item); 
                this->size++; 
                return; 
            }
            else
            {
                Node* newNode = new Node(item);
                Node* current_node = this->head;  
                for(size_t i = 0; i<index; ++i)
                {
                    current_node->value = current_node->next->value;
                    current_node = current_node->next;  
                }
                Node* next_current = current_node->next; //дошли до нужного места, и новый созданный контейнер связываем с соседями на index-1 и index
                next_current->prev = newNode; 
                current_node->next = newNode; 
                newNode->prev = current_node; 
                newNode->next = next_current;
            }
        }
        void Set( T item, size_t index)
        {
            Node* newNode = this->head;
            for(size_t i = 0; i< index; ++i)
            {
                newNode = newNode->next; 
            }
            newNode->value = item; 

        }
        LinkedList<T> Concat(const LinkedList<T>& list)
        {
            this->size += list.GetLength();
            tail->next = list.head; 
            return *this;
        }
        ~LinkedList()
        {
            this->Clear();
            this->head = nullptr; 
            this->tail = nullptr; 
             
        } 
};



#endif /* LINKEDLIST_H */