  //#include "glut.h"
  // #include <iostream>
  // using namespace std;
  // 
  // void myDisplay(void)
  // {
  // 	//ʹ��RGBA��ɫģʽ���ñ���ɫΪ��ɫ�ľ��ο�
  //
  // 
  // 	//���������Ļ���õ���ɫ
  // 	/*glClearColor(0.5,0.8,0.3,0);
  // 	glClear(GL_COLOR_BUFFER_BIT);
  // 	glFlush();*/
  // 
  // 	//������ɫģ��
  //
  // 	//glShadeModel(GL_FLAT);    //ȡ����ɫ�Ľ��䣬��Ϊ��һ��ɫ
  // 	glClear(GL_COLOR_BUFFER_BIT);
  // 	glBegin(GL_TRIANGLE_FAN);
  // 	//glColor3f(1.0f, 1.0f, 1.0f);  //���õ�һ�������ɫ
  // 	//glVertex2f(0.0f, 0.0f);
  // 
  // 	glColor3f(0, 0, 255);//��ɫ
  // 	glVertex2f(0.5, 0.5);
  // 	glColor3f(0, 255, 0);//��ɫ
  // 	glVertex2f(0.0, -0.5);
  // 	glColor3f(0, 255, 255);//��ɫ
  // 	glVertex2f(-1.0, 0.0);
  // 	glColor3f(255, 255, 0);//��ɫ
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
  // 	glutInit(&argc, argv);   //��ʼ��GLUT
  // 	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  // 	glutInitWindowPosition(500, 200);
  // 	glutInitWindowSize(600, 600);
  // 	glutCreateWindow("OpenGL");
  // 	glutDisplayFunc(&myDisplay);   //�ص����� 
  // 	glutSpecialFunc(ProcessSpecialKeys);
  // 	glutMainLoop();    //������ʾ�������ڸı�����»���ͼ��
  // 	return 0;
  // }