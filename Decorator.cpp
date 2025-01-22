#include "Decorator.h"

// �⺻ ������
Decorator::Decorator() : burito(nullptr) {}

// Burito �Ű������� �޴� ������
Decorator::Decorator(Burito* b) : burito(b) {}

// �Ҹ���
Decorator::~Decorator() {
    if (burito) {
        delete burito;
    }
}
