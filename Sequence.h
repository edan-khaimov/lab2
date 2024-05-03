#ifndef LAB2_MEPHI_SEQUENCE_H
#define LAB2_MEPHI_SEQUENCE_H

template <typename T>
class Sequence
{
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get() = 0;
    virtual int GetLength() = 0;
    virtual Sequence<T> *Append(T item) = 0;
    virtual Sequence<T> *Prepend(T item) = 0;
    virtual Sequence<T> *InsertAt(T item, int index) = 0;
    virtual Sequence<T> *GetSubSequence(int startIndex, int endIndex) = 0;
    virtual Sequence<T> *Concat(Sequence<T> &seq) = 0;
};

#endif