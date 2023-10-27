#include <GL/glut.h>
float teapot=0;
void renderTeapot() {

    GLfloat ambient[] = {1.0f, 1.0f, 0.0f, 1.0f};
    GLfloat diffuse[] = {1.0f, 1.0f, 0.0f, 1.0f};
    GLfloat specular[] = {1.0f, 1.0f, 0.0f, 1.0f};
    GLfloat shininess = 50.0f;
    
	glTranslatef(-0.7f+teapot, 0.0f,0);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    glutSolidTeapot(0.2); 

}
void dichuyen(void){
    float teapotspeed = 0.0001f;
    teapot += teapotspeed;
    glTranslatef(teapot, 0, 0); 

    if (teapot >= 1.35f) {
        glutIdleFunc(NULL);
    }

   glutPostRedisplay();
}
void mouse(int button, int state, int x, int y) {
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN) {
                glutIdleFunc(dichuyen);
                glutPostRedisplay();
            }
            break;
    }
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    GLfloat lightPosition[] = {1.0f, 1.0f, 0.0f, 0.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    renderTeapot();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Teapot");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();

    return 0;
}
