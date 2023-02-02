#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

void ULListStr::push_back(const std::string& val){
  if(tail_==0 && head_==0){ //if no Items have been made yet
    head_ = tail_ = new Item();//new Item is now head and tail
  }
  else if(tail_->last==ARRSIZE){ //if tail's array is full at last make new Item
    Item* temp = new Item();
    temp->prev=tail_;
    tail_->next=temp;
    tail_=temp;
    delete temp;
  }
  tail_->val[tail_->last] = val;
  tail_->last++;
  size_++;
}

void ULListStr::push_front(const std::string& val){
  if(tail_==0 && head_==0){ //if no Items have been made yet
    head_ = tail_ = new Item();//new Item is now head and tail
    head_->first=1;
    head_->last=1;  
    //std::cout<<"called??"<<std::endl;
  }
  else if(head_->first==0){ //if head's array is full at first make new Item
    //std::cout<<"CP"<<std::endl;
    Item* temp = new Item();
    temp->next =head_;
    head_->prev =temp;
    head_=temp;
    delete temp;

    head_->first=ARRSIZE;
    head_->last=ARRSIZE;

  }
  head_->first--;
  head_->val[head_->first] = val;
  //std::cout<<"    "<<head_<<std::endl;
  //std::cout<<head_->first<<" "<<head_->last<<std::endl;
  size_++;
  //std::cout<<"size "<<size_<<std::endl;
}

void ULListStr::pop_back(){
  if(size_==0) return; //list is empty
  if(tail_->last-tail_->first==1){//only one value in item
    Item* temp= tail_;
    tail_=tail_->prev;
    delete temp;
    tail_->next=NULL;
  }
  else{
    tail_->last--; //decrement last
  }
  size_--; // Decrement size
}

void ULListStr::pop_front(){
  if(size_==0) return; //list is empty
  if(head_->last-head_->first==1){//only one value in item
    Item* temp = head_;
    head_=head_->next;
    delete temp;
    head_->prev=NULL;
  }
  else{
    head_->first++; //increment first
  }
  size_--; // Decrement size
}

// Returns the value at the back
std::string const & ULListStr::back() const {
  return tail_->val[tail_->last-1]; 
}

// Returns the value at the front 
std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_ || loc < 0) return NULL;
  //std::cout<<"loc "<<loc<<std::endl;
  Item *temp=head_;
  int count=0, incr =0;
  if(loc==0){
    return &(temp->val[temp->first]);
  }
  while(incr!=loc){
    while(temp->first+count!=ARRSIZE){
      if(incr==loc){
        return &(temp->val[temp->first+count]);
      }
      count++;
      incr++;
    }
    if(temp->next!=NULL){
      count=0;
      temp=temp->next;
    }
  }
  return &(temp->val[temp->first+count]);
  /*
  while(temp!=NULL){ //loop through ULL
    if(loc>=temp->first && loc<temp->last){// if in this range, then disired content is in this Item
      std::cout<<"found loc "<<temp->val[loc-temp->first]<<std::endl;
      return &(temp->val[loc-temp->first]); //do calculation to grab the index of val
    }
    std::cout<<"subtracting "<<temp->last-temp->first<<std::endl;
    loc -= temp->last-temp->first; //else, subtract size of this Item
    temp = temp->next;// else cont., go to next Item
  }*/
  //std::cout<<"loc was "<<loc <<" so NULL"<<std::endl;
  //return NULL; //return to make function happy :)
}