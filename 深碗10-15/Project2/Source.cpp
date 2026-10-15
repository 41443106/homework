#include<iostream>

using namespace std;

class GameCharacter{
public:
	string name;
	int hp;
	int level;
	// Constructor
	GameCharacter(string n, int h, int l)
	{
		this->name = n;
		this->hp = h;
		this->level = l;

	}
	// 受到傷害
	void damage(int value)
	{
		hp = hp - value;
		if (hp < 0) { hp = 0; }
		cout << "======" << "角色" << "=====" << "\n";
		cout << "name:" << name << "\n";
		cout << "HP:" << hp << "\n";
		cout << "Level:" << level << "\n";
	}
	// 回復生命值
	void heal(int value)
	{
		hp = hp + value;
		if (hp > 100) { hp = 100; }
		cout << "======" << "角色" << "=====" << "\n";
		cout << "name:" << name << "\n";
		cout << "HP:" << hp << "\n";
		cout << "Level:" << level << "\n";
	}
	// 升級
	void levelUp()
	{
		level++;
		hp = 100;
		cout << "======" << "角色" << "=====" << "\n";
		cout << "name:" << name << "\n";
		cout << "HP:" << hp << "\n";
		cout << "Level:" << level << "\n";
	}
	// 顯示角色資料
	void show()
	{
		cout << "======" << "角色" << "=====" << "\n";
		cout << "name:" << name << "\n";
		cout << "HP:" << hp << "\n";
		cout << "Level:" << level << "\n";
	}
};
int main()
{
	int a=1,b;
	int hp, level;
	string name;
	cout << "======" << "角色" << "=====" << "\n";
	cout << "Name: ";
	cin >> name;
	cout << "";
	cout << "blood: ";
	cin >> hp;
	cout << "";
	cout << "level: ";
	cin >> level;
	cout << "";
	GameCharacter p1(name, hp, level);
	while (a != 0) {
		cout << "======" << "選單" << "=====" << "\n";
		cout << "1.扣血" << "\n";
		cout << "2.回血" << "\n";
		cout << "3.升級" << "\n";
		cout << "4.show角色全部資料" << "\n";
		cout << "0.結束程式" << "\n";
		cout << "請選擇:";
		cin >> a;
		switch (a)
		{
		case 1:
			cout << "輸入扣血值:";
			int DH;
			cin >> DH;
			p1.damage(DH);
			break;
		case 2:
			cout << "輸入回血值:";
			int HH;
			cin >> HH;
			p1.heal(HH);
			break;
		case 3:
			p1.levelUp();
			break;
		case 4:
			p1.show();
			break;
		}
	}
}