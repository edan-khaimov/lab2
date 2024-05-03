#ifndef LIST_SEQUENCE_H
#define LIST_SEQUENCE_H

#include "Sequence.h"
#include "LinkedList.h"

template <typename T>
class ListSequence: public Sequence<T>
{
protected:
    LinkedList<T> *list;
    virtual ListSequence<T> *GetInstance() = 0;
public:
    ListSequence()
    {
        this->list = new LinkedList<T>();
    }

    ListSequence(T *items, int count)
    {
        this->list = new LinkedList<T>(items, count);
    }

    ListSequence(const ListSequence<T> &seq)
    {
        this->list = new LinkedList<T>(*seq.list);
    }

    ListSequence(LinkedList<T> *list)
    {
        this->list = list;
    }

    ~ListSequence()
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

    T Get(int index) override
    {
        return this->list->Get(index);
    }

    int GetLength() override
    {
        return this->list->GetLength();
    }

    ListSequence<T> *Append(T item) override
    {
        ListSequence<T> *result = GetInstance();
        result->list->Append(item);
        return result;
    }

    ListSequence<T> *Prepend(T item) override
    {
        ListSequence<T> *result = GetInstance();
        result->list->Append(item);
        return result;
    }

    ListSequence<T> *InsertAt(T item, int index) override
    {
        ListSequence<T> *result = GetInstance();
        result->list->InsertAt(item, index);
        return result;
    }

    void Print()
    {
        this->list->printList();
    }
};

template <typename T>
class MutableListSequence : public ListSequence<T>
{
private:
    ListSequence<T> *GetInstance() override
    {
        return static_cast<ListSequence<T> *> (this);
    }

public:
    using ListSequence<T>::ListSequence;

    MutableListSequence<T> *Concat(Sequence<T> &seq) override
    {
        MutableListSequence<T> *result = new MutableListSequence<T>(static_cast<MutableListSequence<T> &> (*this));
        for (int i = 0; i < seq.GetLength(); i++)
        {
            result->Append(seq.Get(i));
        }
        return result;
    }

    MutableListSequence<T> *GetSubSequence(int startIndex, int endIndex) override
    {
        if (startIndex * endIndex < 0 || startIndex >= this->list->GetLength() || endIndex > startIndex)
        {
            throw std::invalid_argument("Index out of range");
        }
        T *elements = new T[endIndex - startIndex + 1];
        for (int i = 0; i < endIndex - startIndex + 1; i++)
        {
            elements[i] = this->Get(startIndex + i - 1);
        }
        MutableListSequence<T> *result = new MutableListSequence<T>(elements, endIndex - startIndex + 1);
        delete []elements;
        return result;
    }
};

template <typename T>
class ImmutableListSequence : public ListSequence<T>
{
private:
    ListSequence<T> *GetInstance() override
    {
        ImmutableListSequence<T> *instance = new ImmutableListSequence<T> (*this);
        return instance;
    }

public:
    using ListSequence<T>::ListSequence;

    ImmutableListSequence<T> *Concat(Sequence<T> &seq) override
    {
        ImmutableListSequence<T> *preResult = new ImmutableListSequence<T>(static_cast<ImmutableListSequence<T> &> (*this));
        for (int i = 0; i < seq.GetLength(); i++)
        {
            preResult->Append(seq.Get(i));
        }
        ImmutableListSequence<T> *result = new ImmutableListSequence<T> (*preResult);
        delete preResult;
        return result;
    }

    ImmutableListSequence<T> *GetSubSequence(int startIndex, int endIndex) override
    {
        if (startIndex * endIndex < 0 || startIndex >= this->list->GetLength() || endIndex > startIndex)
        {
            throw std::invalid_argument("Index out of range");
        }
        T *elements = new T[endIndex - startIndex + 1];
        for (int i = 0; i < endIndex - startIndex + 1; i++)
        {
            elements[i] = this->Get(startIndex + i - 1);
        }
        ImmutableListSequence<T> *result = new ImmutableListSequence<T>(elements, endIndex - startIndex + 1);
        delete []elements;
        return result;
    }
};

#endif
