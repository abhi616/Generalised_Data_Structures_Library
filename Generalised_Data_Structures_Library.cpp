#include<iostream>
using namespace std;

// Structure for Singly Linear Linked List

template <class T1>
struct nodeSL
{
	T1 data;
	struct nodeSL<T1> * next;
};

// Structure for Singly Circular Linked List

template <class T2>
struct nodeSC
{
	T2 data;
	struct nodeSC<T2> * next;
};

// Structure for Doubly Linear Linked List

template <class T3>
struct nodeDL
{
	T3 data;
	struct nodeDL<T3> * next;
	struct nodeDL<T3> * prev;
};

// Structure for Doubly Circular Linked List

template <class T4>
struct nodeDC
{
	T4 data;
	struct nodeDC<T4> * next;
	struct nodeDC<T4> * prev;
};

// Class for Singly Linear Linked List

template <class T1>
class SinglyLL
{
      public:
	    struct nodeSL<T1> * First;
		
		SinglyLL()
		{
			First = NULL;
		}
		
		void InsertFirst_SLL(T1);
		void InsertLast_SLL(T1);
		void InsertAtPos_SLL(T1, int);
		void DeleteFirst_SLL();
		void DeleteLast_SLL();
		void DeleteAtPos_SLL(int);
		void Display_SLL();
		int Count_SLL();
};

// Class for Singly Circular Linked List

template <class T2> 
class SinglyCL
{
      public:
	    struct nodeSC<T2> * First;
		struct nodeSC<T2> * Last;
		
		SinglyCL()
		{
			First = NULL;
			Last = NULL;
		}
		
		void InsertFirst_SCL(T2);
		void InsertLast_SCL(T2);
		void InsertAtPos_SCL(T2, int);
		void DeleteFirst_SCL();
		void DeleteLast_SCL();
		void DeleteAtPos_SCL(int);
		void Display_SCL();
		int Count_SCL();
};

// Class for Doubly Linear Linked List

template <class T3>
class DoublyLL
{
     public:
	    struct nodeDL<T3> * First;

        DoublyLL()
		{
           First = NULL;
		}			
		
		void InsertFirst_DLL(T3);
		void InsertLast_DLL(T3);
		void InsertAtPos_DLL(T3, int);
		void DeleteFirst_DLL();
		void DeleteLast_DLL();
		void DeleteAtPos_DLL(int);
		void Display_DLL();
		int Count_DLL();	
};

// Class for Doubly Circular Linked List

template <class T4>
class DoublyCL
{
     public:
	    struct nodeDC<T4> * First;
		struct nodeDC<T4> * Last;

        DoublyCL()
		{
           First = NULL;
		   Last = NULL; 
		}			
		
		void InsertFirst_DCL(T4);
		void InsertLast_DCL(T4);
		void InsertAtPos_DCL(T4, int);
		void DeleteFirst_DCL();
		void DeleteLast_DCL();
		void DeleteAtPos_DCL(int);
		void Display_DCL();
		int Count_DCL();
};

// All Functions Defination Starts From Below Line

template <class T1>
void SinglyLL<T1> :: InsertFirst_SLL(T1 no)
{
	struct nodeSL<T1> * newn = new struct nodeSL<T1>;
	
	newn->data = no;
	newn->next = NULL;
	
	if(First == NULL)
	{
		First = newn;
	}
	else
	{
		newn->next = First;
		First = newn;
	}
}

template <class T2>
void SinglyCL<T2> :: InsertFirst_SCL(T2 no)
{
	struct nodeSC<T2> * newn = new struct nodeSC<T2>;
	
	newn->data = no;
	newn->next = NULL;
	
	if(First == NULL && Last == NULL)
	{
		First = newn;
		Last = newn;
		First->next = newn;
	}
	else
	{
		newn->next = First;
		Last->next = newn;
		First = newn;
	}
}

