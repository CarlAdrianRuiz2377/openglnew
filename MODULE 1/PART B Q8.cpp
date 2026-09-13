#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(0.0f, 0.7f);
        glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(0.7f, 0.0f);
        glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(0.0f, -0.7f);
        glColor3f(1.0f, 1.0f, 0.0f); glVertex2f(-0.7f, 0.0f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q08 - Smooth Shaded Diamond");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
