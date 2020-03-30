#include "json.h"

JSON::JSON()
{

}
JSON::JSON(string k)
{
	key = k;
	isMultiDim = false;
}

string JSON::stringtify(int recursiveCounter)
{
	string result;
	if (recursiveCounter == 1)
		result += "{ \n";

	string t1 = string(recursiveCounter, '\t');
	string t2 = string(recursiveCounter + 1, '\t');

	result += t1 + "\"" + key + "\": ";
	if (isMultiDim)
	{
		result += "{ \n";
	}
	else
	{
		result += "[ \n";
	}

	for (auto value : values)
	{
		result += t2;
		result += ("\"" + value + "\",\n");
	}
	if (jsons.size())
	{
		for (auto json : jsons)
		{
			result += json.stringtify(recursiveCounter + 1) + ",\n";
		}
	}
	result.erase(result.end()-2, result.end()-1);
	result += t1;
	if (isMultiDim)
	{
		result += "}";
	}
	else
	{
		result += "]";
	}

	if (recursiveCounter == 1)
		result += "\n}";

	return result;
}

bool JSON::add(string k, JSON value)
{
	return false;
}

bool JSON::add(string k, string value)
{
	return false;
}

