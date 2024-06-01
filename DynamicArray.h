#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

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
        this->elements = new T[size];
    }

    DynamicArray(T* items, int count) : DynamicArray(count)
    {
        if (items == nullptr)
        {
            throw std::invalid_argument("Invalid argument in constructor");
        }
        for (int i = 0; i < count; i++)
        {
            elements[i] = items[i];
        }
    }

    DynamicArray(const DynamicArray<T> &dynamicArray) : DynamicArray(dynamicArray.elements, dynamicArray.size) {}

    ~DynamicArray()
    {
        delete[] this->elements;
        this->size = 0;
    }

    T Get(int index)
    {
        if (index < 0 || index > this->size)
        {
            throw std::out_of_range("Invalid argument");
        }
        return this->elements[index];
    }

    int GetSize()
    {
        return this->size;
    }

    void Set(int index, T value)
    {
        if (index < 0 || index >= this->size)
        {
            throw std::out_of_range("Invalid argument");
        }
        this->elements[index] = value;
    }

    void Resize(int newSize)
    {
        if (newSize < 0)
        {
            throw std::out_of_range("Invalid argument");
        }
        T* newElements = new T[newSize];
        for (int i = 0; i < (this->size > newSize ? newSize : this->size); i++)
        {
            newElements[i] = this->elements[i];
        }
        delete[] this->elements;
        this->elements = newElements;
        this->size = newSize;
    }

    T &operator[] (int index)
    {
        if (size <= index)
        {
            throw std::invalid_argument("Invalid argument");
        }
        return elements[index];
    }
};

#endif
