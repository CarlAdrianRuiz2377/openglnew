#include <GL/glut.h>

const int QUAD_COUNT = 4;
const int INDICES_PER_QUAD = 4;

GLfloat poolVertices[] = {
    -0.8f, -0.2f,  -0.4f, -0.2f,   0.0f, -0.2f,   0.4f, -0.2f,   0.8f, -0.2f,
    -0.8f,  0.2f,  -0.4f,  0.2f,   0.0f,  0.2f,   0.4f,  0.2f,   0.8f,  0.2f
};

GLubyte quadIndices[QUAD_COUNT * INDICES_PER_QUAD] = {
    0, 1, 6, 5,
    1, 2, 7, 6,
    2, 3, 8, 7,
    3, 4, 9, 8
};

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, poolVertices);

    for (int quad = 0; quad < QUAD_COUNT; ++quad) {
        const float shade = (quad % 2 == 0) ? 0.0f : 1.0f;
        glColor3f(shade, shade, shade);
        glDrawElements(GL_QUADS, INDICES_PER_QUAD, GL_UNSIGNED_BYTE,
            &quadIndices[quad * INDICES_PER_QUAD]);
    }

    glDisableClientState(GL_VERTEX_ARRAY);
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 400);
    glutCreateWindow("Q10 - Checkerboard Row");
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}
