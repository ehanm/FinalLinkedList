#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

using namespace std;

void addstudent(Node* &previous, Node* &node, char name[], int id, float gpa);
void printstudent(Node* node, int checklist);
void removestudent(Node* &head, Node* node, Node* previous, int id);
void averagegpa(Node* node, float average, int totalnodes);


int main(){

  char input[10000];
  Node* head = NULL;
  
  int checkstudent = 0;
  
  float average;
  int totalnodes;

  Node* previous;
  Node* next;

  bool running = true;

  int insertid;

  cout << "Welcome to LinkedList! This does the same stuff as StudentList, but with Nodes instead of vectors." << endl;
  
  while (running == true){
    
    cout << "What would you like to do? (ADD, PRINT, DELETE, QUIT, AVERAGE)" << endl;
    cin >> input;

    if (strcmp(input, "ADD") == 0){

      char nameinput[1000];
      int idinput;
      float gpainput;

      
      cout << "Insert the student's name: " << endl;
      
      cin >> nameinput;
      
      cout << "Insert the student's ID number: " << endl;
      
      cin >> idinput;
      
      cout << "Insert the student's GPA; " << endl;
      
      cin >> gpainput;
      
      addstudent(previous, head, nameinput, idinput, gpainput);
            
    }

    else if (strcmp(input, "PRINT") == 0){

      checkstudent = 0;
      
      printstudent(head, checkstudent);
      
    }

    else if (strcmp(input, "DELETE") == 0){

      cout << "Enter the ID of the student you want to delete: " << endl;

      cin >> insertid;

      removestudent(head, head, previous, insertid);
  
    }

    else if (strcmp(input, "QUIT") == 0){

      running = false;
      break;
      
    }

    else if (strcmp(input, "AVERAGE") == 0){

      average = 0;
      totalnodes = 0;

      averagegpa(head, average, totalnodes);

    }
    
    
  }

  return 0;
}

void addstudent(Node* &previous, Node* &node, char name[], int id, float gpa){
  
  if (node == NULL){

    node = new Node(new Student());
    
    strcpy(node->getStudent()->name, name);
    node->getStudent()->id = id;
    node->getStudent()->gpa = gpa;

    return;
    
  }

  else if (node->getNext() == NULL) {

    cout << "it gets here first";
    
    Node* newnode;

    Student* newstudent = new Student();
    
    newnode = new Node(newstudent);

    if (previous == NULL && node->getStudent()->id > id){
      
      newnode->setNext(node);

      node = newnode;

      strcpy(newnode->getStudent()->name, name);
      newnode->getStudent()->id = id;
      newnode->getStudent()->gpa = gpa;
      
    }
    
    else if (node->getStudent()->id > id){

      cout << "gets here";
      
      previous->setNext(newnode);
      
      newnode->setNext(node);

      node = newnode;
      
      strcpy(newnode->getStudent()->name, name);
      newnode->getStudent()->id = id;
      newnode->getStudent()->gpa = gpa;

    }

    else if (node->getStudent()->id < id){

      node->setNext(newnode);
      
      strcpy(newnode->getStudent()->name, name);
      newnode->getStudent()->id = id;
      newnode->getStudent()->gpa = gpa;
      
    }

    return;
    
  }
  
  else {
    
    Node* newnode = node->getNext();

    addstudent(node, newnode, name, id, gpa);
    
  }

}

void printstudent(Node* node, int checklist){

  if (node == NULL && checklist == 0){

    cout << "List is empty!" << endl;
    return;
    
  }
  
  if (node != NULL) {

    checklist++;
    
    cout << node->getStudent()->name;
    cout << " ";
    cout << node->getStudent()->id;
    cout << " ";
    cout << node->getStudent()->gpa;

    cout << endl;
    
    printstudent(node->getNext(), checklist);
    
  }
  
  
}

void removestudent(Node* &head, Node* node, Node* previous, int id){

  if (node != NULL) {

    if (node->getStudent()->id == id && head == node) {

      head = node->getNext();
      
      node->~Node();
      
      return;

    }
    else if (node->getStudent()->id == id) {

      previous->setNext(node->getNext());
      
      node->~Node();
      
      return;
      
    }

    previous = node;

    Node* nextnode = node->getNext();

    removestudent(head, previous, nextnode, id);
    
  }

  else if (node == NULL) {

    cout << "Couldn't find that student!" << endl;

  }

  
  
}

void averagegpa(Node* node, float average, int totalnodes){

  if (node == NULL) {

    cout << "Nothing to average!";

    return;
  }
  
  else if (node != NULL) {
    
    average += node->getStudent()->gpa;

    totalnodes++;
    
    Node* nextnode = node->getNext();
    
    averagegpa(nextnode, average, totalnodes);
    
  }

  else {
    
    average = average / totalnodes;

    cout << "The average of the Students' GPA is: " << average << endl;

  }
}
