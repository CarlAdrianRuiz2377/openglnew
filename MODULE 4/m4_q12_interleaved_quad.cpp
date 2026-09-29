#include <GL/glut.h>

GLfloat quadData[] = {
    -0.6f, -0.6f, 0.0f,   1.0f, 0.0f, 0.0f,
     0.6f, -0.6f, 0.0f,   0.0f, 1.0f, 0.0f,
     0.6f,  0.6f, 0.0f,   0.0f, 0.0f, 1.0f,
    -0.6f,  0.6f, 0.0f,   1.0f, 1.0f, 0.0f
};

const GLsizei VERTEX_STRIDE = 6 * sizeof(GLfloat);

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, VERTEX_STRIDE, quadData);
    glColorPointer(3, GL_FLOAT, VERTEX_STRIDE, quadData + 3);
    glDrawArrays(GL_QUADS, 0, 4);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Q12 - Interleaved Array Quad");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}
