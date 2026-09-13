#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265f;
const int CIRCLE_SEGMENTS = 50;

void drawCircleOutline(float radius, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < CIRCLE_SEGMENTS; i++) {
            float angle = 2.0f * PI * i / CIRCLE_SEGMENTS;
            glVertex2f(radius * cosf(angle), radius * sinf(angle));
        }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawCircleOutline(0.3f, 1.0f, 0.0f, 0.0f);
    drawCircleOutline(0.6f, 0.0f, 1.0f, 0.0f);
    drawCircleOutline(0.9f, 0.0f, 0.0f, 1.0f);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q11 - Concentric Circles");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
