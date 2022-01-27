#include <iostream>
#include <cstring>

#ifndef STUDENTFILE
#define STUDENTFILE

using namespace std;

class Student {

 public:

  Student(char newname[1000], int newid, float gpa);
  
  char name[1000];
  int id;
  float gpa;  

};

#endif
