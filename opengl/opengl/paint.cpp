 //#include "glut.h"
 //#include <iostream>
 //#include <vector>
 //using namespace std;
 //
 //static float c = 3.1415 / 180.0f; //���ȺͽǶ�ת������ 
 //static int du = 90, oldmy = -1, oldmx = -1; //du���ӵ���y��ĽǶ�,opengl��Ĭ��y�����Ϸ��� 
 //static float r = 1.5f, h = 0.0f; //r���ӵ���y��İ뾶,h���ӵ�߶ȼ���y���ϵ����� 
 //
 //vector<vector<double>> tem1 = {
 //	{ 0, 0, -0.00400272, -1 },
 //	{ 1, 0, -0.00514855, -1 },
 //	{ 0, 1.07113, -0.00430214, -1 },
 //	{ 1, 1.07113, -0.00550055, -1 }
 //};
 //
 //vector<vector<double>> tem2 = {
 //	{ 1, 0, -0.00514855, -1 },
 //	{ 1, 1.07113, -0.00550055, -1 },
 //	{ 2, 0, -0.00692827, -1 },
 //	{ 2, 1.07113, -0.00725252, -1 }
 //};
 //
 //void init(void)
 //{
 //	//������Ȳ���
 //	glEnable(GL_DEPTH_TEST);
 //	//�����άӳ��
 //	glEnable(GL_MAP2_VERTEX_3);
 //
 //	//���뿪��2�����÷�����
 //	glEnable(GL_BLEND);
 //	glEnable(GL_LINE_SMOOTH);
 //	glHint(GL_LINE_SMOOTH_HINT, GL_FASTEST);  // Antialias the lines
 //	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 //}
 //
 //void myDisplay(void)
 //{
 //	//������ɫģ��
 //	//glShadeModel(GL_FLAT);    //ȡ����ɫ�Ľ��䣬��Ϊ��һ��ɫ
 //	//glLoadIdentity();
	//glClearColor(0.0, 0.0, 0.0, 0.0);
 //	glClear(GL_COLOR_BUFFER_BIT);
	//glLoadIdentity();  //���ص�λ����
 //	gluLookAt(r*cos(c*du), h, r*sin(c*du), 0, 0, 0, 0, 1, 0); //���ӵ㿴Զ��,y�᷽��(0,1,0)���Ϸ��� 
 //
 //	glBegin(GL_TRIANGLE_FAN);
 //
 //	glColor3f(0, 0, 255);//��ɫ
 //	glVertex3f(0.5, 0.5, 0);
 //	glColor3f(0, 255, 0);//��ɫ
 //	glVertex3f(0.0, -0.5, 0);
 //	glColor3f(0, 255, 255);//��ɫ
 //	glVertex3f(-1.0, 0.0, 0);
 //	glColor3f(255, 255, 0);//��ɫ
 //	glVertex3f(-0.5, 0.5, 0);
 //
	//glFlush();
 //	glEnd();
	//glutSwapBuffers();
 //
 //}
 //
 //void ProcessSpecialKeys(int key, int x, int y)//up��
 //{
 //	if (key == GLUT_KEY_UP)
 //	{
 //		glScalef(1.1, 1.1, 1.1);
 //	}
 //	if (key == GLUT_KEY_DOWN)
 //	{
 //		glScalef(0.9, 0.9, 0.9);
 //	}
	////glFlush();
 //	//myDisplay();
 //}
 //
 //void Mouse(int button, int state, int x, int y) //��������� 
 //{
 //	if (state == GLUT_DOWN) //��һ����갴��ʱ,��¼����ڴ����еĳ�ʼ���� 
 //		oldmx = x, oldmy = y;
 //}
 //void onMouseMove(int x, int y) //��������϶� 
 //{
 //	//printf("%d\n",du); 
 //	du += x - oldmx; //����ڴ���x�᷽���ϵ������ӵ��ӵ���y��ĽǶ��ϣ�����������ת�� 
 //	h += 0.03f*(y - oldmy); //����ڴ���y�᷽���ϵĸı�ӵ��ӵ��y�����ϣ�������ת�� 
 //	if (h > 1.0f) h = 1.0f; //�ӵ�y������һЩ���ƣ�����ʹ�ӵ�̫��� 
 //	else if (h < -1.0f) h = -1.0f;
 //	oldmx = x, oldmy = y; //�Ѵ�ʱ�����������Ϊ��ֵ��Ϊ��һ�μ���������׼�� 
 //}

 //void reshape(GLsizei w, GLsizei h)
 //{
	// glViewport(0, 0, w, h);
	// glMatrixMode(GL_PROJECTION);
	// glLoadIdentity();
	// gluPerspective(75.0f, (float)w / h, 1.0f, 1000.0f);
	// glMatrixMode(GL_MODELVIEW);
 //}

 //int main(int argc, char *argv[])
 //{
 //	glutInit(&argc, argv);   //��ʼ��GLUT
 //	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_SINGLE);
 //	glutInitWindowPosition(500, 200);
 //	glutInitWindowSize(600, 600);
 //	init();
 //	glutCreateWindow("OpenGL");
	//glutReshapeFunc(reshape);
 //	glutDisplayFunc(&myDisplay);   //�ص����� 
	//glutIdleFunc(myDisplay);  //���ò��ϵ�����ʾ���� 
 //	glutMouseFunc(Mouse);
 //	glutMotionFunc(onMouseMove);
 //	glutSpecialFunc(ProcessSpecialKeys);
 //	glutMainLoop();    //������ʾ�������ڸı�����»���ͼ��
 //	return 0;
 //}