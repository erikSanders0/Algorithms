#include <iostream>

int recurrence(int n){
    if(n == 1){
        return 1;
    }
    std::cout << n << "\n";
    return recurrence(n - 1) + (n * n * n);
}

int main(){
    std::cout << recurrence(10);
    return 0;
}