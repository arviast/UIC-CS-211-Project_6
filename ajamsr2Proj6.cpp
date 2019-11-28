// CS 211 2019 FALL
// Project 6
// Arvinbayar Jamsranjav

#include "Island.h"

class ArchipelagoExpedition
{
 private:
   // Create the Data Members for the Archipelago Network here
   int size;
   Island *islandList;
   FileList *listOfFiles;
   
 public:
  
 // Use a constructor to initialize the Data Members for your expedition
 ArchipelagoExpedition()
 {
  size = 10;
  islandList = new Island[size+1];
  listOfFiles = new FileList();

 }
 
 ~ArchipelagoExpedition()
 {
     delete[] islandList;
//      listOfFiles->removeAll();   
 }
 
 // marks everyone back to unvisited
 // ...
 void markBackToUnvisited()
 {
     for(int i = 0; i < size+1; i++) {
         islandList[i].markUnvisited();
     }
 }
  
 void depthFirstSearchHelper(int x, int y)
 {
     markBackToUnvisited();
     
     if(dfs(x,y) == true) {
         printf(".You can get from Island %d to Island %d in one or more ferry rides.\n", x,y);
     }
     else {
         printf("You can NOT get from Island %d to Island %d in one or more ferry rides.\n", x,y);
     }
 }
 
 bool dfs(int a, int b)
 {
     MyNode* temp = islandList[a]._getHead();
     
     for(; temp != NULL; temp = temp->getNext()){       
         if(temp->getElem() == b) {
             return true;
         }
         
         if(islandList[temp->getElem()].isVisited() == false) {
             islandList[temp->getElem()].markVisited();
          
             if(dfs(temp->getElem(), b) == true) {
                 return true;
             }
         }
     }
     return false;
 }
    
    
 // The main loop for reading in input
 void processCommandLoop (FILE* inFile)
 {
  char  buffer[300];
  char* input;

  input = fgets ( buffer, 300, inFile );   // get a line of input
    
  // loop until all lines are read from the input
  while (input != NULL)
  {
    // process each line of input using the strtok functions 
    char* command;
    command = strtok (input , " \n\t");

    printf ("*%s*\n", command);
    
    if ( command == NULL )
      printf ("Blank Line\n");
 
    else if ( strcmp (command, "q") == 0) 
      exit(1);
     
    else if ( strcmp (command, "?") == 0) 
      showCommands();
     
    else if ( strcmp (command, "t") == 0) 
      doTravel();
     
    else if ( strcmp (command, "r") == 0) 
      doResize();

    else if ( strcmp (command, "i") == 0) 
      doInsert();

    else if ( strcmp (command, "d") == 0) 
      doDelete();

    else if ( strcmp (command, "l") == 0) 
      doList();

    else if ( strcmp (command, "f") == 0) 
      doFile();

    else if ( strcmp (command, "#") == 0) 
      ;
     
    else
      printf ("Command is not known: %s\n", command);
     
    input = fgets ( buffer, 300, inFile );   // get the next line of input

  }
 }
 
 void showCommands()
 {
   printf ("The commands for this project are:\n");
   printf ("  q \n");
   printf ("  ? \n");
   printf ("  # \n");
   printf ("  t <int1> <int2> \n");
   printf ("  r <int> \n");
   printf ("  i <int1> <int2> \n");
   printf ("  d <int1> <int2> \n");
   printf ("  l \n");
   printf ("  f <filename> \n");
 }
 
 void doTravel()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   printf("%s\n", next);
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \n\t");

   printf("%s\n", next);
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
    
   if((val1 <= 0 || val1 > this->size) || (val2 <= 0 || val2 > this->size)) {
       printf("Error message: Island doesn't exist.\n");
       return;
   }
   
   printf ("Performing the Travel Command from %d to %d\n", 
            val1, val2);
     
   depthFirstSearchHelper(val1, val2);
   
 }
 
 void doResize()
 {
   int val1 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");	
   printf("%s\n", next);
     
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   if (val1 <= 0) {
       printf("Error message: Can't assign size less or equal to zero.\n");
       return;
   }  
   // erases everything, prepare for next Island[size]
   // ...
   this->~ArchipelagoExpedition();
   
   for(int i =0; i < size; i++) {
       islandList[i].~Island();
   }
   
   this->size = val1;
   islandList = new Island[this->size+1];  
     
   printf ("Performing the Resize Command with %d\n", val1 );
 }
 
 void doInsert()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   printf("%s\n", next);
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \n\t");

   printf("%s\n", next);
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   // check if these conditions satisfies first
   // ...
   if((val1 <= 0 || val1 > this->size) || (val2 <= 0 || val2 > this->size)) {
       printf("Error message: Island doesn't exist.\n");
       return;
   }
     
   if(islandList[val1].existingEdge(val2) == true) {
       printf("Error message: Already in the list.\n");
       return;
   } 
   // insert
   islandList[val1].addedge(val2);
   printf("Edge inserted between %d and %d\n", val1, val2);
 
 }
 
 void doDelete()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   printf("%s\n", next);
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \n\t");

   printf("%s\n", next);
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }

   // check if these conditions satisfies first
   // ...
   if((val1 <= 0 || val1 > this->size) || (val2 <= 0 || val2 > this->size)) {
       printf("Error message: Island doesn't exist.\n");
       return;
   }
     
   if(islandList[val1].existingEdge(val2) == false) {
       printf("Error message: Can't delete not in the list.\n");
       return;
   } 
   // delete
   islandList[val1].deleteEdge(val2);
   printf("Edge deleted between %d and %d\n", val1, val2);

 }
 // print the whole list
 void doList()
 {
     printf("Displaying the list\n");
     for(int i = 1; i < this->size+1; i++){
         printf("Island #%d",i);
         if(islandList[i].isNoConnection() == true) {
             printf("-> has no edges.");
         }
         else {
             printf("-> ");
             islandList[i].showIslands();
         }
         printf("\n");
     }
 }
 // f command
 void doFile()
 {
   // get a filename from the input
   char* fname = strtok (NULL, " \n\t");
   
   if ( fname == NULL )
   {
     printf ("Filename expected\n");
     return;
   }
   
   printf ("Performing the File command with file: %s\n", fname);
      
   // next steps:  (if any step fails: print an error message and return ) 
   //  1. verify the file name is not currently in use
   if(listOfFiles->isOpen(fname) == true) {
       printf("Error message: File is already open.\n");
       return;
   }
   
   //  2. open the file using fopen creating a new instance of FILE*
   FILE* infile;
   infile = fopen(fname, "r");

   if(infile == NULL) {
       printf("Error message: FILE doesn't exist.\n");
       return;
   }
   
   listOfFiles->addName(fname);
   //  3. recursively call processCommandLoop() with this new instance of FILE* as the parameter
   processCommandLoop(infile);
   //  4. close the file when processCommandLoop() returns
   fclose(infile);
   listOfFiles->removeOneFile(fname);
    
 }
};

int main (int argc, char** argv)
{
  // set up the variable inFile to read from standard input
  FILE* inFile = stdin;

  // set up the data needed for the island adjcency list
  ArchipelagoExpedition islandData;
   
  // call the method that reads and parses the input
  islandData.showCommands();
  printf ("\nEnter commands at blank line\n");
  printf ("    (No prompts are given because of f command)\n");
  islandData.processCommandLoop (inFile);
   
  printf ("Goodbye\n");
  return 1;
 }
