#include "Transaction.h"

// Transaction Ŭ������ ������: �ֹ� �޴��� �ֹ� ID�� �ʱ�ȭ 
Transaction::Transaction() : orderedMenu(nullptr), orderID(0) {

    // orderedMenu�� nullptr�� �ʱ�ȭ
    // orderID�� 0���� �ʱ�ȭ

}
// Transaction Ŭ������ �Ҹ���: �������� �Ҵ��
Transaction::~Transaction() {
    delete orderedMenu; // �ֹ� �޴� �޸𸮸� ���� 
}
