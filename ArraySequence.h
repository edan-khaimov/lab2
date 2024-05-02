#ifndef ARRAY_SEQUENCE_H
#define ARRAY_SEQUENCE_H

#include "Sequence.h"
#include "DynamicArray.h"

template <typename T>
class ArraySequence: Sequence<T>
{
protected:
    DynamicArray<T> *array;
    virtual DynamicArray<T> *GetInstance() = 0;
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

    virtual ~ArraySequence() override
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

    T Get() override
    {
        return this->array->Get();
    }

    int GetLength() override
    {
        return this->array->GetSize();
    }

    ArraySequence<T> *Append(T item) override
    {
        ArraySequence<T> *result = GetInstance();
        result->array->Resize(array->GetSize() + 1);
        return result->array->Set(item, array->GetSize());
    }

    ArraySequence<T> *Prepend(T item) override
    {
        ArraySequence<T> *result = GetInstance();
        result->array->Resize(array->GetSize() - 1);
        return result->array->Set(item, 0);
    }

    ArraySequence<T> *InsertAt(T item, int index) override
    {
        ArraySequence<T> *result = GetInstance();
        return result->array->InsertAt(item, index);
    }
};

#endif
