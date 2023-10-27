#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
void drawCircle(float cx, float cy, float radius) {
    glColor3f(1.0, 0.0, 0.0); // Màu ð?
    glBegin(GL_LINE_LOOP);
    const float angleStep = 0.1;
    for (float angle = 0.0; angle < 2 * M_PI; angle += angleStep) {
        float x = cx + radius * cos(angle);
        float y = cy + radius * sin(angle);
        glVertex3f(x, y, 0.0);
    }
    glEnd();
}
void init(void){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}

void drawStar(float cx, float cy){
    glColor3f (1.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    GLfloat step = 3.14 / 5.0;
    int i;
    GLfloat goc1, r;
    for (i = 0; i < 10; ++i) {
        r = (i % 2 == 0 ? 5 : 15);
        goc1 = i * step;
        glVertex3f(cx + r * cos(goc1), cy + r * sin(goc1), 0.0);
    }
    glEnd();
}

float goc = 0.0, Tx = 0.0, Ty = 0.0;

void display(void){
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
	drawCircle(0.0, 0.0, 15.0);
    glTranslatef(Tx,Ty,0.0);
    glRotatef(goc, 0, 0, 1);
    glTranslatef(-Tx,-Ty,0.0);
    drawStar(0.0, 0.0);
    glFlush ();
}
void spin_dinh(){
    Tx = 15*cos(3.14/5);
    Ty = 15*sin(3.14/5); 
    goc = goc + 0.1; 
    glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y){
    if (key == 'a')
        glutIdleFunc(spin_dinh);
}
void reshape (int w, int h){
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);
    glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow (argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

