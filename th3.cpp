#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}
float angle = 0;
float Tx = 0;
int goc;
void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glLoadIdentity(); 
	gluLookAt (0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
	glRotatef(60, -1, 1, 1);
	glPushMatrix();
		glRotatef(angle, 0, 0, 1);
		glutWireSphere(1, 15, 15);
	glPopMatrix();
	glPushMatrix();
		glScalef (1.0, 1.0, 2.5);
		 glTranslatef(0, 0, -1);
		glutWireCube(1);
	glPopMatrix();
	glutSwapBuffers(); 
	glFlush ();
}
void spin(){
	angle = angle + 0.01;
	glutPostRedisplay();
}
void mouse (int button, int state, int x, int y){
	if(button==GLUT_LEFT_BUTTON)
	{
		glutIdleFunc(spin);
	}
}
void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5.0, 5.0, -5.0, 5.0, 5.0, 20.0);
	glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow (argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
