#include <iostream>
#include <string>

using namespace std;

template<typename T>
class List {
public:
	List();
	~List();

	void push_back(T date);//вставляет в конец спика данные
	int GetSize() { return size; }//возвращает размер списка
	T& operator[](const int index);//перегруженый оператор[] которые по указанному индексу возврщает данные из спсика
	void pop_front();//удалить самый первый элемент
	void clear();//чиста списка
	void push_front(T date); // добавление эдемента в начало списка
	void insert(T data, int index);// добавить данные по индексу
	void remove_at(int index);//удаление элемента по индексу
	void pop_back();//удаление последнего элемента

private:
	template<typename T>
	class Node { // создаем класс Node(указатель на следующий элемент и данные)
	public:
		Node *pNext;// указатель типа Node, которые указывает на следующий узел
		T date;//данные
		Node(T date = T(), Node* pNext = nullptr) {//создаем конструктор в которую передаем данные 
			this->date = date;													//и указатель(на nillptr)
			this->pNext = pNext;
		}
	};
	
	int size; //создаем переменную для сохранения размера списка

	Node<T> *head;//указатель на голову(начало) списка

};

template<typename T>
List<T>::List(){

	size = 0;//присваем, что размер списка изначально 0
	head = nullptr;//начало списка указвет на ноль
}

template<typename T>
List<T>::~List() {
	clear();
}

template<typename T>
void List<T>::push_back(T data) {
	if (head == nullptr) {//проверка пустое ли начало спика
		head = new Node<T>(data);//создаем новый элемент узла и передаем в него данные
	}
	else {
		Node<T>* current = this->head;//создаем указатель на начало списка

		while (current->pNext != nullptr) {//ищем до тех пор пока не найдется элемент который указывает на ноль
			current = current->pNext;//если да то указатею присваем указатель на следующий элемент
		}

		current->pNext = new Node<T>(data);// создаем новый объект узла, и передаем в него данные

	}
	size++;//увеличиваем размер списка
}
template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* curent = this->head;

	while (curent != nullptr) {//ищем до тех пор пока не найдется элемент который указывает на ноль
		if (counter == index) {//если счетки равен индексу, то возвращаем данные 
			return curent->date;
		}
		curent = curent->pNext;//если не нашли нужный индекс, то приваем на следующий элемент списка
		counter++;//увеличиваем счет
	}
}
template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;//создаем временный объект чтобы хранить начало списка

	head = head->pNext;//присваиваем временному объекту указатель на следующий элемент

	delete temp;//удаляем данные
	size--;//уменьшаем размер  списка
}
template<typename T>
void List<T>::clear() {
	while(size){
		pop_front();
	}
}

template<typename T>
void List<T>::push_front(T data) {
	head = new Node<T>(data,head);//Важно! сначала создается объект с данными и ссылкой на этот же элемент, а после присваивается
	size++;
}
template<typename T>
void List<T>::insert(T data, int index) {
	if (index == 0) {
		push_front(data);
	}
	else {
		Node<T>* previous = this->head; //создаем времнный указатель типа Node
		for (int i = 0; i < index - 1; i++) {//цикл для нахождения узла под индексом меньше выбранного
			previous = previous->pNext;
		}

		previous->pNext = new Node<T>(data, previous->pNext);//добавляем новый адресс(текущего объекта)
		size++;
	}

}
template<typename T>
void List<T>::remove_at(int index) {
	if (index == 0) {
		pop_front(index);
	}
	else {
		Node<T>* previous = this->head; //создаем времнный указатель типа Node
		for (int i = 0; i < index - 1; i++) {//цикл для нахождения узла под индексом меньше выбранного
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;//создаем объекта класса Node и присваиваем ему найденый указатель на предудущий индекс
		previous->pNext = toDelete->pNext; // присваиваем этот объект временного элемента
		delete toDelete;//удаляем узел
	}
	size--;
}
template<typename T>
void List<T>::pop_back() {
	remove_at(size-1);
}
int main()
{
}