#ifndef __ICS46_LL_STACK_HPP
#define __ICS46_LL_STACK_HPP
#include <iostream>
#include <stdexcept>

namespace shindler::ics46::project0 {

class StackEmptyException : public std::runtime_error {
   public:
    explicit StackEmptyException(const std::string& err)
        : std::runtime_error(err) {}
};

// This is the LinkedListStack class you will be implementing for this project.
// Remember to see the write-up for more details!
template <typename T>
class LinkedListStack {
   private:
    size_t StackSize{0};
    struct Node
    {
        Node(T t)
        : value{t}, next{nullptr}, previous{nullptr}
        {}
        T value;
        Node * next;
        Node * previous;
    };

	Node * tail{};
    Node * head{};

   public:
    // constructor
    LinkedListStack();

    // copy constructor (remember, deep copy!)
    LinkedListStack(const LinkedListStack& stackb);

    // assignment operator (remember, deep copy!)
    LinkedListStack& operator=(const LinkedListStack& stackb);
    // You do not need to implement these
    LinkedListStack(LinkedListStack&&) = delete;
    LinkedListStack& operator=(LinkedListStack&&) = delete;
    // destructor
    ~LinkedListStack();

    [[nodiscard]] size_t size() const noexcept;
    [[nodiscard]] bool empty() const noexcept;

    // We have two top() functions.  The first gets called if your
    // LinkedListStack is not a const, while the latter gets called on a const
    // LinkedListStack (the latter might occur via const reference parameter,
    // for instance). Be sure to test both!  It is important when testing to
    // ensure that EVERY funtion gets called and tested!
    [[nodiscard]] T& top();
    [[nodiscard]] const T& top() const;

    void push(const T& elem) noexcept;
    void pop();
};

template <typename T>
LinkedListStack<T>::LinkedListStack() {
    // TODO: Fill in your constructor implementation here.
}

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack& stackb) {
    if (stackb.head == nullptr)
	{
		;
	}
	else
	{
		this -> StackSize = stackb.size();
		this->head = new Node(stackb.head->value);
		this -> tail= this -> head;
		Node * tmp2{stackb.head};
		while (tmp2 -> next != nullptr)
		{
			this -> tail-> next= new Node(tmp2 -> next -> value);
			this -> tail = this -> tail -> next;
			tmp2 = tmp2 -> next;
		}
	}
    // TODO: Fill in your copy constructor implementation here.
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(
    const LinkedListStack& stackb) {
    while(this -> head != nullptr)
    {
        Node * tmp{this -> head -> next};
        delete this -> head;
        this -> head = tmp;
    }
    if (stackb.head == nullptr)
	{
		;
	}
	else
	{
		this -> StackSize = stackb.size();
		this->head = new Node(stackb.head->value);
		this -> tail= this -> head;
		Node * tmp2{stackb.head};
		while (tmp2 -> next != nullptr)
		{
			this -> tail-> next= new Node(tmp2 -> next -> value);
			this -> tail = this -> tail -> next;
			tmp2 = tmp2 -> next;
		}
	}
    return *this;  // Stub so this function compiles without implementation.
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    while(this -> head != nullptr)
    {
        Node * tmp{this -> head -> next};
        delete this -> head;
        this -> head = tmp;
    }
}

template <typename T>
size_t LinkedListStack<T>::size() const noexcept {
    // TODO: Fill in your size() implementation here.
    return this -> StackSize;  // Stub so this function compiles without an implementation.
}

template <typename T>
bool LinkedListStack<T>::empty() const noexcept {
    // TODO: Fill in your isEmpty() implementation here.
    if (this -> StackSize == 0)
    {
        return true;  // Stub so this function compiles without an implementation.
    }
    return false;
}

template <typename T>
T& LinkedListStack<T>::top() {
    // TODO: Fill in your top() implementation here.
    // The following is a stub just to get the template project to compile.
    // You should delete it for your implementation.
    if (this -> StackSize == 0)
    {
        throw StackEmptyException("No value at top");
    }
    return this -> head -> value;
}

template <typename T>
const T& LinkedListStack<T>::top() const {
    // TODO: Fill in your const top() implementation here.
    // The following is a stub just to get the template project to compile.
    // You should delete it for your implementation.
    return this -> head -> value;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) noexcept {
    // TODO: Fill in your push() implementation here.
    if (this -> StackSize == 0)
    {
        this -> head = new Node(elem);
        this -> tail = this -> head;
    }
    else
    {
        Node * newNode = new Node(elem);
        newNode -> next = this -> head;
        this -> head = newNode;
    }
    StackSize++;
    
}

template <typename T>
void LinkedListStack<T>::pop() {
    // TODO: Fill in your pop() implementation here.
    if (this -> StackSize != 0)
    {
        Node * newHead{this -> head -> next};
        delete this -> head;
        this -> head = newHead;
    }
    StackSize--;
}

}  // namespace shindler::ics46::project0
#endif
