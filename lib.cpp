#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

class temp
{
  string id,name,author,search;
  fstream file;
   public:
        void addbook();
        void showall();
        void extractbook();
}obj;
int main() 
{

   char choice;
   while (true)
   {
       cout<<"---------------------------";
       cout<<"\n 1.show all books";
       cout<<"\n 2.Extract books";
       cout<<"\n 3.Add books (admin)";
       cout<<"\n 4.Exit";
       cout<<"\n ---------------------------";
       cout<<"\n Enter your choice : ";
       cin>>choice;

       switch(choice)
       {
          case '1':
             cin.ignore();
             obj.showall();
           break;
          case '2':
             cin.ignore();
             obj.extractbook();
          break;
          case '3':
             cin.ignore();
             obj.addbook();
          break;
          case '4':
             return 0;
            break;
          default:
            cout<<" Invalid choice";
        }
      
    } 
 return 0;  
}
void temp :: addbook(){
  cout<<"\n Enter book ID : ";
   getline(cin,id);
  cout<<"\n Enter book name : ";
   getline(cin,name);
  cout<<"\n Enter book's Author name : ";
   getline(cin,author);

  file.open("bookData.txt", ios :: out | ios :: app);
  file<<id<<"*"<<name<<"*"<<author<<endl;
  file.close();

}
void temp :: showall(){
 file.open("bookData.txt", ios::in);
  if (!file) {
    cout << "No data found!" << endl;
    return;
  }
  cout << "\n\n";
  cout << "\t\t Book Id \t\t\t Book Name \t\t\t Author's Name" << endl;
  while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author, '\n')) {
    cout << "\t\t\t" << id << "\t\t\t " << name << "\t\t\t" << author << endl;
  }
  file.close();
}
void temp :: extractbook(){
   showall();
    cout << "Enter Book Id: ";
    getline(cin, search);

    file.open("bookData.txt", ios::in);
    if (!file) {
        cout << "No data found!" << endl;
        return;
    }

    bool found = false;
    cout << "\n\n";
    cout << "\t\t Book Id \t\t\t Book Name \t\t\t Author's Name" << endl;
    while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author, '\n')) {
        if (search == id) {
            cout << "\t\t " << id << " \t\t\t " << name << " \t\t\t " << author << endl;
            found = true;
            break; 
        }
    }

    if (found) {
        cout << "Book Extracted Successfully...!" << endl;
    } else {
        cout << "Book not found!" << endl;
    }

    file.close();
}