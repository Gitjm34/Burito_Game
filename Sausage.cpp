#include "Sausage.h"

Sausage::Sausage(Burito* b) : Decorator(b) {}

Sausage::~Sausage() {}

int Sausage::getCost() {
    return burito->getCost() + 1000; // �ҽ��� �߰� ���
}

std::string Sausage::getDescription() {
    return burito->getDescription() + " + �ҽ���";
}
