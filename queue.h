#ifndef H_queue
#define H_queue

#include <iostream>
#include <exception>
#include <stdexcept>
#include "cvor.h"
#include "queue_interface.h"

template <typename Type>
class queue : public queue_interface<Type>
{
private:
	Cvor<Type> *head;
	Cvor<Type> *tail; 
	size_t _size;
	void copyQueue(const queue<Type>& otherQueue); //metod za kreiranje kopije reda
public:
	const queue<Type>& operator=(const queue<Type>&);
	size_t size() const;
	bool empty() const;	
	void initializeQueue();
	const Type& front() const;
	const Type& back() const;
    Type& front();
	Type& back();
	void push(const Type& queueElement);
	void push(Type&& queueElement);
	void pop();
	queue();
	queue(const queue<Type>& otherQueue);
	~queue(); //Destruktor
};

template <typename Type>
size_t queue<Type>::size() const {
    return _size;
}

template <typename Type>
bool queue<Type>::empty() const {
    return(_size == 0);
}

template <typename Type>
queue<Type>::~queue(){
	initializeQueue();
}


template <typename Type>
void queue<Type>::copyQueue(const queue<Type>& otherQueue)
{
	Cvor<Type>  *current;			//pomoćni pokazivač za kretanje po redu
	if (!empty()) 			//ako red nije prazan, isprazni red
		initializeQueue();
		
	current = otherQueue.head; 	//pozicionira current na početak proslijeđenog reda

	while (current != nullptr)		//dok ima elemenata u proslijeđenom redu
	{
		push(current->getInfo()); //dodaj element u rezultujući red
		current = current->getLink(); //pomjeri trenutni na slijedeći element
	}
	
} 

template <typename Type>
queue<Type>::queue(const queue<Type>& otherQueue)
{
	head = nullptr;	//postavi head na nullptr
	tail  = nullptr;      //postavi tail na nullptr
	copyQueue(otherQueue);	//iskoristi metod kopiraj
}

template <typename Type>
const queue<Type>& queue<Type>::operator=(const queue<Type>& otherQueue)
{
	if (this != &otherQueue) 	//izbjegni samokopiranje
		copyQueue(otherQueue);	//iskoristi funkciju za kopiranje
	return *this;
}


template <typename Type>
void queue<Type>::initializeQueue()
{
	Cvor<Type> *temp;
	while (head!= nullptr) // Dok ima elemenata u redu
	{
		temp = head; 
		head = head->getLink(); //Prebacujemo prvi na sljedeći element u redu 
		delete temp; // dealociramo memoriju 
	}
	tail = nullptr; // Nakon brisanja svih elemenata
} 

template <typename Type>
void queue<Type>::push(const Type& newElement)
{
	Cvor<Type> *newNode;
	newNode = new Cvor<Type>(newElement); // Kreiramo cvor
	
	if (empty()) // ako je red prazan cvor koji dodajemo ce biti pocetak i kraj (glava i rep)
	{
		head = newNode;		
	}
	else // ako red nije prazan novi cvor dodajemo kraj
	{
		tail->setLink(newNode);		
	}
	tail = newNode;
	_size++;
}

template <typename Type>
void queue<Type>::push(Type&& newElement)
{
	Cvor<Type> *newNode;
	newNode = new Cvor<Type>(std::move(newElement)); // Kreiramo cvor
	
	if (empty()) // ako je red prazan cvor koji dodajemo ce biti pocetak i kraj (glava i rep)
	{
		head = newNode;		
	}
	else // ako red nije prazan novi cvor dodajemo kraj
	{
		tail->setLink(newNode);		
	}
	tail = newNode;
	_size++;
}

template <typename Type>
const Type& queue<Type>::front() const
{
	if(head == nullptr) throw std::underflow_error("Red prazan");
	return head->getInfo(); //pristupi prvom elementu preko head, pročitaj njegov info dio i to vrati
} 

template <typename Type>
const Type& queue<Type>::back() const
{
	if(head == nullptr) throw std::underflow_error("Red prazan");
	return tail->getInfo(); //pristupi zadnjem elementu preko tail, pročitaj njegov info dio i to vrati
}

template <typename Type>
Type& queue<Type>::front() 
{
	if(head == nullptr) throw std::underflow_error("Red prazan");
	return head->getInfo(); //pristupi prvom elementu preko head, pročitaj njegov info dio i to vrati
} 

template <typename Type>
Type& queue<Type>::back() 
{
	if(head == nullptr) throw std::underflow_error("Red prazan");
	return tail->getInfo(); //pristupi zadnjem elementu preko tail, pročitaj njegov info dio i to vrati
}

template <typename Type>
void queue<Type>::pop()
{
	Cvor<Type> *temp;
	if (!empty())
	{
		temp = head; // temp pokazuje na prvi cvor
		head = head->getLink(); // sljedeci cvor postaje prvi
		delete temp; // brisemo prvi cvor 
		if (head == nullptr) // ako je poslije brisanja red prazan 
			tail = nullptr; 
		_size--;
	}
	
}
template<class Type>
queue<Type>::queue()
{
	head = nullptr; 
	tail = nullptr;
	_size = 0; 
} 

#endif
