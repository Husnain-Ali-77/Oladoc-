#include "feedback.h"
feedback::feedback()
{

}
void feedback::set_feedback(int a)
{
	int b= 0;
	this->feedback_rate = a * (a + b) / 2;
}