#include <GL/glut.h>

void drawRect(float x0, float y0, float x1, float y1) {
    glBegin(GL_POLYGON);
        glVertex2f(x0, y0);
        glVertex2f(x1, y0);
        glVertex2f(x1, y1);
        glVertex2f(x0, y1);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f);

    drawRect(-0.4f, -0.6f, -0.2f, 0.6f);
    drawRect(-0.4f, 0.4f, 0.4f, 0.6f);
    drawRect(-0.4f, -0.05f, 0.25f, 0.15f);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q13 - Letter F");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
