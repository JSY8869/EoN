#include "DB.h"

DB::DB(string filepath) {
	path1 = filepath;
	ifstream infile(filepath);

	string title, author, year, publiser, genre;
	while (infile){
		infile >> title;
		infile >> author;
		infile >> year;
		infile >> publiser;
		infile >> genre;
		if (!infile){
			break;
		}
		booklist.push_back(book(title, author, year, publiser, genre));
	}
	infile.close();
}
DB::~DB() {

}
menu::menu(string filepath) {
	p1 = new DB(filepath);
	select_menu();
	delete p1;
}
void menu::select_menu(){
	int num;
	cout << "���α׷� ����" << endl;
	do {
		cout << endl;
		cout << "--------------------" << endl;
		cout << "�������� ���α׷�" << endl;
		cout << "\t" << "MENU" << endl;
		cout << "1.���� �߰�" << endl;
		cout << "2.���� �˻�" << endl;
		cout << "3.���� ���� ����" << endl;
		cout << "4.���� ����" << endl;
		cout << "5.���� �� ���� ��� ���" << endl;
		cout << "6.����" << endl;
		cout << "7.���α׷� ������(�ڵ�����)" << endl;
		cout << "--------------------" << endl;
		cout << "�޴��� �Է��ϼ���: ";
		cin >> num;
		switch (num) {
		case 1:
			add();
			break;
		case 2:
			search();
			break;
		case 3:
			modify();
			break;
		case 4:
			del();
			break;
		case 5:
			show();
			break;
		case 6:
			save();
			break;
		case 7:
			save();
			return;
		default:
			;
		}
	} while (num);

}
int DB::count() {
	return booklist.size();
}
void DB::add(book book) {
	booklist.push_back(book);
}
void DB::show(int i) {
	cout << booklist[i].title << " " << booklist[i].author << " " << booklist[i].year << " " << booklist[i].publiser << " " << booklist[i].genre << endl;
}
void menu::show() {
	for (int i = 0; i < p1->count(); i++)
	{
		p1->show(i);
	}
}

book::book(string title, string author, string year, string publiser,string genre) {
	this->title = title;
	this->author = author;
	this->year = year;
	this->publiser = publiser;
	this->genre = genre;
}
void menu::add() {
	string title, author, year, publiser, genre;
	cout << "�߰��� �������� �Է��ϼ���: " << endl;
	cin >> title >> author >> year >> publiser >> genre;
	p1->add(book(title, author, year, publiser, genre));
	
}
void DB::search_title() {
	string title1;
	cout << "�˻��� �������� �Է��ϼ���: ";
	cin >> title1;
	for (int i = 0; i < booklist.size(); i++){
		if (title1.compare(booklist[i].title)==0){
			show(i);
		}
	}
}
void DB::search_author() {
	string author1;
	cout << "�˻��� ���ڸ� �Է��ϼ���: ";
	cin >> author1;
	for (int i = 0; i < booklist.size(); i++) {
		if (author1.compare(booklist[i].author) == 0) {
			show(i);
		}
	}
}
void DB::search_year() {
	string year1;
	cout << "�˻��� ���ǳ⵵�� �Է��ϼ���: ";
	cin >> year1;
	for (int i = 0; i < booklist.size(); i++) {
		if (year1.compare(booklist[i].year) == 0) {
			show(i);
		}
	}
}
void DB::search_publiser() {
	string publiser1;
	cout << "�˻��� ���ǻ縦 �Է��ϼ���: ";
	cin >> publiser1;
	for (int i = 0; i < booklist.size(); i++) {
		if (publiser1.compare(booklist[i].publiser) == 0) {
			show(i);
		}
	}
}
void DB::search_genre() {
	string genre1;
	cout << "�˻��� �帣�� �Է��ϼ���: ";
	cin >> genre1;
	for (int i = 0; i < booklist.size(); i++) {
		if (genre1.compare(booklist[i].genre) == 0) {
			show(i);
		}
	}
}

