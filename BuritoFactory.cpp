#include "BuritoFactory.h"

// BuritoFactory Ŭ������ ������: ��ü�� �ʱ�ȭ
BuritoFactory::BuritoFactory() {}

// BuritoFactory Ŭ������ �Ҹ���: ��ü�� �Ҹ�� �� ȣ��
BuritoFactory::~BuritoFactory() {}


Burito* BuritoFactory::makeOrderedMenu(int type) { // makeOrderedMenu �Լ�: �־��� Ÿ�Կ� ���� �ٸ� �ֹ��� ����

    
    Burito* ordered = new BaseBurito();  // �⺻ �θ��Ǹ� ����

    switch (type) { // Ÿ�Կ� ���� �ֹ��� ����
    case 1: // ��ǰ
        return ordered; // �߰� ���� ���� �⺻ �θ��� ��ȯ
    case 2: // �޺�
        ordered = new Drink(ordered); // �޺��� ���� �߰� 
        ordered = new ComboDiscount(ordered); // �޺� ���� �߰� 
        break;
    case 3: // ��Ʈ
        ordered = new Drink(ordered); // ��Ʈ�� ���� �߰� 
        ordered = new Fries(ordered); // ��Ʈ�� ����Ƣ�� �߰� 
        ordered = new SetDiscount(ordered);  // ��Ʈ ���� �߰� 
        break;
    default:
        break;
    }
    return ordered; // �ϼ��� �ֹ� ��ȯ  
}
