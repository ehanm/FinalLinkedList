#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

using namespace std;

void addstudent(Node* &node);
void printstudent(Node* node);
void removestudent(Node* &node);

int main(){

  char input[10000];
  Node* head = NULL;
  Student* newstudent;

  bool running = true;

  cout << "Welcome to LinkedList! This does the same stuff as StudentList, but with Nodes instead of vectors." << endl;
  
  while (running == true){
    
    cout << "What would you like to do? (ADD, PRINT, DELETE, QUIT, AVERAGE)" << endl;
    cin >> input;

    if (strcmp(input, "ADD") == 0){      
      
      addstudent(head);
            
    }

    else if (strcmp(input, "PRINT") == 0){

      printstudent(head);
      
    }

    else if (strcmp(input, "DELETE") == 0){

      cout << "delete stuff" << endl;
      
    }

    else if (strcmp(input, "QUIT") == 0){

      running = false;
      break;
      
    }

    else if (strcmp(input, "AVERAGE") == 0){

      cout << "Averages" << endl;

    }
    
    
  }

  return 0;
}

void addstudent(Node* &node){

  char nameinput[1000];
  int idinput;
  float gpainput;
  
  if (node == NULL){
    node = new Node(new Student());
    
    cout << "Insert the student's name: " << endl;

    cin >> nameinput;
    
    cout << "Insert the student's ID number: " << endl;

    cin >> idinput;

    cout << "Insert the student's GPA; " << endl;
    
    cin >> gpainput;

    strcpy(node->getStudent()->name, nameinput);
    node->getStudent()->id = idinput;
    node->getStudent()->gpa = gpainput;
    
  }

  else if (node->getNext() != NULL) {

    Node* newnode = node->getNext();
    
    addstudent(newnode);

  }

  else if (node->getNext() == NULL) {

    Node* newnode;

    Student* newstudent = new Student();
    
    newnode = new Node(newstudent);

    node->setNext(newnode);
    
    cout << "insert the student's name: " << endl;

    cin >> nameinput;

    cout << "Insert the student's ID number: " << endl;

    cin >> idinput;

    cout << "Insert the student's gpa: " << endl;

    cin >> gpainput;

    strcpy(newnode->getStudent()->name, nameinput);
    newnode->getStudent()->id = idinput;
    newnode->getStudent()->gpa = gpainput;
    

  }

}

void printstudent(Node* node){
  
  if (node != NULL) {
    
    cout << node->getStudent()->name;
    cout << " ";
    cout << node->getStudent()->id;
    cout << " ";
    cout << node->getStudent()->gpa;

    cout << endl;
    
    printstudent(node->getNext());
    
  }
  
  
}

void removestudent(Node* &node){

  int insertid;
  
  cout << "Enter the ID of the student you want to delete: " << endl;

  cin >> insertid;

}
