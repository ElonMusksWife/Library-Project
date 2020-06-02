#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class Book{
private:
       string Number;
       string Author;
       string Title;
       string Year;
       string Publisher;
       string ISBN;
       string LLC;
       string Stock;
public:
    //Constructors

    Book( string Number, string Author, string Title, string Year, string ISBN, string Publisher, string LLC, string Stock);


    string getNumber();
    string getAuthor();
    string getTitle();
    string getYear();
    string getISBN();
    string getPublisher();
    string getLLC();
    string getStock();

    void setNumber(string Number);
    void setAuthor(string Author);
    void setTitle(string Title);
    void setYear(string Year);
    void setPublisher(string Publisher);
    void setISBN(string ISBN);
    void setLLC(string LLC);
    void setStock(string Stock);
};

#endif // BOOK_H_INCLUDED
