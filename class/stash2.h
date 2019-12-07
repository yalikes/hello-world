#ifndef STASH2_H
#define STASH2_H
class Stash{
    int size;
    int quantity;
    int next;
    unsigned char* storage;
    void inflate(int increase);
public:
    Stash(int size);
    ~Stash();
    int add(unsigned char* element);
    unsigned char*fetch(int index);
    int count();
};
#endif