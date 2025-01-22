#include "ComboDiscount.h"

// �⺻ ������
ComboDiscount::ComboDiscount() : Decorator() {}

// Burito �Ű������� �޴� ������
ComboDiscount::ComboDiscount(Burito* b) : Decorator(b) {}

// �Ҹ���
ComboDiscount::~ComboDiscount() {}

// getCost ����
int ComboDiscount::getCost() {
    if (burito) {
        return burito->getCost() - 300; // 300���� ComboDiscount�� ���ΰ���� ����
    }
    return 0; // burito�� null�� ���
}

// getDescription ����
std::string ComboDiscount::getDescription() {
    if (burito) {
        return burito->getDescription() + " + Combo Discount";
    }
    return "Combo Discount";
}