template <class T3>
void DoublyLL<T3> :: InsertFirst_DLL(T3 no)
{
	struct nodeDL<T3> * newn = new struct nodeDL<T3>;
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if(First == NULL)
	{
		First = newn;
	}
	else
	{
		newn->next = First;
		First->prev = newn;
		First = newn;
	}
}

template <class T4>
void DoublyCL<T4> :: InsertFirst_DCL(T4 no)
{
	struct nodeDC<T4> * newn = new struct nodeDC<T4>;
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if(First == NULL && Last == NULL)
	{
		First = newn;
		Last = newn;
		newn->next = newn;
		newn->prev = newn;
	}
	else
	{
		newn->next = First;
		First->prev = newn;
		First = newn;
		Last->next = First;
		First->prev = Last;
	}
}

template <class T1>
void SinglyLL<T1> :: Display_SLL()
{
	struct nodeSL<T1> * temp = First;
	
	while(temp != NULL)
	{
		cout<<"| "<<temp->data<<" |->";
		temp = temp->next;
	}
	
	cout<<"NULL\n";
}

template <class T2>
void SinglyCL<T2> :: Display_SCL()
{
	if(First == NULL && Last == NULL)
	{
		cout<<"Linked list is empty\n";
		return;
	}
	
	struct nodeSC<T2> * temp1 = First;
	struct nodeSC<T2> * temp2 = Last;
	
	do
	{
	  	cout<<"| "<<temp1->data<<" |->";
		temp1 = temp1->next;
	}while(temp1 != temp2->next);
	
	cout<<"| "<<temp1->data<<" |\n";
}

template <class T3>
void DoublyLL<T3> :: Display_DLL()
{
	struct nodeDL<T3> * temp = First;
	
	cout<<"NULL=>";
	
	while(temp != NULL)
	{
		cout<<"| "<<temp->data<<" |<=>";
		temp = temp->next;
	}
	
	cout<<"NULL\n";
}

template <class T4>
void DoublyCL<T4> :: Display_DCL()
{
	if(First == NULL && Last == NULL)
	{
		cout<<"Linked list is empty\n";
		return;
	}
	
	struct nodeDC<T4> * temp1 = First;
	struct nodeDC<T4> * temp2 = Last;
	
	do
	{
	  	cout<<"| "<<temp1->data<<" |<=>";
		temp1 = temp1->next;
	}while(temp1 != temp2->next);
	
	cout<<"| "<<temp1->data<<" |\n";
}

template <class T1>
int SinglyLL<T1> :: Count_SLL()
{
	struct nodeSL<T1> * temp = First;
	int Cnt = 0;
	
	while(temp != NULL)
	{
		Cnt++;
		temp = temp->next;
	}
	
	return Cnt;
}

template <class T2>
int SinglyCL<T2> :: Count_SCL()
{
	if(First == NULL && Last == NULL)
	{
		cout<<"Linked list is empty\n";
		return 0;
	}
	
	struct nodeSC<T2> * temp1 = First;
	struct nodeSC<T2> * temp2 = Last;
	int Cnt = 0;
	
	do
	{
	  	Cnt++;
		temp1 = temp1->next;
	}while(temp1 != temp2->next);
	
	return Cnt;
}

template <class T3>
int DoublyLL<T3> :: Count_DLL()
{
	struct nodeDL<T3> * temp = First;
	
	int Cnt = 0;
	
	while(temp != NULL)
	{
		Cnt++;
		temp = temp->next;
	}
	
	return Cnt;
}

template <class T4>
int DoublyCL<T4> :: Count_DCL()
{
	if(First == NULL && Last == NULL)
	{
		cout<<"Linked list is empty\n";
		return 0;
	}
	
	struct nodeDC<T4> * temp1 = First;
	struct nodeDC<T4> * temp2 = Last;
	int Cnt = 0;
	
	do
	{
	  	Cnt++;
		temp1 = temp1->next;
	}while(temp1 != temp2->next);
	
	return Cnt;
}

