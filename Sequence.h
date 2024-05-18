#ifndef LAB2_MEPHI_SEQUENCE_H
#define LAB2_MEPHI_SEQUENCE_H

template <typename T>
class Sequence
{
protected:
    virtual Sequence<T> *GetInstance() = 0;
public:
    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual T Get(int index) const = 0;
    virtual int GetLength() const = 0;
    virtual Sequence<T> *Append(T item) = 0;
    virtual Sequence<T> *Prepend(T item) = 0;
    virtual Sequence<T> *InsertAt(T item, int index) = 0;
    virtual Sequence<T> *GetSubSequence(int startIndex, int endIndex) const = 0;
    virtual Sequence<T> *Concat(Sequence<T> &seq) = 0;

    virtual T &operator[] (int index) = 0;

    bool operator==(const Sequence<T> &seq)
    {
        if (seq.GetLength() == this->GetLength())
        {
            for (int i = 0; i < this->GetLength(); i++)
            {
                if (this->Get(i) != seq.Get(i))
                {
                    return false;
                }
            }
        }
        return seq.GetLength() == this->GetLength();
    }

    bool operator!=(const Sequence<T> &seq)
    {
        if (seq.GetLength() == this->GetLength())
        {
            for (int i = 0; i < this->GetLength(); i++)
            {
                if (this->Get(i) != seq.Get(i))
                {
                    return true;
                }
            }
        }
        return seq.GetLength() != this->GetLength();
    }

    void Print()
    {
        for (int i = 0; i < this->GetLength(); i++)
        {
            std::cout << (*this)[i] << std::endl;
        }
    }

    template<typename U>
    Sequence<U> &Map(U (*func)(T))
    {
        Sequence<T> *result = GetInstance();
        for (int i = 0; i < this->GetLength(); i++)
        {
            (*result)[i] = (*func)(this->Get(i));
        }
        return *result;
    }

    T Reduce(T (*func)(T, T), T start)
    {
        for (int i = 0; i < this->GetLength(); i++)
        {
            start = (*func)(start, this->Get(i));
        }
        return start;
    }
};

#endif