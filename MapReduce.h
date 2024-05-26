#ifndef MAP_REDUCE_H
#define MAP_REDUCE_H

#include "ListSequence.h"
#include "ArraySequence.h"

template <typename T, typename U>
Sequence<U> &map(const Sequence<T> &seq, U (*func)(T))
{
    MutableListSequence<U> *result = new MutableListSequence<U>();
    for (int i = 0; i < seq.GetLength(); i++)
    {
        result->Append((*func)(seq.Get(i)));
    }
    return *result;
}

template <typename T>
T reduce(const Sequence<T> &seq, T (*func)(T, T), T start)
{
    for (int i = 0; i < seq.GetLength(); i++)
    {
        start = (*func)(start, seq.Get(i));
    }
    return start;
}

template <typename T, typename... Types>
Sequence<T> &where(const Sequence<T> &seq, bool (*func)(T, Types &...))
{
    MutableListSequence<T> *result = new MutableListSequence<T>();
    for (int i = 0; i < seq.GetLength(); i++)
    {
        if ((*func)(seq.Get(i)) == true)
        {
            result->Append(seq.Get(i));
        }
    }
    return *result;
}

#endif
