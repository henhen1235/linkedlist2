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

void addS(Node* &headNode);//prepare the functions
void printS(Node* &headNode);
void deleteS(Node* &headNode);

int main(){
    Node* headNode;
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
    cout << "hi";
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
        Node* tempnode = new Node(newStudent);
        if (headNode == nullptr){
            headNode = tempnode;
        }
        else{
            Node* tempnode2 = headNode;
            while(tempnode2->getNext() != nullptr){
                tempnode2 = tempnode2->getNext();
            }
            tempnode2->setNext(tempnode);
        }
        cout << "Student has been added!" << endl;
    }




    void printS(Node* &headNode){//function for printing students
        cout << "hi2";
        // int count = 1;
        // for(Student* currentstudent: studentslist){ //for each student
        //     float gpa = currentstudent->gpa;
        //     float roundedgpa = round(gpa*100)/100;//round their GPA and print out their basic info
        //     cout << "Student " << count << " "<< currentstudent->firstName << " " << currentstudent->lastName << endl;
        //     cout << "GPA:" << fixed << setprecision(2) << currentstudent->gpa << " Student ID:" << currentstudent->studentID << endl;
        //     count++;
        // }
    }
    void deleteS(Node* &headNode) {//function for deleting students
        cout << "hi3";

    //     int del;
    //     std::cout << "Which student would you like to delete? Print out their ID: ";
    //     std::cin >> del;//find their ID and save it.
        
    //     for (auto it = studentslist.begin(); it != studentslist.end(); it++) {//go through the list of students
    //         if ((*it)->studentID == del) {//when you find their id
    //             delete *it;//delete it from the heap
    //             studentslist.erase(it);//delete it from the vector
    //             cout << "Student# " << del << " has been deleted." << endl;
    //             return;
    //         }
    //     }
    //     cout << "This student doesn't exist" << endl;//if the id doesn't exist then print it out.
    // }
}
