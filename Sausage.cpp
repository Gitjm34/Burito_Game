#include "Sausage.h"

Sausage::Sausage(Burito* b) : Decorator(b) {}

Sausage::~Sausage() {}

int Sausage::getCost() {
    return burito->getCost() + 1000; // 소시지 추가 비용
}

std::string Sausage::getDescription() {
    return burito->getDescription() + " + 소시지";
}
