#include "Util.h"
using namespace Util;

double Util::Limit(double upperlimit, double lowerlimit, double value)
{
	if( value >= upperlimit)
	{
		value = upperlimit;
		return value;
	}
	if(value <= lowerlimit)
	{
		value = lowerlimit;
		return value;
	}
	return value;
}
