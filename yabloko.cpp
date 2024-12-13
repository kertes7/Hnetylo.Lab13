#include <iostream>
#include <Windows.h>
#include <string>

class Product {
protected:
    std::string name;
    double price;

public:
    Product(const std::string& name, double price)
        : name(name), price(price) {}

    std::string getName() const {
        return name;
    }

    void setName(const std::string& name) {
        this->name = name;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        this->price = price;
    }

    virtual double getFinalPrice() const = 0;
};

class Discountable {
public:
    virtual double applyDiscount(double price) const = 0;
};

class Book : public Product, public Discountable {
public:
    Book(const std::string& name, double price)
        : Product(name, price) {}

    double getFinalPrice() const override {
        return applyDiscount(price);
    }

    double applyDiscount(double price) const override {
        return price * 0.9;
    }
};

class Pen : public Product, public Discountable {
public:
    Pen(const std::string& name, double price)
        : Product(name, price) {}

    double getFinalPrice() const override {
        return applyDiscount(price);
    }

    double applyDiscount(double price) const override {
        return (price > 5) ? price - 5 : price;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Book book("Хочу здати КДС", 120.0);
    Pen pen("Ручка-шпаргалка", 22.0);

    std::cout << "Назва товару: " << book.getName() << "\n"
              << "Базова ціна: " << book.getPrice() << "\n"
              << "Кінцева ціна після знижки: " << book.getFinalPrice() << "\n\n";

    std::cout << "Назва товару: " << pen.getName() << "\n"
              << "Базова ціна: " << pen.getPrice() << "\n"
              << "Кінцева ціна після знижки: " << pen.getFinalPrice() << "\n";

    return 0;
}
