#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265f;
const float OUTER_RADIUS = 0.7f;
const float INNER_RADIUS = 0.28f;
const int STAR_POINTS = 5;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.8f, 0.0f);
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < STAR_POINTS * 2; i++) {
            float angle = PI / 2 + i * PI / STAR_POINTS;
            float radius = (i % 2 == 0) ? OUTER_RADIUS : INNER_RADIUS;
            glVertex2f(radius * cosf(angle), radius * sinf(angle));
        }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q10 - Five-Pointed Star Outline");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
