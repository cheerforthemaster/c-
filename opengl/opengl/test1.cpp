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
 //  	glutInit(&argc, argv);                                       //���ڳ�ʼ��GULT��
 //  	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);  //���ó�ʼ��ʾģʽ
 //  	glutInitWindowPosition(0, 0);                                  //ȷ�����ڵ�λ��
 //  	glutInitWindowSize(900, 500);                              //���ô��ڴ�С
 //  	glutCreateWindow("OpenGlScreen");                        //����һ�����ڱ���
 //  	glewInit();
 //  
 //  	const GLubyte* name = glGetString(GL_VENDOR); //���ظ���ǰOpenGLʵ�ֳ��̵�����
 //  	const GLubyte* biaoshifu = glGetString(GL_RENDERER); //����һ����Ⱦ����ʶ����ͨ���Ǹ�Ӳ��ƽ̨
 //  	const GLubyte* OpenGLVersion = glGetString(GL_VERSION); //���ص�ǰOpenGLʵ�ֵİ汾��
 //  	const GLubyte* gluVersion = gluGetString(GLU_VERSION); //���ص�ǰGLU���߿�汾
 //  	printf("OpenGLʵ�ֳ��̵����֣�%s\n", name);
 //  	printf("��Ⱦ����ʶ����%s\n", biaoshifu);
 //  	printf("OOpenGLʵ�ֵİ汾�ţ�%s\n", OpenGLVersion);
 //  	printf("OGLU���߿�汾��%s\n", gluVersion);
 //  
 //  
 //  	Init();
 //  	//glutFullScreen      ( );          //Put Into Full Screen
 //  	glutDisplayFunc(display);    //ע��һ����ͼ����
 //  	glutReshapeFunc(nullptr);    //����ͶӰ�ĺ���
 //  	glutKeyboardFunc(KeyCallBack);    //���̻ص�����
 //  	glutSpecialFunc(nullptr);    //���õ�ǰ���ڵ�������̻ص���
 //  	glutIdleFunc(nullptr);    //�������ʱ���õĺ���
 //  	glutMainLoop();            // ����GLUT�¼�����ѭ��
 //  
 //  	return 0;
 //  }