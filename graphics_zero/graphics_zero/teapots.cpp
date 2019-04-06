//#include <stdlib.h>
//#include <iostream>
//#include <Windows.h>
//#include <math.h>
//#include <vector>
//#include "glut.h"
//using namespace std;
//
//const int win_w = 700, win_h = 700;
//GLfloat default_matrix[16];
//GLfloat modelview_matrix[16];
//GLfloat modelview_z_dis;
//GLfloat x_min = .0, x_max = 20.0, y_min = .0, y_max = 20.0, z_min = .0, z_max = 20.0;
//GLfloat position[] = { 50.0, 50.0, 75.0, 0.0 };//光源位置
//GLfloat mat[4] = { 0.2,0.2,0.9 };
//
///* 显示
//*/
//void display_func()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadMatrixf(modelview_matrix);
//
//
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
//
//	glLightfv(GL_LIGHT0, GL_POSITION, position);
//
//	glutSolidTeapot(10);
//
//	glutSwapBuffers();
//}
//
//
//void init()
//{
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(20.0, 1.0, 10.0, 300.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	//gluLookAt(100.0 + (x_min + x_max)*0.5, 100.0 + (y_min + y_max)*0.5, 100.0 + (z_min + z_max)*0.5,
//	//	(x_min + x_max)*0.5, (y_min + y_max)*0.5, (z_min + z_max)*0.5, 0.0, 0.0, 1.0);
//	gluLookAt(100.0 + (x_min + x_max)*0.5, 100.0 + (y_min + y_max)*0.5, 100.0 + (z_min + z_max)*0.5,
//		0, 0, 0, 0.0, 1.0, 0.0);
//	modelview_z_dis = 100.0f * sqrt(3.0f);
//	glGetFloatv(GL_MODELVIEW_MATRIX, default_matrix);
//	memcpy(modelview_matrix, default_matrix, sizeof(default_matrix));
//	glLoadIdentity();
//
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	GLfloat ambient[] = {0.0, 0.0, 0.0, 1.0};
//	GLfloat diffuse[] = {1.0, 1.0, 1.0, 1.0};
//	GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
//	
//	GLfloat lmodel_ambient[] = {0.2, 0.2, 0.2, 1.0};
//	GLfloat local_view[] = {0.0};
//	
//	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
//	glLightfv(GL_LIGHT0, GL_POSITION, position);
//	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
//	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
//	
//	glFrontFace(GL_CW);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_AUTO_NORMAL);
//	glEnable(GL_NORMALIZE);
//	glEnable(GL_DEPTH_TEST);
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
//*函数入口，主函数
//*/
//int main(int argc, char** argv)
//{
//	// glut init
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_MULTISAMPLE | GLUT_DEPTH);
//	glutInitWindowSize(win_w, win_h);
//	glutInitWindowPosition(300, 0);
//	glutCreateWindow("glut");
//	// The callbacks.
//
//	init();
//	glutReshapeFunc(reshape_func);
//	glutDisplayFunc(display_func);
//	glutMouseFunc(mouse_click_func);
//	glutMotionFunc(mouse_move_func);
//	glutKeyboardFunc(keyboard_func);
//	glutSpecialFunc(specialkey_func);
//
//	glutMainLoop();
//	return 0;
//}
//
//
//
//// 窗口大小改变的响应函数
//void reshape_func(int w, int h)
//{
//	// 窗口大小变化时物体并不缩放，以防止比例失调
//	glViewport(0, h - win_w, win_w, win_h);
//}
//
///* 以下三个函数对物体进行平移、旋转、缩放，他们均在视觉(绝对)坐标下进行
//* 正常调用 glTranslate,glRotate,glScale 均是在局部坐标下进行(按正序看)
//* 为了达到在视觉坐标下操作的效果，需要将矩阵左乘到当前矩阵
//*/
//void absolute_translate(GLfloat x, GLfloat y, GLfloat z)
//{
//	glMatrixMode(GL_MODELVIEW);
//	glPushMatrix();
//	glLoadIdentity();
//	glTranslatef(x, y, z);
//	glMultMatrixf(modelview_matrix); // 使变换矩阵左乘到当前矩阵，这样才适合绝对坐标的考虑
//	glGetFloatv(GL_MODELVIEW_MATRIX, modelview_matrix);
//	glPopMatrix();
//}
//
//void absolute_rotate(GLfloat dgree, GLfloat vecx, GLfloat vecy, GLfloat vecz)
//{
//	glMatrixMode(GL_MODELVIEW);
//	glPushMatrix();
//	glLoadIdentity();
//	glTranslatef(.0, .0, -modelview_z_dis);		// 平移回去，注意该句和后两句要倒序来看
//	glRotatef(dgree, vecx, vecy, vecz);// 积累旋转量
//	glTranslatef(.0, .0, modelview_z_dis);		// 先平移到原点
//	glMultMatrixf(modelview_matrix); // 使变换矩阵左乘到当前矩阵，这样才适合绝对坐标的考虑
//	glGetFloatv(GL_MODELVIEW_MATRIX, modelview_matrix);
//	glPopMatrix();
//}
//
//void absolute_scale(GLfloat factor)
//{
//	glMatrixMode(GL_MODELVIEW);
//	glPushMatrix();
//	glLoadIdentity();
//	glTranslatef(.0, .0, -modelview_z_dis);		// 平移回去，注意该句和后两句要倒序来看
//	glScalef(factor, factor, factor);
//	glTranslatef(.0, .0, modelview_z_dis);		// 先平移到原点
//	glMultMatrixf(modelview_matrix); // 使变换矩阵左乘到当前矩阵，这样才适合绝对坐标的考虑
//	glGetFloatv(GL_MODELVIEW_MATRIX, modelview_matrix);
//	glPopMatrix();
//}
//
//void absolute_default()
//{
//	memcpy(modelview_matrix, default_matrix, sizeof(default_matrix));
//}
//
//// 鼠标状态变量，用来在鼠标点击事件和拖动事件之间通信
//static bool l_button_down = false, r_button_down = false, mid_button_down = false;
//static int last_x = -1, last_y = -1;
//#define  GLUT_WHEEL_UP		3 // 滚轮操作  
//#define  GLUT_WHEEL_DOWN	4
///* 鼠标点击和移动，左键拖动旋转，中键拖动平移，右键回到最初视图
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
//void keyboard_func(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 99:
//		mat[0] = mat[0]+ 0.2;
//		mat[1] = mat[1] + 0.2;
//		mat[2] = mat[2] + 0.2;
//		mat[0] = mat[0] - int(mat[0]);
//		mat[1] = mat[1] - int(mat[1]);
//		mat[2] = mat[2] - int(mat[2]);
//		break;
//	default:
//		break;
//	}
//	glutPostRedisplay();
//}
//
////键盘特殊键，上下键，左右键
//
//void specialkey_func(int key, int x, int y)
//{
//	switch (key) {
//	case GLUT_KEY_UP:
//		position[0] += 10;
//		break;
//	case GLUT_KEY_DOWN:
//		position[0] -= 10;
//		break;
//	case GLUT_KEY_LEFT:
//		position[1] += 10;
//		break;
//	case GLUT_KEY_RIGHT:
//		position[1] -= 10;
//		break;
//	}
//	glutPostRedisplay();
//}