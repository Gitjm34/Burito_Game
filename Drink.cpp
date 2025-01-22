#include "Drink.h"

Drink::Drink(Burito* b) : Decorator(b) {}

Drink::~Drink() {}

int Drink::getCost() {
    return burito->getCost() + 1000; // 음료수 추가 비용
}

std::string Drink::getDescription() {
    return burito->getDescription() + " + 음료수";
}
