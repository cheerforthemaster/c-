//#include <stdlib.h>
//#include"glut.h"
//#include <math.h>
//#include<memory> 
//using namespace std;
//   
//static float c = 3.1415 / 180.0f; //���ȺͽǶ�ת������ 
//static int du = 90, oldmy = -1, oldmx = -1; //du���ӵ���y��ĽǶ�,opengl��Ĭ��y�����Ϸ��� 
//static float r = 1.5f, h = 0.0f; //r���ӵ���y��İ뾶,h���ӵ�߶ȼ���y���ϵ����� 
//   
//   /* ���Ƶ������ */
//GLfloat ctrlpoints[4][4][3] = {
//	{ { -1.5, -1.5, 2.0 },
//	{ -0.5, -1.5, 2.0 },
//	{ 0.5, -1.5, -1.0 },
//	{ 1.5, -1.5, 2.0 }
//	},
//
//	{ { -1.5, -0.5, 1.0 },
//	{ -0.5, 1.5, 2.0 },
//	{ 0.5, 0.5, 1.0 },
//	{ 1.5, -0.5, -1.0 } },
//
//	{ { -1.5, 0.5, 2.0 },
//	{ -0.5, 0.5, 1.0 },
//	{ 0.5, 0.5, 3.0 },
//	{ 1.5, -1.5, 1.5 } },
//
//	{ { -1.5, 1.5, -2.0 },
//	{ -0.5, 1.5, -2.0 },
//	{ 0.5, 0.5, 1.0 },
//	{ 1.5, 1.5, -1.0 } }
//};
//   
//void init(void)
//{
//	//����ɫ
//	glClearColor(0.0, 0.0, 0.0, 1.0);
//	//�����Ƶ�����ӳ��Ϊ��������
//	//����1��GL_MAP1_VERTEX_3��3ά������
//	//����2��3�����Ʋ���u��ȡֵ��Χ[0, 1]
//	//����4��x����Ԫ�ؼ�Ĳ���Ϊ3��GLfloat
//	//����5��x�������߼�Ĳ���Ϊ4�����Ƶ㡪��������4�����Ƶ�ȷ��
//	//����6-7�����Ʋ���v��ȡֵ��Χ[0, 1]
//	//����8��y����Ԫ�ؼ�Ĳ���Ϊ12��GLfloatԪ��
//	//����9��y����ÿ�����ߵĿ��Ƶ�����Ϊ4
//	//ע��: ������������������ز�����������ctrlpoints���ݸ������߲���
//	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &ctrlpoints[0][0][0]);
//	//�����άӳ��
//	glEnable(GL_MAP2_VERTEX_3);
//	//��άӳ�䣺x��y����U��V�Ĳ���[0, 1]�����м��ֵ����Ϊ��20��
//	glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
//	//������Ȳ���
//	glEnable(GL_DEPTH_TEST);
//   
//	//���뿪��2�����÷�����
//	glEnable(GL_BLEND);
//	glEnable(GL_LINE_SMOOTH);
//	glHint(GL_LINE_SMOOTH_HINT, GL_FASTEST);  // Antialias the lines
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//}
//   
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glLoadIdentity();
//	gluLookAt(r*cos(c*du), h, r*sin(c*du), 0, 0, 0, 0, 1, 0); //���ӵ㿴Զ��,y�᷽��(0,1,0)���Ϸ��� 
//	glColor3f(0.0, 1.0, 0.0);
//	glPushMatrix();
//	//���뿪��1��ȥ��ע�Ͳ鿴Ч����������ת�ǶȲ������鿴Ч��
//	//glRotatef(0.1, 1.0, 1.0, 1.0);
//	int i, j;
//	//����2D�������꣬�Դӿ��Ƶ������ֵȷ�����������Ӧ�ĵ㼯����Ӧ������
//	for (j = 0; j <= 8; j++) {
//   		glBegin(GL_LINE_STRIP);
//   		for (i = 0; i <= 30; i++)
//   			glEvalCoord2f((GLfloat)i / 30.0, (GLfloat)j / 8.0);  //�̶�y����ʱx�������������
//   		glEnd();
//   
//   		glBegin(GL_LINE_STRIP);
//   		for (i = 0; i <= 30; i++)
//   			glEvalCoord2f((GLfloat)j / 8.0, (GLfloat)i / 30.0);  //�̶�x����ʱy�������������     
//   		glEnd();
//	}
//   
//   	//�鿴������ȷ���Ĳ�ֵ��(u, v)��λ��
//   	/*glColor3f(1, 0, 0);
//   	glBegin(GL_POINTS);
//   	for (j = 0; j <= 8; j++) {
//   		for (i = 0; i <= 30; i++)
//   			glVertex3f((GLfloat)i / 30.0, (GLfloat)j / 8.0, 0);
//   		for (i = 0; i <= 30; i++)
//   			glVertex3f((GLfloat)j / 8.0, (GLfloat)i / 30.0, 0);
//   	}*/
//	glEnd();
//	glPopMatrix();
//	glutSwapBuffers();
//}
//   
//void reshape(GLsizei w, GLsizei h)
//{
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	if (w <= h)
//		glOrtho(-5.0, 5.0, -5.0*(GLfloat)h / (GLfloat)w, 5.0*(GLfloat)h / (GLfloat)w, -5.0, 5.0);
//	else
//		glOrtho(-5.0*(GLfloat)w / (GLfloat)h, 5.0*(GLfloat)w / (GLfloat)h, -5.0, 5.0, -5.0, 5.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//   
//void keyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 'x':
//	case 'X':
//	case 27:   //ESC��
//   		exit(0);
//   		break;
//	default:
//   		break;
//	}
//}
//   
//void Mouse(int button, int state, int x, int y) //��������� 
//{
//   	if (state == GLUT_DOWN) //��һ����갴��ʱ,��¼����ڴ����еĳ�ʼ���� 
//   		oldmx = x, oldmy = y;
//}
//void onMouseMove(int x, int y) //��������϶� 
//{
//   	printf("%d\n",du); 
//   	du += x - oldmx; //����ڴ���x�᷽���ϵ������ӵ��ӵ���y��ĽǶ��ϣ�����������ת�� 
//   	h += 0.03f*(y - oldmy); //����ڴ���y�᷽���ϵĸı�ӵ��ӵ��y�����ϣ�������ת�� 
//   	if (h > 1.0f) h = 1.0f; //�ӵ�y������һЩ���ƣ�����ʹ�ӵ�̫��� 
//   	else if (h < -1.0f) h = -1.0f;
//   	oldmx = x, oldmy = y; //�Ѵ�ʱ�����������Ϊ��ֵ��Ϊ��һ�μ���������׼�� 
//}
//
//void ProcessSpecialKeys(int key, int x, int y)
//{
//	if (key == GLUT_KEY_UP)
//	{
//		glScalef(2, 2, 2);
//	}
//	if (key == GLUT_KEY_DOWN)
//	{
//		glScalef(0.9, 0.9, 0.9);
//	}
//	display();
//}
//   
//int main(int argc, char** argv)
//{
//   	//srand((unsigned int)time(0));
//   	glutInit(&argc, argv);
//   	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//ʹ��˫����ģʽ����Ȼ���
//   	glutInitWindowSize(800, 800);
//   	glutInitWindowPosition(0, 0);
//   	glutCreateWindow("Bezier�����߿�ģ��");
//   	init();
//   	glutDisplayFunc(display);
//   	glutReshapeFunc(reshape);
//   	glutKeyboardFunc(keyboard);
//   	glutIdleFunc(display);//���ÿ���ʱ���õĺ���
//   	glutMouseFunc(Mouse);
//   	glutMotionFunc(onMouseMove);
//	glutSpecialFunc(ProcessSpecialKeys);
//   	glutMainLoop();
//   	return 0;
//}