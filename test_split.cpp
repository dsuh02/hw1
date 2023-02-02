/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include "split.h"
#include <iostream>

int main(int argc, char* argv[]) //input args in command line
{
  
  Node* in = new Node{3,new Node{4,new Node{5,new Node{10,new Node{13,nullptr}}}}}; //random vals for linked list in
  //instantiate and set odds/evens to nullptr
  Node* odds=nullptr;
  Node* evens=nullptr;

  std::cout<<"input: "; //print input
  Node* current=in;
  while(current){
    std::cout<<current->value<<" ";
    current=current->next;
  }
  std::cout<<std::endl;


  split(in, odds, evens);//do recursion

  std::cout <<"odds list: "<<std::endl;//print odds
  current=odds;
  while(current){
    std::cout<<current->value<<" ";
    current=current->next;
  }
  std::cout<<std::endl;

  std::cout <<"evens list: "<<std::endl;//print evens
  current=evens;
  while(current){
    std::cout<<current->value<<" ";
    current=current->next;
  }
  std::cout<<std::endl;

  current=odds;
  while(current){
    Node* temp =current;
    current=current->next;
    delete temp;
  }
  current=evens;
  while(current){
    Node* temp =current;
    current=current->next;
    delete temp;
  }


  return 0;
}
