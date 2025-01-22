#include "TransactionManger.h"
#include <iostream>

// 주문 추가, 삭제 처리하는 기능을 담당 
TransactionManger::TransactionManger() {}

TransactionManger::~TransactionManger() {
    for (auto& transaction : orderTransactions) {
        delete transaction.orderedMenu;
    }  
}
// 새로운 주문을 orderTransactions 벡터에 추가
void TransactionManger::addTransaction(Transaction* newTransaction) {
    orderTransactions.push_back(*newTransaction);
}
// 가장 앞에 있는 주문을 처리하고 제거
void TransactionManger::processFrontTransaction() {
    if (orderTransactions.empty()) return; //주문이 비어있으면 함수 종료

    const Transaction& transaction = orderTransactions.front();
    std::cout << "주문 처리!\n";
    std::cout << "1번 주문\n";
    std::cout << "-----------------주문 내용-----------------\n";
    std::cout << transaction.orderedMenu->getDescription() << "\n"; //주문 설명 출력
    std::cout << "가격: " << transaction.orderedMenu->getCost() << "원\n"; // 주문 가격 출력
    std::cout << "-------------------------------------------\n";

    delete transaction.orderedMenu;
    orderTransactions.erase(orderTransactions.begin());
}

void TransactionManger::printTransactions() { // 현재 저장된 모든 주문을 출력
    for (size_t i = 0; i < orderTransactions.size(); ++i) {
        std::cout << i + 1 << ". " << orderTransactions[i].orderedMenu->getDescription() << "\n";
    }
}
// 특정 인덱스의 주문 삭제
void TransactionManger::deleteTransaction(int index) {
    if (index < 0 || index >= orderTransactions.size()) return;
    
    delete orderTransactions[index].orderedMenu;
    orderTransactions.erase(orderTransactions.begin() + index);
}

const std::vector<Transaction>& TransactionManger::getOrderTransactions() const {
    return orderTransactions;
}
