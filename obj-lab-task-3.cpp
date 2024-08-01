#include <iostream>
#include <string>
#include <vector>
#include <variant>
#include <memory>

class Birds {
public:
    virtual void feed() = 0;

    virtual std::string sound() const = 0;

    virtual std::string isHappy() const = 0;

    virtual ~Birds() {};
};

class Ducks : public Birds {
public: 
    Ducks(int food = 0) : duck_food(food) {}

    void feed() override {
        duck_food += 1; 
        std::cout << "Duck was fed\n";
    }

    std::string sound() const override {
        return "Quack\n";
    }

    std::string isHappy() const override {
        if (duck_food > 1) {
            return sound();    
        } else {
            return "Duck is still hungry\n";
        }
    }

private:
    int duck_food;
};

class Geese : public Birds {
public:
    Geese(int food = 0) : goose_food(food) {}

    void feed() override {
        goose_food += 1;
        std::cout << "Goose was fed\n";
    }

    std::string sound() const override {
        return "Honk\n";
    }

    std::string isHappy() const override {
        if (goose_food > 1) {
            return sound();
        } else {
            return "Goose is still hungry with murderous intent\n";
        }
    }

private:
    int goose_food;
};

class Pond {
public:
    template <typename T>
    void addBird(std::shared_ptr<T> bird) {
        birds.push_back(bird);
    }

    std::shared_ptr<Birds> getBird(int index) {
        if (index >= 0 && index < birds.size()) {
            return birds[index];
        }
        return nullptr;
    }

    int getBirdCount() const {
        return birds.size();
    }

private:
    std::vector<std::shared_ptr<Birds>> birds;
};

int main() {
    Pond pond;
    bool running = true;

    while (running) {
        std::cout << "Choose an option:\n";
        std::cout << "1. Add a Duck\n";
        std::cout << "2. Add a Goose\n";
        std::cout << "3. Interact with a bird\n";
        std::cout << "4. Quit\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::shared_ptr<Ducks> duck = std::make_shared<Ducks>();
                pond.addBird(duck);
                std::cout << "Duck added to the pond.\n\n";
                break;
            }
            case 2: {
                std::shared_ptr<Geese> goose = std::make_shared<Geese>();
                pond.addBird(goose);
                std::cout << "Goose added to the pond.\n\n";
                break;
            }
            case 3: {
                if (pond.getBirdCount() == 0) {
                    std::cout << "No birds in the pond to interact with.\n\n";
                    break;
                }

                std::cout << "Enter bird index (0 to " << pond.getBirdCount() - 1 << "): ";
                int index;
                std::cin >> index;

                std::shared_ptr<Birds> bird = pond.getBird(index);
                if (bird) {
                    std::cout << "Choose an option:\n";
                    std::cout << "1. Feed\n";
                    std::cout << "2. Check happiness\n";

                    int action;
                    std::cin >> action;

                    switch (action) {
                        case 1:
                            bird->feed();
                            std::cout << bird->isHappy() << "\n";
                            break;
                        case 2:
                            std::cout << bird->isHappy() << "\n";
                            break;
                        default:
                            std::cout << "Invalid option.\n";
                            break;
                    }
                } else {
                    std::cout << "Invalid bird index.\n\n";
                }
                break;
            }
            case 4:
                running = false;
                break;
            default:
                std::cout << "Invalid option.\n\n";
                break;
        }
    }

    return 0;
}

