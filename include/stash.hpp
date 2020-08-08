#pragma once


struct Stash
{
    int size;
    int quaintity;
    int next;
    unsigned char* storage;

    void initialize(int _size);
    void cleanup();
    int add(const void* element);
    void *fetch(int index);
    int count();
    void inflate(int increase);
};
