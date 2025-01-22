#include "App.h"
#include "BaseBurito.h"
#include "Drink.h"
#include "Jumbo.h"
#include "Sausage.h"
#include "Fries.h"
#include "ComboDiscount.h"
#include "SetDiscount.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// APP 클래스의 생성자: BuritoFactory와 Transactionmanger 객체 생성 
App::App() {
    bf = new BuritoFactory();
    tm = new TransactionManger();
}

// APP 클래스의 소멸자: 생성된 BuritoFactory와 TransactionManger 객체를 삭제
App::~App() {
    delete bf;
    delete tm;
}

// run 함수: 프로그램의 메인 루프 주문 추가, 취소, 처리등 작업 수행 
void App::run() {
    readTransaction(); // 프로그램 시작 시 이전에 저장된 주문을 읽어옴

        while (true) { // 첫 시작 메뉴 
        std::cout << "부리또 주문 관리 프로그램\n";
        std::cout << "---------------------주문 목록---------------------\n";
        std::cout << "1. 주문 추가\n";
        std::cout << "2. 주문 취소\n";
        std::cout << "3. 주문 처리\n";
        std::cout << "-------------------------------------------------\n";
        std::cout << "메뉴 선택: ";

        int choice;
        std::cin >> choice; 

        if (choice == 1) { // 메뉴 선택 파트 
            std::cout << "메뉴 선택\n";
            std::cout << "1. 단품 (부리또, 3000원)\n";
            std::cout << "2. 콤보 (부리또 + 음료, 3700원)\n";
            std::cout << "3. 세트 (부리또 + 음료 + 감자튀김, 4500원)\n";
            std::cout << "-----------------------------------------------\n";
            std::cout << "주문 타입 (1: 단품, 2: 콤보, 3: 세트): ";

            int type;
            std::cin >> type;
            
            Burito* order = bf->makeOrderedMenu(type);
            Transaction* newTransaction = new Transaction();
            newTransaction->orderedMenu = order; //추가  

            while (true) { // 추가 주문 파트
                std::cout << "추가 메뉴 선택\n";
                std::cout << "1. 점보 (1000원)\n";
                std::cout << "2. 소세지 (1000원)\n";
                std::cout << "3. 감자튀김 (2000원)\n";
                std::cout << "4. 음료수 (1000원)\n";
                std::cout << "5. 그만 추가\n";
                std::cout << "-----------------------------------------------\n";

                int ingredientType; // ingredientType: 구성요소 
                std::cin >> ingredientType;
                if (ingredientType == 5) break;

                switch (ingredientType) {
                case 1: order = new Jumbo(order); break; // 점보 추가 
                case 2: order = new Sausage(order); break; // 소세지 추가
                case 3: order = new Fries(order); break; // 감자튀김 추가
                case 4: order = new Drink(order); break; // 음료수 추가
                default: break;
                }
                newTransaction->orderedMenu = order; // ★ 추가된 메뉴를 주문 내역에 반영
                newTransaction->ingredientsInfo.push_back(ingredientType); 
            }
                
            tm->addTransaction(newTransaction);

        }
            else if (choice == 2) { // 주문 취소 파트
            std::cout << "---------------------주문 목록---------------------\n";
            for (size_t i = 0; i < tm->getOrderTransactions().size(); ++i) {
                std::cout << i + 1 << ". " << tm->getOrderTransactions()[i].orderedMenu->getDescription() << "\n";
            }
            std::cout << "-------------------------------------------------\n";
            int index; 
            std::cout << "취소할 주문 인덱스: ";
            std::cin >> index;
            tm->deleteTransaction(index - 1); // 인덱스에 해당하는 주문 삭제 

        }
        else if (choice == 3) { // 주문 처리
            tm->processFrontTransaction(); // 가장 앞의 주문을 처리 코드 
        }
        else {
            break; // 루프 종료 
        }
    }

     writeTransaction();
}

// 이전에 저장된 주문을 읽어오는 함수
void App::readTransaction() {
    std::ifstream infile("Order.txt");
    if (!infile.is_open()) return;

    int listSize;
    infile >> listSize;
    for (int i = 0; i < listSize; ++i) {

        Transaction* transaction = new Transaction();
        int ingredientSize;
        infile >> ingredientSize;
        transaction->ingredientsInfo.resize(ingredientSize);
        for (int j = 0; j < ingredientSize; ++j) {
            infile >> transaction->ingredientsInfo[j];
        }
        tm->addTransaction(transaction);
    }
    infile.close();
}

// 현재 주문을 파일에 저장하는 함수
void App::writeTransaction() {
    std::ofstream outfile("Order.txt");
    outfile << tm->getOrderTransactions().size() << "\n";
    for (const auto& transaction : tm->getOrderTransactions()) {
        outfile << transaction.ingredientsInfo.size() << " ";
        for (const auto& ingredient : transaction.ingredientsInfo) {
            outfile << ingredient << " "; // 추가 메뉴 정보 저장
        }
        outfile << "\n";
    }
    outfile.close(); // 파일 닫기 
}
