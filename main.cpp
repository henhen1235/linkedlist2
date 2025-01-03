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
#include <iomanip>

using namespace std;

void addS(Node* &headNode);//prepare the functions
void printS(Node* headNode);
void deleteS(Node* &headNode);
void checknext(Node* &tempnode, int nid, Node* currentnode);

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
            addS(headNode);
            }
        else if (strcmp(command, print) == 0){//if they run the command print then run the function print
            printS(headNode);
            }
        else if (strcmp(command, delet) == 0){//if they run the command delete then run the function delete
            deleteS(headNode);
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
    }
    return 0;
}

    void addS(Node* &headNode){//adding a new student function
        char fname[20];
        char lname[20];
        float gpa;
        int id;
        Student* newStudent = new Student;//create a new student
        cout << "What is the student's first name?:";//ask for their info
        cin >> fname;
        cout << "What is the student's last name?:";
        cin >> lname;
        cout << "What is the student's GPA?:";
        cin >> gpa;
        cout << "What is the student's ID?:";
        cin >> id;


        newStudent->makestudent(fname, lname, id, gpa);
        Node* newnode = new Node(newStudent);
        
        if (headNode == nullptr){//set as head if head doens't exist
            cout << "adding as headnode" << endl;
            headNode = newnode;
        }
        else if(headNode->getStudent()->getID() > id){
            cout << "adding as new head node" << endl;
            newnode->setNext(headNode);
            headNode = newnode;
        }
        else{
            cout << "Scanning nodes" << endl;
            checknext(headNode, id, newnode);
        }
        cout << "Student has been added!" << endl;
    }

    void printS(Node* headNode){//function for printing students
        cout << "Info:" << headNode->getStudent()->getfirst() 
        << " " << headNode->getStudent()->getlast() << ", " 
        << headNode->getStudent()->getID() << ", " 
        << fixed << setprecision(2)
        << headNode->getStudent()->getGPA() << endl;
        while(headNode->getNext() != nullptr){
            headNode = headNode->getNext();
            cout << "Info:" << headNode->getStudent()->getfirst() 
            << " " << headNode->getStudent()->getlast() << ", " 
            << headNode->getStudent()->getID() << ", " 
            << fixed << setprecision(2)
            << headNode->getStudent()->getGPA() << endl;
        }   
    }
    
    void deleteS(Node* &headNode) {//function for deleting students
        
    }

    void checknext(Node* &tempnode, int nid, Node* newnode){
        Node* tempnode2 = tempnode->getNext();
        if(tempnode2 == nullptr){
            tempnode->setNext(newnode);
            return;
        }
        if(tempnode2->getStudent()->getID() < nid){
            cout << "+1" << endl;
            checknext(tempnode2, nid, newnode);
        }
        else{
            tempnode->setNext(newnode);
            newnode->setNext(tempnode2);
        }
    }
