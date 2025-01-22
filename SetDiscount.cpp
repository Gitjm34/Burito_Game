#include "SetDiscount.h"

SetDiscount::SetDiscount() : burito(nullptr) { }

SetDiscount::SetDiscount(Burito* b) : burito(b) { }

SetDiscount::~SetDiscount() {
    if (burito != nullptr) {
        delete burito;
    }
}

int SetDiscount::getCost() {
    return burito->getCost() - 500; // 할인 금액
}

std::string SetDiscount::getDescription() {
    return burito->getDescription() + ", 세트 할인";
}
