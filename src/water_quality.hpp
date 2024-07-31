#ifndef WATER_QUALITY_HPP //header guards to prevent multiple inclusions
#define WATER_QUALITY_HPP

#include <iostream>
#include <vector>
using std::string;
using std::vector;

class water_quality {

private:

	//sample number, corresponding id, results and conclusion on whether the water is safe to drink
	string sample_num;
	string ID;
	string results;
	bool is_safe_to_drink;

	//microorganisms
	bool cryptosporidium; 
	bool giardia_lamblia;
	bool legionella;
	bool enteric_viruses;

	//inorganic chemicals
	float antimony; 
	float arsenic;	
	float barium; 
	float beryllium; 
	float cadmium;
	float chromium;
	float copper; 
	float cyanide;
	float fluoride; 
	float lead; 
	float mercury;
	float nitrate; 
	float nitrite;
	float selenium;
	float thallium;

public:

	//Randomized Constructor
	void generate_random_data(string num, vector<water_quality> water_sample);

	//getters
	string get_sample_num();
	string get_id();
	string get_results();
	bool get_is_safe_to_drink();
	bool get_cryptosporidium();
	bool get_giardia_lamblia();
	bool get_legionella();
	bool get_enteric_viruses();
	float get_antimony();
	float get_arsenic();
	float get_barium();
	float get_beryllium();
	float get_cadmium();
	float get_chromium();
	float get_copper();
	float get_cyanide();
	float get_fluoride();
	float get_lead();
	float get_mercury();
	float get_nitrate();
	float get_nitrite();
	float get_selenium();
	float get_thallium();
	
	//--------------- METHODS SECTION ---------------

	//generate a random id for sample
	string random_id_generator(vector<water_quality> water_sample);

	//10% chance of testing for each microorganism
	bool bool_generator();

	//generates a 95% chance for a small value (for substances with a smaller MCL #)
	float small_chemical_generator();

	//generates a 10% chance for a larger value (for substances with a larger MCL #)
	float large_chemical_generator();

	//calculates the results of all microorganisms and substances tested
	string calculate_results();
};

#endif
