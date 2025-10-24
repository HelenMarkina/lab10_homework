#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <math.h>

float area_rectangle(float a, float b);
float area_triangle(float a, float b, float c);
float area_trapezoid(float a, float b, float c);
void draw_rectangle(int a, int b, char symbol);
void draw_triangle(char symbol);
void draw_trapezoid(char symbol);
void definition_rectangle();
void definition_triangle();
void definition_trapezoid();
void name(int a);

int main() {
    setlocale(LC_ALL, "");

    int choice, figure_choice;
    float a, b, c;
    char draw_symbol;

    printf("=== ПРОГРАММА ДЛЯ РАБОТЫ С ГЕОМЕТРИЧЕСКИМИ ФИГУРАМИ ===\n");

    // Выбор фигуры
    printf("\nВыберите фигуру:\n");
    printf("1. Прямоугольник\n");
    printf("2. Треугольник\n");
    printf("3. Равнобедренная трапеция\n");
    printf("Ваш выбор: ");
    scanf("%d", &figure_choice);

    // Ввод параметров в зависимости от выбранной фигуры
    switch (figure_choice) {
    case 1: // Прямоугольник
        printf("Введите длину прямоугольника: ");
        scanf("%f", &a);
        printf("Введите ширину прямоугольника: ");
        scanf("%f", &b);
        break;

    case 2: // Треугольник
        printf("Введите сторону a треугольника: ");
        scanf("%f", &a);
        printf("Введите сторону b треугольника: ");
        scanf("%f", &b);
        printf("Введите сторону c треугольника: ");
        scanf("%f", &c);
        break;

    case 3: // Трапеция
        printf("Введите верхнее основание трапеции: ");
        scanf("%f", &a);
        printf("Введите нижнее основание трапеции: ");
        scanf("%f", &b);
        printf("Введите длину боковой стороны: ");
        scanf("%f", &c);
        break;

    default:
        printf("Неверный выбор фигуры!\n");
        return 1;
    }

    do {
        printf("\n=== МЕНЮ ОПЕРАЦИЙ ===\n");
        printf("1. Рассчитать площадь\n");
        printf("2. Вывести определение фигуры\n");
        printf("3. Нарисовать фигуру\n");
        printf("0. Выход\n");
        printf("Выберите опцию: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: // Расчет площади
            switch (figure_choice) {
            case 1:
                printf("Площадь прямоугольника: %.2f\n", area_rectangle(a, b));
                break;
            case 2:
                printf("Площадь треугольника: %.2f\n", area_triangle(a, b, c));
                break;
            case 3:
                printf("Площадь трапеции: %.2f\n", area_trapezoid(a, b, c));
                break;
            }
            break;

        case 2: // Определение фигуры
            switch (figure_choice) {
            case 1:
                definition_rectangle();
                break;
            case 2:
                definition_triangle();
                break;
            case 3:
                definition_trapezoid();
                break;
            }
            break;

        case 3: // Рисование фигуры
            printf("Введите символ для рисования: ");
            scanf(" %c", &draw_symbol);
            switch (figure_choice) {
            case 1:
                draw_rectangle((int)a, (int)b, draw_symbol);
                break;
            case 2:
                draw_triangle(draw_symbol);
                break;
            case 3:
                draw_trapezoid(draw_symbol);
                break;
            }
            break;

        case 0:
            printf("Выход из программы.\n");
            break;

        default:
            printf("Неверный выбор! Попробуйте снова.\n");
            break;
        }

    } while (choice != 0);

    return 0;
}
// Функции для вычисления площадей
float area_rectangle(float a, float b) {
    return a * b;
}

float area_triangle(float a, float b, float c) {
    float p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

float area_trapezoid(float a, float b, float c) {
    float height = sqrt(c * c - ((b - a) * (b - a)) / 4);
    return (a + b) * height / 2;
}

// Функции для рисования фигур
void draw_rectangle(int a, int b, char symbol) {
    printf("\nПрямоугольник %dх%d:\n", a, b);
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            printf("%c", symbol);
        }
        printf("\n");
    }
}

void draw_triangle(char symbol) {
    printf("\nТреугольник:\n");
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= i; j++) {
            printf("%c", symbol);
        }
        printf("\n");
    }
}

void draw_trapezoid(char symbol) {
    printf("\nРавнобедренная трапеция:\n");
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= i; j++) {
            printf("%c", symbol);
        }
        printf("\n");
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%c", symbol);
        }
        printf("\n");
    }
    for (int i = 4; i >= 1; --i) {
        for (int j = 1; j <= i; j++) {
            printf("%c", symbol);
        }
        printf("\n");
    }
}

// Функции для вывода определений
void definition_rectangle() {
    printf("\nОпределение прямоугольника:\n");
    printf("Прямоугольник - это четырехугольник, у которого все углы прямые.\n");
}

void definition_triangle() {
    printf("\nОпределение треугольника:\n");
    printf("Треугольник - это геометрическая фигура, образованная тремя отрезками,\n которые соединяют три точки, не лежащие на одной прямой.\n");
}

void definition_trapezoid() {
    printf("\nОпределение равнобедренной трапеции:\n");
    printf("Равнобедренная трапеция - это трапеция, у которой боковые стороны равны.\n");
}

