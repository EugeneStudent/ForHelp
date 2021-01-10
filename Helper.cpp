#include <iostream>
extern const float Value = 5; //extern не поможет const global value сделать 
							  //доступным для other file
static float Svalue = -15.3;

void foo_set_Svalue(int a)
{
	Svalue = static_cast<float>(a);
}

float foo_get_Svalue()
{
	return Svalue;
}