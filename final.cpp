#include <iostream>
#include<string.h>
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
//class descending_order_stack is implemented  to store ascending order (by number of copy) of books in stack.
//when we print or peek  the stack data the data will print descending order.
class descending_order_stack:public book{
        //declaration of pointers.
       descending_order_stack *top=NULL,*stemp,*stail,*scurrent,*snext;
   public:
void push(book* current){//to push the node data.
        stemp=new descending_order_stack;//create new dos type node and stack type pointer points the node.
        snext=new descending_order_stack;//creating new stack next pointer on each node;
      // store data from sorted linked list to stack linked list.
        stemp->book_id=current->book_id;
        stemp-> book_name=current->book_name;
        stemp->Author=current->Author;
        stemp-> Subject=current->Subject;
        stemp->year_of_pub=current->year_of_pub;
        stemp->edition=current->edition;
        stemp->cover_type=current->cover_type;
        stemp->price=current->price;
        stemp->shelf_no=current->shelf_no;
        stemp->quantity=current->quantity;
        stemp->no_of_soldCopys=current->no_of_soldCopys;

  if(top==NULL){//if stack is empty
      top=stemp;
      stail=stemp;
      stail->snext=NULL;
  }

  else{//store the node on the top of stack.
      stemp->snext=top;
      top=stemp;

   }


}


//to print all deta.
void display(){
      system("cls");

	    if(top==NULL){//if stack is empty.
	       cout<<"There is no book in the store"<<endl;
           return;
	    }

        cout<<left<<setw(20)<<" "<<"                   ______________________________________________________________________________________________________                 "<<endl;
        cout<<left<<setw(20)<<" "<<"___________________                                                                                                      _________________"<<endl;
        cout<<left<<setw(20)<<" "<<"=+=======================------------------------------{  BOOK INFORMATION   }-------------------------=================================+="<<endl;
		cout<<left<<setw(20)<<" "<<"=+======================================================================================================================================+="<<endl;
		cout<<left<<setw(20)<<" "<<"=+= "<<setw(5)<<" ID "<<"|"<<setw(20)<<" Title "<<"|"<<setw(20) <<" Author "<<"|"<<setw(10)<<" Subject "<<"| "<<setw(5)<<"year"<<" | "<<setw(7)<<"Edition"<<" | "<<setw(10)<<"Cover type"<<" | "<<setw(5)<<"price"<<" | "<<setw(8)<<"Shelf_no"<<" | "<<setw(8)<<"Quantity"<<" | "<<setw(10)<<"Sold copys"<<"|||"<<endl;
		cout<<left<<setw(20)<<" "<<"=+======================================================================================================================================+="<<endl;
        scurrent=top;//staring from top node to print all books.

        while(scurrent!=NULL){

		cout<<left<<setw(20)<<" "<<"||| "<<setw(5)<<scurrent->book_id<<"|"<<setw(20)<<scurrent->book_name<<"|"<<setw(20) <<scurrent->Author<<"|"<<setw(10)<<scurrent->Subject<<"| "<<setw(5)<<scurrent->year_of_pub<<" | "<<setw(7)<<scurrent->edition<<" | "<<setw(10)<<scurrent->cover_type<<" | "<<setw(5)<<scurrent->price<<" | "<<setw(8)<<scurrent->shelf_no<<" | "<<setw(8)<<scurrent->quantity<<" | "<<setw(10)<<scurrent->no_of_soldCopys<<"|||"<<endl;
        cout<<left<<setw(20)<<" "<<"-+--------------------------------------------------------------------------------------------------------------------------------------+-"<<endl;
        scurrent=scurrent->snext;//traverse to next node.

        }
		cout<<left<<setw(20)<<" "<<"=+======================================================================================================================================+="<<endl;


  return;
}
};



