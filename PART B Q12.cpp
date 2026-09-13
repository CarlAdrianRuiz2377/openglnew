#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f);

    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.6f, 0.0f);
        glVertex2f(0.5f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(0.5f, 0.15f);
        glVertex2f(0.5f, -0.15f);
        glVertex2f(0.8f, 0.0f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q12 - Arrow");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
