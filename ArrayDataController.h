//
//  ArrayDataController.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef ArrayDataController_h
#define ArrayDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

//Functions used to manage Array
void print(Array& array){
    if (!array.size) {
        std::cout << "Array is empty" << endl;
        return;
    }
    std::cout <<"[";
    for(int i=0;i<array.size;i++){
        std::cout << array.arr[i].ID << " ";
    }
    std::cout <<"]" << endl;
}

void initArray (Array& array, int cap){
    //Init a new array with capacity equals to cap
    //TODO
    array.arr=new Soldier[cap];
    array.capacity=cap;
    return;
}

bool insertAt(Array& array, Soldier element, int pos){
    //Insert element into a pos in the array
    //Return true if insert successfully, false otherwise
    //TODO
    if(pos<0 || pos>array.size){return false;}
    if(array.arr==NULL) return false;
    if(array.size==array.capacity-1){
        Soldier* a=new Soldier[array.capacity];
        a=array.arr;
        array.capacity*=1.5;
        array.arr=new Soldier[array.capacity];
        array.arr=a;
        delete[] a;
    }
    for(int i=pos;i<=array.size;i++){
        Soldier temp;
        temp=array.arr[i];
        array.arr[i]=element;
        element=temp;
    }
    array.size++;
    return true;
}

bool removeAt (Array& array, int idx){
    //Remove element at index idx in the array
    //Return true if remove successfully, false otherwise
    //TODO
    if(idx<0 ||idx>=array.size) return false;
    for(int i=idx;i<array.size;i++){
        array.arr[i]=array.arr[i+1];
    }
    array.size--;
    return true;
}

bool removeFirstItemWithHP (Array& array, int HP){
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO
    for(int i=0;i<array.size;i++){
        if(array.arr[i].HP==HP){
            return removeAt(array,i);
        }
    }
    return false;
}

void ensureCapacity(Array& array, int newCap){
    //Extend the capacity of the array
    //TODO
    Soldier* copy=array.arr;
    array.arr=new Soldier[newCap];
    array.arr=copy;
    array.capacity=newCap;
    return;
}

int indexOf(Array& array, Soldier soldier){
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
    for(int i=0;i<array.size;i++){
        if((array.arr[i].HP==soldier.HP)&&(array.arr[i].ID==soldier.ID) &&(array.arr[i].isSpecial==soldier.isSpecial))
        return i;
    }
    return -1;
}

int size(Array& array){
    //Return size of the array
    //TODO
    return array.size;
}

bool empty(Array& array){
    //Check whether the array is empty
    //TODO
    if(array.size==0) return true;
    return false;
}

string getIDAt(Array& array, int pos){
    //Get ID of the Soldier at pos
    //TODO
    if(pos<0||pos>=array.size) return "-1";
    return array.arr[pos].ID;
}

int getHPAt(Array& array, int pos){
    //Get HP of the Soldier at pos
    //TODO
    if(pos<0 || pos>=array.size) return -1;
    return array.arr[pos].HP;
}

bool setHPAt(Array& array, int HP, int pos){
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    if(pos<0|| pos>=array.size) return false;
    array.arr[pos].HP=HP;
    return true;
}

void clear(Array& array){
    //Delete all of the elements in array
    //TODO
    delete[] array.arr;
    array.arr=NULL;
    array.size=0;
}

bool contains (Array& array, Soldier soldier){
    //Check if array contains soldier
    //TODO
    int temp=indexOf(array,soldier);
    if(temp==-1) return false;
    return true;
}

//You can write your own functions here

//End your own functions

#endif /* ArrayDataController_h */
