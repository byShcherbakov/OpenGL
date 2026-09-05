#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;





int main() {

    // 1 Создание окна

    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return 1 ;
    }
    // размер окна - название - указатели
    GLFWwindow* window = glfwCreateWindow(500, 500, "OpenGL", NULL, NULL);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        fprintf(stderr, "Failed to initialize GLAD\n");
        return 1;
    }

    // 2 Создание массива вершин и задание  их характеристик
    // координаты



     // 1 ТРЕУГОЛЬНИК

    //САЛАТОВЫЙ
    GLfloat vertices1[] = {
        0.0f, 0.5f, 0.0f,    //(x,y,z)
        0.5f, 0.0f, 0.0f,   //(x,y,z)
        -0.5f,0.0f, 0.0f,  //(x,y,z)
    };

    //буффер для хранения параметров вершин для видеокарты GPU
    GLuint vbo1 , vao1;
    glGenBuffers (1, &vbo1);// кол- во буферов 1  и &vbo - адрес куда записать
    glBindBuffer (GL_ARRAY_BUFFER, vbo1); // активация буфера  GL_ARRAY_BUFFER - слот отвеч за данные вершин ( vbo - id буфера )
    glBufferData (GL_ARRAY_BUFFER, 9 * sizeof (GLfloat), vertices1, GL_STATIC_DRAW); // выделение памяти  на видеокарте и копирование туда массива
     //vertices- указатель на массив
    // STATIC - один раз будет записаны данные
    //DRAW -  данные будут исп для пост отрисовки


    //Создание массив верщин
    glGenVertexArrays (1, &vao1); /*создаёт массив вершин и помещает
    его идентификатор в переданный параметр*/
    glBindVertexArray (vao1); /*устанавливает
выбранный массив вершин в качестве текущего*/
    glEnableVertexAttribArray (0);/*указывает, какая из характеристик вершины будет связана с буфером значений */
    glBindBuffer (GL_ARRAY_BUFFER, vbo1); //активация буфера
    glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, NULL);/*связывает активный массив
вершин с активным VBO и присваивает ему индекс*/



    //ЧЕРНЫЙ
    GLfloat vertices2[] = {
        0.5f, 0.0f, 0.0f,     //(x,y,z)
        0.0f, -0.5f, 0.0f,   //(x,y,z)
        1.0f, -0.5f, 0.0f, //(x,y,z)
    };
    //буффер для хранения параметров вершин для видеокарты GPU
    GLuint vbo2 , vao2;
    glGenBuffers (1, &vbo2);// кол- во буферов 1  и &vbo - адрес куда записать
    glBindBuffer (GL_ARRAY_BUFFER, vbo2); // активация буфера  GL_ARRAY_BUFFER - слот отвеч за данные вершин ( vbo - id буфера )
    glBufferData (GL_ARRAY_BUFFER, 9 * sizeof (GLfloat), vertices2, GL_STATIC_DRAW); // выделение памяти  на видеокарте и копирование туда массива
    //vertices- указатель на массив
    // STATIC - один раз будет записаны данные
    //DRAW -  данные будут исп для пост отрисовки


    //Создание массив верщин
    glGenVertexArrays (1, &vao2); /*создаёт массив вершин и помещает
    его идентификатор в переданный параметр*/
    glBindVertexArray (vao2); /*устанавливает
выбранный массив вершин в качестве текущего*/
    glEnableVertexAttribArray (0);/*указывает, какая из характеристик вершины будет связана с буфером значений */
    glBindBuffer (GL_ARRAY_BUFFER, vbo2); //активация буфера
    glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, NULL);/*связывает активный массив
вершин с активным VBO и присваивает ему индекс*/


    // красный
    GLfloat vertices3[] = {
        -0.5f, 0.0f, 0.0f,     //(x,y,z)
        -1.0f, -0.5f, 0.0f,   //(x,y,z)
        0.0f, -0.5f, 0.0f,  //(x,y,z)
    };
    //буффер для хранения параметров вершин для видеокарты GPU
    GLuint vbo3 , vao3;
    glGenBuffers (1, &vbo3);// кол- во буферов 1  и &vbo - адрес куда записать
    glBindBuffer (GL_ARRAY_BUFFER, vbo3); // активация буфера  GL_ARRAY_BUFFER - слот отвеч за данные вершин ( vbo - id буфера )
    glBufferData (GL_ARRAY_BUFFER, 9 * sizeof (GLfloat), vertices3, GL_STATIC_DRAW); // выделение памяти  на видеокарте и копирование туда массива
    //vertices- указатель на массив
    // STATIC - один раз будет записаны данные
    //DRAW -  данные будут исп для пост отрисовки


    //Создание массив верщин
    glGenVertexArrays (1, &vao3); /*создаёт массив вершин и помещает
    его идентификатор в переданный параметр*/
    glBindVertexArray (vao3); /*устанавливает
выбранный массив вершин в качестве текущего*/
    glEnableVertexAttribArray (0);/*указывает, какая из характеристик вершины будет связана с буфером значений */
    glBindBuffer (GL_ARRAY_BUFFER, vbo3); //активация буфера
    glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, NULL);/*связывает активный массив
вершин с активным VBO и присваивает ему индекс*/






    // 3 Создание шейдерной программы

    // 3.1 Создание Верщины шейдера
    const char* vertex_shader =
            "#version 400\n"
            "in vec3 vp;"
            "void main() {"
                "  gl_Position = vec4(vp, 1.0);"
            "}";

    // Загрузить и скомпилировать верхний шрейдер
    GLuint vs = glCreateShader (GL_VERTEX_SHADER); //создаёт шейдер указанного типа
    glShaderSource (vs, 1, &vertex_shader, NULL); // связывает созданный шейдер с текстом его подпрограммы
    glCompileShader (vs); //компилирует  его


    //3.2 Создание фрагментного шейдера
    /*позволяющий задать
    цвет каждого конкретного пикселя примитива(ТРЕУГОЛЬНИК ) */
    const char* fragment_shader1 =
        "#version 400\n"
       "out vec4 frag_colour; "
       "void main() {"
           " frag_colour = vec4 (0.19, 0.84, 0.78, 1.0); "
       "}";
    // Аналогично к пункту 3.1
    GLuint fs1 = glCreateShader (GL_FRAGMENT_SHADER);
    glShaderSource (fs1, 1, &fragment_shader1, NULL);
    glCompileShader (fs1);

    // Сборка программы
    GLuint shader_programme1 = glCreateProgram (); // создаёт шейдерную программу
    glAttachShader (shader_programme1, fs1); // добавляет к ней шейдер(fs - цвет)
    glAttachShader (shader_programme1, vs); // добавляет к ней шейдер(vs - верхний шрейдер  Вершины )
    glLinkProgram (shader_programme1); //выполняет
    //компоновку шейдеров и подготавливает программу к использованию


    const char* fragment_shader2 =
        "#version 400\n"
       "out vec4 frag_colour; "
       "void main() {"
           " frag_colour = vec4 (0.0, 0.0, 0.0, 1.0); "
       "}";
    // Аналогично к пункту 3.1
    GLuint  fs2 = glCreateShader (GL_FRAGMENT_SHADER);
    glShaderSource (fs2, 1, &fragment_shader2, NULL);
    glCompileShader (fs2);

    // Сборка программы
    GLuint shader_programme2 = glCreateProgram (); // создаёт шейдерную программу
    glAttachShader (shader_programme2, fs2); // добавляет к ней шейдер(fs - цвет)
    glAttachShader (shader_programme2, vs); // добавляет к ней шейдер(vs - верхний шрейдер  Вершины )
    glLinkProgram (shader_programme2); //выполняет



    const char* fragment_shader3 =
       "#version 400\n"
      "out vec4 frag_colour; "
      "void main() {"
          " frag_colour = vec4 (255.0, 0.0, 0.0, 1.0); "
      "}";
    // Аналогично к пункту 3.1
    GLuint  fs3 = glCreateShader (GL_FRAGMENT_SHADER);
    glShaderSource (fs3, 1, &fragment_shader3, NULL);
    glCompileShader (fs3);

    // Сборка программы
    GLuint shader_programme3 = glCreateProgram (); // создаёт шейдерную программу
    glAttachShader (shader_programme3, fs3); // добавляет к ней шейдер(fs - цвет)
    glAttachShader (shader_programme3, vs); // добавляет к ней шейдер(vs - верхний шрейдер  Вершины )
    glLinkProgram (shader_programme3); //выполняет



    /* MAin функции
    glClearColor (1.0f, 1.0f, 1.0f, 1.0f); // задаёт цвет фона окна
    glClear (GL_COLOR_BUFFER_BIT); // очищает экран, удаляя предыдущее изображение
    glUseProgram (shader_programme); //устанавливает указанную в качестве параметра шейдерную программу в виде активной
    glBindVertexArray (vao); // создаёт массив вершин и помещает
    glDrawArrays (GL_TRIANGLES, 0, 3);// рисует его (1 - вид примитива 2 -индекс первого отображения 3 -кол - во элементов)
    */
    glClearColor (1.0f, 1.0f, 1.0f, 1.0f);
    while ( !glfwWindowShouldClose (window)) { //позволяет выполнять цикл рисования
        // Закрашивается фон окна
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        // Подключается шейдерная программа
        glUseProgram (shader_programme1);
        glBindVertexArray (vao1); // Подключается массив вершин
        glDrawArrays (GL_TRIANGLES, 0, 3);


        glUseProgram (shader_programme2);
        glBindVertexArray (vao2);
        glDrawArrays (GL_TRIANGLES, 0, 3);

        glUseProgram (shader_programme3);
        glBindVertexArray (vao3);
        glDrawArrays (GL_TRIANGLES, 0, 3);

        // Обработка очереди событий
        glfwPollEvents (); //
        // Использование двойной буферизации
        glfwSwapBuffers (window);


    }
    // Освобождение ресурсов перед выходом
    glDeleteProgram(shader_programme1);
    glDeleteProgram(shader_programme2);
    glDeleteProgram(shader_programme3);
    glDeleteShader(fs1);
    glDeleteShader(fs2);
    glDeleteShader(fs3);
    glDeleteShader(vs);
    glDeleteBuffers(1, &vbo1);
    glDeleteBuffers(1, &vbo2);
    glDeleteBuffers(1, &vbo3);
    glDeleteVertexArrays(1, &vao1);
    glDeleteVertexArrays(1, &vao2);
    glDeleteVertexArrays(1, &vao3);

    glfwTerminate();

    return 0 ;
}