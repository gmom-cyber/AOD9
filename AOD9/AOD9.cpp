

#include <iostream>
using namespace std;
//РЕАЛИЗАЦИЯ НА ДИНАМИЧЕСКОМ МАССИВЕ
#define QMAX 11
struct Queue {
    int qu[QMAX];
    int rear, frnt;  //frnt – позиция первого элемента в очереди, rear – позиция последнего элемента в очереди

};
//Инициализация очереди
void init(struct Queue* q) {
    q->frnt = 1;
    q->rear = 0;
    return;
}
//Метод добавления элемента в очередь
void Push(struct Queue* q, int x) {
    if (q->rear < QMAX - 1) { //если очередь не полна
        q->rear++;            //добавляем поцизицию в очереди
        q->qu[q->rear] = x;    //заполняем массив введеным значением
    }
    else
        printf("Очередь полна!\n");
    return;
}
//Проверка не пуста ли очередь
int IsEmpty(struct Queue* q) { //проверка на пустоту очереди
    if (q->rear < q->frnt)
        return 1;
    else
        return 0;
}
//Метод вывода очереди
void Print(struct Queue* q) {
    int h;
    if (IsEmpty(q) == 1) {
        printf("Очередь пуста!\n");
        return;
    }
    for (h = q->frnt; h <= q->rear; h++)  //c первой позиции идем по всей очереди
        printf("%d ", q->qu[h]);          //выводим значения очереди
    return;
}
//Удаление элемента из очереди
int Remove(struct Queue* q) {
    int x, h;
    if (IsEmpty(q) == 1) { //проверка на пустоту очереди
        printf("Очередь пуста!\n");
        return 0;
    }
    x = q->qu[q->frnt];  //в х присваиваем первый элемент очереди
    for (h = q->frnt; h < q->rear; h++) {
        q->qu[h] = q->qu[h + 1]; //передвигаем всю очередь
    }
    q->rear--;   //удаляем ячейку последней позиции
    return x;
}
//Вывод первого элемента из очереди
void printFront(struct Queue* q)
{
    if (IsEmpty(q) == 1) { //проверка на пустоту очереди
        printf("Очередь пуста!\n");
        return;
    }
    else
    {
        int a;
        a = q->frnt;  //в а присваиваем первую позицию
        printf("%d ", q->qu[a]);
    }
}
//Вывод массива
void print(int* arr, int sz) {

    for (int i = 0; i < sz; i++)
        cout << arr[i] << " ";
    cout << endl;
}
//Размер очереди
int size(struct Queue* q)
{
    int size = 0;
    for (int i = q->frnt; i <= q->rear; i++)
    {
        size++;
    }
    return size;
}
//Сортировка 
void RadixSortLSD(int arr[], int arraySize)
{

    int k = arraySize;

    int i, bucket[10], maxVal = 0, digitPosition = 1;
    for (i = 0; i < arraySize; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];  //maxVal: эта переменная определяет счетчик цикла while!

    }
    //если maxVal состоит из 3 цифр, мы выполняем цикл 3 раза
    while (maxVal / digitPosition > 0) {

        int digitCount[10] = { 0 };         /// обнуляем счетчик 


        for (i = 0; i < arraySize; i++)
            digitCount[arr[i] / digitPosition % 10]++; // cчитаем порядковые цифры (ключи)


        for (i = 1; i < 10; i++)
            digitCount[i] += digitCount[i - 1];  //накопленные переменные в счетчике


        for (i = arraySize - 1; i >= 0; i--)
            bucket[--digitCount[arr[i] / digitPosition % 10]] = arr[i];        // Чтобы сохранить порядок, начинаем с обратной стороны


        for (i = 0; i < arraySize; i++)
            arr[i] = bucket[i];           //переставляем исходный массив, используя элементы в массиве bucket


        digitPosition *= 10; //передвигаем digitPosition 
    }
    print(arr, arraySize);
    return;
}

//РЕАЛИЗАЦИЯ НА однонаправленном динамическом списке.

struct list {
    int field;
    struct list* ptr; //указатель на следующий элемент
    list(int d)
    {
        field = d;
        ptr = NULL;
    }
};

struct queue {

    struct list* front, * rearl; //front указатель на начало очереди; rearl указатель на конец очереди
};
//Инициализация очереди
void InitList(struct queue* ql) {
    ql->front = 0;
    ql->rearl = 0;
}
//Проверка не пуста ли очередь
int IsemptyList(struct queue* ql) {
    if (ql->front == 0)
        return 1;
    else
        return 0;
}
//Метод добавления элемента в очередь
void PushList(struct queue* ql, int x) {
    list* temp = new list(x);    //выделение памяти         
    if (ql->rearl == NULL) {              //если список пуст
        ql->front = ql->rearl = temp;     //оба узла указывают на создаваемый
        return;
    }
    ql->rearl->ptr = temp; //указание что следующее звено списка это новосозданная структура
    ql->rearl = temp; //добавление элемента
}
//Метод вывода элементов в очереди
void printList(struct queue* ql) {
    struct list* h;
    if (IsemptyList(ql) == 1) {
        printf("Очередь пуста!\n");
        return;
    }
    for (h = ql->front; h != NULL; h = h->ptr) //c первой позиции идем по всей очереди
        printf("%d ", h->field);               //выводим элементы очереди
    return;
}
//Метод удаления элемента в очереди
int RemoveList(struct queue* ql) {
    struct list* temp;
    int x;
    if (IsemptyList(ql) == 1) {          //Проверка не пуста ли очередь
        printf("Очередь пуста!\n");
        return 0;
    }
    x = ql->front->field;      //в x записываем первый элемент
    temp = ql->front;          //временный указатель на первый элемент
    ql->front = ql->front->ptr;  //cдвиг начала списка
    free(temp);   //Функция free() возвращает память, на которую указывает параметр ptr, назад в кучу. В резуль­тате эта память может выделяться снова.
    return x;
}
//Вывод первого элемента из очереди
int printFrontList(struct queue* ql) {
    if (IsemptyList(ql) == 1) {
        return printf("Очередь пуста!\n");
    }
    else {
        int x;
        x = ql->front->field; //в x присваиваем значение первого элемента
        return x;
    }
}


int main() {
    setlocale(LC_ALL, "ru");
    struct Queue* q;
    struct queue* qlst;
    int a;
    int s;
    q = (Queue*)malloc(sizeof(Queue));
    qlst = (queue*)malloc(sizeof(queue));
    int ch;
    int ch2;
    init(q);
    InitList(qlst);
    int array[10];
    cout << "Исходный массив: " << endl;

    for (int i = 0; i < 10; i++)
    {
        array[i] = rand() % 1000;
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "Массив после сортировки: " << endl;
    RadixSortLSD(array, 10);

    

   
    return 0;
}



