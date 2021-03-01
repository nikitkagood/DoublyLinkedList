//only for main()
//#include<iostream>
//#include<string>

using namespace std;

//Features:
//1. Default constructor
//2. Copy constructor
//3. Copy assign operator
//4. Destructor
//5. push_front - add element at the beggining 
//6. push_back - add element at the end 
//7. pop_front - delete first element
//8. pop_back - delete last element
//9. front - access fist element
//9. back - access last element
//10. size - number of elements
//11. remove - remove all elements with specific value

template <typename T>
class List
{
public:
	List() : _size(0), head(nullptr), tail(nullptr)
	{}

	List(const List& list) : _size(0), head(nullptr), tail(nullptr)
	{
		if (head != nullptr)
		{
			size_t Size = _size;
			for (size_t i = 0; i < Size; i++)
			{
				pop_back();
			}
		}

		auto current = list.head;

		for (size_t i = 0; i < list._size; i++)
		{
			push_back(current->data);

			current = current->pNext;
		}
	}

	List operator = (const List& list)
	{
		if (head != nullptr)
		{
			size_t Size = _size;
			for (size_t i = 0; i < Size; i++)
			{
				pop_back();
			}
		}

		auto current = list.head;

		for (size_t i = 0; i < list._size; i++)
		{
			push_back(current->data);

			current = current->pNext;
		}

		return *this;
	}

	~List()
	{
		while (_size)
		{
			pop_front();
		}
	}

	void push_front(const T& value)
	{
		Node<T>* node = new Node<T>(value, nullptr, head);
		head->pPrev = node;
		head = node;

		_size++;
	}

	void push_back(const T& value)
	{
		Node<T>* node = new Node<T>(value, tail);

		if (head == nullptr || tail == nullptr)
		{
			head = node;
			tail = node;
		}
		else
		{
			tail->pNext = node;
			tail = node;
		}
		_size++;
	}

	void pop_front()
	{
		if (_size != 0)
		{
			Node<T>* temp = head;
			head = head->pNext;

			delete temp;
			_size--;
		}
	}

	void pop_back()
	{
		if (_size != 0)
		{
			Node<T>* temp = tail;
			tail = tail->pPrev;

			delete temp;
			_size--;
		}

	}

	T& front()
	{
		return head->data;
	}

	const T& front() const
	{
		return head->data;
	}

	T& back()
	{
		return tail->data;
	}

	const T& back() const
	{
		return tail->data;
	}

	unsigned int size() const
	{
		return _size;
	}

	void remove(const T& value)
	{
		auto i = head;
		
		while (i != nullptr)
		{
			if (i->data == value)
			{
				i->pNext->pPrev = i->pPrev;
				i->pPrev->pNext = i->pNext;

				Node<T>* toDelete = i;
				i = i->pNext;
				delete toDelete;
				_size--;
			}
			else
			{
				i = i->pNext;
			}

		}
	}
private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		Node* pPrev;
		T data;

		Node(T data = T(), Node* pPrev = nullptr, Node* pNext = nullptr)
		{
			this->data = data;
			this->pPrev = pPrev;
			this->pNext = pNext;
		}
	};

	unsigned int _size;
	Node<T>* head;
	Node<T>* tail;
};


//For testing
//int main()
//{
//	List<string> l;
//	l.push_back("banan");
//	l.push_back("oreh");
//	l.push_back("penek");
//	l.push_front("pechka");
//
//	l.remove("oreh");
//
//	List<string> l2;
//	l2 = l;
//	l.push_front("kraska");
//
//
//	return 0;
//}