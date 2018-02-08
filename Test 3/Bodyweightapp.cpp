// Test 3 [SIRCLO]
// By Andika Pramana

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>
  
using namespace std;

const int MAX = 100;



struct Info
{
	string date;
	int max;
	int min;
	int variance;

};

void SubMenu_3(char*);
void Selection_Sub1();
void Selection_Sub2();
void Selection_Sub3();
void read_txtfile(fstream&, char *);
void show_summary();
bool sortByDate(const Info &lhs, const Info &rhs);
void show_info_date(string);
void append_rec (char*);
void update_rec (char*);

vector<Info> listofinfo;

int main()
{
	char x;
	do
	{

	cout << "Welcome to CRUD app" << endl;

	cout << endl;
	cout << "1. Show Index Page" << endl;
	cout << "2. Show Max Min for particular day" << endl;
	cout << "3. Create and Edit Page" << endl;
	cout << "9. Quit" << endl;

	cout << "Your option: ";
	cin >> x;


	cout << "----------------------------------------------" << endl;
	cout << endl;


	switch(x)
	{
		case '1' :	Selection_Sub1();
			break;
		case '2' :	Selection_Sub2();
			break;
		case '3' :	Selection_Sub3();
			break;
		case '9' : cout << "Thank you for using CRUD app" << endl;
				   cout << "Have a good day!" << endl;
			break;
		default  : cout << "Invalid Responses" << endl;
				   cout << "----------------------------------------------" << endl;

	}
	}
	while(x != '1' && x != '2' && x != '3' && x != '9');
	{
	
	}
	return 0;
}

void Selection_Sub1()
{
	char filename[MAX];
	int SystemIn = 1;
	fstream infile;

	cout << "Welcome to CRUD app index page" << endl;
	cout << endl;
	
	// ask user about file name first. 
	// in this case the name is supposed to be index.txt / index
	do
	{
		cout << "Please select filename first(ex: index): " ;
		cin  >> filename;
		SystemIn++;
		cout << endl;

	}while(SystemIn < 2);
	
	// append .txt to filename
	strcat(filename,".txt");
	
	// do a reading process on text file
    read_txtfile(infile, filename);
	
	// show the file summary
	show_summary();

}

void read_txtfile(fstream& infile, char * filename_txt)
{
	// clear the array first
	listofinfo.clear();
	
	// initiate reading file processing 
    infile.open (filename_txt, ios::in );
	
	if (!infile)
	{
		// if file open for reading failed
		// exit program
		cout << "Program terminated, Reading file failed" << endl;
		exit(0);
	}
	
	char ch;
	int temp_year, temp_month, temp_day;
	Info anInfo;
	
	// do a loop while not the end of file to read the content of a file
   	while(!infile.eof())
	{
		infile >> temp_year >> ch 
			   >> temp_month >> ch
			   >> temp_day >> ch
			   >> anInfo.max >> ch
			   >> anInfo.min;
		
		// since the input only date, max and min, calculate the variance
		anInfo.variance = anInfo.max-anInfo.min;
		
		// convert the date from int to string
		std::ostringstream oss;
		oss << temp_year << "-" << temp_month << "-" << temp_day;
	    anInfo.date = oss.str();
		
		// add the data to array
		listofinfo.push_back(anInfo);

	}
	
	// close the reading processing
	infile.close ();
	
	cout << "File read succescully"<<endl;
	 

}

// this function is to sort the date to desceding order
bool sortByDate(const Info &lhs, const Info &rhs) { 
	return lhs.date > rhs.date; 
}

void show_summary()
{ 
	// sort the date in decending order
	std::sort(listofinfo.begin(), listofinfo.end(), sortByDate);
	
	// print the header
	cout << "Date" << "\t\t" << "Max" << "\t" << "Min"  << "\t" << "Variance" << endl;
	
	// additional variable for counting average
	float average_max, average_min, average_variance;
	
	for (int i=0; i < listofinfo.size(); i++){
	   // print out all the data
       cout << listofinfo[i].date << "\t" << listofinfo[i].max << "\t" 
	        << listofinfo[i].min  << "\t" << listofinfo[i].variance << endl;
			
			// add the total value for max, min and variance
			average_max += listofinfo[i].max;
			average_min += listofinfo[i].min;
			average_variance += listofinfo[i].variance;
			
    }	
	
	// divide by the count of data to get the average
	average_max = average_max / listofinfo.size();
	average_min = average_min / listofinfo.size();
	average_variance = average_variance / listofinfo.size();
	
	cout << "Average\t\t" << average_max << "\t" << average_min << "\t" << average_variance << endl;
}

void Selection_Sub2()
{
	// second menu, to show a max min for particular date. 
	char filename[MAX], chosenDate[MAX];
	int SystemIn = 1;
	fstream infile;

	cout << "Welcome to CRUD app show page" << endl;
	cout << endl;
	
	// ask the user about the file first
	do
	{
		cout << "Please select filename first(ex: index): " ;
		cin  >> filename;
		SystemIn++;
		cout << endl;

	}while(SystemIn < 2);

	strcat(filename,".txt");
	
	// do a reading process on the text file
    read_txtfile(infile, filename);
	
	SystemIn =1;
	
	// ask user which date they want to view
	do
	{	
		// ask user that the format should be in yyyy-m-dd
		cout << "Please enter the date in format (yyyy-m-dd): " ;
		cin  >> chosenDate;
		SystemIn++;
		cout << endl;

	}while(SystemIn < 2);
	
	// show the information on max, min and variance for that particular page.
	show_info_date(chosenDate);

}

