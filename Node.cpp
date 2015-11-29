//
// Created by nuran on 11/28/15.
//

#include "Node.h"

Node* Node::getNext(){
    return this->next;
}
void Node::setNext(Node* next){
    this->next =next;
}

int Node::getId(){
    return this->id;
}
void Node::setId(int id){
    this->id=id;
}

long Node::getValue(){
    return this->value;
}

void Node::setValue(long value){
    this->value = value;
}
