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

// APP Ŭ������ ������: BuritoFactory�� Transactionmanger ��ü ���� 
App::App() {
    bf = new BuritoFactory();
    tm = new TransactionManger();
}

// APP Ŭ������ �Ҹ���: ������ BuritoFactory�� TransactionManger ��ü�� ����
App::~App() {
    delete bf;
    delete tm;
}

// run �Լ�: ���α׷��� ���� ���� �ֹ� �߰�, ���, ó���� �۾� ���� 
void App::run() {
    readTransaction(); // ���α׷� ���� �� ������ ����� �ֹ��� �о��

        while (true) { // ù ���� �޴� 
        std::cout << "�θ��� �ֹ� ���� ���α׷�\n";
        std::cout << "---------------------�ֹ� ���---------------------\n";
        std::cout << "1. �ֹ� �߰�\n";
        std::cout << "2. �ֹ� ���\n";
        std::cout << "3. �ֹ� ó��\n";
        std::cout << "-------------------------------------------------\n";
        std::cout << "�޴� ����: ";

        int choice;
        std::cin >> choice; 

        if (choice == 1) { // �޴� ���� ��Ʈ 
            std::cout << "�޴� ����\n";
            std::cout << "1. ��ǰ (�θ���, 3000��)\n";
            std::cout << "2. �޺� (�θ��� + ����, 3700��)\n";
            std::cout << "3. ��Ʈ (�θ��� + ���� + ����Ƣ��, 4500��)\n";
            std::cout << "-----------------------------------------------\n";
            std::cout << "�ֹ� Ÿ�� (1: ��ǰ, 2: �޺�, 3: ��Ʈ): ";

            int type;
            std::cin >> type;
            
            Burito* order = bf->makeOrderedMenu(type);
            Transaction* newTransaction = new Transaction();
            newTransaction->orderedMenu = order; //�߰�  

            while (true) { // �߰� �ֹ� ��Ʈ
                std::cout << "�߰� �޴� ����\n";
                std::cout << "1. ���� (1000��)\n";
                std::cout << "2. �Ҽ��� (1000��)\n";
                std::cout << "3. ����Ƣ�� (2000��)\n";
                std::cout << "4. ����� (1000��)\n";
                std::cout << "5. �׸� �߰�\n";
                std::cout << "-----------------------------------------------\n";

                int ingredientType; // ingredientType: ������� 
                std::cin >> ingredientType;
                if (ingredientType == 5) break;

                switch (ingredientType) {
                case 1: order = new Jumbo(order); break; // ���� �߰� 
                case 2: order = new Sausage(order); break; // �Ҽ��� �߰�
                case 3: order = new Fries(order); break; // ����Ƣ�� �߰�
                case 4: order = new Drink(order); break; // ����� �߰�
                default: break;
                }
                newTransaction->orderedMenu = order; // �� �߰��� �޴��� �ֹ� ������ �ݿ�
                newTransaction->ingredientsInfo.push_back(ingredientType); 
            }
                
            tm->addTransaction(newTransaction);

        }
            else if (choice == 2) { // �ֹ� ��� ��Ʈ
            std::cout << "---------------------�ֹ� ���---------------------\n";
            for (size_t i = 0; i < tm->getOrderTransactions().size(); ++i) {
                std::cout << i + 1 << ". " << tm->getOrderTransactions()[i].orderedMenu->getDescription() << "\n";
            }
            std::cout << "-------------------------------------------------\n";
            int index; 
            std::cout << "����� �ֹ� �ε���: ";
            std::cin >> index;
            tm->deleteTransaction(index - 1); // �ε����� �ش��ϴ� �ֹ� ���� 

        }
        else if (choice == 3) { // �ֹ� ó��
            tm->processFrontTransaction(); // ���� ���� �ֹ��� ó�� �ڵ� 
        }
        else {
            break; // ���� ���� 
        }
    }

     writeTransaction();
}

// ������ ����� �ֹ��� �о���� �Լ�
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

// ���� �ֹ��� ���Ͽ� �����ϴ� �Լ�
void App::writeTransaction() {
    std::ofstream outfile("Order.txt");
    outfile << tm->getOrderTransactions().size() << "\n";
    for (const auto& transaction : tm->getOrderTransactions()) {
        outfile << transaction.ingredientsInfo.size() << " ";
        for (const auto& ingredient : transaction.ingredientsInfo) {
            outfile << ingredient << " "; // �߰� �޴� ���� ����
        }
        outfile << "\n";
    }
    outfile.close(); // ���� �ݱ� 
}
