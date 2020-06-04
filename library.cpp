
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
typedef struct book{
    int acc_no;
    string a_name;
    string title;
    short flag;
}Book;
void print(const Book & B)
{
        cout<<"Accession Number: "<<B.acc_no<<endl;
        cout<<"Author Name: "<<B.a_name<<endl;
        cout<<"Title: "<<B.title<<endl;
        B.flag?cout<<"Available":cout<<"Not availabe";
        cout<<endl;
        cout<<"_____________________________________"<<endl;
}
void print(const Book arr[], int len)
{
    for(int i=0;i<len;i++){
        print(arr[i]);
    }
}
Book addBook(){
    Book temp;
    cout<<"Accession Number: ";
    cin>>temp.acc_no;
    cout<<"Author Name: ";
    cin>>temp.a_name;
    cout<<"Title: ";
    cin>>temp.title;
    temp.flag=1;
    return temp;
}
void searchAuthorBook(const Book arr[], int len,string name){
    int flag=0;
    for(int i=0;i<len;i++){
        if(arr[i].a_name==name){
            print(arr[i]);
            flag=1;   
        }
    }
    if(flag==0){
        cout<<"No book for author "<<name<<endl;
        cout<<"_____________________________________"<<endl;
    }
}
void BookCount(const Book arr[], int len,string title){
    int count=0,availabe=0;
    for(int i=0;i<len;i++){
        if(arr[i].title==title){
            count++;
            if(arr[i].flag==1){
                availabe++;
            }
        }
    }
    if(count==0){
        cout<<"No book for title "<<title<<endl;
        cout<<"_____________________________________"<<endl;
    }else{
        cout<<"Number of books for title "<<title<<" : "<<count<<endl;
        cout<<"Number of availabe books for title "<<title<<" : "<<availabe<<endl;
        cout<<"_____________________________________"<<endl;
    }
}
void IssueBook(Book arr[],int len,int acc_no){
    int flag=0;
    for(int i=0;i<len;i++){
        if(arr[i].acc_no==acc_no){
            arr[i].flag=0;
            flag=1;
        }
    }
    if(flag==0){
        cout<<"No book with Accession Number :"<<acc_no<<endl;
        cout<<"_____________________________________"<<endl;
    }else{
        cout<<"Book with Accession Number "<<acc_no<<" issued"<<endl;
    }
}
void ReturnBook(Book arr[],int len,int acc_no){
    int flag=0;
    for(int i=0;i<len;i++){
        if(arr[i].acc_no==acc_no){
            arr[i].flag=1;
            flag=1;
        }
    }
    if(flag==0){
        cout<<"No book with Accession Number :"<<acc_no<<endl;
        cout<<"_____________________________________"<<endl;
    }else{
        cout<<"Book with Accession Number "<<acc_no<<" returned"<<endl;
    }
}
int main()
{
    Book Arr[100];
    int Book_count=0;
    bool done = false;
    while (!done)
    {
        cout << "Library Management" <<endl
        << "1. Display Book Information.\n"
        << "2. Add new book.\n"
        << "3. Book of Author\n"
        << "4. Number of Book of title.\n"
        << "5. Total number of Books.\n"
        << "6. Issue a Book.\n"
        << "7. Return Book.\n"
        << "8. Exit.\n";
        int choice;
        cin >> choice;
        if(choice==1){
            print(Arr,Book_count);
        }else if(choice==2){
            Arr[Book_count++]=addBook();
        }else if(choice==3){
            string name;
            cout<<"Author Name :";
            cin>>name;
            searchAuthorBook(Arr,Book_count,name);
        }else if(choice==4){
            string title;
            cout<<"Title :";
            cin>>title;
            BookCount(Arr,Book_count,title);
        }else if(choice==5){
            cout<<"Total number books in Library "<<" : "<<Book_count<<endl;
            cout<<"_____________________________________"<<endl;
        }else if(choice==6){
            int acc_no;
            cout<<"Accession number :";
            cin>>acc_no;
            IssueBook(Arr,Book_count,acc_no);
        }else if(choice==7){
            int acc_no;
            cout<<"Accession number :";
            cin>>acc_no;
            ReturnBook(Arr,Book_count,acc_no);    
        }
        else if(choice==8){
            done=true;
        }
    }
    return 0;
}
