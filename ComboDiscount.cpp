#include "ComboDiscount.h"

// 기본 생성자
ComboDiscount::ComboDiscount() : Decorator() {}

// Burito 매개변수를 받는 생성자
ComboDiscount::ComboDiscount(Burito* b) : Decorator(b) {}

// 소멸자
ComboDiscount::~ComboDiscount() {}

// getCost 구현
int ComboDiscount::getCost() {
    if (burito) {
        return burito->getCost() - 300; // 300원이 ComboDiscount의 할인가라고 가정
    }
    return 0; // burito가 null일 경우
}

// getDescription 구현
std::string ComboDiscount::getDescription() {
    if (burito) {
        return burito->getDescription() + " + Combo Discount";
    }
    return "Combo Discount";
}

