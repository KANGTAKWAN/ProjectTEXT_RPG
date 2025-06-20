#ifndef ITEM_H
#define ITEM_H

#include <string>

class Character; //������ Character Ŭ���� ������ �ϱ����� ����

class Item //��� ������ ���� �������̽� ����(�߻�Ŭ����)
{
public:
	virtual ~Item() {} //�Ҹ���(�޸� ���� ����)
	virtual std::string getName() const = 0; //������ �̸��� ��ȯ�ϴ� ���� ���� �Լ�
	virtual void use(Character* character) = 0; //ĳ���Ϳ��� �������� ����� �� ȣ��Ǵ� �Լ�
	virtual std::string getbuyprice() const = 0; //�������� ���� ������ ��ȯ�ϴ� ���� ���� �Լ�
	virtual std::string getsellprice() const = 0; //�������� �Ǹ� ������ ��ȯ�ϴ� ���� ���� ��
};


#endif