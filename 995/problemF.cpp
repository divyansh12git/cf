#include<iostream>
using namespace std;

int main(){
    int x=55;
    int *p=&x;
    int **q=&p;
    cout<<**q<<endl;
}