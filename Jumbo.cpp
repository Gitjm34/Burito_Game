#include "Jumbo.h"

Jumbo::Jumbo(Burito* b) : Decorator(b) {}

int Jumbo::getCost() {
    return burito->getCost() + 1000; // ���� �߰� ���
}

std::string Jumbo::getDescription() {
    return burito->getDescription() + " + ����";
}