class book_list{//class book_list to implement operations.
    private:
       //local variables to book_list class.
       string book_name,book_author,subject,cover_type;
       int shelf_no,book_id,year_0f_pub,quantity,edition;
       double book_price;
       bool found=false;

public:

void new_book(){//Function to add new book with information to store.
           system("cls");
	       int num_of_books;//number new of books to store.

           if(tail==NULL){//check if the list is empty and try to read info from file.
             book_id=read_from_file();//calling of function to read from file if it exist.

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
            temp->no_of_soldCopys=0;

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
		continue_page();//
}


void print(){//Function to print all books in store.
	    system("cls");
        if(tail==NULL)//check if the list is empty and try to read info from file.
        {
        book_id =read_from_file();//calling of function to read from file if it exist.

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
		cout<<left<<setw(20)<<" "<<"||| "<<setw(5)<<current->book_id<<"| "<<setw(20)<<current->book_name<<"| "<<setw(20) <<current->Author<<"|"<<setw(10)<<current->Subject<<"| "<<setw(5)<<current->year_of_pub<<" | "<<setw(7)<<current->edition<<" | "<<setw(10)<<current->cover_type<<" | "<<setw(5)<<current->price<<" | "<<setw(8)<<current->shelf_no<<" | "<<setw(8)<<current->quantity<<" | "<<setw(10)<<current->no_of_soldCopys<<"|||"<<endl;
        cout<<left<<setw(20)<<" "<<"-+--------------------------------------------------------------------------------------------------------------------------------------+-"<<endl;
           		current=current->next;//traverse to next node.
		}while(current!=tail->next);
		cout<<left<<setw(20)<<" "<<"=+======================================================================================================================================+="<<endl;


continue_page();
}
void sell_books(){//function to sell_books.
    system("cls");
    int no,id;//number of book title.
    int num_of_copy;//number of copy;
    string word;//word to search book;

     if(tail==NULL)//check if the list is empty and try to read info from file.
        {
        book_id =read_from_file();//calling of function to read from file if it exist.

        }
    cout<<"how many book do you want ? ";
    cin>>no;
     for(int i=0;i<no;i++){

         cout<<"Enter title , author or subject of the book : "<< i+1;
         cin>>word;
         Search(word);
         a:
         cout<<"Enter the id number"<<endl;
         cin>>id;
         Search(id);
         if(id==current->book_id){
         cout<<"Enter number of copy to sale : ";
         cin>>num_of_copy;
         current->quantity-=num_of_copy;//number of copy decreases.
         current->no_of_soldCopys+=num_of_copy;//number of sold copy increases.
         save_to_file();//calling function to update the information.
         }
         else{
            cout<<"Id number of the book is not identical"<<endl;
            goto a;
         }

     }
continue_page();
}
void delete_book(){//function to delete book or node.
   system("cls");
   string Book;//book name.
   int id;//id num of the book to delete.


    if(tail==NULL){//check if the list is empty and try to read info from file.
        book_id=read_from_file();//calling of function to read from file if it exist.

     }

   cout<<"Enter book title to delete"<<endl;
   cin>>Book;
   Search(Book);//function call to search.
   cout<<"Enter id of the book: ";
   cin>>id;
   Search(id);//function call to search.
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
   save_to_file();//rewrite the file.
 }
 continue_page();
}
void charity_and_discount(){
  system("cls");
  int num_of_books;//total number of books
  int num_cpy;//number of copy of a book.
  double percent;
  string word;//to search.
  char choice;//charity or discount.



        cout<<"For charity enter"<<" 'c' "<<" for Discount "<<"enter "<<"' d' : " ;
        cin>>choice;
        if( choice=='c' || choice=='C'){
           cout<<"How many book do you want to ";
           cin>>num_of_books;
           for(int i=0;i<num_of_books;i++){
                   cout<<"Enter title , author or subject of the book : "<< i+1;
                   cin>>word;
                   Search(word);
                   a:
                   cout<<"How many copy do you want ";
                   cin>>num_cpy;
                   if(current->quantity >= num_cpy){
                    current->quantity -=num_cpy;
                    i+=num_cpy;
                   }
                   else{
                    cout<<"You have no enough book"<<endl;
                    goto a;
                   }

                }



        }
        else if(choice=='d' || choice=='D'){
               cout<<"Enter title , author or subject of the book : ";
               cin>>word;
               Search(word);
               if(found){
                 cout<<"How much percent  do you want to discount : ";
                 cin>>percent;
                 current->price-=current->price *(percent/100);
                 cout<<"discount is updated successfully."<<endl;
               }
               else {
                cout<<"Book not found"<<endl;

               }



        }

continue_page();
}

