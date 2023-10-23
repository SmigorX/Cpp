#include <iostream>
#include <string>

int fizz_buzz (int number, std::string* output) {
    if (number % 3 == 0) {*output += "Fizz";}
    if (number % 5 == 0) {*output += "Buzz";}
    if (*output == "") {*output = (std::to_string(number));}
    return 0;
}


int main() {
    for (int i = 0; i < 100; i++) {
        std::string wynik = "";
        fizz_buzz(i, &wynik);
        std::cout << wynik << "\n";
    }
    return 0;
}


