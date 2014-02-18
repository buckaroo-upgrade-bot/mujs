#include "jsi.h"
#include "jsvalue.h"
#include "jsbuiltin.h"

static int Math_abs(js_State *J, int argc)
{
	js_pushnumber(J, abs(js_tonumber(J, 1)));
	return 1;
}

static int Math_acos(js_State *J, int argc)
{
	js_pushnumber(J, acos(js_tonumber(J, 1)));
	return 1;
}

static int Math_asin(js_State *J, int argc)
{
	js_pushnumber(J, asin(js_tonumber(J, 1)));
	return 1;
}

static int Math_atan(js_State *J, int argc)
{
	js_pushnumber(J, atan(js_tonumber(J, 1)));
	return 1;
}

static int Math_atan2(js_State *J, int argc)
{
	js_pushnumber(J, atan2(js_tonumber(J, 1), js_tonumber(J, 2)));
	return 1;
}

static int Math_ceil(js_State *J, int argc)
{
	js_pushnumber(J, ceil(js_tonumber(J, 1)));
	return 1;
}

static int Math_cos(js_State *J, int argc)
{
	js_pushnumber(J, cos(js_tonumber(J, 1)));
	return 1;
}

static int Math_exp(js_State *J, int argc)
{
	js_pushnumber(J, exp(js_tonumber(J, 1)));
	return 1;
}

static int Math_floor(js_State *J, int argc)
{
	js_pushnumber(J, floor(js_tonumber(J, 1)));
	return 1;
}

static int Math_log(js_State *J, int argc)
{
	js_pushnumber(J, log(js_tonumber(J, 1)));
	return 1;
}

static int Math_pow(js_State *J, int argc)
{
	js_pushnumber(J, pow(js_tonumber(J, 1), js_tonumber(J, 2)));
	return 1;
}

static int Math_random(js_State *J, int argc)
{
	js_pushnumber(J, (double)rand() / (RAND_MAX - 1));
	return 1;
}

static int Math_round(js_State *J, int argc)
{
	js_pushnumber(J, round(js_tonumber(J, 1)));
	return 1;
}

static int Math_sin(js_State *J, int argc)
{
	js_pushnumber(J, sin(js_tonumber(J, 1)));
	return 1;
}

static int Math_sqrt(js_State *J, int argc)
{
	js_pushnumber(J, sqrt(js_tonumber(J, 1)));
	return 1;
}

static int Math_tan(js_State *J, int argc)
{
	js_pushnumber(J, tan(js_tonumber(J, 1)));
	return 1;
}

static int Math_max(js_State *J, int argc)
{
	double n = js_tonumber(J, 1);
	int i;
	for (i = 2; i <= argc; ++i) {
		double m = js_tonumber(J, i);
		n = n > m ? n : m;
	}
	js_pushnumber(J, n);
	return 1;
}

static int Math_min(js_State *J, int argc)
{
	double n = js_tonumber(J, 1);
	int i;
	for (i = 2; i <= argc; ++i) {
		double m = js_tonumber(J, i);
		n = n < m ? n : m;
	}
	js_pushnumber(J, n);
	return 1;
}

void jsB_initmath(js_State *J)
{
	js_pushobject(J, jsV_newobject(J, JS_CMATH, J->Object_prototype));
	{
		jsB_propn(J, "E", 2.7182818284590452354);
		jsB_propn(J, "LN10", 2.302585092994046);
		jsB_propn(J, "LN2", 0.6931471805599453);
		jsB_propn(J, "LOG2E", 1.4426950408889634);
		jsB_propn(J, "LOG10E", 0.4342944819032518);
		jsB_propn(J, "PI", 3.1415926535897932);
		jsB_propn(J, "SQRT1_2", 0.7071067811865476);
		jsB_propn(J, "SQRT2", 1.4142135623730951);

		jsB_propf(J, "abs", Math_abs, 1);
		jsB_propf(J, "acos", Math_acos, 1);
		jsB_propf(J, "asin", Math_asin, 1);
		jsB_propf(J, "atan", Math_atan, 1);
		jsB_propf(J, "atan2", Math_atan2, 2);
		jsB_propf(J, "ceil", Math_ceil, 1);
		jsB_propf(J, "cos", Math_cos, 1);
		jsB_propf(J, "exp", Math_exp, 1);
		jsB_propf(J, "floor", Math_floor, 1);
		jsB_propf(J, "log", Math_log, 1);
		jsB_propf(J, "max", Math_max, 2);
		jsB_propf(J, "min", Math_min, 2);
		jsB_propf(J, "pow", Math_pow, 2);
		jsB_propf(J, "random", Math_random, 0);
		jsB_propf(J, "round", Math_round, 1);
		jsB_propf(J, "sin", Math_sin, 1);
		jsB_propf(J, "sqrt", Math_sqrt, 1);
		jsB_propf(J, "tan", Math_tan, 1);
	}
	js_defglobal(J, "Math", JS_DONTENUM);
}
