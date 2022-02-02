#include "Node.h"
#include "Student.h"
using namespace std;
Node::Node(Student* newStudent) {
  next = NULL;
  student = newStudent;
}
Node::~Node() {
  next = NULL;
  delete student;
}
void Node::setNext(Node* newNode) {
  next = newNode;
}
Node* Node::getNext() {
  return next;
}
Student* Node::getStudent() {
  return student;
}
