#include "json.h"

#include <iostream>

int main()
{
	JSON data = JSON();

	data.add(STRING, "status");
	data.set("status", "gotit");

	data.add(ARRAY, "array");
	data.add(OBJECT, "modules");

	JSON & t = data.key("array");
	t.add(STRING, "(one)");
	t.add(STRING, "(two)");
	t.add(STRING, "(three)");

	JSON & modules = data.key("modules");
	JSON & submodule1 = modules.add(OBJECT, "submodule1").key("submodule1");
	JSON & sub = submodule1.add(OBJECT, "sub").key("sub");
	sub.add(ARRAY, "array1");
	sub.add(ARRAY, "array2");
	JSON & array1 = sub.key("array1");
	JSON & array2 = sub.key("array2");

	array2.add(STRING, "login1:pass");
	array2.add(STRING, "login2:pass");
	array2.add(STRING, "login3:pass");
	array1.add(STRING, "login6758:pass");
	array1.add(STRING, "login008:pass");
	array2.add(STRING, "login4:pass");

	string strdat = data.stringtify();

	cout << strdat;

	return 0;
}
