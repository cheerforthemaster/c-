  //#include "glut.h"
  // #include <iostream>
  // using namespace std;
  // 
  // void myDisplay(void)
  // {
  // 	//使用RGBA颜色模式设置背景色为红色的矩形框
  //
  // 
  // 	//设置清除屏幕所用的颜色
  // 	/*glClearColor(0.5,0.8,0.3,0);
  // 	glClear(GL_COLOR_BUFFER_BIT);
  // 	glFlush();*/
  // 
  // 	//设置着色模型
  //
  // 	//glShadeModel(GL_FLAT);    //取消颜色的渐变，改为单一颜色
  // 	glClear(GL_COLOR_BUFFER_BIT);
  // 	glBegin(GL_TRIANGLE_FAN);
  // 	//glColor3f(1.0f, 1.0f, 1.0f);  //设置第一个点的颜色
  // 	//glVertex2f(0.0f, 0.0f);
  // 
  // 	glColor3f(0, 0, 255);//蓝色
  // 	glVertex2f(0.5, 0.5);
  // 	glColor3f(0, 255, 0);//绿色
  // 	glVertex2f(0.0, -0.5);
  // 	glColor3f(0, 255, 255);//青色
  // 	glVertex2f(-1.0, 0.0);
  // 	glColor3f(255, 255, 0);//黄色
  // 	glVertex2f(-0.5, 0.5);
  // 
  // 	glEnd();
  // 	glFlush();
  //
  // }
  // 
  // void ProcessSpecialKeys(int key, int x, int y)
  // {
	 //  if (key == GLUT_KEY_UP)
	 //  {
		//   glScalef(1.1, 1.1, 1.1);
	 //  }
	 //  if (key == GLUT_KEY_DOWN)
	 //  {
		//   glScalef(0.9, 0.9, 0.9);
	 //  }
	 //  myDisplay();
  // }
  // 
  // int main(int argc, char *argv[])
  // {
  // 	glutInit(&argc, argv);   //初始化GLUT
  // 	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  // 	glutInitWindowPosition(500, 200);
  // 	glutInitWindowSize(600, 600);
  // 	glutCreateWindow("OpenGL");
  // 	glutDisplayFunc(&myDisplay);   //回调函数 
  // 	glutSpecialFunc(ProcessSpecialKeys);
  // 	glutMainLoop();    //持续显示，当窗口改变会重新绘制图形
  // 	return 0;
  // }