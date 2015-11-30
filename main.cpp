#include <iostream>
#include "LinkedList.h"

using namespace std;

void serialProgram();
void parallelProgramWithOneMutex();
void parallelProgramWithReadWriteLocks();


int main() {
    Node* head = new Node();
    LinkedList* list = new LinkedList();
    cout << "Concurrent Programming Assignment - 2\n";

    try{
        list->Insert(12,head);
    }catch (const std::exception & e){
        cerr<<e.what()<<endl;
    }

    return 0;
}
