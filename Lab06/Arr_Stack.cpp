#include <iostream>
#include <ctime>
using namespace std;

const int stack_size = 100;

int stack_Arr [stack_size];

int top = -1;

bool isEmpty(){
    return top == -1;
}

bool isFull(){
    return top == stack_size;
}

void Push(int data){
    if(isFull()){
        cout<<"Stack Overflow"<<endl;
    }else{
        top++;
        stack_Arr[top] = data;
    }
}

void Pop(){
    if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
    }else{
        top--;
    }
}

int StackTop(){
    if(isEmpty()){
        cout<<"Stack is empty :"<<endl;
        return top;
    }
    return stack_Arr[top];

}

void Display(){
    if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
    }else{
        cout<<"[ ";
        for(int i=top;i>=0;i--){
            cout<<stack_Arr[i]<<",";
        }
        cout<<"\b ]"<<endl;
    }
}

int main(){

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
