 //#include "glut.h"
 //#include <iostream>
 //#include <vector>
 //using namespace std;
 //
 //static float c = 3.1415 / 180.0f; //弧度和角度转换参数 
 //static int du = 90, oldmy = -1, oldmx = -1; //du是视点绕y轴的角度,opengl里默认y轴是上方向 
 //static float r = 1.5f, h = 0.0f; //r是视点绕y轴的半径,h是视点高度即在y轴上的坐标 
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
 //	//允许深度测试
 //	glEnable(GL_DEPTH_TEST);
 //	//允许二维映射
 //	glEnable(GL_MAP2_VERTEX_3);
 //
 //	//代码开关2：启用反走样
 //	glEnable(GL_BLEND);
 //	glEnable(GL_LINE_SMOOTH);
 //	glHint(GL_LINE_SMOOTH_HINT, GL_FASTEST);  // Antialias the lines
 //	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 //}
 //
 //void myDisplay(void)
 //{
 //	//设置着色模型
 //	//glShadeModel(GL_FLAT);    //取消颜色的渐变，改为单一颜色
 //	//glLoadIdentity();
	//glClearColor(0.0, 0.0, 0.0, 0.0);
 //	glClear(GL_COLOR_BUFFER_BIT);
	//glLoadIdentity();  //加载单位矩阵
 //	gluLookAt(r*cos(c*du), h, r*sin(c*du), 0, 0, 0, 0, 1, 0); //从视点看远点,y轴方向(0,1,0)是上方向 
 //
 //	glBegin(GL_TRIANGLE_FAN);
 //
 //	glColor3f(0, 0, 255);//蓝色
 //	glVertex3f(0.5, 0.5, 0);
 //	glColor3f(0, 255, 0);//绿色
 //	glVertex3f(0.0, -0.5, 0);
 //	glColor3f(0, 255, 255);//青色
 //	glVertex3f(-1.0, 0.0, 0);
 //	glColor3f(255, 255, 0);//黄色
 //	glVertex3f(-0.5, 0.5, 0);
 //
	//glFlush();
 //	glEnd();
	//glutSwapBuffers();
 //
 //}
 //
 //void ProcessSpecialKeys(int key, int x, int y)//up键
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
 //void Mouse(int button, int state, int x, int y) //处理鼠标点击 
 //{
 //	if (state == GLUT_DOWN) //第一次鼠标按下时,记录鼠标在窗口中的初始坐标 
 //		oldmx = x, oldmy = y;
 //}
 //void onMouseMove(int x, int y) //处理鼠标拖动 
 //{
 //	//printf("%d\n",du); 
 //	du += x - oldmx; //鼠标在窗口x轴方向上的增量加到视点绕y轴的角度上，这样就左右转了 
 //	h += 0.03f*(y - oldmy); //鼠标在窗口y轴方向上的改变加到视点的y坐标上，就上下转了 
 //	if (h > 1.0f) h = 1.0f; //视点y坐标作一些限制，不会使视点太奇怪 
 //	else if (h < -1.0f) h = -1.0f;
 //	oldmx = x, oldmy = y; //把此时的鼠标坐标作为旧值，为下一次计算增量做准备 
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
 //	glutInit(&argc, argv);   //初始化GLUT
 //	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_SINGLE);
 //	glutInitWindowPosition(500, 200);
 //	glutInitWindowSize(600, 600);
 //	init();
 //	glutCreateWindow("OpenGL");
	//glutReshapeFunc(reshape);
 //	glutDisplayFunc(&myDisplay);   //回调函数 
	//glutIdleFunc(myDisplay);  //设置不断调用显示函数 
 //	glutMouseFunc(Mouse);
 //	glutMotionFunc(onMouseMove);
 //	glutSpecialFunc(ProcessSpecialKeys);
 //	glutMainLoop();    //持续显示，当窗口改变会重新绘制图形
 //	return 0;
 //}