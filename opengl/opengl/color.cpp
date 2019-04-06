//#include "glut.h"
//#include <iostream>
//using namespace std;
//
//void myDisplay(void)
//{
//	//使用RGBA颜色模式设置背景色为红色的矩形框
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor4f(1, 0, 0, 1);
//	glRectf(-0.8, -0.8, 0.5, 0.5);
//	glFinish();
//	//设置alpha通道透明度
//	glEnable(GL_BLEND);  //开启混合模式
//	glDisable(GL_DEPTH_TEST);  //关闭深度测试
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
//	glColor4f(0, 1, 0, 1);
//	glRectf(-0.5, -0.5, 0.8, 0.8);
//	glFinish();
//
//	//设置清除屏幕所用的颜色
//	/*glClearColor(0.5,0.8,0.3,0);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glFlush();*/
//
//	//设置着色模型
//	int i;
//	float Pi = 3.1415926f;
//	//glShadeModel(GL_FLAT);    //取消颜色的渐变，改为单一颜色
//	glClear(GL_COLOR_BUFFER_BIT);
//	glBegin(GL_TRIANGLE_FAN);
//	//glColor3f(1.0f, 1.0f, 1.0f);  //设置第一个点的颜色
//	//glVertex2f(0.0f, 0.0f);
//	for (i = 0; i <= 8; ++i)
//	{
//		glColor3f(i & 0x04, i & 0x02, i & 0x01);   //设置各个顶点的颜色
//		glVertex2f(cos(i*Pi / 4), sin(i*Pi / 4));  //8个顶点平均分布在一个圆上
//	}
//	glEnd();
//	glFlush();
//}
//
//
//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv);   //初始化GLUT
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
//	glutInitWindowPosition(500, 200);
//	glutInitWindowSize(400, 400);
//	glutCreateWindow("OpenGL");
//	glutDisplayFunc(&myDisplay);   //回调函数 
//	glutMainLoop();    //持续显示，当窗口改变会重新绘制图形
//	return 0;
//}