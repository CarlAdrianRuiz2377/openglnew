#include <GL/glut.h>

const int GRID_SIZE = 4;
const float CELL_SIZE = 2.0f / GRID_SIZE;

void drawCell(int row, int col) {
    float x0 = -1.0f + col * CELL_SIZE;
    float y0 = -1.0f + row * CELL_SIZE;
    float x1 = x0 + CELL_SIZE;
    float y1 = y0 + CELL_SIZE;

    glBegin(GL_POLYGON);
        glVertex2f(x0, y0);
        glVertex2f(x1, y0);
        glVertex2f(x1, y1);
        glVertex2f(x0, y1);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            if ((row + col) % 2 == 0) {
                glColor3f(0.1f, 0.1f, 0.1f);
            } else {
                glColor3f(0.9f, 0.9f, 0.9f);
            }
            drawCell(row, col);
        }
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q09 - 4x4 Checkerboard");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
