#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_QUADS);
        glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
        glVertex2f(-0.6f, -0.4f);
        glVertex2f(0.2f, -0.4f);
        glVertex2f(0.2f, 0.4f);
        glVertex2f(-0.6f, 0.4f);
    glEnd();

    glBegin(GL_QUADS);
        glColor4f(0.0f, 0.0f, 1.0f, 0.5f);
        glVertex2f(-0.2f, -0.6f);
        glVertex2f(0.6f, -0.6f);
        glVertex2f(0.6f, 0.2f);
        glVertex2f(-0.2f, 0.2f);
    glEnd();

    glDisable(GL_BLEND);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q19 - Overlapping Alpha-Blended Quads");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
