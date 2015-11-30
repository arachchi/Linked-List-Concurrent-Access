//
// Created by nuran on 11/30/15.
//

#ifndef CP_LAB_2_LINKEDLIST_H
#define CP_LAB_2_LINKEDLIST_H

#include <jmorecfg.h>
#include "Node.h"

class LinkedList {

public:

    boolean Delete(long value,Node* head);
    boolean Insert(long value, Node* head);
    boolean Member(int value,Node* head);

};


#endif //CP_LAB_2_LINKEDLIST_H
