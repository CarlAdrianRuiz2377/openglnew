#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265f;
const int SEGMENT_COUNT = 60;
const float RADIUS = 0.8f;

void setRainbowColor(float t) {
    float red = 0.5f + 0.5f * sinf(2.0f * PI * t);
    float green = 0.5f + 0.5f * sinf(2.0f * PI * t + 2.0f * PI / 3.0f);
    float blue = 0.5f + 0.5f * sinf(2.0f * PI * t + 4.0f * PI / 3.0f);
    glColor3f(red, green, blue);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.0f, 0.0f);

        for (int i = 0; i <= SEGMENT_COUNT; i++) {
            float t = (float)i / SEGMENT_COUNT;
            float angle = t * 2.0f * PI;
            setRainbowColor(t);
            glVertex2f(RADIUS * cosf(angle), RADIUS * sinf(angle));
        }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q20 - Procedural Rainbow Fan");
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
