#include <iostream>
enum HAMSTER_COLOR {
    BROWN,WHITE,MIXED
};

class Hamster {
private:
    char* name;
    const HAMSTER_COLOR color = BROWN;
public:
    Hamster(const char* n, HAMSTER_COLOR c):color(c),name(nullptr) {
        //color = WHITE;
        if (n != nullptr) {
            name = new char[strlen(n) + 1];
            strcpy_s(name, strlen(n) + 1, n);
        }
    }
    ~Hamster() {
        if (name != nullptr)delete[]name;
    }

    void printHamster() const{//константний метод
        std::cout << "Name: " << this->name << '\n';
        std::cout << "Color: ";
        switch (this->color) {
        case BROWN: std::cout << "brown";break;
        case WHITE:std::cout << "white";break;
        case MIXED:std::cout << "mixed";break;
        default:std::cout << "unknown";break;
        }
        std::cout << '\n';

        //this->color = BROWN;
    }

    //void setThis(Hamster& hamster) {
    //    this = &Hamster;
    //}

    void setName(const char* newName) {
        if (newName != nullptr) {
            name = new char[strlen(newName) + 1];
        }
        else {
            if (name != nullptr) delete[]name;
            name = nullptr;
        }
    }
    //void setColor(HAMSTER_COLOR newColor) {
    //    color = newColor;
    //}
    const char* getName() const{
        return name;
    }
    HAMSTER_COLOR getColor() const{
        return color;
    }
    void deleteThis() {
        delete this;
    }
};

int main()
{
    Hamster* ptr = new Hamster("Del", WHITE);

    delete ptr;
    ptr = nullptr;

    ptr->printHamster();

    //Hamster h1("Ham", BROWN);
    //h1.deleteThis();
    //Hamster h2("John", MIXED);

    //const Hamster hConst("Anton", WHITE);

    //hConst.printHamster();

    ////char* name = hConst.getName();
    ////name[0] = 'I';
    ////hConst.printHamster();

    //h1.printHamster();
}