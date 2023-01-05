#include <iostream>
#include<string>
#include<fstream>
#include <iomanip>
using namespace std;
class book{ //class book
	public:
		int book_id;
		int shelf_no;
		string book_name;
		string Author;
		int year_of_pub;
		int quantity;
		string Subject;
		int edition;
		int no_of_soldCopys;
		string cover_type;
		double price;
	    book *next;


};
book *head,*tail,*temp,*current,*q,*p; //declaration of book type pointers.

class book_list{//class book_list to implement oprations.
    private:
       string book_name,book_author,subject,cover_type;
       int shelf_no,book_id=0,year_0f_pub,quantity,edition;
       double book_price;

    public:

void new_book(){//Function to add new book with information to store.
           system("cls");
	       int num_of_books;//number new of books to store.

           if(tail==NULL){//check if the list is empty and try to read info from file.
              read_from_file();//calling of function to read from file if it exist.
            }

	        cout<<" how many books do you ";
            cin>>num_of_books;

	for( int i=0 ;i<num_of_books;i++){
		book_id+=1;//increases as the number of book increases to give id number automatically.
		//Accept information of book from the shopkeeper.
	    cout<<"Enter Title Of The Book: " <<i+1 <<"-> ";
	    cin.ignore();
	    getline(cin,book_name);
       	cout<<"Enter the Author : " <<i+1 <<"-> ";
       	getline(cin,book_author);
        cout<<"Enter Subject Of The Book: " <<i+1 <<"-> ";
        getline(cin,subject);
       	cout<<"Enter Year of published: " <<i+1 <<"-> ";
      	cin>>year_0f_pub;
     	cout<<"Enter Edition Of The Book: " <<i+1 <<"-> ";
    	cin>>edition;
    	cout<<"Enter Cover Type: " <<i+1 <<"-> ";
        cin.ignore();
    	getline(cin,cover_type);
       	cout<<"Enter Price: " <<i+1 <<"-> ";
      	cin>>book_price;
     	cout<<"Enter Shelf Number: " <<i+1 <<"-> ";
    	cin>>shelf_no;
    	cout<<"Enter Number of copys: " <<i+1 <<"-> ";
    	cin>>quantity;

            temp =new book;//create new node and point the temp to address.
            //Store information to the linked list that are entered from the shopkeeper.
            temp->book_id=book_id;
            temp->book_name=book_name;
            temp->Author=book_author;
            temp->Subject=subject;
            temp->year_of_pub=year_0f_pub;
            temp->edition=edition;
            temp->cover_type=cover_type;
            temp->price=book_price;
            temp->shelf_no=shelf_no;
            temp->quantity=quantity;

            if(tail==NULL){//if the list is empty linked list will instantiated.
               tail=temp;
               head=temp;
               tail->next=head;

            }
            else{//if the node is already instantiated, the new node will be inserted at a given position.



                    current=tail;//starting from tail.
                 do{
                        int res=book_name.compare(current->book_name);//compare book name string in the new node with the list to get the position, to make the list is sorted by book name.
                        q=current->next;
                    if(res < 0 && current == head){//at the begining.

                            temp->next=head;
                            tail->next=temp;
                            head=temp;



                        }

                       else if(res >0){

                               if(current==tail){//At the end.
                                    temp->next=head;
                                    tail->next=temp;
                                    tail=temp;

                               }
                               if(q->book_name >= book_name && res >0){//N_th position
                                    temp->next=q;
                                    current->next=temp;

                               }

                       }



                       current=current->next;//traverse to all nodes to compare the string.

		           }while(current!=tail);//till the end of the linked list.

                 }
        }
		save_to_file();//function calling to store and rewrite all informations read from the file and entered from the shopkeeper.
}


void print(){//Function to print all books in store.
	    system("cls");
        cout<<book_id;
        if(tail==NULL)//check if the list is empty and try to read info from file.
        {
         read_from_file();//calling of function to read from file if it exist.

        }


	    if(tail==NULL){
	       cout<<"There is no book in the store"<<endl;
           return;
	    }
	    current=tail->next;//staring from head node to print all books.
        cout<<left<<setw(20)<<" "<<"                   ______________________________________________________________________________________________________                 "<<endl;
        cout<<left<<setw(20)<<" "<<"___________________                                                                                                      _________________"<<endl;
        cout<<left<<setw(20)<<" "<<"=+=======================------------------------------{  BOOK INFORMATION   }-------------------------=================================+="<<endl;
		cout<<left<<setw(20)<<" "<<"=+======================================================================================================================================+="<<endl;
		cout<<left<<setw(20)<<" "<<"=+= "<<setw(5)<<" ID "<<"|"<<setw(20)<<" Title "<<"|"<<setw(20) <<" Author "<<"|"<<setw(10)<<" Subject "<<"| "<<setw(5)<<"year"<<" | "<<setw(7)<<"Edition"<<" | "<<setw(10)<<"Cover type"<<" | "<<setw(5)<<"price"<<" | "<<setw(8)<<"Shelf_no"<<" | "<<setw(8)<<"Quantity"<<" | "<<setw(10)<<"Sold copys"<<"|||"<<endl;
		cout<<left<<setw(20)<<" "<<"=+======================================================================================================================================+="<<endl;

        do{
		cout<<left<<setw(20)<<" "<<"||| "<<setw(5)<<current->book_id<<"|"<<setw(20)<<current->book_name<<"|"<<setw(20) <<current->Author<<"|"<<setw(10)<<current->Subject<<"| "<<setw(5)<<current->year_of_pub<<" | "<<setw(7)<<current->edition<<" | "<<setw(10)<<current->cover_type<<" | "<<setw(5)<<current->price<<" | "<<setw(8)<<current->shelf_no<<" | "<<setw(8)<<current->quantity<<" | "<<setw(10)<<current->no_of_soldCopys<<"|||"<<endl;
        cout<<left<<setw(20)<<" "<<"-+--------------------------------------------------------------------------------------------------------------------------------------+-"<<endl;
           		current=current->next;//traverse to next node.
		}while(current!=tail->next);
		cout<<left<<setw(20)<<" "<<"=+======================================================================================================================================+="<<endl;



	}


void sale_books(){//function to sale_books.
    system("cls");
    int no;//number of book title.
    int num_of_copy;//number of copy;
    string word;//word to search book;
    cout<<"how many book do you want : ";
    cin>>no;
     for(int i=0;i<no;i++){

         cout<<"Enter title , author or subject of the book : "<< i+1;
         cin>>word;
         Search(word);
         cout<<"Enter number of copy to sale : ";
         cin>>num_of_copy;
         current->quantity-=num_of_copy;//number of copy decreases.
         current->no_of_soldCopys+=num_of_copy;//number of sold copy increases.

		save_to_file();//calling function to update the information.
     }

}
void delete_book(){//function to delete book or node.
   system("cls");
   string Book;//book name.
   int id;//id num of the book to delete.
   cout<<"Enter book title to delete"<<endl;
   cin>>Book;
   Search(Book);//function call to search.
   cout<<"Enter id of the book: ";
   cin>>id;
   //current describes the exact address of the node.
   if(id==current->book_id){
      if(tail==NULL){//if there is no node.
          cout<<"There is no book in the store"<<endl;
          return;
        }
     else if(tail->next==tail){//if it is only  one node.
            tail=NULL;
            delete head;
        }
     else if(current==head){//delete at the beginning of linked list.
           head=current->next;
           tail->next=head;
           delete current;
        }
     else if(current==tail){//delete at the end of linked list.
            tail=p;
            tail->next=head;
            delete current;
        }
     else{//delete at nth position.
          p->next=current->next;
          delete current;

   }
   save_to_file();//update the file.
 }
}
void charity_and_discount(){

// this function to used to make discount and give books to charity
//charity
// first the books must be searched from the store
//and if they exist and if the owner wants to give all books it will be removed or deleted from store.
//and if the owner wants to give specific quantity of that book the quantity of the book must decreases
// discount
//  first the books must be searched from the store
//if exist accept how much percent of discount is the owner wants
//calculate and decrease the price of books

//you can use by calling delete and search functions.




}
void most_and_worest_seald_books(){
  //this function is used to determaine  most seald and worest seald books.
  // works with sorting algorithm
  //first sorting must out put assending order of books by seald_number_copy,
  //seacond sorting must out put desending order of books by seald_number_copy,

  //finally it prints as the owner wonts

  //use two function for asending and desending
  //u can use any sort algorithm as want.

}
void store_status(){
  //used as summary
  //desplay top 10 seald books
  // desplay the income of the store
  // and add some ....


}







void Search(string val){//function to search.
	current=head;//starting from head.
     p=tail;//to track behind current pointer.
	 do{

        if(val.compare(current->book_name)==0 || val.compare(current->Author)==0 || val.compare(current->Subject)==0){
               cout<<left<<setw(50)<<" "<<setw(10)<<"=+="<<current->book_id<<setw(10)<<current->book_name<<setw(10)<<current->Author<<setw(10)<<current->price <<endl;
                break;
            }

            current=current->next;//traverse to next node.
            p=p->next;//traverse to next node.
         }while(current!=head);

}

void save_to_file(){//function to save info from linked list to file.
    current=tail->next;//starting from the beginning.
    ofstream myFile("BOOK.txt");//open file.
    if(myFile.is_open()){
       do{//store all informations on the linked list to file.
          myFile<<current->book_id<<endl;
          myFile<<current->book_name<<endl;
          myFile<<current->Author<<endl;
          myFile<<current->Subject<<endl;
          myFile<<current->year_of_pub<<endl;
          myFile<<current->edition<<endl;
          myFile<<current->cover_type<<endl;
          myFile<<current->price<<endl;
          myFile<<current->shelf_no<<endl;
          myFile<<current->quantity<<endl;
          myFile<<current->no_of_soldCopys<<endl;

          current=current->next;//traverse to next node.
       }
       while(current!=tail->next);
       myFile.close();//close file.
       cout<<"Information is saved successfully."<<endl;

    }
    else
        cout<<"Unable to open file"<<endl;
        cout<<endl;

}

void read_from_file(){//function to read from file save to linked list.
    ifstream myFile("BOOK.txt");
    if(myFile.is_open()){
       while(!myFile.eof()){
           temp=new book;//create new node and point temp to book address.
           //read and store data from file to linked list.
          myFile >>temp->book_id;
          myFile >>temp-> book_name;
          myFile >>temp->Author;
          myFile >>temp-> Subject;
          myFile >>temp->year_of_pub;
          myFile >>temp->edition;
          myFile >>temp->cover_type;
          myFile >>temp->price;
          myFile >>temp->shelf_no;
          myFile >>temp->quantity;
          myFile >>temp->no_of_soldCopys;



            if(myFile.eof()){//to delete temp node with garbage files.
                delete temp;
                break;

            }

            book_id+=1;//counting book id.
           if(tail==NULL){//instantiation.

              tail=temp;
              head=temp;
              tail->next=head;

           }
           else {//at the end;
              tail->next=temp;
              tail=temp;
              tail->next=head;

           }

         }

     myFile.close();

     }
     else
         cout<<"Unable to open file"<<endl;

}
};

