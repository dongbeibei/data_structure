#include <iostream>
#include <cstdlib>

using namespace std;

int main(void)
{
	try
	{
		int *p = new int[10000000000L];
	}
	catch(bad_alloc& ba)
	{
		cerr<<"Error: "<<ba.what()<<endl;
		//abort();
		exit(EXIT_FAILURE);
	}

	cout<<"The end of the process"<<endl;

	return 0;
}
