/*
Henry Xu
LinkedList 2
Using code from Elliot
1/2/2025
Note that I commented out all of the unused code in Node.H and Node.cpp from elliots code.
Additionally I will be refrencing my own code from studentlist and both student.cpp and student.h were copied from linkedlist1
*/
#include <iostream>
#include <cstring>
#include "student.h"
#include "node.h"
#include <vector>

using namespace std;

void addS();//prepare the functions
void printS();
void deleteS();

int main(){
    Node* headNode = nullptr;
    char command[50];
    vector<Student*> studentslist;//create the vector of pointers
    while(true){
        cout << "What command would you like to run?" << endl;//ask the user for the command they would like to run
        cin >> command;
        char add[50] = "add";
        char print[50] = "print";
        char delet[50] = "delete";
        char quit[50] = "quit";
        if (strcmp(command, add) == 0){//if they run the command add then run the function add
            addS();
            }
        else if (strcmp(command, print) == 0){//if they run the command print then run the function print
            printS();
            }
        else if (strcmp(command, delet) == 0){//if they run the command delete then run the function delete
            deleteS();
            }
        else if (strcmp(command, quit) == 0){//if they run the command quit then delete all the students in the vector list
            if(headNode != NULL){
                while(headNode != nullptr){
                    if(headNode->getNext() != nullptr){
                        Node* nextNode = headNode->getNext();
                        delete headNode;
                        headNode = nextNode;
                        }
                    else{
                        delete headNode;
                        break;
                    }
                    } 
                }
            break;
            }
        else{
            cout << "Your input was not valid your options are: add, print, delete, quit.";//their command isn't valid
        }
          return 0;
    }
