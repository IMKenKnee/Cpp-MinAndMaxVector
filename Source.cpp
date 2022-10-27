//Kenny Hedlund
//create a program that sorts minimum and maximum strings and intigers -> based on input file minmax.txt

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
 
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::vector;
using std::string;
ifstream inputFile;

class Minmax
{
private:
	void openFile();
	void testFile();
	void closeFile();
	void vectorDisplay();

	//templates
	template<class T>
	T min(vector <T> v);
	template<class T>
	T max(vector <T> v);

public:
	void driver();
};

/********************Method Definitions********************/

//Minmax: openFile
//opens input file to populate data and calls testFile() method
void Minmax::openFile()
{
	inputFile.open("minmax.txt");

	//test if input file opened
	testFile();
}

//Minmax: testFile
//test if the input file opened correctly
void Minmax::testFile()
{
	if (!inputFile)
	{
		cerr << "minmax.txt did not open properly, please check that the file is present and try again." << endl;
		exit(9999);
	}
}

//Minmax: closeFile
//close the input file
void Minmax::closeFile()
{
	inputFile.close();			//close input file to clear buffers
}

//Minmax: vectorDisplay
//populate vectors with templates and display the results
void Minmax::vectorDisplay()
{	
	//Populate
	ifstream inputFile("minmax.txt");
	if (inputFile.is_open())
	{
		//declare variable and string
		int n;
		string s;

		//vector declarations
		vector<int> vector1;
		vector<string> vector2;

		//for loop to read in data for integers from inputFIle
		for (int i = 0; i < 5; i++)
		{
			inputFile >> n;
			//append new data to end of container
			vector1.push_back(n);
		}

		//for loop to read in data for strings from inputFile
		for (int i = 0; i < 5; i++)
		{
			inputFile >> s;
			//append new data to end of container
			vector2.push_back(s);
		}

		//Display
		//Integers
		cout << "Minimum integer: " << min(vector1) << endl
		    << "Maximum integer: " << max(vector1) << endl;
		//Strings
		cout << "Minimum string: " << min(vector2) << endl
			<< "Maximum string: " << max(vector2) << endl;

		//call to closeFile function to clear buffer
		closeFile();
	}
}

//Minmax: driver
//order of execution
void Minmax::driver()
{
	//open input file and tests
	openFile();

	//populate and display results
	vectorDisplay();

	//close program
	closeFile();
}

/********************Templates********************/

//Minmax: Minimum template
//run a forloop to populate minimums
template <typename T>
T Minmax::min(vector <T> vector) 
{
	T result = vector[0];
	for (int i = 0; i < 5; ++i) 
	{
		//if element is less than result
		if (vector[i] < result) 
		{	
			//set element as new result
			result = vector[i];
		}
	}
	//return result for function display
	return result;
}

//Minmax: Maximum template
//run a forloop to populate maximums
template <typename T>
T Minmax::max(vector <T> vector) 
{
	T result = vector[0];
	for (int i = 0; i < 5; ++i) 
	{
		//if element is greater than result
		if (vector[i] > result) 
		{
			//set element as new result
			result = vector[i];
		}
	}
	//return result for function display
	return result;
}

/********************MAIN********************/
int main()
{
	//instantiate an object for Minmax class
	Minmax vObj;

	//call driver to execute program
	vObj.driver();

	return 0;
}