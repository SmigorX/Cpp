#include <iostream>
#include <list>

void showlist(std::list<int> lista)
{
    std::list<int>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it)
        std::cout << '\t' << *it;
    std::cout << '\n';
}

void reverseLayers(std::list<int> lista) {
    std::list<int> reversed_list;
    int current = -1, jump = 0, increment = 2;
    while (jump < size(lista)) {
        for (int i = jump; i > current; i--) {
            reversed_list.push_back(i);
        }
        current = jump;
        jump += increment;
        increment = increment * 2;
    }
    if (jump > size(lista)) {for (int i = size(lista)-1; i > current; i--) {reversed_list.push_back(i);} current = jump;}
    showlist(reversed_list);
}

int main () {
    std::list<int> tree;
    for (int i; i<6; i++) {
        tree.push_back(i);
    }
    showlist(tree);
    reverseLayers(tree);
    return 0;
}