template <class T1>
void SinglyLL<T1> :: InsertLast_SLL(T1 no)
{
	struct nodeSL<T1> * newn = new struct nodeSL<T1>;
	struct nodeSL<T1> * temp = NULL;
	
	newn->data = no;
	newn->next = NULL;
	
	if(First == NULL)
	{
		First = newn;
	}
	else
	{
		temp = First;
		
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		
		temp->next = newn;
	}
}

template <class T2>
void SinglyCL<T2> :: InsertLast_SCL(T2 no)
{
	struct nodeSC<T2> * newn = new struct nodeSC<T2>;
	
	newn->data = no;
	newn->next = NULL;
	
	if(First == NULL&& Last == NULL)
	{	
	   First = Last = newn;
	   newn->next = First;
	}
	else
	{
		Last->next = newn;
		newn->next = First;
		Last = newn;
	}
}

template <class T3>
void DoublyLL<T3> :: InsertLast_DLL(T3 no)
{
	struct nodeDL<T3> * newn = new struct nodeDL<T3>;
	struct nodeDL<T3> * temp = NULL;
	
	newn->data = no;
	newn->prev = NULL;
	newn->next = NULL;
	
	if(First == NULL)
	{
		First = newn;
	}
	else
	{
		temp = First;
		
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		
		temp->next = newn;
		newn->prev = temp;
	}
	
}

template <class T4>
void DoublyCL<T4> :: InsertLast_DCL(T4 no)
{
	struct nodeDC<T4> * newn = new struct nodeDC<T4>;
	
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if(First == NULL && Last == NULL)
	{
		First = Last = newn;
		newn->next = First;
		newn->prev = Last;
	}
	else
	{
		Last->next = newn;
		newn->prev = Last;
		newn->next = First;
		Last = newn;
	}
}

template <class T1>
void SinglyLL<T1> :: InsertAtPos_SLL(T1 no, int ipos)
{
	int Count = Count_SLL();
	
	if(ipos <= 0 || ipos > Count+1)
	{
		cout<<"\nInvalid position\n\n";
		return;
	}
	
	if(ipos == 1)
	{
		InsertFirst_SLL(no);
	}
	else if(ipos == Count+1)
	{
		InsertLast_SLL(no);
	}
	else
	{
		struct nodeSL<T1> * newn = new struct nodeSL<T1>;
		newn->data = no;
		newn->next = NULL;
		
		struct nodeSL<T1> * temp = First;
		
		for(int i = 1; i< ipos-1; i++)
		{
			temp = temp->next;
		}
		
		newn->next = temp->next;
		temp->next = newn;
	}
}

template <class T2>
void SinglyCL<T2> :: InsertAtPos_SCL(T2 no, int ipos)
{
	int Count = Count_SCL();
	
	if(ipos <= 0 || ipos > Count+1)
	{
		cout<<"\nInvalid position\n\n";
		return;
	}
	
	if(ipos == 1)
	{
		InsertFirst_SCL(no);
	}
	else if(ipos == Count+1)
	{
		InsertLast_SCL(no);
	}
	else
	{
		struct nodeSC<T2> * newn = new struct nodeSC<T2>;
		newn->data = no;
		newn->next = NULL;
		
		struct nodeSC<T2> * temp = First;
		
		for(int i = 1; i< ipos-1; i++)
		{
			temp = temp->next;
		}
		
		newn->next = temp->next;
		temp->next = newn;
	}
}

template <class T3>
void DoublyLL<T3> :: InsertAtPos_DLL(T3 no, int ipos)
{
	int Count = Count_DLL();
	
	if(ipos <= 0 || ipos > Count+1)
	{
		cout<<"\nInvalid position\n\n";
		return;
	}
	
	if(ipos == 1)
	{
		InsertFirst_DLL(no);
	}
	else if(ipos == Count+1)
	{
		InsertLast_DLL(no);
	}
	else
	{
		struct nodeDL<T3> * newn = new struct nodeDL<T3>;
		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;
		
		struct nodeDL<T3> * temp = First;
		
		for(int i = 1; i< ipos-1; i++)
		{
			temp = temp->next;
		}
		
		newn->next = temp->next;
		temp->next = newn;
		newn->prev = temp;
		newn->next->prev = newn;
	}
}

