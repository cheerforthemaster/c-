#include "3Dsort.h"
#include "glut.h"
#include "paint_second.h"

using namespace std;

threeDsort read_file;
vector<vector<double>> sour = read_file.readPoint();
vector<double> tem = read_file.readTemperature();

setModelArray(sour,tem,88,114,5);

int main(int argc, char** argv)
{
	// glut init
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_MULTISAMPLE | GLUT_DEPTH);
	initPaint();

	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(300, 0);
	glutCreateWindow("glut test");
	// The callbacks.
	glutReshapeFunc(reshape_func);
	glutDisplayFunc(display_func);
	glutMouseFunc(mouse_click_func);
	glutMotionFunc(mouse_move_func);
	glutKeyboardFunc(keyboard_func);
	glutSpecialFunc(specialkey_func);
	initPaint();

	glutMainLoop();
	return 0;
}