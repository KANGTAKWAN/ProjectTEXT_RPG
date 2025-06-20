#include "shop.h"
#include <iostream>

using namespace std;

Shop::Shop() {
	cout << "������ ���Ƚ��ϴ�!" << endl;
	cout << "�������� �����ϰų� �Ǹ��� �� �ֽ��ϴ�." << endl;
	cout << "�������� ���ϴ� �۾��� �����ϼ���." << endl;


	availableItems.push_back(make_unique<HealthPotion>("�⺻ ü�� ����", 50)); // �̸�, ����, 
	availableItems.push_back(make_unique<AttackBoost>("���ݷ� ���� ����", 70)); // �̸�, ����, 
	// �ʱ�ȭ �۾��� �ʿ��ϴٸ� ���⿡ �ۼ�
}

void Shop::displayItems() const {
	cout << "������ �ִ� ������ ���:" << endl;
	for (availableItems.empty()) {
		cout << "�������� �����ϴ�." << endl;
		return;

	}
	for (int i = 0; i < availableItems.size(); ++i) {
		cout << i + 1 << ". " << availableItems[i]->getName() << " - ����: " << availableItems[i]->getbuyprice() << endl;
	}
}
void Shop::buyItem(int index, Character* player) {
	if (index < 0 || index >= availableItems.size()) {
		cout << "�߸��� ������ �����Դϴ�." << endl;
		return;
	}
	auto& item = availableItems[index];
	if (player.getGold() < item->getbuyprice()) {
		cout << "��尡 �����մϴ�." << endl;
		return;
	}
	Character.addItem(item->clone()); // �������� �÷��̾�� �߰�
	Character.setGold(player.getGold() - item->getbuyprice()); // ��� ����
	cout << item->getName() << "��(��) �����߽��ϴ�!" << endl;
}
void Shop::sellItem(int index, Character* player) {   //ĳ���� Ŭ���� �ʿ���
	if (index < 0 || index >= player.getItems().size()) {
		cout << "�߸��� ������ �����Դϴ�." << endl;
		return;
	}
	auto& item = player.getItems()[itemIndex];
	player.setGold(player.getGold() + item->getsellprice()); // ��� ����
	player.removeItem(itemIndex); // ������ ����
	cout << item->getName() << "��(��) �Ǹ��߽��ϴ�!" << endl;
}