#include "stash.hpp"

#include<iostream>
#include<cassert>

const int INCREMENT = 100;

Stash::Stash(int _size, int init_size /* = 0 */)
{
    size = _size;
    quaintity = 0;
    storage = 0;
    next = 0;
    inflate(init_size);
}

int Stash::add(const void *element)
{
    if (next >= quaintity)
        inflate(INCREMENT);

    int start_bytes = next * size;
    unsigned char *e = (unsigned char *)element;

    for (int i = 0; i < size; i++)
    {
        storage[start_bytes + i] = e[i];
    }

    next++;

    return (next - 1);
}

void * Stash::fetch(int index)
{
    assert(0 <= index);
    if(index >= next)
        return 0;

    return &(storage[index * size]);
}

 int Stash::count()
 {
     return next;
 }

void Stash::inflate(int increase)
{
    assert(increase > 0);
    int new_quantity = quaintity + increase;
    int new_bytes = new_quantity * size;
    int old_bytes = quaintity * size;
    unsigned char *buf = new unsigned char[new_bytes];

    for (int i = 0; i < old_bytes; i++)
        buf[i] = storage[i];

    delete[] storage;
    storage = buf;
    quaintity = new_quantity;
}

Stash::~Stash()
{
    if (storage != 0)
    {
        std::cout << "Freeing storage" << std::endl;
        delete[] storage;
    }
}
