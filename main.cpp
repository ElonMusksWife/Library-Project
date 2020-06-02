#include <iostream>
#include <string>
#include <vector>
#include <fstream>//file stream processing types
#include <cstdlib>//exit function prototype
#include <iomanip>
#include <algorithm>

#include "Book.h"

using namespace std;


 void printVector(vector<Book>& Book_vector, int i){

                    cout<<left<<setw(12)<<"Number: "<<left<<Book_vector[i].getNumber()<<endl;
                    cout<<left<<setw(12)<<"Author: "<<left<<Book_vector[i].getAuthor()<<endl;
                    cout<<left<<setw(12)<<"Title: "<<left<<Book_vector[i].getTitle()<<endl;
                    cout<<left<<setw(12)<<"Year: "<<left<<Book_vector[i].getYear()<<endl;
                    cout<<left<<setw(12)<<"ISVN: "<<left<<Book_vector[i].getISBN()<<endl;
                    cout<<left<<setw(12)<<"Publisher: "<<right<<Book_vector[i].getPublisher()<<endl;
                    cout<<left<<setw(12)<<"LLC: "<<left<<Book_vector[i].getLLC()<<endl;
                    cout<<left<<setw(12)<<"Stock: "<<left<<Book_vector[i].getStock()<<endl<<endl;
                    }

