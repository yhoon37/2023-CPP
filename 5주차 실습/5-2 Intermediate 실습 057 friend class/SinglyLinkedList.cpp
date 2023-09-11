#include "SinglyLinkedList.h"
#include <iostream>

void SinglyLinkedList::addNode(Song data){
    if(head == nullptr){
        Node* newNode = new Node(data);
        head = newNode;
    }
    else{
        Node* newNode = new Node(data);
        newNode->next = head;  //newNode->next가 가능한 이유는 next가 private이지만 friend class라서다
        head = newNode;
    }
}

void SinglyLinkedList::removeNode(Song data){
    Node* find = head, * prev = nullptr;
    while(find != nullptr){
        if( find->data.equals(data)){//지우고자 하는 데이터면...
            if(prev){
                prev->next = find->next;
            }
            else{
                head = find->next;
            }
            delete find;
            break;
        }
        prev = find;
        find = find->next;
    }
}

void SinglyLinkedList::printList(){
    Node* current = head;
    std::cout << "Playlist:" << std::endl;
    while(current){
        std::string message = current->data.toString();
        std::cout << message << std::endl;

        current = current->next;
    }
}

