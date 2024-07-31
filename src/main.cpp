#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <limits> //used for error handling
#include "water_quality.hpp" //header file for water_quality class
using std::cout;
using std::endl;
using std::cin;

/* -----------------------------------------------------------------------------------------------------------------------------------------------------------------

WATER SAMPLING PROGRAM

By: Claudio Perinuzzi, 11/22/23

program consists of -> main.cpp
					-> water_quality.hpp
					-> water_quality.cpp	

resources used:
	Information on National Primary Drinking Water Regulations obtained from the U.S. Environmental Protection Agency. 
	(URL: https://www.epa.gov/ground-water-and-drinking-water/national-primary-drinking-water-regulations#Inorganic)

------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//functions below are used within the main menu logic in main and are used to manipulate the water_sample vector

//test water samples
void test_water_samples(vector<water_quality> &water_sample, int num_of_samples) {
	static int sample_number = 1;
	int i = sample_number + num_of_samples; 				//current index i = current sample number plus new samples made
	while (sample_number < i) {								//while this sample number is less than how many samples were added to index i
		string number = std::to_string(sample_number);	
		string sample_name = "Sample " + number;
		water_quality sample;								//create a sample object
		sample.generate_random_data(number, water_sample);  //generate random data for the object
		water_sample.push_back(sample);						//append the object to the water sample vector
		cout << water_sample.back().get_results() << endl;	//prints the results of the water sample
		sample_number++;
	}
}

//search for results by id
void search_id_number(vector<water_quality> water_sample, string id_number) {
	bool found = false;
	for (int i = 0; i < water_sample.size(); i++) {	 //iterate through object vector until we find a match
		if (water_sample[i].get_id() == id_number) {
			cout << water_sample[i].get_results();
			found = true;
			break;
		}
	}
	if (!found) cout << "No results found!\n";
}

//deletes a water sample object from the vector
void delete_sample(vector<water_quality> &water_sample, string id_number) {
	bool found = false;
	for (int i = 0; i < water_sample.size(); i++) {	//iterate through object vector until we find a match
		if (water_sample[i].get_id() == id_number) {
			water_sample.erase(water_sample.begin() + i); //erase the current water sample object
			found = true;
		}
	}
	if (!found) cout << "No results found!\n";
	else cout << "Sample successfully deleted.\n";
}

//displays the results of all water sample objects from the vector
void display_results(vector<water_quality> water_sample) {
	for (int i = 0; i < water_sample.size(); i++) {
		cout << water_sample[i].get_results();
	}
}

//saves the results to a .txt file
void save_results(vector<water_quality> water_sample) {
	std::ofstream f;									//create a ofstream object f
	f.open("Water_Sample_Reports.txt");					//creates a .txt file
	if (!f.is_open()) {			
		cout << "Error, cannot save file." << endl;
		return;
	}
	for (int i = 0; i < water_sample.size(); i++) {		//populates a text file with all current results
		f << water_sample[i].get_results();
	}
	f.close();											//closes the file
	cout << "Results sucessfully saved!" << endl;
}

int main() {

	cout << "---WELCOME TO THE WATER SAMPLING PROGRAM---" << endl;
	cout << "\nInstructions: type in any of the numbers below and press enter." << endl;
	cout << "\t1) Test water samples." << endl;
	cout << "\t2) Search samples tested." << endl;
	cout << "\t3) Delete samples tested." << endl;
	cout << "\t4) Display samples tested." << endl;
	cout << "\t5) Save results to a text file." << endl;
	cout << "\t6) Quit, notice data will be lost if results are not saved.\n" << endl;

	cout << "Please enter a number from above: ";

	srand(time(0)); //seed random number generator

	//declare variables used
	int num_of_samples = 0;	
	bool saved = false;
	string menu_response, quit_input, id_number; 
	vector<water_quality> water_sample;			//declare a vector of water quality objects called water sample

	//main menu logic
	while (true) {

		cin >> menu_response;

		//test samples
		if (menu_response == "1") { 
			cout << "Please enter the number of water samples in which you wish to test: ";
			cin >> num_of_samples;	
			while (!cin) { 		//while not an int (error in input stream)
			    cout << "Invalid input. Please enter an integer: ";
                cin.clear();  //clears the error flag on input stream
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //discards the invalid input up to the newline character \n
                cin >> num_of_samples;	//reads input again
			}
			test_water_samples(water_sample, num_of_samples); //test water samples
			saved = false; 		//set saved to false if we create more samples
		}

		//search samples
		else if (menu_response == "2") { 
			if (water_sample.empty()) {
				cout << "You have not tested any water samples yet!" << endl;
			}
			else {
				cout << "Please enter the sample ID number to search for the results: ";
				cin >> id_number;
				search_id_number(water_sample, id_number);
			}
		}

		//remove samples
		else if (menu_response == "3") { 
			if (water_sample.empty()) {
				cout << "You have not tested any water samples yet!" << endl;
			}
			else {
				cout << "Please enter the sample ID number to delete the sample: ";
				cin >> id_number;
				delete_sample(water_sample, id_number);
				saved = false;	//set saved to false if we delete samples
			}
		}

		//display water samples
		else if (menu_response == "4") { 
			if (water_sample.empty()) {
				cout << "You have not tested any water samples yet!" << endl;
			}
			else {
				display_results(water_sample);
			}
		}
		
		//save results
		else if (menu_response == "5") { 
			if (water_sample.empty()) {
				cout << "You have not tested any water samples yet!" << endl;
			}
			else {
				saved = true;
				save_results(water_sample);
			}
		}
		
		//quit program
		else if (menu_response == "6") { 
			if (!water_sample.empty() && !saved) { //if the water sample vector is not empty and we have not saved our results
				cout << "You have unsaved data, quitting now will lose data. Would you like to end? Type \"y\" to end, otherwise press anything else to continue.";
				cin >> quit_input;
				if (quit_input == "y") {
					cout << "Program Ended." << endl;
					return 0;
				} 
			}
			else {
				cout << "Program Ended." << endl;
				return 0;
			}
		}

		else {
			cout << "Invalid response. Please enter a number 1 through 6: ";
			continue;
		}

		cout << "What else would you like to do: ";

	}

	return 0;
}