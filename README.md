# 🌯 부리또 매장 관리 프로그램

## 📌 프로젝트 개요
부리또 매장 관리 프로그램을 설계 및 구현하는 프로젝트입니다. 
**팩토리 패턴(Factory Pattern)**과 **데코레이터 패턴(Decorator Pattern)**을 활용하여 주문 및 관리를 효율적으로 수행하도록 설계되었습니다.

---

## 🛠 시스템 구성 요소

### 🔹 주요 클래스 및 역할
- `App`: `BuritoFactory`와 `TransactionManager`를 포함하여 실행을 담당합니다.
- `BuritoFactory`: 팩토리 패턴을 적용하여 주문받은 메뉴를 생성합니다.
- `TransactionManager`: 주문 내역을 관리합니다.
- `Burito`: 데코레이터 패턴을 구현한 기본 부리또 클래스입니다.
- `BaseBurito`: 기본 부리또 구성 요소입니다.
- `Decorator`: 추가 재료 및 할인 정보를 적용하기 위한 클래스입니다.
- `Jumbo, Sausage, Drink, Fries`: 추가 재료 데코레이터 클래스입니다.
- `ComboDiscount, SetDiscount`: 할인 데코레이터 클래스입니다.

### 🔹 주요 기능
- 주문 추가 및 처리
- 주문 취소
- 주문 목록 조회 및 관리
- 데이터 파일(txt)에서 주문 내역 적재

---

## 🎮 프로그램 실행 흐름
1️⃣ 프로그램 실행 시 `txt` 파일에서 기존 주문 내역을 불러옵니다.  
2️⃣ 사용자에게 현재 받은 주문 목록을 표시합니다.  
3️⃣ 사용자는 다음 기능을 수행할 수 있습니다:
   - 주문 추가
   - 주문 처리
   - 주문 취소
4️⃣ 주문 처리 시, 가장 앞의 주문이 처리되며 내역이 갱신됩니다.  
5️⃣ 주문이 완료되면 결과가 저장됩니다.

---

## 📂 파일 입출력 시스템
✅ **Order DB**: 주문 내역을 저장하고 로드할 수 있습니다.

#### 📌 예시 데이터:
```yaml
1 Burito_Sausage + Drink 7500
2 Burito_Jumbo + Fries + SetDiscount 8800
```

---

## 🏛 디자인 패턴 적용
### 🔹 Factory 패턴
- `BuritoFactory`에서 주문받은 메뉴를 생성합니다.

### 🔹 Decorator 패턴
- `Burito`를 기반으로 추가 재료 및 할인 옵션을 적용합니다.

---

## 🔗 프로젝트 코드 및 실행 방법
📌 **GitHub Repository**: [Burito Store Management 프로젝트](https://github.com/your-repository-link)  
📌 **프로젝트 코드 및 실행 방법**은 해당 저장소에서 확인 가능합니다.

---
