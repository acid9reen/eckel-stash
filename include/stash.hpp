#pragma once


class Stash
{
    int size;
    int quaintity;
    int next;
    unsigned char* storage;

    void inflate(int increase);

public:
    Stash(int _size, int init_size = 0);
    ~Stash();
    int add(const void* element);
    void *fetch(int index);
    int count();
};
