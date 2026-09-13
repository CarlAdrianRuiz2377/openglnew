#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265f;
const float FACE_RADIUS = 0.8f;
float handAngle = PI / 2;

void drawClockFace() {
    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 60; i++) {
            float angle = 2.0f * PI * i / 60;
            glVertex2f(FACE_RADIUS * cosf(angle), FACE_RADIUS * sinf(angle));
        }
    glEnd();

    glBegin(GL_LINES);
        for (int i = 0; i < 12; i++) {
            float angle = 2.0f * PI * i / 12;
            float innerRadius = FACE_RADIUS - 0.08f;
            glVertex2f(innerRadius * cosf(angle), innerRadius * sinf(angle));
            glVertex2f(FACE_RADIUS * cosf(angle), FACE_RADIUS * sinf(angle));
        }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawClockFace();

    glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.6f * cosf(handAngle), 0.6f * sinf(handAngle));
    glEnd();

    glFlush();
}

void idle() {
    handAngle -= 0.01f;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q18 - Rotating Clock Hand");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
