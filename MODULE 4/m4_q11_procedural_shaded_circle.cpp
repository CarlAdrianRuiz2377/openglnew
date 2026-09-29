#include <GL/glut.h>
#include <cmath>

const int SEGMENT_COUNT = 64;
const int VERTEX_COUNT = SEGMENT_COUNT + 2;
const float CIRCLE_RADIUS = 0.7f;
const float PI = 3.14159265f;

GLfloat circleVertices[VERTEX_COUNT * 2];
GLfloat circleColors[VERTEX_COUNT * 3];

void buildCircleArrays()
{
    circleVertices[0] = 0.0f;
    circleVertices[1] = 0.0f;
    circleColors[0] = circleColors[1] = circleColors[2] = 1.0f;

    for (int segment = 0; segment <= SEGMENT_COUNT; ++segment) {
        const float angle = 2.0f * PI * segment / SEGMENT_COUNT;
        const int vertexIndex = segment + 1;

        circleVertices[vertexIndex * 2] = CIRCLE_RADIUS * std::cos(angle);
        circleVertices[vertexIndex * 2 + 1] = CIRCLE_RADIUS * std::sin(angle);

        circleColors[vertexIndex * 3] = 0.5f + 0.5f * std::sin(angle);
        circleColors[vertexIndex * 3 + 1] = 0.5f + 0.5f * std::sin(angle + 2.094f);
        circleColors[vertexIndex * 3 + 2] = 0.5f + 0.5f * std::sin(angle + 4.189f);
    }
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, circleVertices);
    glColorPointer(3, GL_FLOAT, 0, circleColors);
    glDrawArrays(GL_TRIANGLE_FAN, 0, VERTEX_COUNT);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Q11 - Procedural Shaded Circle");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    buildCircleArrays();
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}
