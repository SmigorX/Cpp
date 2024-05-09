#include <iostream>
#include <string>

class Vehicle {
public:
  Vehicle() {};
  
  Vehicle(std::string new_color, std::string new_model) {
    set_model(new_model);
    set_color(new_color);
  }

  std::string get_color() {
    return color;
  }

  std::string get_model() {
    return model;
  }

  void set_model(std::string new_model) {
    model = new_model;
  }  

  void set_color(std::string new_color) {
    color = new_color;
  }
private:
  std::string color;
  std::string model;
};

class AverageHuman {
public:
  AverageHuman() {};

  AverageHuman(int new_age, std::string new_name, Vehicle new_vehicle) {
    set_age(new_age);
    set_name(new_name);
    set_vehicle(new_vehicle);
  }

  void set_age(int new_age) {
    age = new_age;
  }

  void set_vehicle(Vehicle new_vehicle) {
    vehicle = new_vehicle;
  }

  int get_age () {
    return age;
  }
  
  void set_name(std::string new_name) {
    name = new_name;
  }

  std::string get_name() {
    return name;
  }

  std::string get_vehicle() {
    return vehicle.get_color() + " " + vehicle.get_model();
  }

private:
  int age;
  std::string name;
  Vehicle vehicle;

};

class Builder: public AverageHuman {
public:
  Builder(int new_age, std::string new_name, Vehicle new_vehicle, int new_years_of_experience, std::string new_title) 
    : AverageHuman(new_age, new_name, new_vehicle)
  {
    set_years_of_experience(new_years_of_experience);
    set_title(new_title);
  }

  void set_years_of_experience(int new_years_of_experience) {
    years_of_experience = new_years_of_experience;
  }

  int get_years_of_experience() {
    return years_of_experience;
  }

  void set_title(std::string new_title) {
    title = new_title;
  }

  std::string get_title() {
    return title;
  }

private:
  int years_of_experience;
  std::string title;
};

int main() {
  //We create a test vehicle 
  Vehicle TestVehicle("Red", "Honda Civic");

  std::cout << "Color of first vehicle: " << TestVehicle.get_color() << std::endl;
  std::cout << "Model of first vehicle: " << TestVehicle.get_model() << std::endl << std::endl;

  //We create a second test vehicle
  Vehicle TestVehicle2("Blue", "Mazda 8");

  std::cout << "Color of the second vehicle: " << TestVehicle2.get_color() << std::endl;
  std::cout << "Model of the second vehicle: " << TestVehicle2.get_model() << std::endl << std::endl;

  //We create first human using first vehicle 
  AverageHuman TestHuman(20, "Jan", TestVehicle);

  std::cout << "Name: " << TestHuman.get_name() << std::endl;
  std::cout << "Age: " << TestHuman.get_age() << std::endl;
  std::cout << "Vehicle: " << TestHuman.get_vehicle() << std::endl << std::endl;

  //We create second instance of avrg. human using the 2nd vehicle
  AverageHuman SecondTestHuman(25, "Alice", TestVehicle2);

  std::cout << "Name: " << SecondTestHuman.get_name() << std::endl;
  std::cout << "Age: " << SecondTestHuman.get_age() << std::endl;
  std::cout << "Vehicle: " << SecondTestHuman.get_vehicle() << std::endl << std::endl;

  //We create an instance of Vehicle class for the Builder
  Vehicle Buldozer("Yellow", "Caterpillar");

  //And an instance of the Builder itself
  Builder TheBuilder(40, "Bob", Buldozer, 15, "Majster");

  std::cout << "Name: " << TheBuilder.get_name() << std::endl;
  std::cout << "Age: " << TheBuilder.get_age() << std::endl;
  std::cout << "Vehicle: " << TheBuilder.get_vehicle() << std::endl;
  std::cout << "Years of experience: " << TheBuilder.get_years_of_experience() << std::endl;
  std::cout << "Title: " << TheBuilder.get_title() << std::endl;

  return 0;
}