  //this function is used to determin  most  and worst sold books in order.
  //first sorting  put ascending order of books by sold_number_copy,
  //second sorting  out put descending order which is the ascending order data stored on descending order stack of books by sold_number_copy,
  //implemented using merge sort algorithim.
  //finally it prints as the owner wants



void most_and_worest_sold_books(){
    descending_order_stack dos;
    system("cls");
    if(tail==NULL){//check if the list is empty and try to read info from file.
        book_id=read_from_file();//calling of function to read from file if it exist.

     }
    int option;

   MergeSort(&head );
    current=head;
        do{

          dos.push(current);//calling push function to store all nodes to decending order stack;

          if(current->next==NULL){//if current pointer points the last node  assign to tail and make its pointer to point the head (circularly linked);

             current->next=head;
             tail=current;
          }
          current=current->next;
         }while(current!=head);



cout<<" Enter 1 to print from best \n Enter  2 to print from worest: ";
cin>>option;



    if(option== 1){
      //sort descending order.
     dos.display();

    }
    else if(option == 2){

      //sort ascending order.
      print();

    }
    continue_page();

}
 //used as summary
  // display the income of the store
  //display total  sold books.
  //full volume of the store.
  //number of books
void store_status(){

    system("cls");
   if(tail==NULL)//check if the list is empty and try to read info from file.
        {
         read_from_file();//calling of function to read from file if it exist.

        }

  int sold_books,count_by_title,full_number_of_books;
  double total_income=0;

   sold_books=count_by_title=full_number_of_books=0;

  current=tail;
   do{
      count_by_title++;//count nodes, one node represent number of books with there copy.
      full_number_of_books +=current->quantity;// sum of number of copy exist in all nodes.
      sold_books +=current->no_of_soldCopys;// sum of number of sold copy in all nodes.
      total_income +=(current->price * current->no_of_soldCopys);

     current=current->next;//traverse to next node.
    }while(current!=tail);

    cout<<left<<setw(20)<<" "<<"=+========================================================+="<<endl;
    cout<<left<<setw(20)<<" "<<"=+= "<<setw(35)<<"Current Total book capacity  "<<"|  "<<setw(8)<<full_number_of_books<<setw(5)<<"Books"<<"  =+= "<<endl;
    cout<<left<<setw(20)<<" "<<"=+=------------------------------------------------------=+="<<endl;
    cout<<left<<setw(20)<<" "<<"=+= "<<setw(35)<<"Number of different books "<<"|  "<<setw(8)<<count_by_title <<setw(5)<<"Books" <<"  =+= "<<endl;
    cout<<left<<setw(20)<<" "<<"=+=------------------------------------- ----------------=+="<<endl;
    cout<<left<<setw(20)<<" "<<"=+= "<<setw(35)<<"Number of sold-out books "<<"|  "<<setw(8)<<sold_books<<setw(5)<<"Books"<<"  =+= "<<endl;
    cout<<left<<setw(20)<<" "<<"=+=------------------------------------------------------=+="<<endl;
    cout<<left<<setw(20)<<" "<<"=+= "<<setw(35)<<"Total income "<<"|  "<<setw(8)<<total_income<<setw(5)<<"Birr"<<"  =+= "<<endl;
    cout<<left<<setw(20)<<" "<<"=+========================================================+="<<endl;

continue_page();
}

void Search(string val){//function to search.
	current=head;//starting from head.
	found=false;//check the book is found .
    p=tail;//to track behind current pointer.
     cout<<left<<setw(20)<<" "<<"=+======================================================================================================================================+="<<endl;
     cout<<left<<setw(20)<<" "<<"=+= "<<setw(5)<<" ID "<<"|"<<setw(20)<<" Title "<<"|"<<setw(20) <<" Author "<<"|"<<setw(10)<<" Subject "<<"| "<<setw(5)<<"year"<<" | "<<setw(7)<<"Edition"<<" | "<<setw(10)<<"Cover type"<<" | "<<setw(5)<<"price"<<" | "<<setw(8)<<"Shelf_no"<<" | "<<setw(8)<<"Quantity"<<" | "<<setw(10)<<"Sold copys"<<"|||"<<endl;
     cout<<left<<setw(20)<<" "<<"=+======================================================================================================================================+="<<endl;
	 do{

        if(val.compare(current->book_name)==0 || val.compare(current->Author)==0 || val.compare(current->Subject)==0){// compare function returns integer.

               cout<<left<<setw(20)<<" "<<"||| "<<setw(5)<<current->book_id<<"|"<<setw(20)<<current->book_name<<"|"<<setw(20) <<current->Author<<"|"<<setw(10)<<current->Subject<<"| "<<setw(5)<<current->year_of_pub<<" | "<<setw(7)<<current->edition<<" | "<<setw(10)<<current->cover_type<<" | "<<setw(5)<<current->price<<" | "<<setw(8)<<current->shelf_no<<" | "<<setw(8)<<current->quantity<<" | "<<setw(10)<<current->no_of_soldCopys<<"|||"<<endl;
               cout<<left<<setw(20)<<" "<<"-+--------------------------------------------------------------------------------------------------------------------------------------+-"<<endl;
               found=true;//the book is found.
            }

            current=current->next;//traverse to next node.
            p=p->next;//traverse to next node.
         }while(current!=head);

}

void Search(int val){//function to search.
	current=head;//starting from head.
	found=false;//check the book is found .
    p=tail;//to track behind current pointer.
     cout<<left<<setw(20)<<" "<<"=+======================================================================================================================================+="<<endl;
     cout<<left<<setw(20)<<" "<<"=+= "<<setw(5)<<" ID "<<"|"<<setw(20)<<" Title "<<"|"<<setw(20) <<" Author "<<"|"<<setw(10)<<" Subject "<<"| "<<setw(5)<<"year"<<" | "<<setw(7)<<"Edition"<<" | "<<setw(10)<<"Cover type"<<" | "<<setw(5)<<"price"<<" | "<<setw(8)<<"Shelf_no"<<" | "<<setw(8)<<"Quantity"<<" | "<<setw(10)<<"Sold copys"<<"|||"<<endl;
     cout<<left<<setw(20)<<" "<<"=+======================================================================================================================================+="<<endl;
	 do{

        if(val==current->book_id){// compare function returns integer.

               cout<<left<<setw(20)<<" "<<"||| "<<setw(5)<<current->book_id<<"|"<<setw(20)<<current->book_name<<"|"<<setw(20) <<current->Author<<"|"<<setw(10)<<current->Subject<<"| "<<setw(5)<<current->year_of_pub<<" | "<<setw(7)<<current->edition<<" | "<<setw(10)<<current->cover_type<<" | "<<setw(5)<<current->price<<" | "<<setw(8)<<current->shelf_no<<" | "<<setw(8)<<current->quantity<<" | "<<setw(10)<<current->no_of_soldCopys<<"|||"<<endl;
               cout<<left<<setw(20)<<" "<<"-+--------------------------------------------------------------------------------------------------------------------------------------+-"<<endl;
               found=true;//the book is found.
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

int read_from_file(){//function to read from file save to linked list.
    book_id=0;
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

           book_id=(temp->book_id > book_id) ? temp->book_id :book_id; //get the maximum id number.
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
      return book_id;
     }
     else
         cout<<"Unable to open file"<<endl;
}

void continue_page(){
  string res;
  cout<<"Enter any key to continue.....";
  cin>>res;
  }
book* Merge(book* head1, book* head2)
  { //declaration of pointers to track nodes;
	book *t1 = new book;
	book *t2 = new book;
	book *temp = new book;

   if(head1 == NULL)// Return if the first list is empty the second list is returned as sorted list.
		return head2;

   if(head2 == NULL)// if the second list is empty the first list is returned as sorted list.
		return head1;

	t1 = head1;//assign first list to t1.

	//the loop is  to insert all nodes one by one from list 2 to list one.
	//the if list two is null(all nodes are inserted to list one), list one is returned as sorted list.

	while (head2 != NULL)
	{

        t2 = head2;//assign second list to t2.


		head2 = head2->next;// Shifting second list head to the next.
		t2->next = NULL;//t2(the first node) will detached from list 2.

		// If the no_of_soldCopys  is lesser than the head of first list add that node at the beginning.
		if(head1->no_of_soldCopys > t2->no_of_soldCopys)
		{
			t2->next = head1;
			head1 = t2;
			t1 = head1;
			continue;
		}
		flag:
		if(t1->next == NULL)
		{
			t1->next = t2;
			t1 = t1->next;
		}
		// Traverse first list until t2->no_of_soldCopys more than node's no_of_soldCopys.
		else if(t1->next->no_of_soldCopys <= t2->no_of_soldCopys)
		{
			t1 = t1->next;
			goto flag;
		}
		else
		{
			// Insert the node as t2->no_of_soldCopys is lesser than the next node.
			temp = t1->next;
			t1->next = t2;
			t2->next = temp;
		}




	}

    return head1;//return sorted list.
}

// A function is used to divide the lists in to to parts
// and send the first and the second list to merge function
//the divide and concur is made by recursion or function calling itself.

void MergeSort(book **head)//parameter head of the list to divide.
{
    //creating pointers to track the the divided lists head and the centre of the list(temp).
	book *first= new book;
	book *second = new book;
	book *temp = new book;
	first = *head;
	temp = *head;


	if(first == NULL || first->next == first)//  if list have less than two nodes.
	{
	    first->next=NULL;//change the circular node to normal node.
        return;
	}
	else
	{
		// traverse to get the middle of the linked list.
		//in this loop first pointer will traverse two times in one iteration(fast or skip list).
		//and temp pointer will traverse half of first pointer then the middle will be temp.
		while(first->next != *head)
		{
			first = first->next;
			if(first->next != *head)
			{
				temp = temp->next;
				first = first->next;
			}
		}
		//divide the list in two parts after temp and up to temp pointer.
		second = temp->next;
		first->next=second;
		first = *head;
		temp->next = first;


	}

	  // Implementing divide and conquer approach with recursion.
	   MergeSort(&first);
       MergeSort(&second);


  // after the divide and concur recursion returned  Merge function is called to merge the two part of the list into a sorted one.
  //then returned the the list.
   *head = Merge(first, second);
  }
};

int main(){
    book b;
    book_list bl;
    system("Color 5f");
    int choice;

 do{
    system("cls");
    cout<<endl;
	cout<<left<<setw(40)<<" "<<setw(40)<<"___---------------- MENU------------------___"<<endl;
	cout<<left<<setw(40)<<" "<<setw(40)<<"___->  1.Store new book"<<"<-___"<<endl;
	cout<<left<<setw(40)<<" "<<setw(40)<<"___->  2.Display all book"<<"<-___"<<endl;
	cout<<left<<setw(40)<<" "<<setw(40)<<"___->  3.Sell books    "<<"<-___"<<endl;
	cout<<left<<setw(40)<<" "<<setw(40)<<"___->  4.Delete   "<<"<-___"<<endl;
	cout<<left<<setw(40)<<" "<<setw(40)<<"___->  5.Charity and discount"<<"<-___"<<endl;
	cout<<left<<setw(40)<<" "<<setw(40)<<"___->  6.Most and worst sold books "<<"<-___"<<endl;
	cout<<left<<setw(40)<<" "<<setw(40)<<"___->  7.Store status"<<"<-___"<<endl;
	cout<<left<<setw(40)<<" "<<setw(40)<<"___->  0.Exit" <<"<-___"<<endl;
	cout<<left<<setw(40)<<" "<<setw(40)<<"___---------------------------------------___"<<endl;
	cout<<"===+====-> Please Enter your choice : ";
	cin>>choice;
      switch(choice){
		case 1:
			bl.new_book();//function calling to add new books on store.
			system("clear");
            break;
        case 2:
			bl.print();//function calling to add new books on store.
						system("clear");

            break;
        case 3:
			bl.sell_books();//function calling to add new books on store.
						system("clear");

            break;
        case 4:
            bl.delete_book();
            			system("clear");

            break;
        case 5:
            bl.charity_and_discount();
            			system("clear");

            break;
        case 6:
             bl.most_and_worest_sold_books();
             			system("clear");

             break;
         case 7:
            bl.store_status();
            			system("clear");

            break;

        case 0:
                break;
        default:
            cout<<"Please enter the valid option!"<<endl;
            break;
	}

}while(choice!=0);
cout<<"The system is closed"<<endl;
return 0;
}
