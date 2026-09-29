#include <GL/glut.h>

GLfloat hexagonData[] = {
     0.70f,  0.00f, 0.0f,   1.0f, 0.0f, 0.0f,   // red
     0.35f,  0.61f, 0.0f,   1.0f, 1.0f, 0.0f,   // yellow
    -0.35f,  0.61f, 0.0f,   0.0f, 1.0f, 0.0f,   // green
    -0.70f,  0.00f, 0.0f,   0.0f, 1.0f, 1.0f,   // cyan
    -0.35f, -0.61f, 0.0f,   0.0f, 0.0f, 1.0f,   // blue
     0.35f, -0.61f, 0.0f,   1.0f, 0.0f, 1.0f    // magenta
};

GLubyte hexagonIndices[] = { 0, 1, 2, 3, 4, 5 };

const GLsizei VERTEX_STRIDE = 6 * sizeof(GLfloat);

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, VERTEX_STRIDE, hexagonData);
    glColorPointer(3, GL_FLOAT, VERTEX_STRIDE, hexagonData + 3);
    glDrawElements(GL_POLYGON, 6, GL_UNSIGNED_BYTE, hexagonIndices);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Q19 - Interleaved + Indexed Hexagon");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}
