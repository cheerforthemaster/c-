// #include"glut.h"
// #include <stdlib.h>
// #include <math.h>
// using namespace std;
// 
// 
// static float c = 3.1415 / 180.0f; //���ȺͽǶ�ת������ 
// static int du = 90, oldmy = -1, oldmx = -1; //du���ӵ���y��ĽǶ�,opengl��Ĭ��y�����Ϸ��� 
// static float r = 1.5f, h = 0.0f; //r���ӵ���y��İ뾶,h���ӵ�߶ȼ���y���ϵ����� 
// 
// void display(void)
// {
// 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// 
// 	//printf("At:%.2f %.2f %.2f\n",r*cos(c*du),h,r*sin(c*du)); //������ӵ������ 
// 	glLoadIdentity();
// 	gluLookAt(r*cos(c*du), h, r*sin(c*du), 0, 0, 0, 0, 1, 0); //���ӵ㿴Զ��,y�᷽��(0,1,0)���Ϸ��� 
// 
// 	glColor3f(1.0f, 0.0f, 0.0f);
// 	glutWireTeapot(0.5f);
// 
// 	glFlush();
// 	glutSwapBuffers();
// }
// void Mouse(int button, int state, int x, int y) //��������� 
// {
// 	if (state == GLUT_DOWN) //��һ����갴��ʱ,��¼����ڴ����еĳ�ʼ���� 
// 		oldmx = x, oldmy = y;
// }
// void onMouseMove(int x, int y) //��������϶� 
// {
// 	//printf("%d\n",du); 
// 	du += x - oldmx; //����ڴ���x�᷽���ϵ������ӵ��ӵ���y��ĽǶ��ϣ�����������ת�� 
// 	h += 0.03f*(y - oldmy); //����ڴ���y�᷽���ϵĸı�ӵ��ӵ��y�����ϣ�������ת�� 
// 	if (h > 1.0f) h = 1.0f; //�ӵ�y������һЩ���ƣ�����ʹ�ӵ�̫��� 
// 	else if (h < -1.0f) h = -1.0f;
// 	oldmx = x, oldmy = y; //�Ѵ�ʱ�����������Ϊ��ֵ��Ϊ��һ�μ���������׼�� 
// }
// void init()
// {
// 	glEnable(GL_DEPTH_TEST);
// }
// void reshape(int w, int h)
// {
// 	glViewport(0, 0, w, h);
// 	glMatrixMode(GL_PROJECTION);
// 	glLoadIdentity();
// 	gluPerspective(75.0f, (float)w / h, 1.0f, 1000.0f);
// 	glMatrixMode(GL_MODELVIEW);
// }
// int main(int argc, char *argv[])
// {
// 	glutInit(&argc, argv);
// 	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
// 	glutInitWindowPosition(100, 100);
// 	glutInitWindowSize(400, 400);
// 	glutCreateWindow("OpenGL");
// 	init();
// 	glutReshapeFunc(reshape);
// 	glutDisplayFunc(display);
// 	glutIdleFunc(display);  //���ò��ϵ�����ʾ���� 
// 	glutMouseFunc(Mouse);
// 	glutMotionFunc(onMouseMove);
// 	glutMainLoop();
// 	return 0;
// }