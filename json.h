#pragma once
#pragma once

#include <vector>
#include <string>
using namespace std;

class JSON
{
public:
	JSON();
	JSON(string key);
	~JSON();
	string stringtify(int recursiveCounter = 1);
	bool add(string key, string value);
	bool add(string key, JSON value);
private:
	string key;
	vector <string> values;
	vector <JSON> jsons;
	bool isMultiDim;
};


