#include "person.h"
#include "teacher.h"
#include "student.h"
#include "garstudent.h"
#include"parttime.h"
#include <iostream>
using namespace std;

void main()
{
	parttime *one=new parttime;
	one->GetInfo();
	one->SetIfo();
	one->setmyteacher();
	one->getmyteacher();
	one->SetTitle();
	one->GetTitle();
	one->setwage();
	one->getwage();
	one->get();
	one->caltuition();
}