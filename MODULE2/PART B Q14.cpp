#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(3.0f);

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
    glBegin(GL_LINES);
        glVertex2f(-0.8f, 0.3f);
        glVertex2f(0.8f, 0.3f);
    glEnd();
    glDisable(GL_LINE_STIPPLE);

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(2, 0xAAAA);
    glBegin(GL_LINES);
        glVertex2f(-0.8f, -0.3f);
        glVertex2f(0.8f, -0.3f);
    glEnd();
    glDisable(GL_LINE_STIPPLE);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q14 - Two Stipple Patterns");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
