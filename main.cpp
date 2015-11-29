#include <iostream>
#include <jmorecfg.h>
#include "Node.h"

using namespace std;

boolean Delete(long value,Node* head);
void Insert(long value, Node* head);
boolean member(int value,Node* head);


int main() {
    Node* head;
    cout << "Concurrent Programming Assignment - 2\n";

    try{
        Insert(10,head);
        Delete(1,head);
    }catch (const std::exception & e){
        cerr<<e.what()<<endl;
    }

    return 0;
}



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

void Insert(long value,Node* head){
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
    }
}

boolean member(int value,Node* head){
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

