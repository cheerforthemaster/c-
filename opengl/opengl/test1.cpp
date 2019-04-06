//  #include <stdio.h>
 //  #include <string>
 //  #include <vector>
 //  #include <iostream>
 //  using namespace std;
 //  
 //  //opengl headers!
 //  #include "glew.h"
 //  #include "glut.h"
 //  
 //  #pragma comment(lib,"glew32.lib")
 //  #pragma comment(lib,"glut32.lib")
 //  
 //  //////////////////////////////////////
 //  
 //  enum VAO_IDs { Triangles, NumVAOs };
 //  enum Buffer_IDs { ArrayBuffer, NumBuffers };
 //  enum Attrib_IDs { vPosition = 0 };
 //  GLuint VAOs[NumVAOs];
 //  GLuint Buffers[NumBuffers];
 //  const GLuint NumVertices = 6;
 //  
 //  
 //  GLuint LoadShaders()
 //  {
 //  	//generate shader names
 //  	GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
 //  	GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
 //  
 //  	const char* vertShaderSrc = "#version 330 core \n layout (location = 0)  in vec4 vPosition; layout (location = 1)  in vec4 vColor; out vec4 fs_color; void main(){fs_color = vColor;gl_Position = vPosition;}";
 //  	const char* fragShaderSrc = "#version 330 core \n in vec4 fs_color; out vec4 color; void main(){color = fs_color;}";
 //  	GLint result = GL_FALSE;
 //  	int logLength;
 //  
 //  	//compile vertex shader
 //  	glShaderSource(vertShader, 1, &vertShaderSrc, NULL);
 //  	glCompileShader(vertShader);
 //  	glGetShaderiv(vertShader, GL_COMPILE_STATUS, &result);
 //  	glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &logLength);
 //  	vector<char> vertShaderError(logLength + 1);
 //  	glGetShaderInfoLog(vertShader, logLength, NULL, &vertShaderError[0]);
 //  	cout << &vertShaderError[0] << endl;
 //  
 //  	//compile fragment shader
 //  	glShaderSource(fragShader, 1, &fragShaderSrc, NULL);
 //  	glCompileShader(fragShader);
 //  	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &result);
 //  	glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &logLength);
 //  	vector<char> fragShaderError(logLength + 1);
 //  	glGetShaderInfoLog(fragShader, logLength, NULL, &fragShaderError[0]);
 //  	cout << &fragShaderError[0] << endl;
 //  
 //  	//link the program
 //  	GLuint program = glCreateProgram();
 //  	glAttachShader(program, vertShader);
 //  	glAttachShader(program, fragShader);
 //  
 //  
 //  	glLinkProgram(program);
 //  
 //  	glGetProgramiv(program, GL_LINK_STATUS, &result);
 //  	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
 //  	vector<char> programError(logLength > 1 ? logLength : 1);
 //  	glGetProgramInfoLog(program, logLength, NULL, &programError[0]);
 //  	cout << &programError[0] << endl;
 //  
 //  	glDeleteShader(vertShader);
 //  	glDeleteShader(fragShader);
 //  
 //  	return program;
 //  }
 //  
 //  #define BUFFER_OFFSET(a) ((void*)(a))
 //  
 //  GLuint g_program;
 //  
 //  
 //  void Init()
 //  {
 //  	static const GLfloat vertices[NumVertices][2] =
 //  	{
 //  		{ -0.90, -0.90 }, // Triangle 1
 //  		{ 0.85, -0.90 },
 //  		{ -0.90, 0.85 },
 //  		{ 0.90, -0.85 }, // Triangle 2
 //  		{ 0.90, 0.90 },
 //  		{ -0.85, 0.90 }
 //  	};
 //  	glCreateBuffers(NumBuffers, Buffers);
 //  	glNamedBufferStorage(Buffers[ArrayBuffer], sizeof(vertices),
 //  		vertices, 0);
 //  
 //  	g_program = LoadShaders();
 //  
 //  	glUseProgram(g_program);
 //  
 //  
 //  	glGenVertexArrays(NumVAOs, VAOs);
 //  	glBindVertexArray(VAOs[Triangles]);
 //  	glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
 //  
 //  
 //  	glVertexAttribPointer(vPosition, 2, GL_FLOAT,
 //  		GL_FALSE, 0, BUFFER_OFFSET(0));
 //  	glEnableVertexAttribArray(vPosition);
 //  
 //  }
 //  
 //  float g_fRed = 1.0f;
 //  float g_fGreen = 0.0f;
 //  float g_fBlue = 0.0f;
 //  
 //  void display()
 //  {
 //  	static const float color[] = { (float)240 / 255, (float)240 / 255, (float)240 / 255,1.0 };
 //  	glClearBufferfv(GL_COLOR, 0, color);
 //  
 //  	//we get the vColor key
 //  	GLuint vColor = glGetAttribLocation(g_program, "vColor");
 //  	//we set the vColor key!
 //  	glVertexAttrib4f(vColor, g_fRed, g_fGreen, g_fBlue, 1.0f);
 //  
 //  
 //  	glDrawArrays(GL_TRIANGLES, 0, NumVertices);
 //  	glutSwapBuffers();
 //  }
 //  
 //  void KeyCallBack(unsigned char key, int x, int y)
 //  {
 //  	static int i = 0;
 //  	i++;
 //  	i = i % 255;
 //  	g_fRed = (float)i / 255;;
 //  	g_fGreen = 1 - g_fRed;
 //  	g_fBlue = 1 - g_fRed / 2;
 //  
 //  	cout << "key call back" << endl;
 //  	display();
 //  }
 //  
 //  
 //  int main(int argc, char* argv[])
 //  {
 //  	glutInit(&argc, argv);                                       //用于初始化GULT库
 //  	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);  //设置初始显示模式
 //  	glutInitWindowPosition(0, 0);                                  //确定窗口的位置
 //  	glutInitWindowSize(900, 500);                              //设置窗口大小
 //  	glutCreateWindow("OpenGlScreen");                        //创建一个窗口标题
 //  	glewInit();
 //  
 //  	const GLubyte* name = glGetString(GL_VENDOR); //返回负责当前OpenGL实现厂商的名字
 //  	const GLubyte* biaoshifu = glGetString(GL_RENDERER); //返回一个渲染器标识符，通常是个硬件平台
 //  	const GLubyte* OpenGLVersion = glGetString(GL_VERSION); //返回当前OpenGL实现的版本号
 //  	const GLubyte* gluVersion = gluGetString(GLU_VERSION); //返回当前GLU工具库版本
 //  	printf("OpenGL实现厂商的名字：%s\n", name);
 //  	printf("渲染器标识符：%s\n", biaoshifu);
 //  	printf("OOpenGL实现的版本号：%s\n", OpenGLVersion);
 //  	printf("OGLU工具库版本：%s\n", gluVersion);
 //  
 //  
 //  	Init();
 //  	//glutFullScreen      ( );          //Put Into Full Screen
 //  	glutDisplayFunc(display);    //注册一个绘图函数
 //  	glutReshapeFunc(nullptr);    //设置投影的函数
 //  	glutKeyboardFunc(KeyCallBack);    //键盘回调函数
 //  	glutSpecialFunc(nullptr);    //设置当前窗口的特殊键盘回调。
 //  	glutIdleFunc(nullptr);    //程序空闲时调用的函数
 //  	glutMainLoop();            // 进入GLUT事件处理循环
 //  
 //  	return 0;
 //  }