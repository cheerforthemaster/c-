//#include <Windows.h>
//#include <stdio.h>
//#include "glut.h"
//#include <stdio.h>
//#include<iostream>
//#include<conio.h>
//#include <stdarg.h>
//#include <math.h>
//#include <vector>
//#include "getline.h"
//using namespace std;
//
//const int win_w = 700, win_h = 700;
//GLfloat default_matrix[16];
//GLfloat modelview_matrix[16];
//GLfloat modelview_z_dis;
//GLfloat x_min = .0, x_max = 20.0, y_min = .0, y_max = 20.0, z_min = .0, z_max = 20.0;
//
////void xyz_line(float len)
////{
////	GLfloat color[] = { .0, .0, .0, 1.0 };
////	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
////
////	glBegin(GL_LINES);
////	color[0] = 1.0; color[1] = 0.0; color[2] = 0.0;
////	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
////	glVertex3f(45.0, 15.0, 0.0);
////	glVertex3f(len+45, 15.0, 0.0);
////	color[0] = 0.0; color[1] = 1.0; color[2] = 0.0;
////	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
////	glVertex3f(45.0, 15.0, 0.0);
////	glVertex3f(45.0, len+15, 0.0);
////	color[0] = 0.0; color[1] = 0.0; color[2] = 1.0;
////	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
////	glVertex3f(45.0, 15.0, .0);
////	glVertex3f(45.0, 15.0, len);
////	glEnd();
////}
//
//vector<vector<double>> tem1 = {
//	{ 0, 0, -0.0400272, 1 },
//	{ 0, 10.7113, -0.0430214, 24 },
//	{ 10, 10.7113, -0.0550055, 49 },
//	{ 10, 0, -0.0514855, 74 }
//};
//
//vector<vector<double>> tem2 = {
//	{ 10, 0, -0.0514855, 74 },
//	{ 10, 10.7113, -0.0550055, 49 },
//	{ 20, 10.7113, -0.0725252, 24 },
//	{ 20, 0, -0.0692827, 100 }
//};
//
//void setRecColor(double Pointcolor)
//{
//	//int colorkinds = 5;//��ɫ���� 
//	//int setnum = Pointcolor / (100 / (colorkinds-1));
//	//switch (setnum)
//	//{
//	//case 0://0~25 0Ϊ��ɫ
//	//	glColor3f(255, int(float(Pointcolor / 25.0 * 255)), 0);
//	//	cout << int(float(Pointcolor / 25.0 * 255)) << endl;
//	//	break;
//	//case 1://25~50 25Ϊ��ɫ
//	//	glColor3f(255 - (double((Pointcolor - 25) / 25) * 255), 255, 0);
//	//	break;
//	//case 2://50~75 50Ϊ��ɫ
//	//	glColor3f(0, 255, double((Pointcolor - 50) / 25) * 255);
//	//	break;
//	//case 3://75~100 75Ϊ��ɫ
//	//	glColor3f(0, 255 - (double((Pointcolor - 75) / 25) * 255), 255);
//	//	break;
//	//case 4://100 100Ϊ��ɫ
//	//	glColor3f(0, 0, 255);
//	//	break;
//	//default:
//	//	break;
//	//}
//
//	int colorkinds = 5;//��ɫ���� 
//	int setnum = Pointcolor / (100 / (colorkinds));
//	switch (setnum)
//	{
//	case 0://0~20 ��ɫ
//		glColor3f(255, 0, 0);
//		break;
//	case 1://20~40 ��ɫ
//		glColor3f(255, 255, 0);
//		break;
//	case 2://40~60 ��ɫ
//		glColor3f(0, 255, 0);
//		break;
//	case 3://60~80 ��ɫ
//		glColor3f(0, 255, 255);
//		break;
//	case 4://80~100 ��ɫ
//		glColor3f(0, 0, 255);
//		break;
//	case 5://100 ��ɫ
//		glColor3f(0, 0, 255);
//		break;
//	default:
//		break;
//	}
//
//}
//
//void draw()
//{
//	//������ɫģ��
//	//glShadeModel(GL_FLAT);    //ȡ����ɫ�Ľ��䣬��Ϊ��һ��ɫ
//
//	//glBegin(GL_QUADS);//GL_POLYGON
// //	glColor3f(0, 0, 255);//��ɫ
// //	glVertex3f(5, 5, 0);
// //	glColor3f(0, 255, 0);//��ɫ
// //	glVertex3f(0.0, -5, 0);
// //	glColor3f(0, 255, 255);//��ɫ
// //	glVertex3f(-10, 0.0, 0);
// //	glColor3f(255, 255, 0);//��ɫ
// //	glVertex3f(-5, 5, 0);
//	//glFlush();
//	//glEnd();
//
//	glColor3f(0, 0, 0);//��ɫ
//	glBegin(GL_QUADS);
//	int size = tem1.size();
//	for (int i = 0; i < size; i++)
//	{
//		setRecColor(tem1[i][3]);
//		glVertex3f(tem1[i][0], tem1[i][1], tem1[i][2]);
//
//	}
//	size = tem2.size();
//	for (int i = 0; i < size; i++)
//	{
//		setRecColor(tem2[i][3]);
//		glVertex3f(tem2[i][0], tem2[i][1], tem2[i][2]);
//
//	}
//	glEnd();
//
//	glColor3f(0, 0, 0);//��ɫ
//	glBegin(GL_LINES);
//	size = tem1.size();
//	for (int i = 0; i < size; i++)
//	{
//		glVertex3f(tem1[i][0], tem1[i][1], tem1[i][2]);
//		glVertex3f(tem1[(i + 1) % size][0], tem1[(i + 1) % size][1], tem1[(i + 1) % size][2]);
//	}
//	size = tem2.size();
//	for (int i = 0; i < size; i++)
//	{
//		glVertex3f(tem2[i][0], tem2[i][1], tem2[i][2]);
//		glVertex3f(tem2[(i + 1) % size][0], tem2[(i + 1) % size][1], tem2[(i + 1) % size][2]);
//	}
//	glEnd();
//
//	glColor3f(0, 0, 0);//��ɫ
//	glBegin(GL_LINES);
//
//	vector<vector<double>> tem3;
//	bool isExist;
//	tem3 = getline(tem1, 15, isExist);
//	size = tem3.size();
//	if (isExist)
//	{
//		for (int i = 0; i < size-1; i++)
//		{
//			glVertex3f(tem3[i][0], tem3[i][1], tem3[i][2]);
//			glVertex3f(tem3[(i + 1) % size][0], tem3[(i + 1) % size][1], tem3[(i + 1) % size][2]);
//		}
//	}
//	glEnd();
//
//}
//
///* ��ʾ
//*/
//void display_func()
//{
//	static int z = 0;
//	std::cout << "display: " << z++ << std::endl;
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadMatrixf(modelview_matrix);
//
//	draw();
//	//xyz_line(5.0);
//
//	glutSwapBuffers();
//}
//
///* OpenGL ��ʼ��
//*/
//void init()
//{
//	// projection matrix init
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(20.0, 1.0, 10.0, 300.0);
//	// default_matrix, modelview_matrix, modelview_z_dis init
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(100.0 + (x_min + x_max)*.5, 100.0 + (y_min + y_max)*.5, 100.0 + (z_min + z_max)*.5,
//		(x_min + x_max)*.5, (y_min + y_max)*.5, (z_min + z_max)*.5, .0, .0, 1.0);
//	modelview_z_dis = 100.0f * sqrt(3.0f);
//	glGetFloatv(GL_MODELVIEW_MATRIX, default_matrix);
//	memcpy(modelview_matrix, default_matrix, sizeof(default_matrix));
//	glLoadIdentity();
//
//	glClearColor(1.0, 1.0, 1.0, 0.0);
//	glClear(GL_COLOR_BUFFER_BIT);
//}
//
//void reshape_func(int w, int h);
//void display_func();
//void mouse_click_func(int button, int state, int x, int y);
//void mouse_move_func(int x, int y);
//void keyboard_func(unsigned char key, int x, int y);
//void specialkey_func(int key, int x, int y);
//
///*
//*������ڣ�������
//*/
//int main(int argc, char** argv)
//{
//	// glut init
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_MULTISAMPLE | GLUT_DEPTH);
//	glutInitWindowSize(win_w, win_h);
//	glutInitWindowPosition(300, 0);
//	glutCreateWindow("glut test");
//	// The callbacks.
//	glutReshapeFunc(reshape_func);
//	glutDisplayFunc(display_func);
//	glutMouseFunc(mouse_click_func);
//	glutMotionFunc(mouse_move_func);
//	glutKeyboardFunc(keyboard_func);
//	glutSpecialFunc(specialkey_func);
//
//	init();
//	glutMainLoop();
//	return 0;
//}
//
//
//
//// ���ڴ�С�ı����Ӧ����
//void reshape_func(int w, int h)
//{
//	// ���ڴ�С�仯ʱ���岢�����ţ��Է�ֹ����ʧ��
//	glViewport(0, h - win_w, win_w, win_h);
//}
//
///* ���������������������ƽ�ơ���ת�����ţ����Ǿ����Ӿ�(����)�����½���
//* �������� glTranslate,glRotate,glScale �����ھֲ������½���(������)
//* Ϊ�˴ﵽ���Ӿ������²�����Ч������Ҫ��������˵���ǰ����
//*/
//void absolute_translate(GLfloat x, GLfloat y, GLfloat z)
//{
//	glMatrixMode(GL_MODELVIEW);
//	glPushMatrix();
//	glLoadIdentity();
//	glTranslatef(x, y, z);
//	glMultMatrixf(modelview_matrix); // ʹ�任������˵���ǰ�����������ʺϾ�������Ŀ���
//	glGetFloatv(GL_MODELVIEW_MATRIX, modelview_matrix);
//	glPopMatrix();
//}
//
//void absolute_rotate(GLfloat dgree, GLfloat vecx, GLfloat vecy, GLfloat vecz)
//{
//	glMatrixMode(GL_MODELVIEW);
//	glPushMatrix();
//	glLoadIdentity();
//	glTranslatef(.0, .0, -modelview_z_dis);		// ƽ�ƻ�ȥ��ע��þ�ͺ�����Ҫ��������
//	glRotatef(dgree, vecx, vecy, vecz);// ������ת��
//	glTranslatef(.0, .0, modelview_z_dis);		// ��ƽ�Ƶ�ԭ��
//	glMultMatrixf(modelview_matrix); // ʹ�任������˵���ǰ�����������ʺϾ�������Ŀ���
//	glGetFloatv(GL_MODELVIEW_MATRIX, modelview_matrix);
//	glPopMatrix();
//}
//
//void absolute_scale(GLfloat factor)
//{
//	glMatrixMode(GL_MODELVIEW);
//	glPushMatrix();
//	glLoadIdentity();
//	glTranslatef(.0, .0, -modelview_z_dis);		// ƽ�ƻ�ȥ��ע��þ�ͺ�����Ҫ��������
//	glScalef(factor, factor, factor);
//	glTranslatef(.0, .0, modelview_z_dis);		// ��ƽ�Ƶ�ԭ��
//	glMultMatrixf(modelview_matrix); // ʹ�任������˵���ǰ�����������ʺϾ�������Ŀ���
//	glGetFloatv(GL_MODELVIEW_MATRIX, modelview_matrix);
//	glPopMatrix();
//}
//
//void absolute_default()
//{
//	memcpy(modelview_matrix, default_matrix, sizeof(default_matrix));
//}
//
//// ���״̬������������������¼����϶��¼�֮��ͨ��
//static bool l_button_down = false, r_button_down = false, mid_button_down = false;
//static int last_x = -1, last_y = -1;
//#define  GLUT_WHEEL_UP		3 // ���ֲ���  
//#define  GLUT_WHEEL_DOWN	4
///* ��������ƶ�������϶���ת���м��϶�ƽ�ƣ��Ҽ��ص������ͼ
//
//*/
//void mouse_click_func(int button, int state, int x, int y)
//{
//	y = win_h - y;
//	switch (button) {
//	case GLUT_LEFT_BUTTON:
//		if (state == GLUT_DOWN) {
//			l_button_down = true;
//			last_x = x; last_y = y;
//			glutSetCursor(GLUT_CURSOR_CROSSHAIR);
//		}
//		else {
//			l_button_down = false;
//			last_x = -1; last_y = -1;
//			glutSetCursor(GLUT_CURSOR_INHERIT);
//		}
//		break;
//	case GLUT_MIDDLE_BUTTON:
//		if (state == GLUT_DOWN) {
//			mid_button_down = true;
//			last_x = x; last_y = y;
//			glutSetCursor(GLUT_CURSOR_CYCLE);
//		}
//		else {
//			mid_button_down = false;
//			last_x = -1; last_y = -1;
//			glutSetCursor(GLUT_CURSOR_INHERIT);
//		}
//		break;
//	case GLUT_RIGHT_BUTTON:
//		if (state == GLUT_DOWN) {
//			r_button_down = true;
//			absolute_default();
//			glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
//			glutPostRedisplay();
//		}
//		else {
//			r_button_down = false;
//			glutSetCursor(GLUT_CURSOR_INHERIT);
//		}
//		break;
//	case GLUT_WHEEL_DOWN:
//		if (state == GLUT_UP) {
//			absolute_scale(.9f);
//			glutPostRedisplay();
//		}
//		break;
//	case GLUT_WHEEL_UP:
//		if (state == GLUT_UP) {
//			absolute_scale(1.1f);
//			glutPostRedisplay();
//		}
//		break;
//	}
//}
//
//void mouse_move_func(int x, int y)
//{
//	y = win_h - y;
//	if (last_x >= 0 && last_y >= 0 && (last_x != x || last_y != y)) {
//		GLfloat deltax = GLfloat(x - last_x), deltay = GLfloat(y - last_y);
//		if (mid_button_down) {
//			absolute_translate(deltax * .1f, deltay * .1f, .0f);
//			glutPostRedisplay();
//		}
//		else if (l_button_down) {
//			GLfloat dis = sqrt(deltax*deltax + deltay*deltay);
//			absolute_rotate(dis, -deltay / dis, deltax / dis, .0);
//			glutPostRedisplay();
//		}
//	}
//	last_x = x; last_y = y;
//}
//
///* ���̰���
//
//*/
//void keyboard_func(unsigned char key, int x, int y)
//{
//	//�����
//	;
//}
//
///* ��������������¼�����������ת�����Ҽ�����������ת
//
//*/
//void specialkey_func(int key, int x, int y)
//{
//	GLfloat deltax = .0, deltay = .0;
//	switch (key) {
//	case GLUT_KEY_UP:
//		deltay += 1.0;
//		break;
//	case GLUT_KEY_DOWN:
//		deltay -= 1.0;
//		break;
//	case GLUT_KEY_LEFT:
//		deltax -= 1.0;
//		break;
//	case GLUT_KEY_RIGHT:
//		deltax += 1.0;
//		break;
//	}
//	if (abs(deltax) > .0 || abs(deltay) > .0) {
//		GLfloat dis = sqrt(deltax*deltax + deltay*deltay);
//		absolute_rotate(dis, -deltay / dis, deltax / dis, .0);
//		glutPostRedisplay();
//	}
//}