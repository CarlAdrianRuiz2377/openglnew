#include <GL/glut.h>

const int STEP_COUNT = 4;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.3f, 0.5f, 0.8f);

    glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= STEP_COUNT; i++) {
            float x = -0.8f + i * 0.4f;
            float topY = -0.5f + i * 0.25f;
            glVertex2f(x, -0.5f);
            glVertex2f(x, topY);
        }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q12 - Staircase Ribbon");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
