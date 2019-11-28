// CS 211 2019 FALL
// Project 6
// Arvinbayar Jamsranjav

#include "Island.h"

MyNode::MyNode (int v1)
{
  elem = v1;
  next = NULL;
}
  
MyNode::MyNode (int v1, MyNode* n)
{
  elem = v1;
  next = n;
}

void MyNode::setElem (int e)
{
  elem = e;
}

int MyNode::getElem ()
{
  return elem;
}

void MyNode::setNext (MyNode* n)
{
  next = n;
}

MyNode* MyNode::getNext()
{
  return next;
}

//-----------------------------------------------
// constructor
MyList::MyList()
{
  head = NULL;
}
// deconstructor
MyList::~MyList()
{
    removeAll();
}
// display the list
void MyList::show()
{
 MyNode *temp = head;
 while(temp != NULL) {
     printf( "%d ", temp->getElem());
     temp = temp->getNext();
 }
}
// checks if its empty
bool MyList::isEmpty()
{
  MyNode *temp1 = head;
  if(head == NULL) {
      return true;
  }
  return false;
}
// insert
void MyList::insert (int v1)
{
  MyNode* tmp = new MyNode (v1);
  
  MyNode *curr = head;
  MyNode *prev = NULL;

  while(curr != NULL && curr->getElem() < v1) {
      prev = curr;
      curr = curr->getNext();
  }
    
  tmp->setNext(curr);
    
  if(prev == NULL) {
      head = tmp;
  } 
  else {
      prev->setNext(tmp);
  }
}
// gets the length
int MyList::getListLength()
{
    MyNode *temp = head;
    int length = 0;
    while(temp != NULL) {
        length++;
        temp = temp->getNext();
    }
    return length;
}
// remove from the list
void MyList::remove (int v1)
{
  MyNode* curr = head;
  MyNode* prev = NULL;
    
  while ( (curr != NULL) && (curr->getElem() != v1) )
  {
      prev = curr;
      curr = curr->getNext();
  }
    
  if(curr == NULL) {
      return;
  }
  
  if(prev == NULL) {
      head = curr->getNext();
  }
  else {
      prev->setNext(curr->getNext());
  }
  delete curr;
}

// finds nth element
int MyList::getNthElem(int v1)
{
    MyNode* temp = head;
    int count = 0;
    
    while (temp != NULL) {
        if(count == v1) {
            return temp->getElem();
        }
        count++;
        temp = temp->getNext();
    }
}

// removes all list
void MyList::removeAll()
{
    if(head == NULL) {
        return;
    }
    
    MyNode* temp = head;
    MyNode* next = NULL;
    
    while(temp != NULL) {
        next = temp->getNext();
        delete temp;
        temp = next;
    }
    head = NULL; 
}

// search and if find returns 1
int MyList::search(int v1)
{
    if(head == NULL) {
        
        return 0;
    }
    MyNode* temp = head;
    
    while(temp != NULL) {
        if(temp->getElem() == v1) {
            return 1;
        }
        temp = temp->getNext();
    }
    return 0;
}

// if u need head
MyNode* MyList::getHead()
{
    if(head == NULL) {
        return NULL;
    }
    return head;
}

//-------------------------------------
//constructor
FileNode::FileNode (char* fileName)
{
  name = fileName;
  next = NULL;
}
// gets file name
char* FileNode::getName()
{
  return name;
}
// set *-> next
void FileNode::setNext (FileNode* n)
{
  next = n;
}
// gets next
FileNode* FileNode::getNext()
{
  return next;
}

//-------------------------------------
// constructor
FileList::FileList()
{
  head = NULL;
}
// deconstructor
FileList::~FileList()
{
  removeAll();
}
// same as deconstructor
void FileList::removeAll()
{
    if(head == NULL) {
        return;
    }
    
    FileNode* temp = head;
    FileNode* next = NULL;
    
    while(temp != NULL) {
        next = temp->getNext();
        delete temp;
        temp = next;
    }
    head = NULL; 
}
// add file name 
void FileList::addName(char* fileName)
{
    FileNode* tmp = new FileNode(fileName);

    if(head == NULL) {
      head = tmp;
      cout <<"TEST!!!!\n";
      return;
    }
    FileNode *curr = head;
    while(curr->getNext() != NULL) {
      curr = curr->getNext();
    }
    curr->setNext(tmp);
    
}
// check if its open or not
bool FileList::isOpen(char* fileName)
{
    if(head==NULL) {
        return false;
    }
    
    FileNode *temp = head;
  
    while(temp != NULL) {
        if ( strcmp(temp->getName(), fileName)==0){
            return true;
        }
        temp = temp->getNext();
    }
    return false;
}
// remove one file node
void FileList::removeOneFile (char* fileName)
{
  FileNode* curr = head;
  FileNode* prev = NULL;
    
  while ( (curr != NULL) && (curr->getName() != fileName) )
  {
      prev = curr;
      curr = curr->getNext();
  }
    
  if(curr == NULL) {
      return;
  }
  
  if(prev == NULL) {
      head = curr->getNext();
  }
  else {
      prev->setNext(curr->getNext());
  }
  delete curr;
}

//-------------------------------------

Island::Island()
{
    visited = false;
}

Island::~Island()
{
    listStart.removeAll();
}

void Island::addedge(int v1)
{
    listStart.insert(v1);
}

bool Island::existingEdge(int v1)
{
    if(listStart.search(v1) == 1) {
        return true;
    }
    return false;
}

void Island::deleteEdge(int v1)
{
    listStart.remove(v1);
}

void Island::showIslands()
{
    listStart.show();
}

bool Island::isNoConnection()
{
    if(listStart.isEmpty() == true) {
        return true;
    }
    return false;
}

void Island::markVisited()
{
    this->visited = true;
}

void Island::markUnvisited()
{
    this->visited = false;
}

MyNode* Island::_getHead()
{
    listStart.getHead();
}

bool Island::isVisited()
{
    return this->visited;
}

