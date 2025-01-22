#include "Jumbo.h"

Jumbo::Jumbo(Burito* b) : Decorator(b) {}

int Jumbo::getCost() {
    return burito->getCost() + 1000; // 점보 추가 비용
}

std::string Jumbo::getDescription() {
    return burito->getDescription() + " + 점보";
}
