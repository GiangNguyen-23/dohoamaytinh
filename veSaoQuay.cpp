//khai bao thu vien
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>  

static GLfloat spin = 0.0; // spin luu goc quay cua ngoi sao bat dau tu 0
const double PI = 3.14159265358979323846;  //hang so pi

void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0); // mau nen cua so
    glShadeModel (GL_FLAT);//che do to mau
}

//ve ngoi sao
void drawStar() 
{
    glBegin(GL_LINE_LOOP); // bat dau ve
    for(int i = 0; i < 5; i++)
    {
        glVertex2f(50 * cos(2 * i * PI / 5), 50 * sin(2 * i * PI / 5));
        glVertex2f(25 * cos((2 * i + 1) * PI / 5), 25 * sin((2 * i + 1) * PI / 5));
    }
    glEnd(); // ket thuc ve
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);//xoa bo dem mau
    glPushMatrix();//dua ma tran hien tai vao stack
    glRotatef(spin, 0.0, 0.0, 1.0);//xoay ngoi sao theo goc spin
    glColor3f(1.0, 1.0, 1.0); // thiet lap mau trang
    drawStar(); //ve ngoi sao
    glPopMatrix(); //lay ma tran tu stack
    glutSwapBuffers(); //hoan doi cac bo dem
}

//ham duoc goi khi chuot duoc nhan
void spinDisplay(void)
{
    spin = spin + 0.2;
    if (spin > 360.0) //neu spin vuot qua 360 thi quay lai 0
        spin = spin - 360.0;
    glutPostRedisplay();
}

//duoc goi khi cua so thay doi kch thuoc
void reshape(int w, int h) //w,h la kich thuoc cua so moi
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-60.0, 60.0, -60.0, 60.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

//tuong tac chuot
//a
void mouse(int button, int state, int x, int y)
{
    switch (button) {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN) //duoc nhan
            glutIdleFunc(spinDisplay);
        break;
    case GLUT_MIDDLE_BUTTON:
        if (state == GLUT_DOWN) //duoc tha ra
            glutIdleFunc(NULL);
        break;
    default:
        break;
    }
}
//b
void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 'a':
        spin = spin + 2;
        if (spin > 360.0)
            spin = spin - 360.0;
        glutPostRedisplay();
        break;
    }
}

int main(int argc, char** argv)
{
	//khoi tao cua so va tham so
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (250, 250);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();//thiet lap li moi truong ban dau
    
    //gan cac ham de xu ly sk va hien thi
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

