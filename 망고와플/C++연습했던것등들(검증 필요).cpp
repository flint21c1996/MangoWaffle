#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;



class Item
{

public:
	int uid = 0;
	string name = "";
	int level = 0;
	int grade = 0;
public:
	Item(int uid, string name, int level, int grade)
	{
		this->uid = uid;
		this->name = name;
		this->level = level;
		this->grade = grade;
	};
};

void PrintItem(Item& item)
{
	cout << "------------------------------" << endl;
	cout << "uid : " << item.uid << endl;
	cout << "name : " << item.name << endl;
	cout << "level : " << item.level << endl;
	cout << "grade : " << item.grade << endl;
	cout << "------------------------------" << endl;

}

class ItemManager
{
private:
	int size = 0;
public:
	//추가
	unique_ptr<vector<Item>> ItemAdd(unique_ptr<vector<Item>> myitem, Item* item)
	{
		myitem->push_back(*item);
		return move(myitem);
	}
	//삭제
	unique_ptr<vector<Item>> DeleteItem(unique_ptr<vector<Item>> myitem, int uid)
	{
		myitem->erase(myitem->begin() + uid);
		return move(myitem);

	}
	//검색
	unique_ptr<vector<Item>> SearchItem(unique_ptr<vector<Item>> myitem, int uid)
	{
		vector<Item>::iterator iter = myitem->begin();
		PrintItem(iter[uid]);
		return move(myitem);

	}
	//목록 출력
	unique_ptr<vector<Item>> PrintAllItem(unique_ptr<vector<Item>> myitem)
	{
		vector<Item>::iterator iter = myitem->begin();
		for (int i = 0; i < myitem->size(); i++)
		{
			PrintItem(iter[i]);
		}
		return move(myitem);
	}
};

int main()
{
	ItemManager* Sung = new ItemManager();
	Item* myItem1 = new Item(1, "성동재", 9, 9);
	Item* myItem2 = new Item(1, "성윤재", 10, 10);
	Item* myItem3 = new Item(1, "초롱이", 11, 11);
	Item* myItem4 = new Item(1, "코코", 12, 12);

	unique_ptr<vector<Item>> Inven = make_unique<vector<Item>>();

	Inven = Sung->ItemAdd(move(Inven), myItem1);
	Inven = Sung->ItemAdd(move(Inven), myItem2);
	Inven = Sung->ItemAdd(move(Inven), myItem3);
	Inven = Sung->ItemAdd(move(Inven), myItem4);

	cout << "------SearchItem-------" << endl;
	Inven = Sung->SearchItem(move(Inven), 0);
	cout << "------PrintAllItem-------" << endl;
	Sung->PrintAllItem(move(Inven));
	cout << "------DeleteItem-------" << endl;
	Sung->DeleteItem(move(Inven), 0);
	cout << "------PrintAllItem-------" << endl;
	Sung->PrintAllItem(move(Inven));

	delete myItem1, myItem2, myItem3, myItem4;
}
////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

// Product 클래스: 생성할 복잡한 객체의 틀
class Computer {
public:
	void setCPU(const std::string& cpu) {
		cpu_ = cpu;
	}

	void setGPU(const std::string& gpu) {
		gpu_ = gpu;
	}

	void setRAM(const std::string& ram) {
		ram_ = ram;
	}

	void showInfo() const {
		std::cout << "Computer Info: CPU-" << cpu_ << ", GPU-" << gpu_ << ", RAM-" << ram_ << std::endl;
	}

private:
	std::string cpu_;
	std::string gpu_;
	std::string ram_;
};

// Builder 인터페이스: Product의 생성 과정을 정의하는 인터페이스
class ComputerBuilder {
public:
	virtual void buildCPU() = 0;
	virtual void buildGPU() = 0;
	virtual void buildRAM() = 0;
	virtual Computer getResult() = 0;
};

// ConcreteBuilder 클래스: Builder 인터페이스를 구현하여 객체를 생성하는 클래스
class GamingComputerBuilder : public ComputerBuilder {
public:
	void buildCPU() override {
		computer_.setCPU("High-end Gaming CPU");
	}

	void buildGPU() override {
		computer_.setGPU("Gaming GPU");
	}

	void buildRAM() override {
		computer_.setRAM("16GB Gaming RAM");
	}

	Computer getResult() override {
		return computer_;
	}

private:
	Computer computer_;
};

// Director 클래스: Builder 인터페이스를 사용하여 객체를 생성하는 클래스
class ComputerDirector {
public:
	Computer construct(ComputerBuilder& builder) {
		builder.buildCPU();
		builder.buildGPU();
		builder.buildRAM();
		return builder.getResult();
	}
};

int main() {
	// Director를 이용하여 GamingComputerBuilder를 이용해 Computer 객체 생성
	ComputerDirector director;
	GamingComputerBuilder gamingBuilder;
	Computer gamingComputer = director.construct(gamingBuilder);

	// 생성된 Computer 객체의 정보 출력
	gamingComputer.showInfo();

	return 0;
}

///-------------------------코테를 위하여 -------------------------------
#include <iostream>

using namespace std;

class a
{
public:
	virtual void foo() { cout << "Hello" << endl; }
	virtual void foo1() { cout << "Hello" << endl; }
	virtual void foo2() { cout << "Hello" << endl; }
};

class b : public a
{
public:
	virtual void foo1() { cout << "Hello2" << endl; }
	virtual void foo3() { cout << "Hello3" << endl; }
};

class c : public b
{
public:
	virtual void foo3() { cout << "Hello3" << endl; }
	virtual void foo4() { cout << "Hello3" << endl; }
	virtual void foo5() { cout << "Hello3" << endl; }
};

int main()
{
	a* mon = new a;
	b* mon1 = new b;
	c* mon2 = new c;

	int a23123 = 10;



	return 0;
}
