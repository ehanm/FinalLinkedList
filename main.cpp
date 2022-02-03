// Made by Ehan Masud
// Completed 2/2/2022 (Wow!)
// Basically the same as StudentList, but instead made using nodes

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Node.h"
#include "Student.h"

using namespace std;

void addstudent(Node* &previous, Node* &node, char name[], int id, float gpa); // prototypes
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
  
  while (running == true){ // runs until user enters "QUIT"
    
    cout << "What would you like to do? (ADD, PRINT, DELETE, QUIT, AVERAGE)" << endl;
    cin >> input;

    if (strcmp(input, "ADD") == 0){ // gets all inputs, then passes it into the add function

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

    else if (strcmp(input, "PRINT") == 0) { // checkstudent just exists to make sure the list isn't empty

      checkstudent = 0;
      
      printstudent(head, checkstudent);
      
    }

    else if (strcmp(input, "DELETE") == 0) { // again, read in the input before passing it in

      cout << "Enter the ID of the student you want to delete: " << endl;

      cin >> insertid;

      removestudent(head, head, previous, insertid);
  
    }

    else if (strcmp(input, "QUIT") == 0){ // quits

      running = false;
      break;
      
    }

    else if (strcmp(input, "AVERAGE") == 0){ // resets the average and totalnodes in case more nodes are added

      average = 0;
      totalnodes = 0;

      averagegpa(head, average, totalnodes);

    }
    
    
  }

  return 0;
}

void addstudent(Node* &previous, Node* &node, char name[], int id, float gpa){
  
  if (node == NULL){ // if no nodes exist, make the first one

    node = new Node(new Student());
    
    strcpy(node->getStudent()->name, name);
    node->getStudent()->id = id;
    node->getStudent()->gpa = gpa;

    return;
    
  }

  else if (node->getNext() == NULL) { // if recursion lead to the end of the list, check through the if statements to find where to put the new node

    cout << "it gets here first";
    
    Node* newnode;

    Student* newstudent = new Student();
    
    newnode = new Node(newstudent);

    if (previous == NULL && node->getStudent()->id > id){ // if the list is only one node large, move new node to beginning
      
      newnode->setNext(node);

      node = newnode;

      strcpy(newnode->getStudent()->name, name);
      newnode->getStudent()->id = id;
      newnode->getStudent()->gpa = gpa;
      
    }
    
    else if (node->getStudent()->id > id){ // if the last node has a larger id than the new node, move it directly behind.
      
      previous->setNext(newnode);
      
      newnode->setNext(node);

      node = newnode;
      
      strcpy(newnode->getStudent()->name, name);
      newnode->getStudent()->id = id;
      newnode->getStudent()->gpa = gpa;

    }

    else if (node->getStudent()->id < id){ // if the new node has a larger id than the last node, move it in front.

      node->setNext(newnode);
      
      strcpy(newnode->getStudent()->name, name);
      newnode->getStudent()->id = id;
      newnode->getStudent()->gpa = gpa;
      
    }

    return;
    
  }
  
  else { // if it didn't fit any of the cases, recurse again
    
    Node* newnode = node->getNext();

    addstudent(node, newnode, name, id, gpa);
    
  }

}

void printstudent(Node* node, int checklist){ // prints out the students

  if (node == NULL && checklist == 0){ // if list is empty

    cout << "List is empty!" << endl;
    return;
    
  }
  
  if (node != NULL) { // if the list is not empty, also changes checklist just to make sure it doesn't run the first if statement

    checklist++;
    
    cout << node->getStudent()->name;
    cout << " ";
    cout << node->getStudent()->id;
    cout << " ";
    cout << setprecision(2) << fixed << node->getStudent()->gpa;

    cout << endl;
    
    printstudent(node->getNext(), checklist);
    
  }
  
  
}

void removestudent(Node* &head, Node* node, Node* previous, int id){

  if (node != NULL) { // only deletes if the node exists

    if (node->getStudent()->id == id && head == node) { // if head is being deleted

      head = node->getNext();
      
      node->~Node();
      
      return;

    }
    else if (node->getStudent()->id == id) { // if any other node that's being recursed through matches

      previous->setNext(node->getNext());
      
      node->~Node();
      
      return;
      
    }

    // if no if statements have been reached, keep recursing
    
    previous = node;

    Node* nextnode = node->getNext();

    removestudent(head, previous, nextnode, id);
    
  }

  else if (node == NULL) { // if at the end of the list and no id found, student doesn't exist

    cout << "Couldn't find that student!" << endl;

  }

  
  
}

void averagegpa(Node* node, float average, int totalnodes){

  if (node == NULL) { // if there are no nodes, nothing to average

    cout << "Nothing to average!";

    return;
  }
  
  else if (node != NULL) { // goes through list, adds all gpas to a specific float
    
    average += node->getStudent()->gpa;

    totalnodes++; // goes up every time it passes a node
    
    Node* nextnode = node->getNext();
    
    averagegpa(nextnode, average, totalnodes);
    
  }

  else {
    
    average = average / totalnodes; // finds average

    cout << "The average of the Students' GPA is: " << setprecision(2) << fixed << average << endl; // prints average

  }
}
