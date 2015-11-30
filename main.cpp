#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "LinkedList.h"

using namespace std;

void serialProgram(int n,  int m);
void parallelProgramWithOneMutex(int n, int m);
void parallelProgramWithReadWriteLocks(int n, int m);


int main() {
    cout << "Concurrent Programming Assignment - 2\n";


    return 0;
}

void serialProgram(int n,int m){
    Node* head = new Node();
    LinkedList* list = new LinkedList();
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
    while(i<m){
        int  randomOperation= rand()%3;
        randomValue = rand()%(n*100);
        switch (randomOperation){
            case 0:
                list->Insert(randomValue,head);
                break;
            case 1:
                list->Member(randomValue,head);
                break;
            case 2:
                list->Delete(randomValue,head);
                break;
        }


    }
}

void parallelProgramWithOneMutex(int n, int m){
    Node* head = new Node();
    LinkedList* list = new LinkedList();

    pthread_mutex_t* mutex_p = new pthread_mutex_t();

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
    while(i<m){
        int  randomOperation= rand()%3;
        randomValue = rand()%(n*100);
        switch (randomOperation){
            case 0:
                pthread_mutex_lock(mutex_p);
                list->Insert(randomValue,head);
                pthread_mutex_unlock(mutex_p);
                break;
            case 1:
                pthread_mutex_lock(mutex_p);
                list->Member(randomValue,head);
                pthread_mutex_unlock(mutex_p);
                break;
            case 2:
                pthread_mutex_lock(mutex_p);
                list->Delete(randomValue,head);
                pthread_mutex_unlock(mutex_p);
                break;
        }


    }

}
void parallelProgramWithReadWriteLocks(int n, int m){
    cout<< "parallel Program implementation";

}
