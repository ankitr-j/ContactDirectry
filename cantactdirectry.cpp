//Contact directry 
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
struct node{
    string name,number,email;
    node* next;

};
node *head=NULL,*newnode, *temp;
//Function to create a node
void create_node(){
    newnode=new node;
    cout<<endl<<"Enter name: ";
    cin>>newnode->name;
   
     cout<<"Enter number: ";
    cin>>newnode->number;
     cout<<"Enter mail id: ";
    cin>>newnode->email;
    cout<<endl;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
}
//Function to display all the contacts in the directry
void display(){

    if(head==NULL){
        cout<<"Contact list is empty! "<<endl;
    }
    else{
        
        node *ptr=head;
       while(ptr!=NULL){
            cout<<"\nFull name:- "<<ptr->name<<endl;
        cout<<"Number:- "<<ptr->number<<endl;
        cout<<"Mail ID:- "<<ptr->email<<endl;
        ptr=ptr->next;
        
       }
       
    }
}
//This function gives a prompt to user about various options 
void menu(){
    cout<<"\nEnter 1 to add contact"<<endl;
    cout<<"Enter 2 to display all contacts "<<endl;
    cout<<"Enter 3 to search a particular contact name from their name or number or mail id. "<<endl;
    cout<<"Enter 4 to delete a contact."<<endl;
    cout<<"Enter 5 to delete all contacts."<<endl;
}
//This function let user to search a particular contact
void search_contact(){
  
   
    if(head==NULL){
        cout<<"\nContact list is empty.\n"<<endl;
    }
    else{
          string srch;
          cout<<"\nEnter the name or number or mail of the contact you wanna search\n";
          cin>>srch;
          node* ptr1=head;
           bool found=false;
        while(ptr1!=NULL){
            if((srch==ptr1->name)||(srch==ptr1->name)||(srch==ptr1->email)){
                found=true;
                break;
            }
            ptr1=ptr1->next;
        }
         if(found){
            cout<<"Name:- "<<ptr1->name<<endl;
             cout<<"Number:- "<<ptr1->number<<endl;
            cout<<"Mail:- "<<ptr1->email<<endl<<endl;
         }
        else{
           cout<<"\nThe contact you are looking for is not in the directry.\n"<<endl;
        }
    }
   
}
//To delete a particular contact
void delete_contact(){
    node *ptr2=head;
    string req_contact;
    if(head==NULL){
        cout<<"\nContact directry is empty."<<endl;
    }
    else if(head->next==NULL){
        cout<<"\nEnter the name or number or mail of the contact that has to be deleted - ";
        cin>>req_contact;
        if((req_contact==head->email)||(req_contact==head->name)||(req_contact==head->number)){
             head=NULL;
        
            delete ptr2;
            cout<<"\n\n The contact has been deleted successfully."<<endl;
            

        }
        else{
            cout<<"\n\nThe contact you are looking for is not in the directry."<<endl;
        }
       
    }
   
    else{
        cout<<"\nEnter the name or number or mail of the contact that has to be deleted - ";
        cin>>req_contact;
         if((req_contact==head->email)||(req_contact==head->name)||(req_contact==head->number)){
              head=head->next;
              delete ptr2;
              cout<<"\n\n The contact has been deleted successfully."<<endl;
              
              return;
        }
        while(ptr2->next!=NULL){
             if(ptr2->next->next==NULL){
                if((req_contact==ptr2->next->email)||(req_contact==ptr2->next->name)||(req_contact==ptr2->next->number)){
                    node *ptr3=ptr2->next;
                    ptr2->next=NULL;
                    delete ptr3;
                    cout<<"\n \nThe contact has been deleted successfully."<<endl;
                    
                    break;

                }
                else{
                 cout<<"\n\nThe contact you are looking for is not in the directry."<<endl;
                 break;
                }
            
            
            }
            else if((req_contact==ptr2->next->email)||(req_contact==ptr2->next->name)||(req_contact==ptr2->next->number)){
                 node *ptr3=ptr2->next;
                 ptr2->next=ptr3->next;
                 delete ptr3;
                 cout<<"\n\n The contact has been deleted successfully."<<endl;
                 
                 break;

             }
           
             ptr2=ptr2->next;

             
        
           

        }
       


        
    }

}
//It clears all the contacts in the directry
void clear_all(){
    node *ptr4;
    if(head==NULL){
        cout<<"\nThe directry is already empty."<<endl;
    }
   else{
        while(head!=NULL){
            ptr4=head;
            head=head->next;
            delete ptr4;
        }
        cout<<"\nContact directry is cleared now."<<endl;
   }
}
int main(){
    int op;
    while(true){
        menu();
        cin>>op;
        switch(op){
            case 1:
                create_node();
                break;
            case 2:
                display();
                break;

            case 3:{
                search_contact();
                break;
            }
            case 4:{
                delete_contact();
                break;
            } 
            case 5:{
                clear_all();
                break;
            }     
                
            
            default:
                cout<<"Invalid option\n"<<endl;
            

            
        }
    }


    return 0;
}
//Done
