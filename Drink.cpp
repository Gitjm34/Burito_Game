#include "Drink.h"

Drink::Drink(Burito* b) : Decorator(b) {}

Drink::~Drink() {}

int Drink::getCost() {
    return burito->getCost() + 1000; // ����� �߰� ���
}

std::string Drink::getDescription() {
    return burito->getDescription() + " + �����";
}
