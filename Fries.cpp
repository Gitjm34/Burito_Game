#include "Fries.h"

Fries::Fries(Burito* b) : Decorator(b) {}

Fries::~Fries() {}

int Fries::getCost() {
    return burito->getCost() + 2000; // 감자튀김 추가 비용
}

std::string Fries::getDescription() {
    return burito->getDescription() + " + 감자튀김";
}
