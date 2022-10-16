#include <Python.h>
#include <iostream>
#define NOMINMAX
#include <Windows.h>
#undef NOMINMAX
#include <cmath>
#include <string>
#include <fstream>


using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("CornerGrocer");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"CornerGrocer");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"CornerGrocer");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

//Create the menu for the Grocery list choices
void menu()
{
	int choice = 0;
	int itemQuantity;
	string itemChoice = " ";
	string itemName;
	ifstream file;

	//Create the Main menu, loop until user wishes to exit.
	while (choice != -1)
	{
		cout << "Grocery Tracking" << endl;
		cout << "1. Produce a list of all items purchased in a given day along with the number of times each item was purchased." << endl;
		cout << "2. Produce a number representing how many times a specific item was purchased in a given day." << endl;
		cout << "3. Produce a text-based histogram listing all items purchased in a given day, along with a representation of the number of times each item was purchased." << endl;
		cout << "4. Exit" << endl;
		cout << "Please make a selection" << endl;
		cin >> choice;

		//Check if the user did not enter an integer.
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please make a valid choice." << endl;
			cin >> choice;
		}

		//Process the user choice.
		if (choice == 1)
		{
			CallProcedure("displayItemsPurchased");
			system("PAUSE");
			system("CLS");
		}
		else if (choice == 2)
		{
			cout << "Please enter the item you wish to check: " << endl;
			cin >> itemChoice;
			cout << itemChoice << ": " << callIntFunc("displaySpecificItemPurchased", itemChoice) << endl;
			system("PAUSE");
			system("CLS");
		}
		else if (choice == 3)
		{
			//Calls the python function displayItemsPurchasedHistogram program and writes to the respective frequency file.
			CallProcedure("displayItemsPurchasedHistogram");

			//Open frequency.dat, previously created and written to by the displayItemsPurchasedHistogram python function
			file.open("frequency.dat");

			//Get the first item name and its quantity
			file >> itemName;
			file >> itemQuantity;

			//Creates the histogram based on how many of each item was sold
			while (!file.fail())
			{
				cout << itemName;
				for (int i = 0; i < itemQuantity; ++i)
				{
					cout << "*";
				}

				cout << endl;
				file >> itemName;
				file >> itemQuantity;
			}

			//Close the file
			file.close();
			system("PAUSE");
			system("CLS");
		}
		else if(choice == 4)
		{
			cout << "Goodbye";
			choice = -1;
		}
	}
}


void main()
{
	menu();
}