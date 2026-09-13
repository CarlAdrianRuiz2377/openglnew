#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.1f, 0.6f, 0.1f);
    glBegin(GL_POLYGON);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(1.0f, -0.4f);
        glVertex2f(-1.0f, -0.4f);
    glEnd();

    glColor3f(1.0f, 0.85f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.6f, 0.6f);
        for (int i = 0; i <= 30; i++) {
            float angle = 2.0f * PI * i / 30;
            glVertex2f(0.6f + 0.15f * cosf(angle), 0.6f + 0.15f * sinf(angle));
        }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Q14 - Simple Landscape");
    glClearColor(0.55f, 0.8f, 0.95f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
