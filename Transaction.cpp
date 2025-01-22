#include "Transaction.h"

// Transaction 클래스의 생성자: 주문 메뉴와 주문 ID를 초기화 
Transaction::Transaction() : orderedMenu(nullptr), orderID(0) {

    // orderedMenu는 nullptr로 초기화
    // orderID는 0으로 초기화

}
// Transaction 클래스의 소멸자: 동적으로 할당된
Transaction::~Transaction() {
    delete orderedMenu; // 주문 메뉴 메모리를 해제 
}
