#include <iostream>
#include "FCIPriorityQueue.cpp"
#include "Test.h"
using namespace std;



int main() {
    FCIPriorityQueue<Test<int>> qu;
    while (true) {
        cout << "welcome to priority queue program" << endl;
        cout << "1- enqueue" << endl;
        cout << "2- dequeue" << endl;
        cout << "3- first" << endl;
        cout << "4- is empty" << endl;
        cout << "5- print " << endl;
        cout << "0- exit" << endl;
        string choice;
        int value;
        cin >> choice;
        if (choice == "1") {
            cout << "enter the value : " << endl;
            cin >> value;
            int pr;
            cout<<"enter the priority"<<endl;
            cin>>pr;
            Test<int> test(value, pr);

            qu.enqueue(test);
            qu.print();
        } else if (choice == "2") {
            if (!qu.isEmpty()) {
                cout << "item has been removed" << endl;
            }
            qu.dequeue();
            qu.print();

        }  else if (choice == "4") {
            if (qu.isEmpty())
                cout << "queue is empty" << endl;
            else
                cout << "queue is not empty" << endl;
        } else if (choice == "5") {
            if (!qu.isEmpty())
            qu.print();
            else
                cout<<"list is empty";
        } else if (choice == "0") {
            break;
        }else if (choice=="3"){
            if (!qu.isEmpty())
                cout<<qu.first() <<" is the first "<<endl;
            else
                cout<<"queue is already empty"<<endl;
        }
    }
    return 0;
}
