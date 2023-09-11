#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H

#include "Song.h"

class Node {
public:
    Node(Song d) : data(d), next(nullptr) {}

    friend class SinglyLinkedList;

private:
    Song data;
    Node* next;
};

#endif //UNTITLED_NODE_H
