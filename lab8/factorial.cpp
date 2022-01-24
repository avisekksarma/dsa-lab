#include <iostream>

using namespace std;

long int fact(int n){
    if(n==1){
        return 1;
    }
    return n * fact(n-1);
}

long int factTail(int n,long int value){
    if(n == 1){
        return value;
    }
    return factTail(n-1,n*value);
}

int main(){
    cout<< "Factorial of 5 (non-tail) is: "<<fact(5)<<endl;
    cout<< "Factorial of 5 (tail) is: "<<factTail(5,1)<<endl;
    return 0;
}