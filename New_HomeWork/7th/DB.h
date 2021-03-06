#pragma once
#include<vector>
#include<iostream>
#include <fstream>
#include <string>
using namespace std;
struct book {
	book(string,string,string,string,string);
	string title;
	string author;
	string year;
	string publiser;
	string genre;
};
class DB{
public:
	DB(string filepath);
	void add(book);
	void show(int i);
	int count();
	void search_title();
	void search_author();
	void search_year();
	void search_publiser();
	void search_genre();
	void modify_title();
	void modify_author();
	void modify_year();
	void modify_publiser();
	void modify_genre();
	void del(int i);
	void save();
	~DB();
private:
	vector<book> booklist;
	string path1;
};


class menu{
public:
	menu(string);
	
private:
	void select_menu();
	DB* p1;
	void add();
	void search();
	void modify();
	void del();
	void show();
	void save();
};