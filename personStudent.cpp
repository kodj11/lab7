#include <cstring>
#include <iostream>

struct homo_sapiens {
	// ����� ����������� �-�� 
	// ������ ��� ����������� ����� (���������)
	virtual void f() = 0;
	virtual void facultates() = 0;
};

struct person : homo_sapiens {
private:
	char addres[100];
	
public:
	char name[64]{};
	char sex; // �m� or �f�
	int year_of_birth;

	// ����������� ������
	person(const char* name2, int year_of_birth2) {
		strcpy_s(name, name2);
		year_of_birth = year_of_birth2;
	}
	person() {}

	// ����� Show() 
	// ������� ��� ���������� ��� ������ person 
	// �� ��� �������� �� �� ����� �������� �� �������������� ����������.
	/*
	void Show() {
		std::cout << "Show person info: " << name << "\t" << sex
			<< "\t" << year_of_birth << std::endl;
	}
	*/
	// ����������� ����� Show()
	// ������ �������� ���� ����������� ����� �������� 
	// �������� �� ����������� 
	virtual void Show() {
		std::cout << "Show person info: " << name << "\t" << sex
			<< "\t" << year_of_birth << std::endl;
	}

	// ���������� ������ person
	// ����� ��������� ������� ������ ������� person 
	// �� ����� �� ��������� ��� ��������  
	/*
	~person() {
		std::cout << "~person()" << std::endl;
	}
	*/
	// ����������� ���������� ������
	virtual ~person() {
		std::cout << "~person()" << std::endl;
	}

	virtual void f() {
		return;
	}
	// ������ ����� ���������� �-�� f ������ person
	void f_from_person() { person::f(); }
	// �� ����������� ����� ���������� �-��
	// ������������� � ������ ������ �������� 
	void f_from_current_place() { f(); }

	virtual void facultates() {
		return;
	}


protected:
	char* getAddres() {
		return addres;
	}
};

struct student : public person {

public:
	int code; // specialty code
	int year; // year of study
	double gpa; // Grade Point Average
	char more_info[111]{};
	// ����������� �������
	student() : person("Fayustov Nikita", 2002), code(335) {}
	// virtual Show �������
	virtual void Show() {
		std::cout << "Show student info: " << name << "\t" << sex
			<< "\t" << year_of_birth << "\t" << code << "\t" << year
			<< "\t" << gpa << std::endl;
	}

	// �����������  ���������� �������
	virtual ~student() {
		std::cout << "~student()" << std::endl;
	}

	virtual void f() {
		throw "student throw!";
		return;
	}
};

// public private protected 

// ������ �� �������, ����������� � ��������� person 
// ����� �������� �� ��� ������ ���� ����������� �������� � incognito
struct incognito : private person {
private:
	// ������ �-�� facultates ������ ������ � ���� ������!
	char** facultates;
public:
	double gpa = 2;
	// ����������� private �������
	incognito() : person(), gpa(3) { }
	// virtual Show �������
	virtual void Show() {
		std::cout << "Show incognito info: " << gpa << std::endl;
	}
	

	// ����������� ���������� �������
	virtual ~incognito() {
		std::cout << "~incognito()" << std::endl;
	}
	// ���� �� ��� � private 
	// �� ��� ����� ��� �� �������� ������ ����� �����:
	void delete_this() {
		delete this;
	}

	virtual void f() {
		throw "incognito throw!";
		return;
	}
};

int main() {
	student s1;
	strcpy_s(s1.name, "Ivanov Ivan");
	s1.sex = 'm';
	s1.year_of_birth = 2000;
	s1.code = 335;
	s1.year = 3;
	s1.gpa = 4.5;

	std::cout << s1.name << " " << s1.sex << " " << s1.year_of_birth
		<< " " << s1.code << " " << s1.year << " " << s1.gpa << std::endl;

	try {
		s1.f();
	}
	catch (const student & ex) {
		std::cout << "ctudent err" << std::endl;
	}
	catch (...) {
		std::cout << "... err" << std::endl;
	}

	// ����������� ������ � ���������� 
	person* p;
	student* sp{};
	p = &s1; // �����!
	std::cout << "*p: " << p->name << " " << p->sex << " " << p->year_of_birth << std::endl;
	person& ref = s1; // �����!
	std::cout << "&ref: " << ref.name << " " << ref.sex << " " << ref.year_of_birth << std::endl;
	// ^ ����� ������� ����� �������� ��������� � ���������� �-��,
	// ����������� ������ 
	// student* s2 = p; // ������!
	p = sp; // good
	//sp = p; // error
	p = static_cast<person*>(sp); // good
	sp = static_cast<student*>(p); // good
	
	person pp("Non Grata", 1);
	// ������ 
	incognito noname;
	noname.gpa = 1;
	// noname.year_of_birth = 1; ������!
	// noname.addres			 ������!

	// Show ��� ������� � �������� 
	pp.Show();
	s1.Show();
	noname.Show();
	//noname.delete_this();
	
	s1.facultates(); // �����!
	//noname.facultates; // ������!

	return 0;
}