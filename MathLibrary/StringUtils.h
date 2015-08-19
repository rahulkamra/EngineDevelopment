#include <iostream>
#include <sstream>

using namespace std;
class StringUtils
{
public:
	
	inline static string toString(int integer)
	{
		string result;
		ostringstream convert;
		convert << integer;
		return convert.str();
	}

private:

};

