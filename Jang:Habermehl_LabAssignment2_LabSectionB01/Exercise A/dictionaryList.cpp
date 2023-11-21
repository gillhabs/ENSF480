/*
* File Name: dictionaryList.cpp
* Assignment: Lab 2 Exercise A
* Completed by: Gillian Habermehl and Grace Jang
* Submission Date: October 2, 2023
*/

// lookuptable.cpp
#include <assert.h>
#include <iostream>
#include <stdlib.h>
#include "dictionaryList.h"
#include "mystring_B.h"
using namespace std;
Node::Node(const Key& keyA, const Datum& datumA, Node *nextA)
  : keyM(keyA), datumM(datumA), nextM(nextA)
{
}
DictionaryList::DictionaryList()
  : sizeM(0), headM(0), cursorM(0)
{
}
DictionaryList::DictionaryList(const DictionaryList& source)
{
  copy(source);
}
DictionaryList& DictionaryList::operator =(const DictionaryList& rhs)
{
  if (this != &rhs) {
    destroy();
    copy(rhs);
  }
  return *this;
}




// Overloading operators

// Overloader for <<
ostream& operator <<(ostream& os, DictionaryList& d) {
    for(int i = 0; i < d.size(); i++) {
        os << d.cursor_key() << " " << d.cursor_datum() << "\n";
        d.step_fwd();
    }
    return os;
}

// Overloader for DictionaryList subscript operators
Mystring& DictionaryList::operator[](int index) {
    Node* temp = headM;
    for (int i = 0; i < index; i++) {
        temp = temp -> nextM;
    }
    return temp -> datumM;
}

// Overloader for DictionaryList subscript operators (const version)
const Mystring& DictionaryList::operator[](int index) const {
    Node* temp = headM;
    for (int i = 0; i < index; i++) {
        temp = temp -> nextM;
    }
    return temp -> datumM;
}

// Non-const definition of cursor_datum()
Mystring& DictionaryList::cursor_datum() {
    assert(cursor_ok());
    return cursorM->datumM;
}





DictionaryList::~DictionaryList()
{
  destroy();
}
int DictionaryList::size() const
{
  return sizeM;
}
int DictionaryList::cursor_ok() const
{
  return cursorM != 0;
}
int DictionaryList::cursor_next_ok() const
{
  return cursorM -> nextM != 0;
}
const Key& DictionaryList::cursor_key() const
{
  assert(cursor_ok());
  return cursorM->keyM;
}
const Datum& DictionaryList::cursor_datum() const
{
  assert(cursor_ok());
  return cursorM->datumM;
}
void DictionaryList::insert(const int& keyA, const Mystring& datumA)
{
  // Add new node at head?
  if (headM == 0 || keyA < headM->keyM) {
    headM = new Node(keyA, datumA, headM);
    sizeM++;
  }
    
  // Overwrite datum at head?
  else if (keyA == headM->keyM)
    headM->datumM = datumA;
    
  // Have to search ...
  else {
      
    //POINT ONE
        
    // if key is found in list, just overwrite data;
    for (Node *p = headM; p !=0; p = p->nextM)
        {
            if(keyA == p->keyM)
            {
                p->datumM = datumA;
                return;
            }
        }
        
    //OK, find place to insert new node ...
    Node *p = headM ->nextM;
    Node *prev = headM;
        
    while(p !=0 && keyA >p->keyM)
        {
            prev = p;
            p = p->nextM;
        }
        
    prev->nextM = new Node(keyA, datumA, p);
    sizeM++;
  }
  cursorM = NULL;
    
}
void DictionaryList::remove(const int& keyA)
{
    if (headM == 0 || keyA < headM -> keyM)
        return;
    
    Node *doomed_node = 0;
    
    if (keyA == headM-> keyM) {
        doomed_node = headM;
        headM = headM->nextM;
        
        // POINT TWO
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->nextM;
        while(maybe_doomed != 0 && keyA > maybe_doomed-> keyM) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->nextM;
        }
        
        if (maybe_doomed != 0 && maybe_doomed->keyM == keyA) {
            doomed_node = maybe_doomed;
            before->nextM = maybe_doomed->nextM;
        }
        
        
    }
    if(doomed_node == cursorM)
        cursorM = 0;
    
    delete doomed_node;           // Does nothing if doomed_node == 0.
    sizeM--;
}
void DictionaryList::go_to_first()
{
    cursorM = headM;
}
void DictionaryList::step_fwd()
{
    assert(cursor_ok());
    cursorM = cursorM->nextM;
}
void DictionaryList::make_empty()
{
    destroy();
    sizeM = 0;
    cursorM = 0;
}


// The following function are supposed to be completed by the stuents, as part
// of the exercise B part II. the given fucntion are in fact place-holders for
// find, destroy and copy, in order to allow successful linking when you're
// testing insert and remove. Replace them with the definitions that work.
void DictionaryList::find(const Key& keyA)
{
    // If list is empty or keyA < head node key
    if (headM == 0 || keyA < headM -> keyM) {
        // Not in list, cursorM is 0
        cursorM = 0;
        return;
    }
    
    // If key == head node key
    else if (keyA == headM -> keyM) {
        // cursorM point to head node key
        cursorM = headM;
        return;
    }
    // Else we have to search the list for the node
    else {
        // For every node in the list
        for (Node *current = headM; current !=0; current = current -> nextM) {
            // If keyA = key of current node
            if(keyA == current -> keyM) {
                // cursorM points to the current node
                cursorM = current;
                return;
            }
        }
    }
}
void DictionaryList::destroy()
{
    Node *current = headM;
    Node *next;
    // Iterate through while list still exists
    while (current != nullptr) {
        // Assign next by using nextM and delete current node
        // New current node is next
        next = current->nextM;
        delete current;
        current = next;
    }
    // Reset head, size, cursor
    headM = nullptr;
    sizeM = 0;
    cursorM = nullptr;
}
void DictionaryList::copy(const DictionaryList& source)
{
    cursorM = 0;
    headM = 0;
    
    // If source list is empty
    if (source.headM == 0) {
        // Set everything to 0
        headM = 0;
        cursorM = 0;
        sizeM = 0;
        return;
    }
    // Copy head node
    headM = new Node(source.headM -> keyM, source.headM -> datumM, nullptr);
    
    // Get iterator node pointers for source and new DictionaryList
    Node* current = headM;
    Node* sourceCurrent = source.headM->nextM;
    // Iterate through and copy the rest of the nodes
    while (sourceCurrent != nullptr) {
        current -> nextM = new Node(sourceCurrent -> keyM, sourceCurrent -> datumM, nullptr);
        current = current -> nextM;
        sourceCurrent = sourceCurrent -> nextM;
    }
    
    // Set cursorM to source cursor
    cursorM = source.cursorM;
    
    // Set sizeM to source size
    sizeM = source.sizeM;
    return;
}





