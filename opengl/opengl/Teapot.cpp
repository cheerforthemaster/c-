 //#include "glut.h"
 //#include <math.h>
 //
 //using namespace std;
 // 
 //static float c = 3.1415 / 180.0f; //���ȺͽǶ�ת������ 
 //static int du = 90, oldmy = -1, oldmx = -1; //du���ӵ���y��ĽǶ�,opengl��Ĭ��y�����Ϸ��� 
 //static float r = 1.5f, h = 0.0f; //r���ӵ���y��İ뾶,h���ӵ�߶ȼ���y���ϵ����� 
 //
 // void init(void)
 // {
 //	glEnable(GL_DEPTH_TEST);
 // 	glClearColor(0.0, 0.0, 0.0, 0.0); //������ɫ
 // }
 // 
 // void display(void)
 // {
 //	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 // 	glColor3f(1.0, 1.0, 1.0); //���ʰ�ɫ
 // 
 // 	glLoadIdentity();  //���ص�λ����
 //	gluLookAt(r*cos(c*du), h, r*sin(c*du), 0, 0, 0, 0, 1, 0); //���ӵ㿴Զ��,y�᷽��(0,1,0)���Ϸ��� 
 //	glutWireTeapot(0.5);
 //	
 //	glFlush();
 // 	glutSwapBuffers();
 // }
 // 
 // void Mouse(int button, int state, int x, int y) //��������� 
 // {
 //	 if (state == GLUT_DOWN) //��һ����갴��ʱ,��¼����ڴ����еĳ�ʼ���� 
 //		 oldmx = x, oldmy = y;
 // }
 // void onMouseMove(int x, int y) //��������϶� 
 // {
 //	 printf("%d\n",du); 
 //	 du += x - oldmx; //����ڴ���x�᷽���ϵ������ӵ��ӵ���y��ĽǶ��ϣ�����������ת�� 
 //	 h += 0.03f*(y - oldmy); //����ڴ���y�᷽���ϵĸı�ӵ��ӵ��y�����ϣ�������ת�� 
 //	 if (h > 1.0f) h = 1.0f; //�ӵ�y������һЩ���ƣ�����ʹ�ӵ�̫��� 
 //	 else if (h < -1.0f) h = -1.0f;
 //	 oldmx = x, oldmy = y; //�Ѵ�ʱ�����������Ϊ��ֵ��Ϊ��һ�μ���������׼�� 
 // }
 //
 //  void reshape(int w, int h)
 //  {
 //  	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
 //  	glMatrixMode(GL_PROJECTION);
 //  	glLoadIdentity();
 //  	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
 //  	glMatrixMode(GL_MODELVIEW);
 //  	glLoadIdentity();
 // 	gluLookAt(r*cos(c*du), h, r*sin(c*du), 0, 0, 0, 0, 1, 0); //���ӵ㿴Զ��,y�᷽��(0,1,0)���Ϸ��� 
 //  }
 // 
 // void reshape(GLsizei w, GLsizei h)
 // {
 //	 glViewport(0, 0, w, h);
 //	 glMatrixMode(GL_PROJECTION);
 //	 glLoadIdentity();
 //	 gluPerspective(75.0f, (float)w / h, 1.0f, 1000.0f);
 //	 glMatrixMode(GL_MODELVIEW);
 // }
 //
 // int main(int argc, char** argv)
 // {
 // 	glutInit(&argc, argv);
 // 	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 // 	glutInitWindowSize(500, 500);
 // 	glutInitWindowPosition(100, 100);
 // 	glutCreateWindow(argv[0]);
 // 	init();
 // 	glutReshapeFunc(reshape);
 // 	glutDisplayFunc(display);
 //	glutIdleFunc(display);  //���ò��ϵ�����ʾ���� 
 //	glutMouseFunc(Mouse);
 //	glutMotionFunc(onMouseMove);
 // 	glutMainLoop();
 // 	return 0;
 // }
