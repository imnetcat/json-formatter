#pragma once
#ifndef _JSON_H
#define _JSON_H

#include <vector>
#include <string>
using namespace std;

class JSON
{
public:
	JSON();
	JSON(string key);
	~JSON();
	string stringtify(int recursiveCounter = 0);
	bool add(string key, string value);
	bool add(JSON value, string key = "");
private:
	string key;
	vector <string> values;
	vector <JSON> jsons;
	bool isMultiDim;
};


#endif