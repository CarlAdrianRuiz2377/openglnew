#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.4f, 0.8f);
    glLineWidth(2.0f);

    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.8f, -0.3f);
        glVertex2f(-0.5f, 0.4f);
        glVertex2f(-0.2f, -0.3f);
        glVertex2f(0.1f, 0.4f);
        glVertex2f(0.4f, -0.3f);
        glVertex2f(0.7f, 0.4f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q03 - Zig-Zag Line Strip");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
