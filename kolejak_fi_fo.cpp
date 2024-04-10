#include <iostream>
#include <string>

using namespace std;

//struct zawierający dane o pojedyńczym filmie
//struct to store film data
struct film {
  int id;
  string title;
  string release_date;
  char genre;
};

//dwukierunkowa lista zawierająca wskaźniki na następny i poprzedni element oraz obiekt danych o filmie
//double linked list node struct containing next and previeous node pointers and object of film data
struct double_linked_list_node {
  film data;
  double_linked_list_node *next;
  double_linked_list_node *prev;
};

//funkcja dodająca element na końcu listy, przekazujemy wskaźnik na głowę listy i obiekt danych o filmie
//function to add an element to the end of the list, we pass pointer to the head of the list and object of film data
//funckja tworzy nowy obiekt typu double_linked_list_node, przypisuje mu przekazane dane, ustawia wskażnik na element poprzedni oraz w poprzednim elemencie uaktualnia wskaźnik na następny element
//function creates new object of double_linked_list_node type, assigns passed data to it, sets pointer to previous element and updates pointer to next element in previous element
void add_element_to_end(double_linked_list_node *&head, film data) {
  double_linked_list_node *new_node = new double_linked_list_node;
  new_node -> data = data;
  new_node -> next = nullptr;
  new_node -> prev = nullptr;

  if (head == nullptr) {
          head = new_node;
  } else {
      double_linked_list_node* current = head;
      while (current -> next != nullptr) {
        current = current -> next;
      }
      current -> next = new_node;
      new_node -> prev = current;
    }
  }
  
//funkcja usuwająca element z początku listy, ustawiająca head pointer na nowy początek listy oraz pointer na poprzedni element pierwszego elementu na nullpointer, przekazujemy wskaźnik na głowę listy
//function to remove element from the beginning of the list, sets head pointer to new beginning of the list and pointer to previous element of the first element to nullpointer, we pass pointer to the head of the list
void remove_element_from_beginning(double_linked_list_node *&head) {
  if (head == nullptr) {
    cout << "List is empty. Cannot remove from the beginning.\n";
    return;
  }

  double_linked_list_node *current = head;
  head = head -> next;
  if (head != nullptr) {
        head -> prev = nullptr;
    }
  delete current;
}

//funkcja przechodzi przez listę, wyświetla zawartość objektu film, przekazujemy wskaźnik na głowę listy
//function traverses the list, prints content of film object, we pass pointer to the head of the list
void print_list(double_linked_list_node *head) {
  double_linked_list_node *current = head;
  if (current == nullptr) {
    cout << "List is empty.\n";
    return;
  }
  
  cout << "id release_date genre title" << endl;
  while (current != nullptr) {
    cout << current -> data.id << " " << current -> data.release_date << " " << current -> data.genre << " " << current -> data.title << endl;
    current = current->next;
  }
}


int main () {
  //wskaźnik na głowę listy
  //pointer to the head of the list
  double_linked_list_node *head = nullptr;

  //główna pętla programu wyświetlająca menu
  //main program loop displaying menu
  while (true) {
    cout << "1. Dodaj element na koniec" << endl;
    cout << "2. Usuń element z początku" << endl;
    cout << "3. Wyświetl listę" << endl;
    cout << "4. Wyjście" << endl;

    int choice;
    cin >> choice;

    if (choice == 1) {
      film data;
      
      cout << "Podaj id: ";
      cin >> data.id; 
      
      cin.ignore();
      cout << "Podaj tytuł: "; 
      getline(cin, data.title);
     

      cout << "Podaj datę premiery: ";
      getline(cin, data.release_date);
      
      cout << "Podaj gatunek: (h - horror, k - komedia, d - dramat)" << endl; 
      cin >> data.genre;
      cout << endl;
      
      cout << "id release_date genre title" << endl;
      cout << data.id << " " << data.release_date << " " << data.genre << " " << data.title << endl;
      
      add_element_to_end(head, data);
    
    } else if (choice == 2) {
      remove_element_from_beginning(head);
    
    } else if (choice == 3) {
      print_list(head);
    
    } else if (choice == 4) {
      break;
    
    } else {
      cout << "Nieprawidłowy wybór." << endl;
      cin.clear();
      cin.ignore(10000, '\n');
    }
  }

    //zwolnienie pamięci
    //freeing memory
    double_linked_list_node* current = head;
    while (current != nullptr) {
        double_linked_list_node* next = current -> next;
        delete current;
        current = next;
    }

  return 0;
}

