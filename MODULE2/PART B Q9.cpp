#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.6f, 0.4f);

    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(-0.6f, -0.4f);
        glVertex2f(-0.6f, 0.4f);
        glVertex2f(0.6f, -0.4f);
        glVertex2f(0.6f, 0.4f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q09 - Rectangle from Triangle Strip");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
