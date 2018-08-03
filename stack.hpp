#include <new>
#include <string>

   //change this from a generic stack to specfic
class Node {
public:
	Node() { next = 0; }
	Node(const int x) { data = x; name = " "; next = NULL; }
	Node(const int x, const std::string& str) { data = x; name = str; next = NULL; }
	void add() {data++;}
	Node* next;
	int data;
	std::string name;
};


class stack {
public:
	stack();
	stack(const stack&);
	~stack();
	void      swap(stack&);
	stack& operator= (stack);

	bool          empty() const;
	bool          full() const;
	Node*         top() const;
	int           pop();
	void          push(const int&);
	void          push(const int&, const std::string);
	int           value(Node* node) const;
	std::string   name(Node* node) const;
	void          addValue(Node* node);

private:
	Node*         tos;
	Node*         bottom;
};
