//
// Created by nuran on 11/30/15.
//
#include <iostream>
#include "LinkedList.h"

boolean Delete(long value,Node* head){
    Node* current_p = head;
    Node* predecessor_p = NULL;
    if(head==NULL)
        return false;
    else
        while(current_p !=NULL && current_p->getValue()<value){
            predecessor_p=current_p;
            current_p=current_p->getNext();
        }

    if(current_p != NULL && current_p->getValue() == value){
        if(predecessor_p == NULL){
            head->setNext(current_p->getNext());
        }else{
            predecessor_p->setNext(current_p->getNext());
        }
        return true;
    } else
        return false;
}

boolean Insert(long value,Node* head){
    Node* current_p = head;
    Node* predecessor_p = NULL;
    Node* node = new Node();
    node->setValue(value);

    if(head==NULL)
        head = node;
    else
        while(current_p != NULL && current_p->getValue()<value){
            predecessor_p = current_p;
            current_p = current_p->getNext();
        }

    if(current_p == NULL || current_p->getValue()>value){
        node->setNext(current_p);
        predecessor_p->setNext(node);
        return true;
    }else
        return false;
}

boolean Member(int value,Node* head){
    Node* iterator = head;

    if(head==NULL)
        return false;
    else
        while(iterator != NULL & iterator->getValue()<value){
            iterator = iterator->getNext();
        }

    if(iterator==NULL || iterator->getValue() > value){
        return false;
    }else
        return true;

}

