#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(char newname[1000], int newid, float newgpa){

  strcpy(name, newname);
  id = newid;
  gpa = newgpa;
  
}
