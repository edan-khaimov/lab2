#ifndef LIST_SEQUENCE_H
#define LIST_SEQUENCE_H

#include "Sequence.h"
#include "LinkedList.h"

template <typename T>
class ArraySequence: Sequence<T>
{
protected:
    LinkedList<T> *list;
    virtual ArraySequence<T> *GetInstance() = 0;
    /* ArraySequence<T> *AppendWithoutInstance(T item)
    {
        ArraySequence<T> *result = this;
        return result->list->Append(item);
    }
     */
public:
    ArraySequence()
    {
        this->list = new LinkedList<T>();
    }

    ArraySequence(T *items, int count)
    {
        this->list = new LinkedList<T>(items, count);
    }

    ArraySequence(const ArraySequence<T> &seq)
    {
        this->list = new LinkedList<T>(*seq.list);
    }

    ArraySequence(LinkedList<T>* list)
    {
        this->list = list;
    }

    virtual ~ArraySequence() override
    {
        delete this->list;
    }

    T GetFirst() override
    {
        return this->list->GetFirst();
    }

    T GetLast() override
    {
        return this->list->GetLast();
    }

    T Get() override
    {
        return this->list->Get();
    }

    int GetLength() override
    {
        return this->list->GetLength();
    }

    ArraySequence<T> *Append(T item) override
    {
        ArraySequence<T> *result = GetInstance();
        return result->list->Append(item);
    }

    ArraySequence<T> *Prepend(T item) override
    {
        ArraySequence<T> *result = GetInstance();
        return result->list->Append(item);
    }

    ArraySequence<T> *InsertAt(T item, int index) override
    {
        ArraySequence<T> *result = GetInstance();
        return result->list->InsertAt(item, index);
    }
};

#endif
