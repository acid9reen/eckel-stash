#pragma once

#include<iostream>
#include<cassert>

class Stash
{
    int size;
    int quaintity;
    int next;
    unsigned char* storage;

    void inflate(int increase);

public:
    inline Stash(int _size, int init_size = 0) : size(_size), 
        quaintity(0), next(0), storage(0)
    {
        inflate(init_size);
    };

    inline ~Stash()
    {
        if (storage != 0)
        {
            std::cout << "Freeing storage" << std::endl;
            delete[] storage;
        }
    };

    int add(const void* element);
    inline void* fetch(int index)
    {
        assert(0 <= index);
        if (index >= next)
            return 0;

        return &(storage[index * size]);
    };

    inline int count() const { return next; };
};
