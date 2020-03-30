#include "json.h"

#include <iostream>

int main()
{
	JSON modules = JSON();

	modules.add(JSON("module1"));

	modules.add(JSON("submodules"), "module1");
	modules.add(JSON("submodule1"), "submodules");
	modules.add(JSON("submodule2"), "submodules");
	modules.add(JSON("sub1"), "submodule1");
	modules.add(JSON("sub2"), "submodule1");

	modules.add("sub1", "something");
	modules.add("sub1", "qwerty");
	modules.add("sub1", "1234");
	modules.add("sub2", "poiuytreqw");

	modules.add("submodule2", "sub1");
	modules.add("submodule2", "sub2");
	modules.add("submodule2", "sub3");
	modules.add("submodule2", "sub4");
	modules.add("submodule2", "sub5");
	modules.add("submodule2", "sub6");
	modules.add("submodule2", "sub7");
	modules.add("submodule2", "sub8");

	string data = modules.stringtify();

	cout << data;

	return 0;
}
