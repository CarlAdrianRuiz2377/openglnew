#include <GL/glut.h>

const int STEP_COUNT = 4;


GLfloat stairVertices[] = {
    -0.8f, -0.8f,  -0.8f, -0.4f,
    -0.4f, -0.8f,  -0.4f, -0.4f,
    -0.4f, -0.8f,  -0.4f, -0.1f,
     0.0f, -0.8f,   0.0f, -0.1f,
     0.0f, -0.8f,   0.0f,  0.2f,
     0.4f, -0.8f,   0.4f,  0.2f,
     0.4f, -0.8f,   0.4f,  0.5f,
     0.8f, -0.8f,   0.8f,  0.5f
};


GLfloat stairColors[] = {
    1.0f, 0.2f, 0.2f,  1.0f, 0.2f, 0.2f,
    1.0f, 0.2f, 0.2f,  1.0f, 0.2f, 0.2f,
    1.0f, 0.7f, 0.1f,  1.0f, 0.7f, 0.1f,
    1.0f, 0.7f, 0.1f,  1.0f, 0.7f, 0.1f,
    0.2f, 0.9f, 0.3f,  0.2f, 0.9f, 0.3f,
    0.2f, 0.9f, 0.3f,  0.2f, 0.9f, 0.3f,
    0.3f, 0.5f, 1.0f,  0.3f, 0.5f, 1.0f,
    0.3f, 0.5f, 1.0f,  0.3f, 0.5f, 1.0f
};

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, stairVertices);
    glColorPointer(3, GL_FLOAT, 0, stairColors);
    glDrawArrays(GL_QUAD_STRIP, 0, STEP_COUNT * 4);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 500);
    glutCreateWindow("Q14 - Colored Quad Strip Staircase");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}