int main(){
book_list bl;
system("Color 5f");
	int choice;
	cout<<endl;
	cout<<left<<setw(40)<<" "<<setw(40)<<"___---------------- MENU------------------___"<<endl;
	cout<<left<<setw(40)<<" "<<setw(40)<<"___->  1.Store new book"<<"<-___"<<endl;
	cout<<left<<setw(40)<<" "<<setw(40)<<"___->  2.Display all book"<<"<-___"<<endl;
	cout<<left<<setw(40)<<" "<<setw(40)<<"___->  3.Seal books    "<<"<-___"<<endl;
	cout<<left<<setw(40)<<" "<<setw(40)<<"___->  4.Delete   "<<"<-___"<<endl;
	cout<<left<<setw(40)<<" "<<setw(40)<<"___->  5.charity and discount"<<"<-___"<<endl;
	cout<<left<<setw(40)<<" "<<setw(40)<<"___->  6.most and worst sealed books "<<"<-___"<<endl;
	cout<<left<<setw(40)<<" "<<setw(40)<<"___->  7.store status"<<"<-___"<<endl;
	cout<<left<<setw(40)<<" "<<setw(40)<<"___->  n.------"<<"<-___"<<endl;
	cout<<left<<setw(40)<<" "<<setw(40)<<"___->  10.Exit" <<"<-___"<<endl;
	cout<<left<<setw(40)<<" "<<setw(40)<<"___---------------------------------------___"<<endl;
	cout<<"===+====-> Please Enter your choice : ";
	cin>>choice;
      switch(choice){
		case 1:
			bl.new_book();//function calling to add new books on store.
            main();
            break;
        case 2:
			bl.print();//function calling to add new books on store.
            main();
            break;
        case 3:
			bl.sale_books();//function calling to add new books on store.
            main();
            break;
        case 4:
            bl.delete_book();
            main();
            break;

        case 15:
                exit(0);
                break;
        default:
            cout<<"Please enter the valid option!"<<endl;
            main();
            break;
	}




}
