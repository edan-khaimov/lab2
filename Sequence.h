#ifndef LAB2_MEPHI_SEQUENCE_H
#define LAB2_MEPHI_SEQUENCE_H

template <typename T>
class Sequence
{
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get() = 0;
    virtual int GetLength() = 0;
    virtual Sequence<T> *Append() = 0;
    virtual Sequence<T> *Prepend() = 0;
    virtual Sequence<T> *InsertAt() = 0;
    virtual Sequence<T> *GetSubSequence() = 0;
    virtual Sequence<T> *Concat() = 0;
};

#endif