template <class T4>
void DoublyCL<T4> :: InsertAtPos_DCL(T4 no, int ipos)
{
	int Count = Count_DCL();
	
	if(ipos <= 0 || ipos > Count+1)
	{
		cout<<"\nInvalid position\n\n";
		return;
	}
	
	if(ipos == 1)
	{
		InsertFirst_DCL(no);
	}
	else if(ipos == Count+1)
	{
		InsertLast_DCL(no);
	}
	else
	{
		struct nodeDC<T4> * newn = new struct nodeDC<T4>;
		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;
		
		struct nodeDC<T4> * temp = First;
		
		for(int i = 1; i< ipos-1; i++)
		{
			temp = temp->next;
		}
		
		newn->next = temp->next;
		temp->next = newn;
		newn->prev = temp;
		newn->next->prev = newn;
	}
}

template <class T1>
void SinglyLL<T1> :: DeleteFirst_SLL()
{
	if(First == NULL)
	{
		cout<<"Linked list is empty\n";
	    return;	
	}
	
	if(First->next == NULL)
	{
		delete First;
		First = NULL;
	}
	else
	{
		struct nodeSL<T1> * temp = First;
		First = First->next;
		delete temp;
	}
}

template <class T2>
void SinglyCL<T2> :: DeleteFirst_SCL()
{
	if(First == NULL && Last == NULL)
	{
		cout<<"Linked list is empty\n";
	    return;	
	}
	
	if(First == Last)
	{
		delete First;
		First = Last = NULL;
	}
	else
	{
		Last->next = First->next;
		delete First;
		First = Last->next;
	}
}

template <class T3>
void DoublyLL<T3> :: DeleteFirst_DLL()
{
	if(First == NULL)
	{
		cout<<"Linked list is empty\n";
	    return;	
	}
	
	if(First->next == NULL)
	{
		delete First;
		First = NULL;
	}
	else
	{
		struct nodeDL<T3> * temp = First;
		First = First->next;
		delete temp;
	}
}

template <class T4>
void DoublyCL<T4> :: DeleteFirst_DCL()
{
	if(First == NULL && Last == NULL)
	{
		cout<<"Linked list is empty\n";
	    return;	
	}
	
	if(First == Last)
	{
		delete First;
		First = Last = NULL;
	}
	else
	{
		Last->next = First->next;
		First->next = Last;
		delete First;
		First = Last->next;
	}
}

template <class T1>
void SinglyLL<T1> :: DeleteLast_SLL()
{
	if(First == NULL)
	{
		cout<<"Linked list is empty\n";
	    return;	
	}
	
	if(First->next == NULL)
	{
		delete First;
		First = NULL;
	}
	else
	{
		struct nodeSL<T1> * temp = First;
		
		while(temp->next->next != NULL)
		{
		   temp = temp->next;	
		}
		
		delete temp->next;
		temp->next = NULL;
	}
}

template <class T2>
void SinglyCL<T2> :: DeleteLast_SCL()
{
	if(First == NULL && Last == NULL)
	{
		cout<<"Linked list is empty\n";
	    return;	
	}
	
	if(First == Last)
	{
		delete First;
		First = Last = NULL;
	}
	else
	{
		struct nodeSC<T2> * temp = First;
		
		while(temp->next != Last)
		{
			temp = temp->next;
		}
		
		delete temp->next;
		temp->next = First;
		Last = temp;
	}
}

template <class T3>
void DoublyLL<T3> :: DeleteLast_DLL()
{
	if(First == NULL)
	{
		cout<<"Linked list is empty\n";
	    return;	
	}
	
	if(First->next == NULL)
	{
		delete First;
		First = NULL;
	}
	else
	{
		struct nodeDL<T3> * temp = First;
		
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		
		delete temp->next;
		temp->next = NULL;
	}
}

