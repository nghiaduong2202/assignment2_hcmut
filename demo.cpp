#include<iostream>
#include<string.h>
using namespace std;

enum BookType {Science, Novel, Programming, NoLabel};
bool isSameName(char* _a, char* _b) {
    if (strlen(_a) != strlen(_b)) return false;
    for (int i = 0; i < strlen(_a); i++) {
        if (_a[i] != _b[i]) return false;
    }
    return true;
}
class Author {
    char* name;
public:
    Author(const char*);
    char* getName();
};
Author::Author(const char* name){
	this->name=new char[strlen(name+1)];
	strcpy(this->name,name);
}
char* Author::getName(){return this->name;}

class Book {
    int ID;
    char* name;
    bool isBorrowed;
    Author* pAuthor;
    Book* pNext;
    BookType typ;
public:
    Book();
    Book(const char* _name, Author*, bool isBorrowed, BookType);
    Book(Book&);
    ~Book();
    operator bool();
    char* getName();
    char* getAuthorName();
    void setName();
    void disp();
    void setNext(Book*);
    Book* getNext();
    BookType getType();
    int getID();
};
char* Book::getName(){return this->name;}
char* Book::getAuthorName(){return pAuthor->getName();}
void Book::setName(){};
void Book::disp(){}
void Book::setNext(Book* p){
	this->pNext->pNext=p;
	this->pNext=p;
	this->pNext->pNext=NULL;
}
Book* Book::getNext(){return this->pNext;}
BookType Book::getType(){return this->typ;}
int Book::getID(){return this->ID;}
class BookList {
    int curID;
    Book* pHead;
    Book* pTail;
    BookType bookType;
    BookList* pNext;
public:
    BookList() {
        curID = 0;
        pHead = NULL;
        pTail = NULL;
        bookType = NoLabel;
    };
    int getNewID();
    void addNewBook(Book*);
    int findBook(char*);
    void setType(BookType);
    void setNext(BookList*);
    BookType getType();
    BookList* getNext();
};
int BookList::findBook(char* name){
	Book* p=this->pHead;
	while(p){
		bool b=true;
		char* str=new char[strlen(p->getName())];
		strcpy(str,p->getName());
		if(strlen(name)!=strlen(str)) b=false;
		else{
			for(int i=0;i<strlen(name);i++){
			if(str[i]!=name[i]) b=false;
			}
		}
		if(b){
			return p->getID();
		}
		p=p->getNext();
	}
	return -1;
}
int main(){
	Book* p;
	cout<<*p;
}