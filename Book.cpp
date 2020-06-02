#include "Book.h"
#include <iostream>
#include <string>

Book::Book( string Number, string Author, string Title, string Year, string ISBN, string Publisher, string LLC, string Stock)
 {
    this->Number = Number;
    this->Author = Author;
    this->Title = Title;
    this->Year = Year;
    this->ISBN = ISBN;
    this->LLC = LLC;
    this->Stock = Stock;
    this->Publisher =Publisher;
}

string Book::getNumber(){
    return Number;
}
string Book::getAuthor(){
    return Author;
}
string Book::getTitle(){
    return Title;
}
string Book::getYear(){
    return Year;
}
string Book::getPublisher(){
    return Publisher;
}
string Book::getISBN(){
    return ISBN;
}
string Book::getLLC(){
    return LLC;
}
string Book::getStock(){
    return Stock;
}

void Book::setNumber(string Number){
    this->Number = Number;
}
void Book::setAuthor(string Author){
    this->Author = Author;
}
void Book::setTitle(string Title){
    this->Title = Title;
}
void Book::setYear(string Year){
    this->Year = Year;
}
void Book::setPublisher(string Publisher){
    this->Publisher = Publisher;
}
void Book::setISBN(string ISBN){
    this->ISBN = ISBN;
}
void Book::setLLC(string LLC){
    this->LLC = LLC;
}
void Book::setStock(string Stock){
    this->Stock = Stock;
}
