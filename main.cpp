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
void deleter(Node* tempnode,int id);
void average(Node* headNode);
void averager(Node* nextnode, float &sum, int &iteration);

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
        char avg[50] = "average";
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
         else if (strcmp(command, avg) == 0){//if they run the command delete then run the function delete
            average(headNode);
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
            cout << "Your input was not valid your options are: add, print, delete, quit, average.";//their command isn't valid
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
            headNode = newnode;
        }
        else if(headNode->getStudent()->getID() > id){//if the head is bigger then the new Id we can replace it
            newnode->setNext(headNode);
            headNode = newnode;
        }
        else{//call function to recursivly find the next slot from smallest to largest
            checknext(headNode, id, newnode);
        }
        cout << "Student has been added!" << endl;
    }

    void printS(Node* headNode){//function for printing students
        if(headNode == nullptr){//if there list isn't empty
            return;
        }
        cout << "Info:" << headNode->getStudent()->getfirst() //print out their info
            << " " << headNode->getStudent()->getlast() << ", " 
            << headNode->getStudent()->getID() << ", " 
            << fixed << setprecision(2)
            << headNode->getStudent()->getGPA() << endl;
        printS(headNode->getNext()); //do it again recursivly
    }
    
    void deleteS(Node* &headNode) {//function for deleting students
        cout << "What Id would you like to delete?";//prompt for ID
        int id;
        cin >> id;
        if(headNode->getStudent()->getID() == id){//if the id is the head then replace
            Node* nextNode = headNode->getNext();
            delete headNode;
            headNode = nextNode;
        }
        deleter(headNode, id);//call a function to check id recursivly
    }

    void average(Node* headNode){//average function
        if(headNode == nullptr){//if there is nothing
            cout << "there is nothing" << endl;
            return;
        }

        float sum = headNode->getStudent()->getGPA();
        int iteration = 1;
        averager(headNode->getNext(), sum, iteration);//call a function to recursivly add the gpa togeter
        float finalaverage = sum/iteration;//claculat it
        cout << "gpa average is: " << fixed << setprecision(2) << finalaverage << endl;
    }

    void averager(Node* nextnode, float &sum, int &iteration){//function for recursivly adding gpa
        sum = sum + nextnode->getStudent()->getGPA();//add gpa
        iteration++;//add iteration
        if(nextnode->getNext() == nullptr){
            return;//if it is the end of the linkedlist
        }
        else{//run it again with the next node
            averager(nextnode->getNext(), sum, iteration);
        }
    }

    void deleter(Node* tempnode, int nid){//recursivly delete
        if(tempnode->getNext()->getStudent()->getID() != nid){
            deleter(tempnode->getNext(), nid);//if your id doens't match the input id then run this functiona again
        }
        else{//if it matches then delete it
            Node* badnode = tempnode->getNext();
            tempnode->setNext(badnode->getNext());
            delete badnode;
        }
    }
    void checknext(Node* &tempnode, int nid, Node* newnode){//checking the next node recursivly and adding
        Node* tempnode2 = tempnode->getNext();
        if(tempnode2 == nullptr){//if the next node is the end then add node in at end
            tempnode->setNext(newnode);
            return;
        }//if the next node is smaller then run this function again
        if(tempnode2->getStudent()->getID() < nid){
            checknext(tempnode2, nid, newnode);
        }
        else{//if node is bigger or equal then replace the node with this node and push everything back
            tempnode->setNext(newnode);
            newnode->setNext(tempnode2);
        }
    }
