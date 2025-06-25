#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <random>

class Person {
public:
    virtual std::string getFirstName() const = 0;
    virtual ~Person() = default;
};

class Moe : public Person {
public:
    std::string getFirstName() const override { return "Moe"; }
};

class Larry : public Person {
public:
    std::string getFirstName() const override { return "Larry"; }
};

class Curley : public Person {
public:
    std::string getFirstName() const override { return "Curley"; }
};

class Shemp : public Person {
public:
    std::string getFirstName() const override { return "Shemp"; }
};

int main(int argc, char* argv[]) {
    (void)argc; (void)argv;
    std::vector<std::unique_ptr<Person>> people;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> num_dist(3, 10);
    std::uniform_int_distribution<> type_dist(0, 3);
    int num_people = num_dist(gen);
    for (int i = 0; i < num_people; ++i) {
        switch (type_dist(gen)) {
            case 0: people.push_back(std::make_unique<Moe>()); break;
            case 1: people.push_back(std::make_unique<Larry>()); break;
            case 2: people.push_back(std::make_unique<Curley>()); break;
            case 3: people.push_back(std::make_unique<Shemp>()); break;
        }
    }
    for (const auto& person : people) {
        std::cout << "Hello, " << person->getFirstName() << "!" << std::endl;
    }
    return 0;
} 

void print_hello_world() {
    std::cout << "Hello, World!" << std::endl;
}