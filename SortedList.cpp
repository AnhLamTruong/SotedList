//
// Created by Anh on 9/4/2022.
//
// Purpose: Implementation file for a demonstration of an unsorted
//		list implemented as an array.

#include "SortedList.h"

//Class constructor
//Initialize the private data
sortedList::sortedList() {
    count = -1;
}

//Class destructor
//Freed the private data
sortedList::~sortedList() {

}
//ClearList
//Remove all items from the list
void sortedList::ClearList() {
    count = -1;
}

//InsertItemsToList
// Insert an item into the list in the next open slot.
void sortedList::Insert(int key, float val) {
    int finder=0;
    //Check the List to see that if it's full
    if(isFull()){
        cout<<"List is Full :("<<endl;
    }
    while((finder<=count)&&(theList[finder].value<val)){
        cout<<"Finder Value"<<' '<<finder<<":"
        <<' '<<theList[finder].value
        <<" with newVal :"<<val<<endl;
        finder++;
    }
    // Move all other items up 1 in list to make room for the
    // new item to be inserted in the correct place
    // Increment head index
    count++;
    for(int i=count;i>finder;i--) {
        theList[i] = theList[i - 1];
    }
    theList[finder].key=key;
    theList[finder].value=val;
}

//DeleteItems
//Delete an item from the list and move all others up to close up the empty space.
void sortedList::Delete(int key) {
    int follower, finder = 0;
    if(isEmpty()){
        cout<<"List is empty :("<<endl;
    }while((finder <= count) && (key != theList[finder].key))
    {
        finder++;
    }
    // Check to see if the item was found
    if(finder>count){
        cout<<"NOT FOUND!!!"<<endl;
    }else{
        for(follower = finder; follower < count; follower++)
        {
            theList[follower] = theList[follower+1]; // Using whole structure copy
        }
        count--; // Reset count
    }
}

//SearchItems
//Search for an item by key and copy the value into the variable *returnVal.

bool sortedList::Search(int key, float *returnVal) {
    int finder = 0;
    while((finder <= count) && (key != theList[finder].key))
    {
        finder++;
    }
    // If item not found return FALSE
    if(finder > count) {
        return false;
    }else{}
    *returnVal = theList[finder].value; // Copy the data
    return true;
}

//Return the number of items in the list.
int sortedList::ListLength() {
    return count+1;;
}

//Return true if the list is empty
bool sortedList::isEmpty() {
    return (count==-1);
}

//Return true if the list is full
//Returns: TRUE if full, otherwise FALSE
bool sortedList::isFull() {
    return count>=MAX_SIZE;
}


//Simply Print :)
void sortedList::PrintList() {
    int i;

    cout << "\n\nItems in the List\n";
    cout << "-----------------------------------------------------------\n";
    cout << "Key\t\tData\n";
    cout << "-----------------------------------------------------------\n";

    for(i=0; i<=count; i++)
    {
        cout << theList[i].key << "\t\t" << theList[i].value<< "\n";
    }
    cout << "-----------------------------------------------------------\n\n";
}