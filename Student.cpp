/*
Henry Xu
C++
11/13/24
student.cpp
*/
#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

Student::Student(){
  first = new char[50];
  last = new char[50];
  ID = 0;
  GPA = 0.0;
}

Student::~Student(){
  delete[] first;
  delete[] last;
}

void Student::makestudent(char* nfirst, char* nlast, int nID, float NGPA){
  strcpy(first, nfirst);
  strcpy(last, nlast);
  ID = nID;
  GPA = NGPA;
}

char* Student::getfirst(){
  return first;
}
char* Student::getlast(){
  return last;
}
int Student::getID(){
  return ID;
}
float Student::getGPA(){
  return GPA;
}