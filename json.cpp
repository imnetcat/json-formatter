#include "json.h"

JSON::JSON()
{
	key.empty();
	isMultiDim = false;
}
JSON::JSON(string k)
{
	key = k;
	isMultiDim = false;
}
JSON::~JSON()
{

}

string JSON::stringtify(int recursiveCounter)
{
	string result;
	//if (recursiveCounter == 1)
	//	result += "{ \n";

	string t1 = string(recursiveCounter, '\t');
	string t2 = string(recursiveCounter + 1, '\t');

	if (key == "")
	{
		result += "{\n";
	}
	else
	{
		result += t1 + "\"" + key + "\": ";
		if (isMultiDim)
		{
			result += "{\n";
		}
		else
		{
			result += "[\n";
		}
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
	result.erase(result.end() - 2, result.end() - 1);

	if (key == "")
	{
		result += "\n}";
	}
	else
	{
		result += t1;
		if (isMultiDim)
		{
			result += "}";
		}
		else
		{
			result += "]";
		}
	}

	return result;
}

bool JSON::add(JSON value, string k)
{
	if (key == k || k == "")
	{
		if (!isMultiDim)
		{
			isMultiDim = true;
			values.clear();
		}
		jsons.push_back(value);
		return true;
	}
	else
	{
		for (JSON & jsn : jsons)
		{
			bool ret = jsn.add(value, k);
			if (ret)
			{
				return true;
			}
		}
	}
	return false;
}

bool JSON::add(string k, string value)
{
	if (key == k)
	{
		if (!isMultiDim)
		{
			values.push_back(value);
		}
		return true;
	}
	else
	{
		for (JSON & jsn : jsons)
		{
			bool ret = jsn.add(k, value);
			if (ret)
			{
				return true;
			}
		}
	}
	return false;
}

