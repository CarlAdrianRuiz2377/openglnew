#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(8.0f);

    glBegin(GL_POINTS);
        glColor3f(1.0f, 1.0f, 1.0f); glVertex2f(0.0f, 0.0f);
        glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(0.0f, 0.4f);
        glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(0.0f, -0.4f);
        glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(-0.4f, 0.0f);
        glColor3f(1.0f, 1.0f, 0.0f); glVertex2f(0.4f, 0.0f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q01 - Plus-Shaped Colored Points");
    glClearColor(0.15f, 0.15f, 0.15f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
