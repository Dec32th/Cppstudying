// Test driver
#include <iostream>
#include <fstream>

#include "StackType.h"

using namespace std;

StackType CopyStack(StackType& stack)
{
    StackType tStack;
    StackType rStack;
    for (int i = 1; i <= MAX_ITEMS; i++)
    {
        if (stack.IsEmpty())
            throw EmptyStack();
        tStack.Push(stack.Top());
        stack.Pop();
        rStack.Push(tStack.Top());
    }
    return rStack;
}

void ReplaceItem(StackType& stack, int oldItem, int newItem)
{
    StackType tStack;
	if (stack.IsEmpty())
		throw EmptyStack();
	else 
	{
        

        while (!stack.IsEmpty())
        {
            if (stack.Top() == oldItem)
            {
                tStack.Push(newItem);
                stack.Pop();
            }
            else
            {
                tStack.Push(stack.Top());
                stack.Pop();
            }
        }
        
        while (!tStack.IsEmpty())
        {
            stack.Push(tStack.Top());
            tStack.Pop();
        }
	}
}

int main()
{

  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  string inFileName;     // input file external name
  string outFileName;    // output file external name
  string outputLabel;     
  string command;        // operation to be executed
  
  ItemType item;
  StackType stack;
  int numCommands;


  //// Prompt for file names, read file names, and prepare files
  //cout << "Enter name of input command file; press return." << endl;
  //cin  >> inFileName;
  //inFile.open(inFileName.c_str());

  //cout << "Enter name of output file; press return." << endl;
  //cin  >> outFileName;
  //outFile.open(outFileName.c_str());

  //cout << "Enter name of test run; press return." << endl;
  //cin  >> outputLabel;
  //outFile << outputLabel << endl;

  //inFile >> command;


  //numCommands = 0;
  //while (command != "Quit")
  //{ 
  //  try 
  //  {
  //    if (command == "Push")
  //    {
  //      inFile >> item; 
  //      stack.Push(item);
  //    }
  //    else if (command == "Pop")
  //      stack.Pop();
  //    else if (command == "Top")
  //    {
  //      item = stack.Top(); 
  //      outFile<< "Top element is " << item << endl;
  //    } 
  //    else if (command == "IsEmpty") 
  //      if (stack.IsEmpty())
  //        outFile << "Stack is empty." << endl;
  //      else 
  //        outFile << "Stack is not empty." << endl;
  //           
  //    else if (command == "IsFull")
  //      if (stack.IsFull())
  //        outFile << "Stack is full." << endl;
  //      else outFile << "Stack is not full."  << endl;  
  //  }
  //  catch (FullStack)
  //  {
  //    outFile << "FullStack exception thrown." << endl;
  //  }
  //  
  //  catch (EmptyStack)
  //  {
  //    outFile << "EmtpyStack exception thrown." << endl;
  //  }    
  //  numCommands++;
  //  cout <<  " Command number " << numCommands << " completed." 
  //       << endl;
  //  inFile >> command;
 
  //};
 
  //cout << "Testing completed."  << endl;
  //inFile.close();
  //outFile.close();
  //return 0;

  stack.Push(8);
  stack.Push(3);
  stack.Push(9);
  stack.Push(8);
  stack.Push(3);
  stack.Push(7);
  stack.Push(5);
  stack.Push(3);

  ReplaceItem(stack, 3, 5);

  for (int i = 1; i <= 8; i++)
  {
      int result = stack.Top();
      stack.Pop();
      cout << result <<endl;
  }
}


