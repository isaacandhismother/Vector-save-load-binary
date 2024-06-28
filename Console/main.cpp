// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void change(int* a) {
    a += 10;
}

int main() {
    int number = 20;

    int* number_ptr = &number;

    number_ptr += 20;

    cout << number;
}