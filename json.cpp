#include "json.h"

JSON::JSON()
{
	_key.empty();
	_type = OBJECT;
}

JSON::JSON(TYPE type, string key)
{
	_key = key;
	_type = type;
}
JSON::~JSON()
{

}

JSON & JSON::key(string key)
{
	for (JSON & jsn : obj)
	{
		if (jsn._key == key)
		{
			return jsn;
		}
	}

	return *this;
}

JSON & JSON::set(string k, string value)
{
	if (_type == OBJECT)
	{
		key(k)._string = value;
	}
	else if (_type == ARRAY)
	{

	}
	return *this;
}


JSON & JSON::add(TYPE type, string key)
{
	if (_type == OBJECT)
	{
		obj.push_back(JSON(type, key));
	}
	else if (_type == ARRAY)
	{
		_values.push_back(key);
	}
	return *this;
}

string JSON::stringtify(int recursiveCounter)
{
	string result;
	//if (recursiveCounter == 1)
	//	result += "{ \n";

	string t1 = string(recursiveCounter, '\t');
	string t2 = string(recursiveCounter + 1, '\t');

	if (_key == "")
	{
		result += "{\n";
	}
	else
	{
		result += t1 + "\"" + _key + "\": ";
		if (_type == OBJECT)
		{
			result += "{\n";
		}
		else if (_type == ARRAY)
		{
			result += "[\n";
		}
	}
	
	if (_type == STRING)
	{
		result += " \"" + _string + "\"\n";
	}

	if (_type == OBJECT || _type == ARRAY)
	{
		if (_values.size())
		{
			for (auto value : _values)
			{
				result += t2 + "\"" + value + "\",\n";
			}
			result.erase(result.end() - 2, result.end() - 1);
		}

		if (obj.size())
		{
			for (auto json : obj)
			{
				result += json.stringtify(recursiveCounter + 1) + ",\n";
			}
			result.erase(result.end() - 2, result.end() - 1);
		}
	}


	if (_key == "")
	{
		result += "\n}";
	}
	else
	{
		result += t1;
		if (_type == OBJECT)
		{
			result += "}";
		}
		else if (_type == ARRAY)
		{
			result += "]";
		}
	}

	return result;
}