void menu::search() {
	int num;
	cout << "� ������ �˻��Ͻðڽ��ϱ�(1.������ 2.���� 3.���ǳ⵵ 4.���ǻ� 5.�帣): ";
	cin >> num;
	do
	{
		switch (num) {
		case 1:
			p1->search_title();
			return;
		case 2:
			p1->search_author();
			return;
		case 3:
			p1->search_year();
			return;
		case 4:
			p1->search_publiser();
			return;
		case 5:
			p1->search_genre();
			return;
		default:
			cout << "�ٽ� �Է��ϼ���: ";
		}
	} while (num);
}
void DB::modify_title() {
	string title1;
	string title2;
	cout << "�ٲ� �������� �Է��ϼ���: ";
	cin >> title1;
	cout << "������ �������� �Է��ϼ���: ";
	cin >> title2;
	for (int i = 0; i < booklist.size(); i++) {
		if (title1.compare(booklist[i].title) == 0) {
			booklist[i].title = title2;
			show(i);
			cout << "���� �Ϸ�";
		}
	}
}
void DB::modify_author() {
	string author1;
	string author2;
	cout << "�ٲ� ���ڸ� �Է��ϼ���: ";
	cin >> author1;
	cout << "������ ���ڸ� �Է��ϼ���: ";
	cin >> author2;
	for (int i = 0; i < booklist.size(); i++) {
		if (author1.compare(booklist[i].author) == 0) {
			booklist[i].author = author2;
			show(i);
			cout << "���� �Ϸ�";
		}
	}
}
void DB::modify_year(){
	string year1;
	string year2;
	cout << "�ٲ� �⵵�� �Է��ϼ���: ";
	cin >> year1;
	cout << "������ �⵵�� �Է��ϼ���: ";
	cin >> year2;
	for (int i = 0; i < booklist.size(); i++) {
		if (year1.compare(booklist[i].year) == 0) {
			booklist[i].year = year2;
			show(i);
			cout << "���� �Ϸ�";
		}
	}
}
void DB::modify_publiser() {
	string publiser1;
	string publiser2;
	cout << "�ٲ� ���ǻ���� �Է��ϼ���: ";
	cin >> publiser1;
	cout << "������ ���ǻ���� �Է��ϼ���: ";
	cin >> publiser2;
	for (int i = 0; i < booklist.size(); i++) {
		if (publiser1.compare(booklist[i].publiser) == 0) {
			booklist[i].publiser = publiser2;
			show(i);
			cout << "���� �Ϸ�";
		}
	}
}
void DB::modify_genre(){
	string genre1;
	string genre2;
	cout << "�ٲ� �帣�� �Է��ϼ���: ";
	cin >> genre1;
	cout << "������ �帣�� �Է��ϼ���: ";
	cin >> genre2;
	for (int i = 0; i < booklist.size(); i++) {
		if (genre1.compare(booklist[i].genre) == 0) {
			booklist[i].genre = genre2;
			show(i);
			cout << "���� �Ϸ�";
		}
	}
}
void menu::modify() {
	int num;
	show();
	cout << "������ ��°�� �����ϼ���: ";
	cin >> num;
	do{
		switch (num) {
		case 1:
			p1->modify_title();
			return;
		case 2:
			p1->modify_author();
			return;
		case 3:
			p1->modify_year();
			return;
		case 4:
			p1->modify_publiser();
			return;
		case 5:
			p1->modify_genre();
			return;
		default:
			cout << "�ٽ� �Է��ϼ���: ";
		}
	} while (num);
}
void DB::del(int i) {
	booklist.erase(booklist.begin()+i-1);
	for (int j = 0; j < booklist.size(); j++){
		show(j);
	}
}
void menu::del() {
	int num;
	show();
	cout << "������ ��°�� �Է��ϼ���: ";
	cin >> num;
	p1->del(num);
}
void DB::save() {
	ofstream ofile(path1);
	for (int i = 0; i < booklist.size(); i++){
		ofile << booklist[i].title << " " << booklist[i].author << " " << booklist[i].year << " " << booklist[i].publiser << " " << booklist[i].genre << endl;	 	
	}
	cout << "����Ϸ�" << endl;
	ofile.close();
}
void menu::save() {
	cout << "�����մϴ�";
	p1->save();
}
