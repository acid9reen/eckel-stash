#include "stash.hpp"

#include<iostream>
#include<cassert>

const int INCREMENT = 100;

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

void Stash::inflate(int increase)
{
    assert(increase >= 0);
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
