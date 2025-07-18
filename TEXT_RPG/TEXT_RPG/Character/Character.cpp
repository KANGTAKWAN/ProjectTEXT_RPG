#include "Character.h"
#include <iostream>
#include <iomanip>
#include "Shop.h"

Character* Character::instance = nullptr; // 싱글톤 인스턴스 초기화

// 생성자: 이름을 받아서 초기값 설정
Character::Character(std::string name)
    : name(name), level(1), health(200), maxHealth(200), attack(30),
    experience(0), gold(0) {
}

// 싱글톤 인스턴스 반환 함수
Character* Character::getInstance(std::string name)
{
    if (!instance)
    {
        instance = new Character(name);
        std::cout << "캐릭터 " << name << " 생성 완료! 레벨: 1, 체력: 200, 공격력: 30" << std::endl;
    }
    return instance;
}

// 캐릭터 상태 출력 함수
void Character::displayStatus() const
{
    std::cout << "==== 캐릭터 상태 ====" << std::endl;
    std::cout << "이름: " << name << " | 레벨: " << level
        << " | 체력: " << health << "/" << maxHealth
        << " | 공격력: " << attack << std::endl;
    std::cout << "경험치: " << experience << "/100"
        << " | 골드: " << gold << std::endl;
    std::cout << "인벤토리: " << inventory.size() << "개 아이템 보유" << std::endl;
}

// 레벨업 함수
void Character::levelUp()
{
    if (level >= 10) return;

    level++;
    maxHealth += level * 20; // 레벨당 최대 체력 증가
    attack += level * 5; // 레벨당 공격력 증가
    health = maxHealth; // 레벨업 시 체력 회복
    experience = 0; // 레벨업 시 경험치 초기화

    std::cout << "[레벨업!] 현재 레벨: " << level << " | 체력: "
        << health << " | 공격력: " << attack << std::endl;
}

//경험치 획득 함수
void Character::addExperience(int exp)
{
    experience += exp;
    std::cout << "[경험치 획득] + " << exp << " EXP (현재: " << experience << "/100)" << std::endl;
    while (experience >= 100 && level < 10)
    {
        experience -= 100;
        levelUp();
    }
}

// 골드 획득 함수
void Character::addGold(int amount)
{
    gold += amount;
    std::cout << "[골드 획득] +" << amount << " G (총: " << gold << " G)" << std::endl;
}

// 몬스터한테 받는 피해 처리 함수
void Character::takeDamage(int damage)
{
    health -= damage;
    if (health < 0) health = 0;
}

// 피해를 받았을 때 상태 출력
bool Character::isDead() const
{
    return health <= 0;
}

// 아이템 획득 함수
void Character::addItem(Item* item)
{
    inventory.push_back(item);
    std::cout << "[아이템 획득] " << item->getName() << " 획득!" << std::endl;
}

// 아이템 사용 함수
void Character::useItem(int index)
{
    if (index < 0 || index >= inventory.size())
    {
        std::cout << "잘못된 인덱스입니다." << std::endl;
        return;
    }
    Item* item = inventory[index];
    item->use(*this); // 아이템 사용 시 Character 객체를 참조로 넘김
    delete item;
    inventory.erase(inventory.begin() + index);
}

// 상점 방문 함수
void Character::visitShop()
{
    Shop shop; // Shop 클래스의 인스턴스 생성
    shop.displayItems();
    shop.interact(this); // Character 객체를 참조로 넘겨 상점과 상호작용
}

std::string Character::getName() const { return name; } // 캐릭터 이름 반환
int Character::getHealth() const { return health; } // 현재 체력 반환
int Character::getAttack() const { return attack; } // 현재 공격력 반환
int Character::getLevel() const { return level; } // 현재 레벨 반환 
int Character::getGold() const { return gold; } // 현재 골드 반환
int Character::getExperience() const { return experience; } // 현재 경험치 반환
int Character::getInventorySize() const { return inventory.size(); } // 인벤토리 크기 반환 
Item* Character::getItem(int index) // 인벤토리에서 아이템 반환
{
    if (index < 0 || index >= inventory.size()) return nullptr; // 인덱스가 유효하지 않으면 nullptr 반환
    return inventory[index];
}
