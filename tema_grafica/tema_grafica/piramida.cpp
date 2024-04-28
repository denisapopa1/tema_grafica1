
#include "glos.h"
#include "gl.h"
#include "glu.h"
#include "glaux.h"
#include "glut.h" 


static GLfloat X = 0;
static GLfloat Y = 0;

void myInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

void specialKeys(int k, int x, int y) {
    if (k == GLUT_KEY_RIGHT) Y += 5.0f;
    else if (k == GLUT_KEY_LEFT) Y -= 5.0f;
    else if (k == GLUT_KEY_UP) X += 5.0f;
    else if (k == GLUT_KEY_DOWN) X -= 5.0f;
    glutPostRedisplay();
}



void pyramid() {

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);

    glVertex3f(-1, 0, -1);
    glVertex3f(-1, 0, 1);

    glVertex3f(-1, 0, 1);
    glVertex3f(1, 0, 1);

    glVertex3f(1, 0, 1);
    glVertex3f(1, 0, -1);

    glVertex3f(1, 0, -1);
    glVertex3f(-1, 0, -1);

    glVertex3f(-1, 0, -1);
    glVertex3f(0, 1.4, 0);

    glVertex3f(-1, 0, 1);
    glVertex3f(0, 1.4, 0);

    glVertex3f(1, 0, 1);
    glVertex3f(0, 1.4, 0);

    glVertex3f(1, 0, -1);
    glVertex3f(0, 1.4, 0);
    glEnd();

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0xF0F0);  
    glBegin(GL_LINES);

    glVertex3f(-1, 0, -1);
    glVertex3f(1, 0, 1);

    glVertex3f(-1, 0, 1);
    glVertex3f(1, 0, -1);

    glVertex3f(0, 0, 0);  
    glVertex3f(0, 1.4, 0); 

    glVertex3f(1, 0, 1);
    glVertex3f(1, 0, -1);

    glVertex3f(1, 0, -1);
    glVertex3f(-1, 0, -1);

    glVertex3f(-1, 0, -1);
    glVertex3f(0, 1.4, 0);

    glEnd();
    glDisable(GL_LINE_STIPPLE);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(X, 1.0f, 0.0f, 0.0f);
    glRotatef(Y, 0.0f, 1.0f, 0.0f);
    pyramid();
    glPopMatrix();
    glFlush();
}

void myReshape(GLsizei w, GLsizei h)
{
    if (!h) {
        return;
    }
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 0.1, 200.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 3.0, 5.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Wireframe Square Pyramid");
    myInit();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);

    glutMainLoop();
    return 0;
}