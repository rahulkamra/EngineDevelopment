#pragma once
#include <Types.h>
//yaw      //pitch    //roll
//heading // attitude // bank

struct EulerAngles
{
	EulerAngles(f32 yaw , f32 pitch , f32 roll):
		yaw(yaw),
		pitch(pitch),
		roll(roll)
	{

	}
	union
	{
		struct 
		{
			f32 yaw;
			f32 pitch;
			f32 roll;
		};

		struct
		{
			f32 heading;
			f32 attitude;
			f32 bank;
		};

	};
	
};
