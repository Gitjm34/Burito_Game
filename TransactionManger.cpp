#include "TransactionManger.h"
#include <iostream>

// �ֹ� �߰�, ���� ó���ϴ� ����� ��� 
TransactionManger::TransactionManger() {}

TransactionManger::~TransactionManger() {
    for (auto& transaction : orderTransactions) {
        delete transaction.orderedMenu;
    }  
}
// ���ο� �ֹ��� orderTransactions ���Ϳ� �߰�
void TransactionManger::addTransaction(Transaction* newTransaction) {
    orderTransactions.push_back(*newTransaction);
}
// ���� �տ� �ִ� �ֹ��� ó���ϰ� ����
void TransactionManger::processFrontTransaction() {
    if (orderTransactions.empty()) return; //�ֹ��� ��������� �Լ� ����

    const Transaction& transaction = orderTransactions.front();
    std::cout << "�ֹ� ó��!\n";
    std::cout << "1�� �ֹ�\n";
    std::cout << "-----------------�ֹ� ����-----------------\n";
    std::cout << transaction.orderedMenu->getDescription() << "\n"; //�ֹ� ���� ���
    std::cout << "����: " << transaction.orderedMenu->getCost() << "��\n"; // �ֹ� ���� ���
    std::cout << "-------------------------------------------\n";

    delete transaction.orderedMenu;
    orderTransactions.erase(orderTransactions.begin());
}

void TransactionManger::printTransactions() { // ���� ����� ��� �ֹ��� ���
    for (size_t i = 0; i < orderTransactions.size(); ++i) {
        std::cout << i + 1 << ". " << orderTransactions[i].orderedMenu->getDescription() << "\n";
    }
}
// Ư�� �ε����� �ֹ� ����
void TransactionManger::deleteTransaction(int index) {
    if (index < 0 || index >= orderTransactions.size()) return;
    
    delete orderTransactions[index].orderedMenu;
    orderTransactions.erase(orderTransactions.begin() + index);
}

const std::vector<Transaction>& TransactionManger::getOrderTransactions() const {
    return orderTransactions;
}
