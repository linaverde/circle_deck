//
// Created by polina on 31.03.19.
//

#ifndef CIRCLE_DECK_DECK_LIB_H
#define CIRCLE_DECK_DECK_LIB_H

class Deck {
private:
    int *deck;
    int head, tale;
    unsigned int size;
    bool empty;

public:
    Deck(unsigned int size);

    Deck(const Deck& copy);

    void push_front(int elem);

    void push_back(int elem);

    int pop_front();

    int pop_back();

    void print();

    bool isEmpty();

    unsigned int getSize();

    unsigned int length();

    Deck& operator = (const Deck&);
};

#endif //CIRCLE_DECK_DECK_LIB_H
