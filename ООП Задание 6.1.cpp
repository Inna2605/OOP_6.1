//Создать имитацию игры «однорукий бандит». Происходит «вращение» трех барабанов(естественно, количество шагов вращений
//каждого из них выбирается случайно), на которых изображены разные значки; и если выпадает определенная
//комбинация, то игрок получает какой - то выигрыш (использовать кольцевую очередь).

#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;
class QueueRing
{
	//Очередь
	int* Wait;
	//Максимальный размер очереди
	int MaxQueueLength;
	//Текущий размер очереди
	int QueueLength;
public:
	//Конструктор
	QueueRing(int m);
	//Деструктор
	~QueueRing();
	//Добавление элемента
	void Add(int c);
	//Извлечение элемента
	int Extract();
	//Очистка очереди
	void Clear();
	//Проверка существования элементов в очереди
	bool IsEmpty();
	//Проверка на переполнение очереди
	bool IsFull();
	//Количество элементов в очереди
	int GetCount();
	//демонстрация очереди
	void Show();
};
void QueueRing::Show() {
	cout << "\n-----------------------------------\n";
	//демонстрация очереди
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " ";
	}
	cout << "\n-------------------------------------\n";
}
QueueRing::~QueueRing()
{
	//удаление очереди
	delete[]Wait;
}
QueueRing::QueueRing(int m)
{
	//получаем размер
	MaxQueueLength = m;
	//создаем очередь
	Wait = new int[MaxQueueLength];
	//Изначально очередь пуста
	QueueLength = 0;
}
void QueueRing::Clear()
{
	//Эффективная "очистка" очереди
	QueueLength = 0;
}
bool QueueRing::IsEmpty()
{
	//Пуст?
	return QueueLength == 0;
}
bool QueueRing::IsFull()
{
	// Полон?
	return QueueLength == MaxQueueLength;
}
int QueueRing::GetCount()
{
	//Количество присутствующих в стеке элементов 
	return QueueLength;
}
void QueueRing::Add(int c)
{
	//Если в очереди есть свободное место, 
	//то увеличиваем количество
	//значений и вставляем новый элемент 
	if (!IsFull())
		Wait[QueueLength++] = c;
}
int QueueRing::Extract()
{
	//Если в очереди есть элементы, то возвращаем тот,
	//который вошел первым и сдвигаем очередь 
	if (!IsEmpty()) {
		//запомнить первый
		int temp = Wait[0];
		//сдвинуть все элементы
		for (int i = 1; i < QueueLength; i++)
			Wait[i - 1] = Wait[i];
		//забрасываем первый "вытолкнутый элемент
		//в конец"
		Wait[QueueLength - 1] = temp;
		return temp;
	}
	else return 0;
}
void main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	//создание очереди
	QueueRing QUR(5);
	//заполнение части элементов
	for (int i = 0; i < 3; i++) {
		QUR.Add(rand() % 50);
	}
	//показ очереди
	//QUR.Show();
	//cout << endl;
	int f, j, k;
	int h1, h2, h3;
	int r1 = rand();
	for (f = 0; f < r1; f++) {
		//извлечение элемента
		h1 = QUR.Extract();
		//cout << h1 << " ";
	}
	//показ очереди
	QUR.Show();
	int r2 = rand();
	for (j = 0; j < r2; j++) {
		//извлечение элемента
		h2 = QUR.Extract();
		//cout << h2 << " ";
	}
	//показ очереди
	QUR.Show();
	int r3 = rand();
	for (k = 0; k < r3; k++) {
		//извлечение элемента
		h3 = QUR.Extract();
		//cout << h3 << " ";
	}
	//показ очереди
	QUR.Show();
	cout << endl;
	if (h1 == h2 && h1 == h3 && h2 == h3) {
		cout << "ВІТАЮ!!!\nСпівпали всі зображення на трьох барабанах!!!\nВи отримуєте приз 5000грн\n\n";
	}
	else {
		cout << "Нажаль зображення на барабанах не співпали.\nНаступного разу Вам пощастить.\nСпробуйте ще раз.\n\n";
	}
}


// Элемент, вышедший из кольцевой очереди, не выбрасывается, а становится в конце очереди