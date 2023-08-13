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
	char* Wait;
	//Максимальный размер очереди
	char MaxQueueLength;
	//Текущий размер очереди
	char QueueLength;
public:
	//Конструктор
	QueueRing(int m);
	//Деструктор
	~QueueRing();
	//Добавление элемента
	void Add(int c);
	//Извлечение элемента
	bool Extract();
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
	Wait = new char[MaxQueueLength];
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
bool QueueRing::Extract()
{
	//Если в очереди есть элементы, то возвращаем тот,
	//который вошел первым и сдвигаем очередь 
	if (!IsEmpty()) {
		//запомнить первый
		char temp = Wait[0];
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
	srand(time(0));
	//создание очереди
	QueueRing QUR(25);
	//заполнение части элементов
	for (int i = 0; i < 5; i++) {
		QUR.Add(rand() % 50);
	}
	//показ очереди
	QUR.Show();
	cout << endl;
	int r1 = rand();
	for (int i = 0; i < r1; i++) {
		//извлечение элемента
		QUR.Extract();
	}
	//показ очереди
	QUR.Show();
	int r2 = rand();
	for (int i = 0; i < r2; i++) {
		//извлечение элемента
		QUR.Extract();
	}
	//показ очереди
	QUR.Show();
	int r3 = rand();
	for (int i = 0; i < r3; i++) {
		//извлечение элемента
		QUR.Extract();
	}
	//показ очереди
	QUR.Show();
}

// Элемент, вышедший из кольцевой очереди, не выбрасывается, а становится в конце очереди