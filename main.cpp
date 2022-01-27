#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

using namespace std;

void addstudent(Node* node);
void printstudent(Node* node);


int main(){

  char input[10000];
  Node* head = NULL;
  Node* current;
  Student* newstudent;

  bool running = true;

  cout << "Welcome to LinkedList! This does the same stuff as StudentList, but with Nodes instead of vectors." << endl;
  
  while (running == true){
    
    cout << "What would you like to do? (ADD, PRINT, DELETE, QUIT, AVERAGE)" << endl;
    cin >> input;

    if (strcmp(input, "ADD") == 0){      
      
      addstudent(head);
            
    }

    if (strcmp(input, "PRINT") == 0){

      
    }

    if (strcmp(input, "DELETE") == 0){

      cout << "delete stuff" << endl;
      
    }

    if (strcmp(input, "QUIT") == 0){

      running = false;
      break;
      
    }

    if (strcmp(input, "AVERAGE") == 0){

      cout << "Averages" << endl;

    }
    
    
  }

  return 0;
}

void addstudent(Node* node){

  char nameinput[1000];
  int idinput;
  int gpainput;
  
  Student* newstudent;
  Node* current = node;

  if (current == NULL){
    node = new Node(newstudent);

    cout << "Insert the student's name: " << endl;

    cin >> nameinput;
    
    cout << "Insert the student's ID number: " << endl;

    cin >> idinput;

    cout << "Insert the student's GPA; " << endl;
    
    cin >> gpainput;


    newstudent = new Student(nameinput, idinput, gpainput);
    
  }

}

void printstudent(Node* node){

  

  
}
