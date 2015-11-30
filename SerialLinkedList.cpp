//
// Created by nuran on 11/30/15.
//


#include <iostream>
#include <stdlib.h>
#include "LinkedList.h"
#include <ctime>

using namespace std;

int main() {
    int n=1000,m=1000;
    Node* head = new Node();
    LinkedList* list = new LinkedList();
    boolean condition;
    int i=0;
    long randomValue;

    while(i<n){
        randomValue= rand()%(n*100);
        boolean cond = list->Insert(randomValue,head);

        if(cond)
            i++;
    }
    //creating m operation
    i=0;
    clock_t begin= clock();
    while(i<m){
        int  randomOperation= rand()%3;
        randomValue = rand()%(n*100);
        switch (randomOperation){
            case 0:
                condition=list->Insert(randomValue,head);
                if(condition) i++;
                break;
            case 1:
                condition=list->Member(randomValue,head);
                if(condition) i++;
                break;
            case 2:
                condition=list->Delete(randomValue,head);
                if(condition) i++;
                break;
        }


    }
    clock_t end = clock();
    double elapsed_time = double(end-begin)/CLOCKS_PER_SEC;
    cout << elapsed_time << endl;
    return 0;
}