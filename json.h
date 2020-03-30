#pragma once
#ifndef _JSON_H
#define _JSON_H

#include <vector>
#include <string>
using namespace std;

enum TYPE
{
	OBJECT,
	ARRAY,
	STRING
};

class JSON
{
public:
	JSON();
	JSON(TYPE type, string key);
	~JSON();
	string stringtify(int recursiveCounter = 0);
	//bool add(string key, string value);
	//bool add(JSON value, string key = "");
	JSON & add(TYPE type, string key);
	JSON & set(string key, string value);
	JSON & key(string key);
private:
	string _key;
	string _string;
	int _int;
	vector <string> _values;
	vector <JSON> obj;
	TYPE _type;
};

#endif