void show_info_date(string chosenDate)
{ 
	bool found = false;
	
	// search within the array for the date that user want to view
	for (int i=0; i < listofinfo.size(); i++){
		// the found, the show the data
		if(!listofinfo[i].date.compare(chosenDate)){
			found = true;
			
			cout << "Date\t\t" << listofinfo[i].date << endl;
			cout << "Max\t\t" << listofinfo[i].max << endl;
			cout << "Min\t\t" << listofinfo[i].min << endl;
			cout << "Variance\t" << listofinfo[i].variance << endl;
		}

			
    }	
	
	// if not found, then show message that date is not found
	if(found == false){
		cout << "Date not found, please try again" << endl;
	}
}

void Selection_Sub3()
{
	// third functionality create and edit page
	char filename[MAX], chosenDate[MAX];
	int SystemIn = 1;
	fstream infile;

	cout << "Welcome to CRUD app create and edit page" << endl;
	cout << endl;
	
	// ask user about the file they want to edit / create
	do
	{
		cout << "Please enter filename to be edit/append first(ex: index): " ;
		cin  >> filename;
		SystemIn++;
		cout << endl;

	}while(SystemIn < 2);

	strcat(filename,".txt");
	
	// do a reading process on the file
	read_txtfile(infile, filename);
	
	// run another menu that user can choose. 
	SubMenu_3(filename);

}

void SubMenu_3(char* filename)
{
	char x;
	
	// for this functionality user can either create 
	// or edit a data. 
	
	// ask user to add or edit a data
 	do
	{

	cout << "1. Append a Record" << endl;
	cout << "2. Update a Record" << endl;
	cout << "9. Quit" << endl;
	cout << endl;
	cout << "Your option: ";
	cin >> x;

	cout << endl;
	cout << "----------------------------------------------" << endl;
	switch(x)
	{

		case '1' : append_rec (filename);
			break;
		case '2' : update_rec (filename);
			break;
		case '9' : ;
			break;
		default : cout << "Invalid Responses" << endl;

	}
	}
	while(!(x == '1' && x =='2' && x == '3'  || x == '9'));
}

void append_rec (char* filename)
{
	fstream afile;
	int SystemIn =1;
	
	cout << "Begin creating data to file " << filename << endl;
	cout << endl;
	
	// start a ios::app processing - appending
	afile.open(filename, ios::out | ios::app);

	if(!afile)
	{
		cout << filename << "opened for creation failed" << endl;
		cout << "----------------------------------------------" << endl;
		return;
	}

	Info anInfo;
	char choice;
	
	// enter the required information about the data
	do
	{
		cout << "Enter the date in format (yyyy-mm-dd): ";
		cin >> anInfo.date;
		
		cout << "Enter Max: ";
		cin >> anInfo.max;
		
		cout << "Enter Min: ";
		cin >> anInfo.min;
		
		// append the info to the file
		afile << endl << anInfo.date << "," << anInfo.max << "," << anInfo.min;
		cout << "Date " << anInfo.date << " has been added" << endl;

		cout << endl;
		cout << "Any more append(y/n): ";
		cin  >> choice;
		cout << endl;

	}while(choice == 'y');

	afile.close();

	cout << "Filename " << filename << " closed for reading" << endl;
	cout << "----------------------------------------------" << endl;
}

void update_rec (char* filename)
{
	cout << "Begin updating of file " <<  filename << endl;
	cout << endl;
	
	fstream afile;
	string chosenDate;
	char choice;
	int noOfRec;
	int temp_year;
	
	do
	{
		Info anInfo;
		
		// ask the user which date they want to edit
		cout << "Please enter the date that you want to edit, in format (yyyy-m-dd): " ;
		cin  >> chosenDate;
	
		cout << endl;
		
		
		read_txtfile(afile, filename);
		
		for (int i=0; i < listofinfo.size(); i++){
	   	
			if(!listofinfo[i].date.compare(chosenDate)){
				noOfRec=i;
				anInfo.date = chosenDate;
				show_info_date(anInfo.date);
				cout << endl;
			}
			else{
			}
			
    	}	
		
		afile.open(filename, ios::out | ios::in);
		

		if(!afile)
		{
			cout << filename << " opened for creation failed" << endl;
			return;
		}
		
		cout << "Update data for date : " << anInfo.date << endl ;
		
		cout << "Please enter Max of this date: " ;
		cin >> anInfo.max;
		cout << endl;
		
		cout << "Please enter Min of this date: " ;
		cin >> anInfo.min;
		cout << endl;
		
		// set the pointer to desired location
		afile.seekp ((noOfRec * sizeof(anInfo)), ios::beg);
		
		// edit the file 
		afile << anInfo.date << "," << anInfo.max << "," << anInfo.min;
		
		cout << "Date : " << anInfo.date << " updated" << endl;

		cout << "Any more update? (y/n) ";
		cin >> choice;
		cout << endl;

		afile.close ();

	}while(choice == 'y');
	
	cout << "File " << filename << " closed for update" << endl;
	cout << "----------------------------------------------" << endl;
}

