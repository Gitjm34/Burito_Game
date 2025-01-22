#include "BaseBurito.h"

BaseBurito::BaseBurito() {
    // 기본 부리또 초기화 코드
}

BaseBurito::~BaseBurito() {
    // 리소스 정리 코드
}

int BaseBurito::getCost() {
    return 3000; // 기본 부리또의 가격
}

std::string BaseBurito::getDescription() {
    return "부리또"; // 기본 부리또 설명
}
