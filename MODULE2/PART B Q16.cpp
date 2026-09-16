#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265f;
const int CIRCLE_SEGMENTS = 40;

void drawCircle() {
    float centerX = 0.0f;
    float centerY = 0.25f;
    float radius = 0.35f;

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(centerX, centerY);
        for (int i = 0; i <= CIRCLE_SEGMENTS; i++) {
            float angle = 2.0f * PI * i / CIRCLE_SEGMENTS;
            glColor3f(1.0f, 0.4f, 0.6f);
            glVertex2f(centerX + radius * cosf(angle), centerY + radius * sinf(angle));
        }
    glEnd();
}

void drawBase() {
    glColor3f(0.8f, 0.6f, 0.3f);
    glBegin(GL_QUADS);
        glVertex2f(-0.3f, -0.6f);
        glVertex2f(0.3f, -0.6f);
        glVertex2f(0.3f, 0.25f);
        glVertex2f(-0.3f, 0.25f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawBase();
    drawCircle();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q16 - Fan + Quad Composition");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
