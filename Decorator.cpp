#include "Decorator.h"

// 기본 생성자
Decorator::Decorator() : burito(nullptr) {}

// Burito 매개변수를 받는 생성자
Decorator::Decorator(Burito* b) : burito(b) {}

// 소멸자
Decorator::~Decorator() {
    if (burito) {
        delete burito;
    }
}
