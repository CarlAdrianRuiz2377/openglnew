#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.8f, -0.3f);
        glVertex2f(-0.2f, -0.3f);
        glVertex2f(-0.2f, 0.3f);
        glVertex2f(-0.8f, 0.3f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.2f, -0.3f);
        glVertex2f(0.8f, -0.3f);
        glVertex2f(0.8f, 0.3f);
        glVertex2f(0.2f, 0.3f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q11 - Two Quads, One Block");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
