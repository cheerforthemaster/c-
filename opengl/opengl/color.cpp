//#include "glut.h"
//#include <iostream>
//using namespace std;
//
//void myDisplay(void)
//{
//	//ʹ��RGBA��ɫģʽ���ñ���ɫΪ��ɫ�ľ��ο�
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor4f(1, 0, 0, 1);
//	glRectf(-0.8, -0.8, 0.5, 0.5);
//	glFinish();
//	//����alphaͨ��͸����
//	glEnable(GL_BLEND);  //�������ģʽ
//	glDisable(GL_DEPTH_TEST);  //�ر���Ȳ���
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
//	glColor4f(0, 1, 0, 1);
//	glRectf(-0.5, -0.5, 0.8, 0.8);
//	glFinish();
//
//	//���������Ļ���õ���ɫ
//	/*glClearColor(0.5,0.8,0.3,0);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glFlush();*/
//
//	//������ɫģ��
//	int i;
//	float Pi = 3.1415926f;
//	//glShadeModel(GL_FLAT);    //ȡ����ɫ�Ľ��䣬��Ϊ��һ��ɫ
//	glClear(GL_COLOR_BUFFER_BIT);
//	glBegin(GL_TRIANGLE_FAN);
//	//glColor3f(1.0f, 1.0f, 1.0f);  //���õ�һ�������ɫ
//	//glVertex2f(0.0f, 0.0f);
//	for (i = 0; i <= 8; ++i)
//	{
//		glColor3f(i & 0x04, i & 0x02, i & 0x01);   //���ø����������ɫ
//		glVertex2f(cos(i*Pi / 4), sin(i*Pi / 4));  //8������ƽ���ֲ���һ��Բ��
//	}
//	glEnd();
//	glFlush();
//}
//
//
//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv);   //��ʼ��GLUT
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
//	glutInitWindowPosition(500, 200);
//	glutInitWindowSize(400, 400);
//	glutCreateWindow("OpenGL");
//	glutDisplayFunc(&myDisplay);   //�ص����� 
//	glutMainLoop();    //������ʾ�������ڸı�����»���ͼ��
//	return 0;
//}