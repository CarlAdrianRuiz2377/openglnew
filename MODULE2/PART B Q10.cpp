#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265f;
const int OUTER_VERTICES = 8;
const float RADIUS = 0.7f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.5f, 0.2f);

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, -0.2f);
        for (int i = 0; i <= OUTER_VERTICES; i++) {
            float angle = PI * i / OUTER_VERTICES;
            glVertex2f(RADIUS * cosf(angle), -0.2f + RADIUS * sinf(angle));
        }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q10 - Half-Circle Fan");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
