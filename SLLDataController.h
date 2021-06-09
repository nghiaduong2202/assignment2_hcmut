//
//  SLLDataControler.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef SLLDataController_h
#define SLLDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

//Functions used to manage Singly Linked List
void print(SLinkedList& list){
    if (!list.size) {
        std::cout << "List is empty" << endl;
        return;
    }
    SoldierNode* head = list.head;
    while (head){
        std::cout << head->data.ID << "->";
        head = head->next;
    }
    std::cout << "NULL"<<endl;
}

bool insertAt (SLinkedList& list, Soldier element, int pos){
    //Insert element into a pos in the SLL
    //Return true if insert successfully, false otherwise
    //[1] [2] [3] [4] [5] [6] [7] [8] [9] [10] [11]
    if(list.head==NULL && pos==0){
        list.head=new SoldierNode;
        list.head->data=element;
        list.head->next=NULL;
        list.size++;
        return true;
    }
    if(list.size<pos || pos<0)
    {
        return false;
    }
    SoldierNode* p=new SoldierNode;
    p->data=element;
    if(pos==0){
        p->next=list.head;
        list.head=p;
    } else if(pos==list.size){
        SoldierNode* pHead=list.head;
        while(pHead->next){
            pHead=pHead->next;
        }
        pHead->next=p;
        pHead=p;
        pHead->next=NULL;
    } else {
        SoldierNode* pHead=list.head;
        for(int i=0;i<pos-1;i++){
            pHead=pHead->next;
        }
        p->next=pHead->next;
        pHead->next=p;
    }
    list.size++;
    return true;
}

bool removeAt (SLinkedList& list, int idx){
    //Remove element at index idx in the SLL
    //Return true if remove successfully, false otherwise
    //TODO
    if(idx<0||idx>=list.size){
        return false;
    }
    if(list.size==1 && idx==0){
        delete list.head;
        list.head=NULL;
        list.size=0;
        return true;
    }
    SoldierNode* p=list.head;
    if(idx==0){
        list.head=list.head->next;
    } else if(idx==list.size-1){
        while(p->next->next){
            p=p->next;
        }
        delete p->next;
        p->next=NULL;
    } else {
        for(int i=0;i<idx-1;i++){
            p=p->next;
        }
        p->next=p->next->next;
    }
    list.size--;
    return true;
}

bool removeFirstItemWithHP (SLinkedList& list, int HP){
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO
    SoldierNode* pHead=list.head;
    int pos=-1;
    while(pHead){
        pos++;
        if(pHead->data.HP==HP){
            return removeAt(list,pos);       
        }
        pHead=pHead->next;
    }
    return false;
}

int indexOf(SLinkedList& list, Soldier soldier){
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
    SoldierNode* pHead=list.head;
    int index=-1;
    while(pHead){
        index++;
        if((pHead->data.HP==soldier.HP) && (pHead->data.ID==soldier.ID) && (pHead->data.isSpecial==soldier.isSpecial))
        return index;
        pHead=pHead->next;
    }
    return -1;
}

int size(SLinkedList& list){
    //Return size of the list
    //TODO
    return list.size;
}

bool empty(SLinkedList& list){
    //Check whether the list is empty
    //TODO
    if(list.size==0) return true;
    else return false;
}

void clear(SLinkedList& list){
    //Delete all of the elements in list
    //TODO
    delete list.head;
    list.head=NULL;
    list.size=0;
    return;
}

string getIDAt(SLinkedList& list, int pos){
    //Get ID of the Soldier at pos
    //TODO
    if(pos<0 || pos>=list.size) return "-1";
    SoldierNode* pHead=list.head;
    for(int i=0;i<pos;i++){
        pHead=pHead->next;
    }
    return pHead->data.ID;
}

int getHPAt(SLinkedList& list, int pos){
    //Get HP of the Soldier at pos
    //TODO
    if(pos<0 || pos>=list.size) return -1;
    SoldierNode* p=list.head;
    for(int i=0;i<pos;i++){
        p=p->next;
    }
    return p->data.HP;
}

bool setHPAt(SLinkedList& list, int HP, int pos){
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    if(pos<0 || pos>=list.size) return false;
    SoldierNode* p=list.head;
    for(int i=0;i<pos;i++){
        p=p->next;
    }
    p->data.HP=HP;
    return true;
}

bool contains (SLinkedList& list, Soldier soldier){
    //Check if array contains soldier
    //TODO
    int temp=indexOf(list,soldier);
    if(temp==-1) return false ;
    else return true;
}

//You can write your own functions here

//End your own functions

#endif /* SLLDataControler_h */
