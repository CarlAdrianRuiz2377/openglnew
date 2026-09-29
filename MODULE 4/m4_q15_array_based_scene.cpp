#include <GL/glut.h>
#include <cmath>

const int SUN_SEGMENT_COUNT = 16;
const int SUN_VERTEX_COUNT = SUN_SEGMENT_COUNT + 1;
const int SUN_INDEX_COUNT = SUN_SEGMENT_COUNT + 2;
const float SUN_CENTER_X = 0.6f;
const float SUN_CENTER_Y = 0.6f;
const float SUN_RADIUS = 0.18f;
const float PI = 3.14159265f;

GLfloat sunVertices[SUN_VERTEX_COUNT * 2];
GLubyte sunIndices[SUN_INDEX_COUNT];

GLfloat mountainVertices[] = {
    -1.0f, -0.5f,  -0.4f,  0.4f,   0.2f, -0.5f,
    -0.2f, -0.5f,   0.4f,  0.2f,   1.0f, -0.5f
};

GLfloat groundVertices[] = {
    -1.0f, -1.0f,   1.0f, -1.0f,   1.0f, -0.5f,  -1.0f, -0.5f
};

void buildSunArrays()
{
    sunVertices[0] = SUN_CENTER_X;
    sunVertices[1] = SUN_CENTER_Y;
    sunIndices[0] = 0;

    for (int segment = 0; segment < SUN_SEGMENT_COUNT; ++segment) {
        const float angle = 2.0f * PI * segment / SUN_SEGMENT_COUNT;
        sunVertices[(segment + 1) * 2] = SUN_CENTER_X + SUN_RADIUS * std::cos(angle);
        sunVertices[(segment + 1) * 2 + 1] = SUN_CENTER_Y + SUN_RADIUS * std::sin(angle);
        sunIndices[segment + 1] = (GLubyte)(segment + 1);
    }
    sunIndices[SUN_INDEX_COUNT - 1] = 1;
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);

    glColor3f(1.0f, 0.85f, 0.1f);
    glVertexPointer(2, GL_FLOAT, 0, sunVertices);
    glDrawElements(GL_TRIANGLE_FAN, SUN_INDEX_COUNT, GL_UNSIGNED_BYTE, sunIndices);

    glColor3f(0.45f, 0.35f, 0.3f);
    glVertexPointer(2, GL_FLOAT, 0, mountainVertices);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glColor3f(0.2f, 0.6f, 0.2f);
    glVertexPointer(2, GL_FLOAT, 0, groundVertices);
    glDrawArrays(GL_QUADS, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 500);
    glutCreateWindow("Q15 - Array-Based Scene");
    glClearColor(0.5f, 0.75f, 1.0f, 1.0f);
    buildSunArrays();
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}
