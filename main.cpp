#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

using namespace std;

void addstudent(Node* &previous, Node* &node, char name[], int id, float gpa);
void printstudent(Node* node);
void removestudent(Node* &node);
void averagegpa(Node* node, float average, int totalnodes);


int main(){

  char input[10000];
  Node* head = NULL;
  Student* newstudent;

  float average;
  int totalnodes;

  Node* previous = NULL;
  Node* next;

  bool running = true;

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

    Node* newnode;

    Student* newstudent = new Student();
    
    newnode = new Node(newstudent);

    if (previous == NULL){

      newnode->setNext(node);

      node = newnode;

      strcpy(newnode->getStudent()->name, name);
      newnode->getStudent()->id = id;
      newnode->getStudent()->gpa = gpa;
      
    }
    
    if (node->getStudent()->id > id){

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

  else if (id > node->getStudent()->id) {
    
    Node* newnode = node->getNext();

    addstudent(node, newnode, name, id, gpa);
    
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

void averagegpa(Node* node, float average, int totalnodes){

  if (node != NULL) {
    
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
