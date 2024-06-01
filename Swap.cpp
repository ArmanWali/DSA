#include <iostream>
using namespace std;
//swap function
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int x,y;
    cout<<"Enter the first number: "<<endl;
    cin>>x;
    cout<<"Enter the Second number: "<<endl;
    cin>>y;
    cout<<"The numbers before swapping : "<<endl;
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
    swap(x,y);                             //calling swap function
    cout<<"The numbers after swapping : "<<endl;
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;

    return 0;
}
