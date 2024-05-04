#ifndef ARRAY_SEQUENCE_H
#define ARRAY_SEQUENCE_H

#include "Sequence.h"
#include "DynamicArray.h"

template <typename T>
class ArraySequence: public Sequence<T>
{
protected:
    DynamicArray<T> *array;
    virtual ArraySequence<T> *GetInstance() = 0;
public:
    ArraySequence()
    {
        this->array = new DynamicArray<T>();
    }

    ArraySequence(T *items, int count)
    {
        this->array = new DynamicArray<T>(items, count);
    }

    ArraySequence(const ArraySequence<T> &seq)
    {
        this->array = new DynamicArray<T>(*seq.array);
    }

    ArraySequence(DynamicArray<T>* array)
    {
        this->array = array;
    }

    virtual ~ArraySequence()
    {
        delete this->array;
    }

    T GetFirst() override
    {
        return this->array->Get(0);
    }

    T GetLast() override
    {
        return this->array->Get(this->array->GetSize() - 1);
    }

    T Get(int index) override
    {
        return this->array->Get(index);
    }

    int GetLength() override
    {
        return this->array->GetSize();
    }

    ArraySequence<T> *Append(T item) override
    {
        ArraySequence<T> *result = GetInstance();
        result->array->Resize(result->array->GetSize() + 1);
        result->array->Set(result->array->GetSize() - 1, item);
        return result;
    }

    ArraySequence<T> *Prepend(T item) override
    {
        ArraySequence<T> *result = GetInstance();
        result->array->Resize(result->array->GetSize() + 1);
        T current = this->array->Get(0);
        for (int i = this->array->GetSize() - 1; i > 0; i--)
        {
            result->array->Set(i, result->array->Get(i - 1));
        }
        result->array->Set(0, item);
        return result;
    }

    ArraySequence<T> *InsertAt(T item, int index) override
    {
        ArraySequence<T> *result = GetInstance();
        result->array->Set(index, item);
        return result;
    }

    void Print()
    {
        this->array->printArray();
    }
};

template <typename T>
class MutableArraySequence : public ArraySequence<T>
{
private:
    ArraySequence<T> *GetInstance() override
    {
        return static_cast<ArraySequence<T> *> (this);
    }

public:
    using ArraySequence<T>::ArraySequence;

    MutableArraySequence<T> *Concat (Sequence<T> &seq) override
    {
        for (int i = 0; i < seq.GetLength(); i++)
        {
            this->Append(seq.Get(i));
        }
        return this;
    }

    MutableArraySequence<T> *GetSubSequence (int startIndex, int endIndex) override
    {
        DynamicArray<T> *resultArray = new DynamicArray<T>(endIndex - startIndex);
        for (int i = 0; i < endIndex - startIndex + 1; i++)
        {
            resultArray->Set(startIndex + i, this->array->Get(i));
        }
        MutableArraySequence<T> *result = new MutableArraySequence<T>(resultArray);
        result->array = resultArray;
        return result;
    }
};

template <typename T>
class ImmutableArraySequence : public ArraySequence<T>
{
private:
    ArraySequence<T> *GetInstance() override
    {
        ImmutableArraySequence<T> *instance = new ImmutableArraySequence<T> (* this);
        return instance;
    }

public:
    using ArraySequence<T>::ArraySequence;

    ImmutableArraySequence<T> *Concat (Sequence<T> &seq) override
    {
        DynamicArray<T> *resultArray = new DynamicArray<T>(this->GetLength() + seq.GetLength());
        for (int i = 0; i < this->GetLength(); i++)
        {
            resultArray->Set(i, this->Get(i));
        }
        for (int i = 0; i < seq.GetLength(); i++)
        {
            resultArray->Set(this->GetLength() + i, seq.Get(i));
        }
        ImmutableArraySequence<T> *result = new ImmutableArraySequence<T>(resultArray);
        return result;
    }

    ImmutableArraySequence<T> *GetSubSequence (int startIndex, int endIndex) override
    {
        DynamicArray<T> *resultArray = new DynamicArray<T>(endIndex - startIndex);
        for (int i = 0; i < endIndex - startIndex + 1; i++)
        {
            resultArray->Set(startIndex + i, this->array->Get(i));
        }
        ImmutableArraySequence<T> *result = new ImmutableArraySequence<T>(resultArray);
        result->array = resultArray;
        return result;
    }

};

#endif
