// CS 211 2019 FALL
// Project 6
// Arvinbayar Jamsranjav

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

//----------------------------------------------------
// node class for the mylist
class MyNode
{
 private:
  int elem;
  MyNode* next;
  
 public:
  MyNode (int v1);
  MyNode (int v1, MyNode* n);
  
  void setElem (int e);
  int getElem ();
  void setNext (MyNode* n);
  MyNode* getNext();
};

//----------------------------------------------------
//myList class for adjancencies
class MyList
{
 private:
  MyNode* head;
  
 public:
  MyList();
  ~MyList();
  
  void show();
  void insert(int v1);
  void remove(int v1);
  bool isEmpty();
  int getListLength();
  int getNthElem(int v1);
  void removeAll();
  int search(int v1);
  MyNode* getHead();
};


//----------------------------------------------------
// node for file names
class FileNode
{
  private:
      char* name;
      FileNode* next;
      
  public:
      FileNode (char* fileName);
      char* getName();
      void setNext(FileNode* n);
      FileNode* getNext();
      
};

//----------------------------------------------------
// list that contains nodes with file names
class FileList
{
  private:
      FileNode* head;
  
  public:
      FileList();
      ~FileList();
      void removeAll();
      void addName(char* fileName);
      bool isOpen(char* fileName);
      void removeOneFile(char* fileName);
};

//----------------------------------------------------
// island class that contains the list of islands with their adjancencies

class Island
{
  private:
    bool visited;
    MyList listStart;
    
  public:
    Island();
    ~Island();
    
    void addedge(int v1);
    bool existingEdge(int v1);
    void deleteEdge(int v1);
    void showIslands();
    bool isNoConnection();
    void markVisited();
    void markUnvisited();
    bool isVisited();
    MyNode* _getHead();
};