template <class T4>
void DoublyCL<T4> :: DeleteLast_DCL()
{
	if(First == NULL && Last == NULL)
	{
		cout<<"Linked list is empty\n";
	    return;	
	}
	
	if(First == Last)
	{
		delete First;
		First = Last = NULL;
	}
	else
	{
		Last->prev->next = First;
		First->prev = Last->prev;
		delete Last;
		Last = First->prev;	
	}
}


template <class T1>
void SinglyLL<T1> :: DeleteAtPos_SLL(int ipos)
{
	int Count = Count_SLL();
	
	if(ipos <= 0 || ipos > Count)
	{
		cout<<"Invalid position\n";
		return;
	}
	
	if(ipos == 1)
	{
		DeleteFirst_SLL();
	}
	else if(ipos == Count)
	{
		DeleteLast_SLL();
	}
	else
	{
		struct nodeSL<T1> * temp1 = First;
		struct nodeSL<T1> * temp2 = NULL;
		
		for(int i = 1; i< ipos-1; i++)
		{
			temp1 = temp1->next;
		}
		
		temp2 = temp1->next;
		temp1->next = temp2->next;
		delete temp2;
	}
}

template <class T2>
void SinglyCL<T2> :: DeleteAtPos_SCL(int ipos)
{
	int Count = Count_SCL();
	
	if(ipos <= 0 || ipos > Count)
	{
		cout<<"Invalid position\n";
		return;
	}
	
	if(ipos == 1)
	{
		DeleteFirst_SCL();
	}
	else if(ipos == Count)
	{
		DeleteLast_SCL();
	}
	else
	{
		struct nodeSC<T2> * temp1 = First;
		struct nodeSC<T2> * temp2 = NULL;
		
		for(int i = 1; i< ipos-1; i++)
		{
			temp1 = temp1->next;
		}
		
		temp2 = temp1->next;
		temp1->next = temp2->next;
		delete temp2;
	}
}

template <class T3>
void DoublyLL<T3> :: DeleteAtPos_DLL(int ipos)
{
	int Count = Count_DLL();
	
	if(ipos <= 0 || ipos > Count)
	{
		cout<<"Invalid position\n";
		return;
	}
	
	if(ipos == 1)
	{
		DeleteFirst_DLL();
	}
	else if(ipos == Count)
	{
		DeleteLast_DLL();
	}
	else
	{
		struct nodeDL<T3> * temp1 = First;
        struct nodeDL<T3> * temp2 = NULL;
		
		for(int i = 1; i< ipos-1; i++)
		{
			temp1 = temp1->next;
		}
		
		temp2 = temp1->next;
		temp2->next->prev = temp1;
		temp1->next = temp2->next;
		delete temp2;
	}
}

template <class T4>
void DoublyCL<T4> :: DeleteAtPos_DCL(int ipos)
{
	int Count = Count_DCL();
	
	if(ipos <= 0 || ipos > Count)
	{
		cout<<"Invalid position\n";
		return;
	}
	
	if(ipos == 1)
	{
		DeleteFirst_DCL();
	}
	else if(ipos == Count)
	{
		DeleteLast_DCL();
	}
	else
	{
		struct nodeDC<T4> * temp1 = First;
		struct nodeDC<T4> * temp2 = NULL;
		
		for(int i = 1; i< ipos-1; i++)
		{
			temp1 = temp1->next;
		}
		
		temp2 = temp1->next;
		temp2->next->prev = temp1;
		temp1->next = temp2->next;
		delete temp2;
	}
}

