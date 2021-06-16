struct node {
  int val;
  node *next;
};

struct List
{
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

bool is_sorted(node *lst) {

   if(lst == nullptr || lst->next == nullptr)
      return true;
   return (lst->val <= lst->next->val) &&
            is_sorted(lst->next);
}
// checks if values are in shorted order

//
// push_front
//
// pushes passed in value to fron of linked list
void push_front(List &mylist, int value1)
{
	node *newN = new node;
	newN->next = mylist.Head;
	mylist.Head = newN;

	mylist.Count++;

}


int main() {
  
	List mylisyofnodes;
	mylisyofnodes.Head = nullptr;
	mylisyofnodes.Count = 0;

	for (int i = 0; i < 5; i++)
	{
		push_front(mylisyofnodes, i);
	}

	lst_free3(mylisyofnodes.Head);
	is_sorted(mylisyofnodes.Head);

  return 0;
}
