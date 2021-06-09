//
//  thirdBattle.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//
// Students can remove the final initial return of the functions

#ifndef thirdBattle_h
#define thirdBattle_h

#include "SLLDataController.h"
#include "ArrayDataController.h"
#include <vector>
#include <string>

//////////////////////////////////////////////////////
/// TASK 1
//////////////////////////////////////////////////////

bool push(Array& array, Soldier soldier){
    //Return true if push successfully, false otherwise
    //TODO
    if(array.size==0) {
        array.capacity=1000;
        array.arr=new Soldier[array.capacity];
        array.arr[0]=soldier;
        array.size=1;
        return true;
    }
    return insertAt(array,soldier,array.size);
}

bool pop(Array& array){
    //Return true if pop successfully, false otherwise
    //TODO
    if(array.size==0) return false;
    array.size--;
    return true;
}

Soldier top(Array& array){
    //TODO
    if(array.size==0)
    return Soldier();//return this if cannot get top
    return array.arr[array.size-1];

}

//////////////////////////////////////////////////////
/// TASK 2
//////////////////////////////////////////////////////

bool enqueue(SLinkedList& list, Soldier soldier){
    //Return true if enqueue successfully, false otherwise
    //TODO
    SoldierNode* t=new SoldierNode;
    t->data=soldier;

    if(list.size==0) {
        t->next=NULL;
        list.head=t;
        list.size=1;
        return true;
    }
    SoldierNode* pHead=list.head;
    while(pHead->next){
        pHead=pHead->next;
    }
    pHead->next=t;
    pHead=t;
    pHead->next=NULL;
    list.size++;
    return true;
}

bool dequeue(SLinkedList& list){
    //Return true if dequeue successfully, false otherwise
    //TODO
    if(list.size==0) return false;
    if(list.size==1) {
        delete list.head;
        list.head=NULL;
        list.size=0;
        return true;
    }
    list.head=list.head->next;
    list.size--;
    return true;
}

Soldier front(SLinkedList& list){
    //TODO
    if(list.size==0)
    return Soldier();//Return this if cannot get front
    return list.head->data;
}

//////////////////////////////////////////////////////
/// TASK 3
//////////////////////////////////////////////////////

void reverse(SLinkedList& list){
    //TODO
    if(list.size==0 || list.size==1) return;
    int size=list.size;
    SoldierNode* pHead=list.head;
    Soldier* copy=new Soldier[size];
    for(int i=0;i<size;i++){
        copy[i]=pHead->data;
        pHead=pHead->next;
    }
    SoldierNode* p=new SoldierNode;
    p->data=copy[size-1];
    p->next=NULL;
    list.head=p;
    for(int i=size-2;i>=0;i--){
        SoldierNode* t=new SoldierNode;
        t->data=copy[i];
        p->next=t;
        p=t;
        p->next=NULL;
    }
    delete pHead;
    delete[] copy;
}

//////////////////////////////////////////////////////
/// TASK 4
//////////////////////////////////////////////////////

SLinkedList merge(SLinkedList& list1, SLinkedList& list2){
    //TODO
    if(list2.size==0 && list1.size==0)  
    return SLinkedList();
    if(list2.size==0) return list1;
    if(list1.size==0) return list2;

    SoldierNode* pHead1=list1.head;
    SoldierNode* pHead2=list2.head;
    SoldierNode* pHead=new SoldierNode;
    SoldierNode* p=new SoldierNode;
    if(pHead1->data.HP<pHead2->data.HP){
        p->data=pHead1->data;
        pHead1=pHead1->next;
    }else if(pHead1->data.HP>pHead2->data.HP){
        p->data=pHead2->data;
        pHead2=pHead2->next;
    }else if(pHead1->data.isSpecial==0 && pHead2->data.isSpecial==1){
        p->data=pHead1->data;
        pHead1=pHead1->next;
    } else if(pHead1->data.isSpecial==1 && pHead2->data.isSpecial==0){
        p->data=pHead2->data;
        pHead2=pHead2->next;
    }else if(pHead1->data.ID<pHead2->data.ID){
        p->data=pHead1->data;
        pHead1=pHead1->next;
    }else{
        p->data=pHead2->data;
        pHead2=pHead2->next;
    }
    p->next=NULL;
    pHead=p;
    while(pHead1 || pHead2){
        if(pHead1==NULL){
            p->next=pHead2;
            break;
        }
        if(pHead2==NULL){
            p->next=pHead1;
            break;
        }
        ///////////////////////////////////////////////////////////
        SoldierNode* t=new SoldierNode;
        if(pHead1->data.HP<pHead2->data.HP){
            t->data=pHead1->data;
            pHead1=pHead1->next;
        }else if(pHead1->data.HP>pHead2->data.HP){
            t->data=pHead2->data;
            pHead2=pHead2->next;
        }else if(pHead1->data.isSpecial==0 && pHead2->data.isSpecial==1){
            t->data=pHead1->data;
            pHead1=pHead1->next;
        } else if(pHead1->data.isSpecial==1 && pHead2->data.isSpecial==0){
            t->data=pHead2->data;
            pHead2=pHead2->next;
        }else if(pHead1->data.ID<pHead2->data.ID){
            t->data=pHead1->data;
            pHead1=pHead1->next;
        }else{
            t->data=pHead2->data;
            pHead2=pHead2->next;
        }
        p->next=t;
        p=t;
        p->next=NULL;
        //////////////////////////////////////////////////////////
    }
    SLinkedList list;
    list.size=list1.size+list2.size;
    list.head=pHead;
    return list;
}

//You can write your own functions here

//End your own functions

#endif /* thirdBattle_h */
