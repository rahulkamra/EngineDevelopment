#include <math.h>
#define TEST_UTILS_PRECISION 0.0001

class TestUtils
{
public :
	bool static almostEqual(f32 lhs , f32 rhs)
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

	bool static almostEqual(f32 lhs, f64 rhs)
	{

		if (abs(lhs - rhs) < TEST_UTILS_PRECISION)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};

