//
// Created by nuran on 11/30/15.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "LinkedList.h"
#include <ctime>

using namespace std;

void *calculation(void* arg);

double total_time=0;
pthread_mutex_t* mutex_total = new pthread_mutex_t();

int n =1000, m =10000,mDelete,mMember,mInsert;
Node* head = new Node();

LinkedList* list = new LinkedList();

pthread_rwlock_t* rwlock_t = new pthread_rwlock_t();

int main(int argc, char* argv[]) {
    int value = atoi(argv[1]);
    mMember = atof(argv[2]);
    mInsert = atof(argv[3]);
    mDelete = atof(argv[4]);

    pthread_t threads[value];

    cout << "Parallel Linked list with Readers Writers Lock"<< endl;

    for(int id=1;id<=value;id++){
        int ret = pthread_create(&threads[id],NULL,&calculation,(void*)id);
        if(ret != 0)
            cout<< "failed"<<endl;
    }
    for(int id=1;id<=value;id++)
        pthread_join(threads[id],NULL);

    cout << "Total time taken : " << total_time/value <<endl;
    pthread_exit(NULL);
}

void *calculation(void *arg){

    int i=0;
    long randomValue;

    while(i<n){
        randomValue= rand()%(n*100);
        boolean cond = list->Insert(randomValue,head);

        if(cond)
            i++;
    }
    //creating m operations

    clock_t begin= clock();
    for (i = 0; i < m; ++i)
    {
        float operation = rand();
        randomValue = rand() % (n * 100);
        if(operation<=mMember){
            pthread_rwlock_wrlock(rwlock_t);
            list->Insert(randomValue, head);
            pthread_rwlock_unlock(rwlock_t);
        }else if(operation<=mMember+mInsert){
            pthread_rwlock_rdlock(rwlock_t);
            list->Member(randomValue, head);
            pthread_rwlock_unlock(rwlock_t);
        }else{
            pthread_rwlock_wrlock(rwlock_t);
            list->Delete(randomValue,head);
            pthread_rwlock_unlock(rwlock_t);
        }
    }
    clock_t end = clock();
    double elapsed_time = double(end-begin)/CLOCKS_PER_SEC;

    /*Time assignment*/
    pthread_mutex_lock(mutex_total);
    total_time+=elapsed_time;
    pthread_mutex_unlock(mutex_total);

    pthread_exit(NULL);
}