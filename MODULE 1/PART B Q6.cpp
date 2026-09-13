#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.25f, 0.45f);
        glVertex2f(-0.25f, 0.45f);
        glVertex2f(-0.5f, 0.0f);
        glVertex2f(-0.25f, -0.45f);
        glVertex2f(0.25f, -0.45f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q06 - Hexagon Outline");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
