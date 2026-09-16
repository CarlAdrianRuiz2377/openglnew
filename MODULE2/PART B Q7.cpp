#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.2f, 0.6f, 0.9f);

    glBegin(GL_QUADS);
        glVertex2f(-0.6f, -0.5f);
        glVertex2f(0.7f, -0.3f);
        glVertex2f(0.5f, 0.6f);
        glVertex2f(-0.4f, 0.4f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q07 - One Quadrilateral");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
