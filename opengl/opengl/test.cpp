//void myDisplay()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glRectf(-0.5, -0.5, 0.5, 0.5);
//	glFlush();
//}
//
//int main(int argc,char*argv[])
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(400, 400);
//	glutCreateWindow("第一个opengl程序！");
//	glutDisplayFunc(&myDisplay);
//	glutMainLoop();
//	return 0;
//}

//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//}
//
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//
//	//glShadeModel(GL_FLAT);
//
//	glBegin(GL_POLYGON);
//
//	//glShadeModel(GL_FLAT);
//
//	glColor3f(1.0, 1.0, 1.0);
//	glVertex3f(0.0, 0.0, 0.0);
//
//	glColor3f(1.0, 1.0, 0.0);
//	glVertex3f(0.0, 1.0, 0.0);
//
//	glColor3f(0.0, 1.0, 1.0);
//	glVertex3f(1.0, 1.0, 0.0);
//
//	glColor3f(1.0, 0.0, 1.0);
//	glVertex3f(1.0, 0.0, 0.0);
//
//	//glShadeModel(GL_FLAT);
//
//	glEnd();
//	glFlush();
//
//}
//
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowPosition(500, 300);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("SimplePentage");
//	init();
//	glutDisplayFunc(display);
//	glutMainLoop();
//	return 0;
//}