// intlist.cpp
// Implements class IntList
// Luis Solano 04/14/2025

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {

    head = nullptr;
    tail = nullptr;

    Node* current = source.head;
    while(current){
        
        push_back(current->info);
        current = current->next;
    }


}

// destructor deletes all nodes
IntList::~IntList() {
    Node* current = head;
    
    while(current){
        Node* cnext = current->next;
        delete current;
        current = cnext;
        
    }

    head = nullptr;
    tail = nullptr;
    
}

// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node* n = head;
    while(n){
        sum = sum + n->info;
    
        n = n->next;      
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    if(head == nullptr){
        return false;
    }
    Node* temp = head;

    while(temp){
        if(temp->info == value){
            return true;
        }
        
        temp = temp->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if(head == nullptr){
        return 0;
    }

    Node* temp = head;
    int max = temp->info;
   
    while(temp){

        if(temp->info > max){
            max = temp->info;
        }
        temp = temp->next;
    }
    return max;
    
}



// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    double total = sum();
    double amount = count();

    return total / amount;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* front = new Node();
    front->info = value;  
    if(head == nullptr){
        front->next = nullptr;
        head = front;
    }else{
        front->next = head;
        head = front;
    }

}

// append value at end of list
void IntList::push_back(int value) {
    Node* end = new Node{value, nullptr};
    if(head == nullptr){
        head = end;
        tail = end;
    }else{
        
        tail->next = end;
        tail = tail->next;

    }
    
}

void IntList::clear(){
    Node* current = head;
    
    while(current){
        Node* cnext = current->next;
        delete current;
        current = cnext;
        
    }

    head = nullptr;
    tail = nullptr;
}

// return count of values
int IntList::count() const {
    int count = 0;
    Node* n = head;
    while(n){
        count++;
    
        n = n->next;      
    }
    return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){

    if(this == &source){
        return *this;    //We make sure check for self assignment
    }

    clear();        //we delete everything in the current node.


    head = nullptr;
    tail = nullptr;

    Node* current = source.head;
    while(current){
        
        push_back(current->info);
        current = current->next;
    }

    return *this;

}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

