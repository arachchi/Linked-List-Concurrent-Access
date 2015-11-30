//
// Created by nuran on 11/28/15.
//

#ifndef CP_LAB_2_NODE_H
#define CP_LAB_2_NODE_H


class Node {
public:
    Node* next;
    int id;
    long value;


    Node* getNext();
    void setNext(Node* next);

    int getId();
    void setId(int id);

    long getValue();
    void setValue(long value);
};


#endif //CP_LAB_2_NODE_H
