#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "math_3d.h"//подключаем вспомогательную структуру - вектор

GLuint VBO; //глобальная переменная для хранения указателя на буфер вершин

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableVertexAttribArray(0); /*координаты вершин, используемые в буфере, 
                                  рассматриваются как атрибут вершины с индексом 0 в фиксированной функции конвейера 
                                  (которая становится активной, если не используется шейдер)*/
    glBindBuffer(GL_ARRAY_BUFFER, VBO); //обратно привязываем наш буфер, приготавливая его для отрисовки
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); /*Первый параметр указывает на индекс атрибута.
                                                           Второй параметр - это количество компонентов в атрибуте (3 для X, Y и Z). 
                                                           Третий параметр - тип данных для каждого компонента. 
                                                           Четвертый - хотим ли мы нормализовать атрибуты перед использованием в конвейере.
                                                           Пятый параметр (названный "шаг") является числом байтов между 2 экземплярами атрибута. */

    glDrawArrays(GL_POINTS, 0, 1); //функция для отрисовки

    glDisableVertexAttribArray(0); //отключаем каждый атрибут вершины, как только отпадает необходимость в нем

    glutSwapBuffers();
}


static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB);
}

static void CreateVertexBuffer()
{
    Vector3f Vertices[1]; //создаем массив из одного экземпляра структуры Vector3f
    Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f); //задаем XYZ по нулям, точка в середине экрана

    glGenBuffers(1, &VBO); /*первый параметр определяет количество объектов, которые вы хотите создать, 
                           и второй - ссылка на массив типа GLuints для хранения указателя, 
                           по которому будут храниться данные*/
    glBindBuffer(GL_ARRAY_BUFFER, VBO); /*привязываем указатель к названию цели,
                                        параметр GL_ARRAY_BUFFER означает, 
                                        что буфер будет хранить массив вершин*/
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW); /*принимает название цели, размер данных в байтах, 
                                                                               адрес массива вершин, и флаг, 
                                                                               который обозначает использование паттернов для этих данных*/
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Chelyshkina Ekaterina Tutorial 02");

    InitializeGlutCallbacks();

    // Must be done after glut is initialized!
    GLenum res = glewInit();
    if (res != GLEW_OK) { //проверка на ошибки
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    CreateVertexBuffer();

    glutMainLoop();

    return 0;
}

