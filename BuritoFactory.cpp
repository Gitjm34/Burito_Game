#include "BuritoFactory.h"

// BuritoFactory 클래스의 생성자: 객체를 초기화
BuritoFactory::BuritoFactory() {}

// BuritoFactory 클래스의 소멸자: 객체가 소멸될 때 호출
BuritoFactory::~BuritoFactory() {}


Burito* BuritoFactory::makeOrderedMenu(int type) { // makeOrderedMenu 함수: 주어진 타입에 따라 다른 주문을 생성

    
    Burito* ordered = new BaseBurito();  // 기본 부리또를 생성

    switch (type) { // 타입에 따라 주문을 구성
    case 1: // 단품
        return ordered; // 추가 수정 없이 기본 부리또 반환
    case 2: // 콤보
        ordered = new Drink(ordered); // 콤보에 음료 추가 
        ordered = new ComboDiscount(ordered); // 콤보 할인 추가 
        break;
    case 3: // 세트
        ordered = new Drink(ordered); // 세트에 음료 추가 
        ordered = new Fries(ordered); // 세트에 감자튀김 추가 
        ordered = new SetDiscount(ordered);  // 세트 할인 추가 
        break;
    default:
        break;
    }
    return ordered; // 완성된 주문 반환  
}