int main(){
    vector<string> Library;//Library as vector to store books
    vector<Book> Book_vector;
    string str;

       string Number;
       string Author;
       string Title;
       string Year;
       string Publisher;
       string ISBN;
       string LLC;
       string Stock;
       char choice;
       string nameDelete;
       int outf=1;

    fstream inClientFile, outClientFile;
    inClientFile.open("test3.csv", ios::in);

    if (!inClientFile)
    {
      cerr << "File could not be opened" << endl;
      exit (EXIT_FAILURE);
    }

   while(!inClientFile.eof()){
        getline(inClientFile, str, ';');

        //inClientFile.getline()
        Library.push_back(str);

    }

    unsigned int size_lib = Library.size();

    for(unsigned int i = 0; i<size_lib; i+=8){
        Book newBook(Library[i],Library[i+1],Library[i+2],Library[i+3],Library[i+4],Library[i+5],Library[i+6],Library[i+7]);
                  //   string Number, string Author, string Title, string Year, string ISBN, string Publisher, string LLC, string Stock);
        Book_vector.push_back(newBook);
        }
/*

        }*/
  //  for (auto i= Book_vector.begin();i!= Book_vector.end(); ++i){}


     /* */



    cout<<endl<<endl<<setw(80)<<"Welcome to Library Management System"<<endl<<endl;
    cout<<setw(65)<<"****"<<endl<<endl;
    cout<<setw(68)<<"Main Menu"<<endl<<endl;
    cout<<setw(65)<<"****"<<endl<<endl;
    while(outf)
    {
        cout<<"***Available commands***"<<endl<<endl;
        cout<<"****"<<endl;
        cout<<"1: Add book"<<endl<<"2: Delete Book"<<endl<<"3: Modify Book"<<endl<<"4: View Book"<<endl<<"5: Return book"<<endl<<"6: Issue book"<<endl<<"7: Search book"<<endl<<"8: Print all Books"<<endl<<"9: Sort Books"<<endl<<"q: Exit system"<<endl<<"****"<<endl;
        cout<<endl<<"Please enter your choice:";
        cin>>choice;
        cout<<endl<<endl;
        switch(choice){
            case '1':
            {//1- add
                cout<<endl<<"***Book addition***"<<endl<<endl;
                cout<<"Please enter the Author's name"<<endl;
                cin>>Author;
                cout<<"Title"<<endl;
                cin>>Title;
                cout<<"Year"<<endl;
                cin>>Year;
                cout<<"ISBN"<<endl;
                cin>>ISBN;
                cout<<"Publisher"<<endl;
                cin>>Publisher;
                cout<<"LLC"<<endl;
                cin>>LLC;
                cout<<"Number"<<endl;
                cin>>Number;
                Book myBook( Number,   Author,   Title,   Year,   ISBN,   Publisher,   LLC,   Stock);
                //Book_vector.push_back(myBook);
                Book_vector.insert(Book_vector.begin()+0, myBook);
                cout<<"Book added!";

                //cout<<Book_vector.back().getAuthor();


                //cout<< Book_vector.back().getAuthor();
                break;
            }
            case '2':
            {//delete
                cout<<endl<<"***Book Deleting***"<<endl<<endl;
                cout<<"Please, enter the name of the book you want to delete "<<endl;
                unsigned int size_book_vector = Book_vector.size();
                cin.ignore(1000,'\n');
                getline(cin, nameDelete);
                bool flag = 1;
                for(unsigned int k=0; k < size_book_vector; k++){
                    if((Book_vector[k].getTitle().compare(nameDelete)) == 0){

                        Book_vector.erase(Book_vector.begin()+k);
                        flag = 0;
                    }
                }
                if(flag){
                    cout<< "Book could not be found"<<endl;
                }else{
                cout<<"Deleted";}
                break;
            }
            case  '3':{
                //3-modify
                //with set
                cout<<endl<<"***Book Modification***"<<endl<<endl;
                cout<<"Please, enter the name of the book you want to modify "<<endl;
                string nameModify;
                cin.ignore(1000,'\n');
                getline(cin, nameModify);
                bool flag = 1;
                unsigned int size_book_vector = Book_vector.size();
                for(unsigned int k=0; k < size_book_vector; k++){
                    if((Book_vector[k].getTitle().compare(nameModify)) == 0){
                        cout<<"Please, enter a parameter you want to modify: 1- Number, 2 - Author, 3 - Title, 4 - Year, 5 - ISBN, 6 - Publisher,  7 -  LLC; q - quit";
                        char choiceModify;
                        cin >> choiceModify;
                        switch(choiceModify){
                            case '1':{
                                cout<< "Write number: "<<endl;
                                cin >>Number;
                                Book_vector[k].setNumber(Number);
                            break;
                            }
                            case '2':{
                                cout<< "Write Author: "<<endl;
                                cin >>Author;
                                Book_vector[k].setAuthor(Author);
                            break;}
                            case '3':{
                                cout<< "Write Title: "<<endl;
                                cin >>Title;
                                Book_vector[k].setTitle(Title);
                            break;}
                            case '4':{
                                cout<< "Write Year: "<<endl;
                                cin >>Year;
                                Book_vector[k].setYear(Year);
                            break;}
                            case '5':{
                                cout<< "Write ISBN: "<<endl;
                                cin >>ISBN;
                                Book_vector[k].setISBN(ISBN);
                            break;}
                            case '6':{
                                cout<< "Write Publisher: "<<endl;
                                cin >>Publisher;
                                Book_vector[k].setPublisher(Publisher);
                            break;}
                            case '7':{
                                cout<< "Write LLC: "<<endl;
                                cin >>LLC;
                                Book_vector[k].setLLC(LLC);
                            break;}
                             case '8':{
                                cout<< "Write Stock: "<<endl;
                                cin >>Stock;
                                Book_vector[k].setStock(Stock);
                            break;}
                            case 'q':{
                            return 0;}


                        }//end switch

                        flag = 0;
                        cout<<"Modified "<<endl;
                        }//end if

                }//end for
               break;
        }//end case 3
            case '4':
            {//write informqtion
                cout<<endl<<"***Book View***"<<endl<<endl;
                cout<<"Write the number of book: ";
                int num;

                cin>>num;
                num -= 1;
                printVector(Book_vector,num);
                break;
            }
            case '5':
            {
               // book_Return(books);
               cout<<endl<<"***Book Return***"<<endl<<endl;
               string enteredisbn;

                        cout << "Enter the ISBN of the book you would like to return: ";
                        unsigned int size_book_vector = Book_vector.size();
                        cin >> enteredisbn;

                        int flag = 0;
                        for (unsigned int k = 0; k < size_book_vector; k++){
                        if ((Book_vector[k].getISBN().compare(enteredisbn)) == 0){
                            cout << "The book is successfully returned" << endl;
                            flag = 1;
                            int stockint = stoi(Book_vector[k].getStock());
                            stockint += 1;
                            string stockstring = to_string(stockint);
                            Book_vector[k].setStock(stockstring);
                            cout << "The number of available books is " << stockstring << endl;
                            }
                        }

                        if (flag != 1){
                            cout << "You entered wrong ISBN" << endl;
                            flag = 0;
                        }
                        break;
            }
            case '6':
            {
               // book_Issue(books);
               cout<<endl<<"***Book Issue***"<<endl<<endl;
               int flag = 0;
                    string enteredisbn;

                    cout << "Enter the ISBN of the book you would like to issue: ";
                    unsigned int size_book_vector = Book_vector.size();
                     cin.ignore(1000,'\n');
                    getline(cin, enteredisbn);


                    for (unsigned int k = 0; k < size_book_vector; k++){
                    if ((Book_vector[k].getISBN().compare(enteredisbn)) == 0){
                        cout << "The book is successfully issued" << endl;
                        flag = 1;
                        int stockint = stoi(Book_vector[k].getStock());
                        stockint -= 1;
                        string stockstring = to_string(stockint);
                        Book_vector[k].setStock(stockstring);
                        cout << "The number of available books left is " << stockstring << endl;
                        }
                    }

                    if (flag != 1){
                        cout << "The book is not found" << endl;
                        flag = 0;
                    }
                    break;
            }
            case '7':
                        {
               // search
               cout<<endl<<"***Book Searching***"<<endl<<endl;
                cout<<endl<<"***Parameters for search***"<<endl<<endl;
                cout<<"1: Author"<<endl<<"2: Title"<<endl<<"3: Year"<<endl<<"4: ISBN"<<endl<<"5: Publisher"<<endl<<"6: LLC"<<endl<<"7: Stock"<<endl<<"q: Exit to main Menu"<<endl<<"****"<<endl;
                cout<<endl<<"Choose parameter for search:"<<endl;
                cin>>choice;
                switch(choice){
                    case '1':{
                         cout<<endl<<"***Search by Author***"<<endl<<endl;
                         cout<<"Please enter Author for search:";
                         string author;
                         cin.ignore(1000,'\n');
                         getline(cin,author);
                         unsigned int size_book_vector = Book_vector.size();
                         for(unsigned int k=0; k < size_book_vector; k++){
                            if((Book_vector[k].getAuthor().compare(author)) == 0){
                                    printVector(Book_vector,(int)k);
                            }

                         }
                         break;
                    }

                    case '2':{
                         cout<<endl<<"***Search by Title***"<<endl<<endl;
                         cout<<"Please enter Title for search:";
                         string title;
                         cin.ignore(1000,'\n');
                         getline(cin,title);
                         unsigned int size_book_vector = Book_vector.size();
                         for(unsigned int k=0; k < size_book_vector; k++){
                            if((Book_vector[k].getTitle().compare(title)) == 0){
                                    printVector(Book_vector,(int)k);
                            }

                         }
                         break;
                    }

                    case '3':{
                        cout<<endl<<"***Search by Year***"<<endl<<endl;
                        cout<<"Please enter Year for search:";
                        string year;
                         cin.ignore(1000,'\n');
                         getline(cin,year);
                         unsigned int size_book_vector = Book_vector.size();
                         for(unsigned int k=0; k < size_book_vector; k++){
                            if((Book_vector[k].getYear().compare(year)) == 0){
                                    printVector(Book_vector,(int)k);
                            }

                         }
                         break;
                    }
                    case '4':{
                        cout<<endl<<"***Search by ISBN***"<<endl<<endl;
                        cout<<"Please enter ISBN for search:";
                        string isbn;
                        cin.ignore(1000,'\n');
                        getline(cin,isbn);
                         unsigned int size_book_vector = Book_vector.size();
                         for(unsigned int k=0; k < size_book_vector; k++){
                            if((Book_vector[k].getISBN().compare(isbn)) == 0){
                                    printVector(Book_vector,(int)k);
                            }

                         }
                        break;
                    }
                    case '5':{
                        cout<<endl<<"***Search by Publisher***"<<endl<<endl;
                        cout<<"Please enter Publisher for search:";
                           string publisher;
                         cin.ignore(1000,'\n');
                         getline(cin,publisher);
                         unsigned int size_book_vector = Book_vector.size();
                         for(unsigned int k=0; k < size_book_vector; k++){
                            if((Book_vector[k].getPublisher().compare(publisher)) == 0){
                                    printVector(Book_vector,(int)k);
                            }

                         }
                        break;
                    }
                    case '6':{
                        cout<<endl<<"***Search by LLC***"<<endl<<endl;
                        cout<<"Please enter LLC for search:";
                           string llc;
                         cin.ignore(1000,'\n');
                         getline(cin,llc);
                         unsigned int size_book_vector = Book_vector.size();
                         for(unsigned int k=0; k < size_book_vector; k++){
                            if((Book_vector[k].getLLC().compare(llc)) == 0){
                                    printVector(Book_vector,(int)k);
                            }

                         }
                        break;
                    }
                    case 'q':{
                        return 0;
                    }
                    default:
                    {
                        cout<<"Undefined choice, please try again"<<endl;
                        break;
                    }
                }
                break;
            }

            case '8':
            {
                     unsigned int size_book_vector = Book_vector.size();
                for(unsigned int k=0; k < size_book_vector; k++){
                    printVector(Book_vector, k);
                }

                    break;}

            case '9':{break;}

            case 'q':
            {
                outf = 0;
                break;
            }
            default:
            {
                cout<<"Wrong choice"<<endl;
                break;
            }


        }//end while
    }//end main



cout << "Good bye" << endl;


outClientFile.open("test3.csv", ios::out);

 for(unsigned int i = 0; i<Book_vector.size(); ++i)
            {
            outClientFile << Book_vector[i].getNumber() << ';';
            outClientFile << Book_vector[i].getAuthor() << ';';
            outClientFile << Book_vector[i].getTitle() << ';';
            outClientFile << Book_vector[i].getYear() << ';';
            outClientFile << Book_vector[i].getISBN() << ';';
            outClientFile << Book_vector[i].getPublisher() << ';';
            outClientFile << Book_vector[i].getLLC() << ';';
            outClientFile << Book_vector[i].getStock()  << ';';
            }



    inClientFile.close();
    outClientFile.close();
    return 0;


}
