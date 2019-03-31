//
// Created by polina on 31.03.19.
//

#include <iostream>
#include "deck_lib.h"

#define minSize 10
#define IS_FULL  "Deck is full";
#define IS_EMPTY "Deck is empty";

Deck::Deck(unsigned int size) {
    if (size == 0) {
        deck = new int[minSize];
    } else {
        deck = new int[size + 1];
    }
    head = size / 2;
    tale = head + 1;
    this->size = size + 1;
    empty = true;
}

void Deck::push_front(int elem) {
    if (head != tale || empty) {
        empty = false;
        deck[head] = elem;
        head--;
        if (head == -1) {
            head = size - 1;
        }
    } else {
        throw IS_FULL;
    };
}

void Deck::push_back(int elem) {
    if (head != tale || empty) {
        empty = false;
        deck[tale] = elem;
        tale++;
        if (tale == size) {
            tale = 0;
        }
    } else {
        throw IS_FULL;
    };
}

int Deck::pop_front() {
    if (!empty) {
        head++;
        head%=size;
        if (abs(head - tale) == 1){
            empty = true;
        };
        return deck[head];
    } else {
        throw IS_EMPTY;
    };
}

int Deck::pop_back() {
    if (!empty)  {
        tale--;
        if (tale == -1){
            tale = size - 1;
        }
        if (abs(head - tale) == 1){
            empty = true;
        };
        return deck[tale];
    } else {
        throw IS_EMPTY;
    };
}

unsigned int Deck::length() {
    if (head == tale && !empty){
        return size-1;
    } else if (empty){
        return 0;
    }
    else{
        unsigned int k = 0;
        for (int i = (head+1) % size; i != tale; i++, k++){
            if (i == size){
                i = -1;
                k--;
            }
        };
        return k;
    }
}

void Deck::print() {
    if (!empty) {
        std::cout << "Дек:" << std::endl;
        for (int i = (head + 1) % size; i != tale; i++) {
            if (i == size){
                i = 0;
            }
            std::cout << deck[i] << '\t';
        }
    } else
    {
        std::cout << "Дек пуст";
    }
    std::cout << std::endl;
}

bool Deck::isEmpty() {
    return empty;
}

unsigned int Deck::getSize() {
    return size - 1;
}

 Deck& Deck::operator= (const Deck& right){

     size = right.size;
     head = right.head;
     tale = right.tale;
     empty = right.empty;
     delete [] deck;
     deck = new int [size];
     for (int i = (head + 1) % size; i != tale; i++) {
         if (i == size){
             i = 0;
         }
         deck[i] = right.deck[i];
     };
    return *this;
}

Deck::Deck(const Deck& copy) {
    size = copy.size;
    head = copy.head;
    tale = copy.tale;
    empty = copy.empty;
    delete [] deck;
    deck = new int [size];
    for (int i = (head + 1) % size; i != tale; i++) {
        if (i == size){
            i = 0;
        }
        deck[i] = copy.deck[i];
    };
}