int main()
{
    SinglyLL <int>obj_SLL1;
    SinglyLL <char>obj_SLL2;
	
	SinglyCL <char>obj_SCL1;
    SinglyCL <float>obj_SCL2;
	
	DoublyLL <double>obj_DLL1;
	DoublyLL <float>obj_DLL2;
	
	DoublyCL <int>obj_DCL1;
	DoublyCL <float>obj_DCL2;
	

	cout<<"\n------------------------------------------------------------------\n";	
	cout<<"\tSingly Linear Linked List (Integer): \n";	
	cout<<"------------------------------------------------------------------\n\n";
	
	obj_SLL1.InsertFirst_SLL(51);
	obj_SLL1.Display_SLL();
	obj_SLL1.InsertFirst_SLL(21);
	obj_SLL1.Display_SLL();
	obj_SLL1.InsertFirst_SLL(11);
	obj_SLL1.Display_SLL();
	obj_SLL1.InsertLast_SLL(101);
	obj_SLL1.Display_SLL();
	obj_SLL1.InsertAtPos_SLL(10,1);
	obj_SLL1.Display_SLL();
	obj_SLL1.InsertAtPos_SLL(111,6);
	obj_SLL1.Display_SLL();
	obj_SLL1.InsertAtPos_SLL(20,3);
	obj_SLL1.Display_SLL();
	obj_SLL1.InsertAtPos_SLL(20,9);
	obj_SLL1.Display_SLL();
	obj_SLL1.DeleteFirst_SLL();
	obj_SLL1.Display_SLL();
	obj_SLL1.DeleteLast_SLL();
	obj_SLL1.Display_SLL();
	obj_SLL1.DeleteAtPos_SLL(2);
	obj_SLL1.Display_SLL();
	obj_SLL1.DeleteAtPos_SLL(3);
	obj_SLL1.Display_SLL();
	
	cout<<"\n------------------------------------------------------------------\n";
	cout<<"\tSingly Linear Linked List (Character): \n";
	cout<<"------------------------------------------------------------------\n\n";
	
	obj_SLL2.InsertFirst_SLL('C');
	obj_SLL2.Display_SLL();
	obj_SLL2.InsertFirst_SLL('B');
	obj_SLL2.Display_SLL();
	obj_SLL2.InsertFirst_SLL('A');
	obj_SLL2.Display_SLL();
	obj_SLL2.InsertLast_SLL('D');
	obj_SLL2.Display_SLL();
	obj_SLL2.InsertAtPos_SLL('a',1);
	obj_SLL2.Display_SLL();
	obj_SLL2.InsertAtPos_SLL('E',6);
	obj_SLL2.Display_SLL();
	obj_SLL2.InsertAtPos_SLL('b',3);
	obj_SLL2.Display_SLL();
	obj_SLL2.InsertAtPos_SLL('J',9);
	obj_SLL2.Display_SLL();
	obj_SLL2.DeleteFirst_SLL();
	obj_SLL2.Display_SLL();
	obj_SLL2.DeleteLast_SLL();
	obj_SLL2.Display_SLL();
	obj_SLL2.DeleteAtPos_SLL(2);
	obj_SLL2.Display_SLL();
	obj_SLL2.DeleteAtPos_SLL(3);
	obj_SLL2.Display_SLL();
	
	cout<<"\n------------------------------------------------------------------\n";	
	cout<<"\tSingly Circular Linked List (Character): \n";	
	cout<<"------------------------------------------------------------------\n\n";
	
	obj_SCL1.InsertFirst_SCL('C');
	obj_SCL1.Display_SCL();
	obj_SCL1.InsertFirst_SCL('B');
	obj_SCL1.Display_SCL();
	obj_SCL1.InsertFirst_SCL('A');
	obj_SCL1.Display_SCL();
	obj_SCL1.InsertLast_SCL('D');
	obj_SCL1.Display_SCL();
	obj_SCL1.InsertAtPos_SCL('a',1);
	obj_SCL1.Display_SCL();
	obj_SCL1.InsertAtPos_SCL('E',6);
	obj_SCL1.Display_SCL();
	obj_SCL1.InsertAtPos_SCL('b',3);
	obj_SCL1.Display_SCL();
	obj_SCL1.InsertAtPos_SCL('J',9);
	obj_SCL1.Display_SCL();
	obj_SCL1.DeleteFirst_SCL();
	obj_SCL1.Display_SCL();
	obj_SCL1.DeleteLast_SCL();
	obj_SCL1.Display_SCL();
	obj_SCL1.DeleteAtPos_SCL(2);
	obj_SCL1.Display_SCL();
	obj_SCL1.DeleteAtPos_SCL(3);
	obj_SCL1.Display_SCL();
	
	cout<<"\n------------------------------------------------------------------\n";	
	cout<<"\tSingly Circular Linked List (Float): \n";	
	cout<<"------------------------------------------------------------------\n\n";
	
	obj_SCL2.InsertFirst_SCL(51.2f);
	obj_SCL2.Display_SCL();
	obj_SCL2.InsertFirst_SCL(21.45f);
	obj_SCL2.Display_SCL();
	obj_SCL2.InsertFirst_SCL(11.2f);
	obj_SCL2.Display_SCL();
	obj_SCL2.InsertLast_SCL(101.80f);
	obj_SCL2.Display_SCL();
	obj_SCL2.InsertAtPos_SCL(10.10f,1);
	obj_SCL2.Display_SCL();
	obj_SCL2.InsertAtPos_SCL(111.0f,6);
	obj_SCL2.Display_SCL();
	obj_SCL2.InsertAtPos_SCL(20.63f,3);
	obj_SCL2.Display_SCL();
	obj_SCL2.InsertAtPos_SCL(20.85f,9);
	obj_SCL2.Display_SCL();
	obj_SCL2.DeleteFirst_SCL();
	obj_SCL2.Display_SCL();
	obj_SCL2.DeleteLast_SCL();
	obj_SCL2.Display_SCL();
	obj_SCL2.DeleteAtPos_SCL(2);
	obj_SCL2.Display_SCL();
	obj_SCL2.DeleteAtPos_SCL(3);
	obj_SCL2.Display_SCL();
	
	cout<<"\n------------------------------------------------------------------\n";	
	cout<<"\tDoubly Linear Linked List (Double): \n";	
	cout<<"------------------------------------------------------------------\n\n";
	
	obj_DLL1.InsertFirst_DLL(51.41);
	obj_DLL1.Display_DLL();
	obj_DLL1.InsertFirst_DLL(21.85);
	obj_DLL1.Display_DLL();
	obj_DLL1.InsertFirst_DLL(11.0);
	obj_DLL1.Display_DLL();
	obj_DLL1.InsertLast_DLL(101.41);
	obj_DLL1.Display_DLL();
	obj_DLL1.InsertAtPos_DLL(10.96,1);
	obj_DLL1.Display_DLL();
	obj_DLL1.InsertAtPos_DLL(111.36,6);
	obj_DLL1.Display_DLL();
	obj_DLL1.InsertAtPos_DLL(20.42,3);
	obj_DLL1.Display_DLL();
	obj_DLL1.InsertAtPos_DLL(20.36,9);
	obj_DLL1.Display_DLL();
	obj_DLL1.DeleteFirst_DLL();
	obj_DLL1.Display_DLL();
	obj_DLL1.DeleteLast_DLL();
	obj_DLL1.Display_DLL();
	obj_DLL1.DeleteAtPos_DLL(2);
	obj_DLL1.Display_DLL();
	obj_DLL1.DeleteAtPos_DLL(3);
	obj_DLL1.Display_DLL();
	
	cout<<"\n------------------------------------------------------------------\n";	
	cout<<"\tDoubly Linear Linked List (Float): \n";	
	cout<<"------------------------------------------------------------------\n\n";
	
	obj_DLL2.InsertFirst_DLL(51.25f);
	obj_DLL2.Display_DLL();
	obj_DLL2.InsertFirst_DLL(21.1f);
	obj_DLL2.Display_DLL();
	obj_DLL2.InsertFirst_DLL(11.5f);
	obj_DLL2.Display_DLL();
	obj_DLL2.InsertLast_DLL(101.52f);
	obj_DLL2.Display_DLL();
	obj_DLL2.InsertAtPos_DLL(10.5f,1);
	obj_DLL2.Display_DLL();
	obj_DLL2.InsertAtPos_DLL(111.85f,6);
	obj_DLL2.Display_DLL();
	obj_DLL2.InsertAtPos_DLL(20.03f,3);
	obj_DLL2.Display_DLL();
	obj_DLL2.InsertAtPos_DLL(20.3f,9);
	obj_DLL2.Display_DLL();
	obj_DLL2.DeleteFirst_DLL();
	obj_DLL2.Display_DLL();
	obj_DLL2.DeleteLast_DLL();
	obj_DLL2.Display_DLL();
	obj_DLL2.DeleteAtPos_DLL(2);
	obj_DLL2.Display_DLL();
	obj_DLL2.DeleteAtPos_DLL(3);
	obj_DLL2.Display_DLL();
	
	cout<<"\n------------------------------------------------------------------\n";	
	cout<<"\tDoubly Circular Linked List (Integer): \n";	
	cout<<"------------------------------------------------------------------\n\n";
	
	obj_DCL1.InsertFirst_DCL(51);
	obj_DCL1.Display_DCL();
	obj_DCL1.InsertFirst_DCL(21);
	obj_DCL1.Display_DCL();
	obj_DCL1.InsertFirst_DCL(11);
	obj_DCL1.Display_DCL();
	obj_DCL1.InsertLast_DCL(101);
	obj_DCL1.Display_DCL();
	obj_DCL1.InsertAtPos_DCL(10,1);
	obj_DCL1.Display_DCL();
	obj_DCL1.InsertAtPos_DCL(111,6);
	obj_DCL1.Display_DCL();
	obj_DCL1.InsertAtPos_DCL(20,3);
	obj_DCL1.Display_DCL();
	obj_DCL1.InsertAtPos_DCL(20,9);
	obj_DCL1.Display_DCL();
	obj_DCL1.DeleteFirst_DCL();
	obj_DCL1.Display_DCL();
	obj_DCL1.DeleteLast_DCL();
	obj_DCL1.Display_DCL();
	obj_DCL1.DeleteAtPos_DCL(2);
	obj_DCL1.Display_DCL();
	obj_DCL1.DeleteAtPos_DCL(3);
	obj_DCL1.Display_DCL();
	
	cout<<"\n------------------------------------------------------------------\n";	
	cout<<"\tDoubly Circular Linked List (Float): \n";	
	cout<<"------------------------------------------------------------------\n\n";
	
	obj_DCL2.InsertFirst_DCL(51.0f);
	obj_DCL2.Display_DCL();
	obj_DCL2.InsertFirst_DCL(21.4f);
	obj_DCL2.Display_DCL();
	obj_DCL2.InsertFirst_DCL(11.85f);
	obj_DCL2.Display_DCL();
	obj_DCL2.InsertLast_DCL(101.28f);
	obj_DCL2.Display_DCL();
	obj_DCL2.InsertAtPos_DCL(10.51f,1);
	obj_DCL2.Display_DCL();
	obj_DCL2.InsertAtPos_DCL(111.84f,6);
	obj_DCL2.Display_DCL();
	obj_DCL2.InsertAtPos_DCL(20.67f,3);
	obj_DCL2.Display_DCL();
	obj_DCL2.InsertAtPos_DCL(20.7f,9);
	obj_DCL2.Display_DCL();
	obj_DCL2.DeleteFirst_DCL();
	obj_DCL2.Display_DCL();
	obj_DCL2.DeleteLast_DCL();
	obj_DCL2.Display_DCL();
	obj_DCL2.DeleteAtPos_DCL(2);
	obj_DCL2.Display_DCL();
	obj_DCL2.DeleteAtPos_DCL(3);
	obj_DCL2.Display_DCL();
	
	cout<<"\n----------------------------------------------------------------------------------------------\n";
	
    return 0;
}

