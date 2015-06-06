#include <math.h>
#define TEST_UTILS_PRECISION 0.0001

class TestUtils
{
public :
	bool static almostEqual(float lhs , float rhs)
	{
		
		if (abs(lhs - rhs) < TEST_UTILS_PRECISION )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};

