#include <iostream>
#include <string>
#include <cstring>

using namespace std;

template <class T>
class ListElement
{
public:
	T	data;
	ListElement<T>	*next;
	ListElement(T &i_d, ListElement<T> *i_n):data(i_d),next(i_n) {}
	ListElement<T>* copy()
	{
		return new ListElement(data, (next?next->copy():0));
	}
};

template <class T>
class ListIterator
{
public:
	T operator()();
	int operator++();
	int operator!();
public:
	ListElement<T> *rep;
};

template <class T>
T ListIterator<T>::operator() ()
{
	if(rep)
		return rep->data;
	else
	{
		T	tmp;
		return tmp;
	}
}

template <class T>
int ListIterator<T>::operator++ ()
{
	if(rep)
		rep = rep->next;

	return (rep!=0);
}

template <class T>
int ListIterator<T>::operator! ()
{
	return (rep!=0);
}

template <class T>
class List
{
public:
	friend class ListIterator<T>;
	List();
	List(const List&);
	~List();
	List<T>& operator=(const List<T>&);
	
	T head();
	List<T> tail();
	void add(T&);
	friend ostream& operator<<(ostream&, const List<T>&);

public:
	void clear();
	ListElement<T> *rep;
};

template <class T>
List<T>::List()
{
	rep = 0;
}

template <class T>
List<T>::List(const List<T>& l)
{
	rep = l.rep ? l.rep->copy() : 0;
}

template <class T>
List<T>& List<T>::operator=(const List<T>& l)
{
	if(rep != l.rep)
	{
		clear();
		rep = l.rep ? l.rep->copy() : 0;
	}

	return *this;
}

template <class T>
List<T>::~List()
{
	clear();
}

template <class T>
void List<T>::clear()
{
	while(rep)
	{
		ListElement<T>* tmp = rep;
		rep = rep->next;
		delete tmp;
	}
	rep = 0;
}

template <class T>
void List<T>::add(T &i)
{
	rep = new ListElement<T>(i, rep);
}

template <class T>
T List<T>::head()
{
	if(rep)
		return rep->data;
	else
	{
		T tmp;
		return tmp;
	}
}

template <class T>
List<T> List<T>::tail()
{
	List<T> tmp;

	if(rep)
		if(rep->next)
			tmp.rep = rep->next->copy();

	return tmp;
}

template <class T>
ostream& operator<<(ostream &os, const List<T>& l)
{
	if(l.rep)
	{
		ListElement<T> *p = l.rep;
		os<<"(";
		while(p)
		{
			os<<p->data<<"  ";
			p = p->next;
		}
		os<<")\n";
	}
	else
	{
		os<<"Empty list\n";
	}

	return os;
}

int main(void)
{
	List<int> l;
	cout<<l;
	int i = 1;
	l.add(i);
	i = 2;
	l.add(i);
	i = 3;
	l.add(i);
	cout<<"l is "<<l<<endl;
	cout<<"head of l is "<<l.head()<<endl;
	List<int> m = l.tail();
	List<int> o;
	o = m;
	i = 4;
	m.add(i);
	cout<<"m is "<<m<<endl;
	cout<<"o is "<<o<<endl;
	List<char> clist;
	char ch;
	ch = 'a';
	clist.add(ch);
	ch = 'b';
	clist.add(ch);
	cout<<clist<<endl;
	List<string> ls;
	string str("hello");
	ls.add(str);
	str = "world";
	ls.add(str);
	cout<<"List of strings"<<endl;
	cout<<ls<<endl;
	List<List<int> > listlist;
	listlist.add(o);
	listlist.add(m);
	cout<<"List of lists of ints\n";
	cout<<listlist<<endl;
	List<List<List<int> > > lllist;
	lllist.add(listlist);
	lllist.add(listlist);
	cout<<"List of lists of lists of ints\n";
	cout<<lllist<<endl;
	List<List<string> > slist;
	slist.add(ls);
	slist.add(ls);
	cout<<"List of lists of strings\n";
	cout<<slist<<endl;
	
	return 0;
}
