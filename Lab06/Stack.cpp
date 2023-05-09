#include <iostream>
#include <ctime>
using namespace std;


// Node Structure -- 
struct Node{
    int data;
    struct Node* next;
};

// stack Size ;
int stack_size = 100;

//Store Current size of stack -
int sizes = 0;

//Head pointer ---
struct Node* head = NULL;

//Check if the stack is empty --
bool isEmpty(){
    return head == NULL;
}

//Check if the stack is Full --
bool isFull(){
    return sizes == stack_size;
}


//Push method 
void Push(int new_data) {
   if(!isFull()){
       struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
       new_node->data = new_data;
       if(head==NULL){
        head = new_node;
        head->next = NULL;
        sizes++;
       }else{
           new_node->next = head;
           head = new_node;
           sizes++;
       }
   }else{
       cout<<"Stack is OverFlow"<<endl;
   }

}

// Pop method() -- 
void Pop(){
    if(!isEmpty()){
        head = head->next;
        sizes--;
    }else{
        cout<<"Stack is Empty --"<<endl;
    }
}

// Get Top element of the stack -- 
int StackTop(){
    if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
        return -1;

    }else{
        return head->data;
    }
}

 // print (display) stack -- 
void Display() {
    if(!isEmpty()){
       struct Node* ptr;
       ptr = head;
       while (ptr != NULL) {
          cout<< ptr->data <<" ";
          ptr = ptr->next;
       }
       cout<<endl;
    }else{
        cout<<"Stack is Empty"<<endl;
    }
}

int main(){

    cout<<"Enter Size of Stack : ";
    cin>> stack_size;

    double startTime = clock();

    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);

    Display();

    for (int i=0;i<5;i++){
        Pop();
    }
    Display();

    Push(4);
    Push(30);
    Push(3);
    Push(1);
    Display();

    double endTime = clock();

    double execution_time = double(endTime- startTime) / CLOCKS_PER_SEC;

    cout << "Execution time: " << execution_time << " seconds" << std::endl;


    return 0;
}



