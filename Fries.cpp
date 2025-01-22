#include "Fries.h"

Fries::Fries(Burito* b) : Decorator(b) {}

Fries::~Fries() {}

int Fries::getCost() {
    return burito->getCost() + 2000; // ����Ƣ�� �߰� ���
}

std::string Fries::getDescription() {
    return burito->getDescription() + " + ����Ƣ��";
}
