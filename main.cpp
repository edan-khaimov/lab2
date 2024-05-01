#include <iostream>

template <typename T>
class LinkedList
{
private:
    int size;
    class Node
    {
    public:
        Node *pNext;
        T data;

        Node(T data = T(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    Node *head;

public:
    LinkedList()
    {
        this->size = 0;
        this->head = nullptr;
    }

    LinkedList(T* items, int count) : LinkedList()
    {
        if (count < 0)
        {
            throw std::invalid_argument("Invalid count");
        }
        for (int i = 0; i < count; i++)
        {
            Append(items[i]);
        }
    }

    LinkedList(const LinkedList<T> &list) : LinkedList()
    {
        Node *current = list.head;
        for (int i = 0; i < list.size; i++)
        {
            Append(current->data);
            current = current->pNext;
        }
        this->size = list.size;
    }

    virtual ~LinkedList()
    {
        Node *current = this->head;
        Node *next;
        while (current != nullptr)
        {
            next = current->pNext;
            delete current;
            current = next;
        }
        this->size = 0;
    }

    T GetFirst()
    {
        if (this->head == nullptr)
        {
            throw std::invalid_argument("Index out of range");
        }
        return this->head->data;
    }

    T GetLast()
    {
        Node *current = this->head;
        if (this->head == nullptr)
        {
            throw std::invalid_argument("Index out of range");
        }
        for (int i = 0; i < this->size - 1; i++)
        {
            current = current->pNext;
        }
        return current->data;
    }

    T Get(int index)
    {
        Node *current = this->head;
        if (index < 0 || index >= this->size)
        {
            throw std::invalid_argument("Index out of range");
        }
        for (int i = 0; i < index; i++)
        {
            current = current->pNext;
        }
        return current->data;
    }

    LinkedList<T>* GetSubList(int startIndex, int endIndex)
    {
        if (startIndex * endIndex < 0 || startIndex >= this->size || endIndex >= this->size)
        {
            throw std::invalid_argument("Index out of range");
        }
        LinkedList<T> *resultList = new LinkedList<T>();
        for (int i = startIndex; i < endIndex; i++)
        {
            resultList->Append(this->Get(i));
        }
        /* another realisation
        Node *current = this->head;
        for (int i = 0; i < startIndex; i++)
        {
            current = current->pNext;
        }
        for (int i = startIndex; i < endIndex; i++)
        {
            resultList->Append(current->data);
            current = current->pNext;
        }
        */
        return resultList;
    }

    int GetLength()
    {
        return this->size;
    }

    void Append(const T item)
    {
        if (this->head == nullptr)
        {
            this->head = new Node(item);
        }
        else
        {
            Node *current = this->head;
            for (int i = 1; i < this->size; i++)
            {
                current = current->pNext;
            }
            current->pNext = new Node(item);
        }
        this->size++;
    }

    void Prepend(T item)
    {
        Node *newHead = new Node(item, this->head);
        this->head = newHead;
        this->size++;
    }

    void insertAt(T item, int index)
    {
        if (index < 0 || index >= this->size)
        {
            throw std::invalid_argument("Index out of range");
        }
        Node *newElement = new Node(item);
        Node *current = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->pNext;
        }
        newElement->pNext = current->pNext;
        current->pNext = newElement;
        this->size++;
    }

    LinkedList<T>* Concat(LinkedList<T> *list)
    {
        LinkedList<T> *resultList = new LinkedList<T>();
        for (int i = 0; i < this->size; i++)
        {
            resultList->Append(this->Get(i));
        }
        for (int i = 0; i < list->size; i++)
        {
            resultList->Append(list->Get(i));
        }
        return resultList;
    }

    void printList()
    {
        Node *current = this->head;
        for (int i = 0; i < this->size; i++)
        {
            std::cout << i + 1 << " element is: " << current->data << std::endl;
            current = current->pNext;
        }
    }
};

template <typename T>
class DynamicArray
{
private:
    int size;
    T* elements;
public:
    DynamicArray()
    {
        this->size = 0;
        this->elements = nullptr;
    }

    DynamicArray(int size) : DynamicArray()
    {
        if (size < 0)
        {
            throw std::invalid_argument("Invalid size");
        }
        this->size = size;
    }

    DynamicArray(T* items, int count) : DynamicArray()
    {

    }

    DynamicArray(const DynamicArray<T> &dynamicArray)
    {

    }

    virtual ~DynamicArray()
    {

    }

    T Get(int index)
    {

    }

    int GetSize()
    {

    }

    void Set(int index, T value)
    {

    }

    void Resize(int newSize)
    {

    }
};

template <typename T>
class Sequence
{

};

template <typename T>
class ListSequence: Sequence<T>
{

};

template <typename T>
class ArraySequence: Sequence<T>
{

};

int main()
{
    return 0;
}