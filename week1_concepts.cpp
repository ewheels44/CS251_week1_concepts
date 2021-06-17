#include <iostream>
#include <cstdlib>

struct node {
	int val;
	node *next;
};

struct List
{
	node *Tail; 	// added tail pointer for convenience
	node* Head;
	int   Count;
};

//
// recursive stuff
//

void lst_free3(node *lst) {

   if(lst==nullptr)
     return;
   lst_free3(lst->next);
   delete lst;
}
// deletes nodes right-to-left

//
// is_sorted
//
// NOTE: the data needs to be in accending order???
// returns true is list is in shorted order
//
bool is_sorted(node *lst) {

   if(lst == nullptr || lst->next == nullptr)
      return true;
   return (lst->val <= lst->next->val) &&
            is_sorted(lst->next);
}
// checks if values are in shorted order

//
// lst_print
//
// prints a linked list
//
void lst_print(node *lst){

	if(lst == nullptr)
		return;
	else
	{
		std::cout << lst->val << " ";
		lst_print(lst->next);
	}
}

//
// push_front
//
// pushes passed in value to fron of linked list
//
void push_front(List &mylist, int value1)
{
	node *newN = new node;
	newN->val = value1;
	newN->next = mylist.Head;
	mylist.Head = newN;

	mylist.Count++;
}

void push_back(List &mylist, int value1)
{
	node *newN = new node;
	newN->val = value1;
	newN->next = nullptr;

	if(mylist.Head == nullptr)
	{
		mylist.Head = newN;
		mylist.Tail = newN;
	}
	mylist.Tail->next = newN;
	mylist.Tail = newN;

	mylist.Count++;
}


int main() {
  
	List mylisyofnodes;
	mylisyofnodes.Head = nullptr;
	mylisyofnodes.Count = 0;

	for (int i = 0; i < 5; i++)
	{
		// push_front
		//
		// non-random
		/* push_front(mylisyofnodes, i); */
		/* push_front(mylisyofnodes, i + rand() % 10 + 1); */

		// push_back
		//
		// non-random
		/* push_back(mylisyofnodes, i); */
		push_back(mylisyofnodes, i + rand() % 10 + 1);
	}

	// TODO: change list i.e. non-sorted
	// should also be true cause list is sorted still
	if(is_sorted(mylisyofnodes.Head))
	{
		std::cout << "This list ";
		lst_print(mylisyofnodes.Head);
		std::cout << " is sorted" << std::endl;
	}
	else
	{
		std::cout << "This list ";
		lst_print(mylisyofnodes.Head);
		std::cout << " is not sorted" << std::endl;
	}


	lst_free3(mylisyofnodes.Head);

	// should be true cause list should be empty?
	/* is_sorted(mylisyofnodes.Head); */

  return 0;
}
