#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Animal
{
private:

public:
	virtual void makeSound() = 0;
};

class Dog : public Animal
{
private:

public:
	void makeSound() override
	{
		cout << "멍멍" << endl;
	}
};

class Cat : public Animal
{
private:

public:
	void makeSound() override
	{
		cout << "야옹" << endl;
	}
};

class Cow : public Animal
{
private:

public:
	void makeSound() override
	{
		cout << "음머" << endl;
	}
};

class zoo
{
private:
	vector<Animal*> animals;
public:
	void addAnimal(Animal* _animal)
	{
		animals.push_back(_animal);
	}

	void performActions()
	{
		for (int i = 0; i < animals.size(); i++)
			animals[i]->makeSound();
	}

	~zoo()
	{
		for (int i = 0; i < animals.size(); i++)
			delete animals[i];
	}
};

Animal* CreateRandomAnimal()
{
	//Animal* animal;
	int random_int = rand() % 3;

	if (random_int == 0)
	{
		cout << "강아지 추가" << endl;
		return new Dog();
	}
	else if (random_int == 1)
	{
		cout << "고양이 추가" << endl;
		return new Cat();
	}
	else if (random_int == 2)
	{
		cout << "소 추가" << endl;
		return new Cow();
	}

	return nullptr;
}

int main(void)
{
	srand(time(0));
	vector<Animal*> animals(3);

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Cow();

	for (int i = 0; i < animals.size(); i++)
		animals[i]->makeSound();


	for (int i = 0; i < animals.size(); i++)
		delete animals[i];

	cout << "동물원 생성." << endl;

	zoo* cZoo = new zoo();
	
	cout << "랜덤으로 10마리의 동물 추가." << endl;
	for(int i = 0; i<10; i++)
		cZoo->addAnimal(CreateRandomAnimal());

	cout << "performActions함수 실행." << endl;
	cZoo->performActions();

	delete cZoo;

	return 0;
}