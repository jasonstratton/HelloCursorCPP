#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <random>

// Person interface
class Person {
public:
    virtual std::string getName() const = 0;
    virtual ~Person() = default;
};

class Moe : public Person {
public:
    std::string getName() const override { return "Moe"; }
};

class Larry : public Person {
public:
    std::string getName() const override { return "Larry"; }
};

class Curley : public Person {
public:
    std::string getName() const override { return "Curley"; }
};

// Function to print the hello message
void printHello(const std::string& name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}

int main(int /*argc*/, char* /*argv*/[]) {
    // Seed random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10); // random number of persons
    int numPersons = dist(gen);

    std::vector<std::unique_ptr<Person>> people;
    std::uniform_int_distribution<> typeDist(0, 2);
    for (int i = 0; i < numPersons; ++i) {
        int type = typeDist(gen);
        if (type == 0) people.push_back(std::make_unique<Moe>());
        else if (type == 1) people.push_back(std::make_unique<Larry>());
        else people.push_back(std::make_unique<Curley>());
    }

    for (const auto& person : people) {
        printHello(person->getName());
    }
    return 0;
}
