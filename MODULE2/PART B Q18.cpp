#include <GL/glut.h>

const int SEGMENT_COUNT = 6;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= SEGMENT_COUNT; i++) {
            float x = -0.9f + i * (1.8f / SEGMENT_COUNT);

            if (i % 2 == 0) {
                glColor3f(0.9f, 0.2f, 0.2f);
            } else {
                glColor3f(0.2f, 0.3f, 0.9f);
            }

            glVertex2f(x, -0.3f);
            glVertex2f(x, 0.3f);
        }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 400);
    glutCreateWindow("Q18 - Alternating-Color Ribbon");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glShadeModel(GL_FLAT);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
