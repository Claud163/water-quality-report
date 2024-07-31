#include "water_quality.hpp" 
using std::string;
using std::vector;
using std::to_string;

	//Randomized Constructor
	void water_quality::generate_random_data(string num, vector<water_quality> water_sample) {
		
		//generate unique ID information
		sample_num = num;
		ID = random_id_generator(water_sample);
		
		//generate a positive or false result for the following microorganisms
		cryptosporidium = bool_generator();
		giardia_lamblia = bool_generator();
		legionella 		= bool_generator();
		enteric_viruses = bool_generator();

		//generates large or small floats depending on maximum contaminant number (MCL # (mg/L))
		antimony 	= small_chemical_generator();	//MCL # = 0.006 mg/L
		arsenic 	= small_chemical_generator();	//MCL # = 0.010 mg/L
		barium 		= large_chemical_generator(); 	//MCL # = 2 	mg/L
		beryllium 	= small_chemical_generator();	//MCL # = 0.004 mg/L
		cadmium 	= small_chemical_generator();	//MCL # = 0.005 mg/L
		chromium 	= small_chemical_generator();	//MCL # = 0.1 	mg/L
		copper 		= large_chemical_generator();	//MCL # = 1.3 	mg/L
		cyanide 	= small_chemical_generator();	//MCL # = 0.2 	mg/L
		fluoride 	= large_chemical_generator();	//MCL # = 4.0 	mg/L
		lead 		= small_chemical_generator();	//MCL # = 0.015 mg/L
		mercury 	= small_chemical_generator();	//MCL # = 0.002 mg/L
		nitrate 	= large_chemical_generator();	//MCL # = 10 	mg/L
		nitrite 	= large_chemical_generator();	//MCL # = 1 	mg/L
		selenium 	= small_chemical_generator();	//MCL # = 0.05 	mg/L
		thallium 	= small_chemical_generator();	//MCL # = 0.002 mg/L 

		//calculates potential health concerns
		results = calculate_results();
	}

	//getters
	string water_quality::get_sample_num() {
		return sample_num;
	}

	string water_quality::get_id() {
		return ID;
	}

	string water_quality::get_results() {
		return results;
	}

	bool water_quality::get_is_safe_to_drink() {
		return is_safe_to_drink;
	}

	bool water_quality::get_cryptosporidium() {
		return cryptosporidium;
	}

	bool water_quality::get_giardia_lamblia() {
		return giardia_lamblia;
	}

	bool water_quality::get_legionella() {
		return legionella;
	}

	bool water_quality::get_enteric_viruses() {
		return enteric_viruses;
	}

	float water_quality::get_antimony() {
		return antimony;
	}

	float water_quality::get_arsenic() {
		return arsenic;
	}

	float water_quality::get_barium() {
		return barium;
	}

	float water_quality::get_beryllium() {
		return beryllium;
	}

	float water_quality::get_cadmium() {
		return cadmium;
	}

	float water_quality::get_chromium() {
		return chromium;
	}

	float water_quality::get_copper() {
		return copper;
	}

	float water_quality::get_cyanide() {
		return cyanide;
	}

	float water_quality::get_fluoride() {
		return fluoride;
	}

	float water_quality::get_lead() {
		return lead;
	}

	float water_quality::get_mercury() {
		return mercury;
	}

	float water_quality::get_nitrate() {
		return nitrate;
	}

	float water_quality::get_nitrite() {
		return nitrite;
	}

	float water_quality::get_selenium() {
		return selenium;
	}

	float water_quality::get_thallium() {
		return thallium;
	}

	//--------------- CLASS METHODS SECTION ---------------

	//generate a random id for sample
	string water_quality::random_id_generator(vector<water_quality> water_sample) {
		int random_id_num = rand() % (99999 - 10000 + 1) + 10000; //random 5 digit number
		string random_id = std::to_string(random_id_num);
		for (int i = 0; i < water_sample.size(); i++) { //checks if id is already in use
			if (water_sample[i].get_id() == random_id) return random_id_generator(water_sample);	
		}
		return random_id;
	}

	//10% chance of testing for each microorganism
	bool water_quality::bool_generator() {
		int random_number = rand() % 100 + 1;	//generates a random number between 1 and 100
		if (random_number <= 10) return true; 	//10% chance 
		else return false;
	}

	//generates a 95% chance for a small value (for substances with a smaller MCL #)
	float water_quality::small_chemical_generator() {
		int probability = rand() % 100 + 1;		//generates a random number between 1 and 100
		if (probability <= 5) { 				//5% chance of a possible larger value
			float random_float = float(rand() % (999 + 1)); //creates a random float between 0 and 999
			return random_float / 1000;						//returns the random float divided by 1000 to achieve a decimal
		} 
		else { //95% chance of a smaller number
			float random_float = float(rand() % (7)); //creates a random float between 0 and 6 
			return random_float / 1000;			      //returns the random float divided by 1000 to achieve 0.006 as the max or less 
		}											  //max of 0.006 used for only the 95% chance of a smaller number
	}												  //0.006 max is about half of the chemicals using the small chemical generator

	//generates a 10% chance for a larger value (for substances with a larger MCL #)
	float water_quality::large_chemical_generator() {
		int probability = rand() % 100 + 1; //generates a random number between 1 and 100
		if (probability <= 10) { 			//10% chance of a possible larger number
			float random_float = float(rand() % (999 + 1) + 1); //creates a random float between 0 and 999
			return random_float / 100;		//returns the random float divided by 100
		} 
		else { //90% chance of a smaller number
			float random_float = float(rand() % (7)); //creates a random float between 0 and 6 
			return random_float / 1000;				  //0.006 max is about half of the chemicals using the small chemical generator
		}
	}

	//calculates the results of all microorganisms and substances tested
	string water_quality::calculate_results() {
		is_safe_to_drink = true; 	//gets flagged false if there is any positive finding found
		string impression;			//used display health hazards for any positive finding
		string results = "\n------------------------------------------------------\n";
		results += "Sample " + get_sample_num() + "\t\t\t\t" + "ID #: " + get_id() + "\n";
		results += "---------------------RESULTS--------------------------\n\n";
		results += "Detection of Microorganisms:\n";
		
		if (get_cryptosporidium()) {
			results += "  Cryptosporidium --- Positive(+).\n";
			impression += "\t• Cryptosporidium (+) -> Gastrointestinal illness (such as diarrhea, vomiting, and cramps)\n"; 
			is_safe_to_drink = false;
		} else { 
			results += "  Cryptosporidium --- Negative(-).\n";
		}
		
		if (get_giardia_lamblia()) {
			results += "  Giardia Lamblia --- Positive(+).\n";
			impression += "\t• Giardia Lamblia (+) ->Gastrointestinal illness (such as diarrhea, vomiting, and cramps)\n"; 
			is_safe_to_drink = false;
		} else {
			results += "  Giardia Lamblia --- Negative(-).\n";
		}

		if (get_legionella()) { 
			results += "  Legionella \t  --- Positive(+).\n";
			impression += "\t• Legionella (+) -> Legionnaire's Disease, a type of pneumonia.\n"; 
			is_safe_to_drink = false;
		} else { 
			results += "  Legionella \t  --- Negative(-).\n";
		}

		if (get_enteric_viruses()) { 
			results += "  Enteric Viruses --- Positive(+).\n\n";
			impression += "\t• Enteric Viruses (+) -> Gastrointestinal illness (such as diarrhea, vomiting, and cramps)\n"; 
			is_safe_to_drink = false;
		} else {
			results += "  Enteric Viruses --- Negative(-).\n\n";
		}

		results += "Inorganic Chemical Values (WNL = Within Normal Limits):\n";

		results += "  Antimony: \n\tDetected: ";
		results += to_string(get_antimony());
		results += " mg/L (Upper Limit: 0.006 mg/L)\n";
		results += "\tResult: ";
		if (get_antimony() >= 0.006) {
			results += "EXCEEDS LIMIT\n";
			impression += "\t• Antimony -> Increase in blood cholesterol; decrease in blood sugar\n"; 
			is_safe_to_drink = false;
		} else {
			results += "WNL\n";
		}

		results += "  Arsenic: \n\tDetected: ";
		results += to_string(get_arsenic());
		results += " mg/L (Upper Limit 0.010 mg/L)\n";
		results += "\tResult: ";
		if (get_arsenic() >= 0.010) {
			results += "EXCEEDS LIMIT\n";
			impression += "\t• Arsenic -> Skin damage or problems with circulatory systems, and may have increased risk of getting cancer.\n"; 
			is_safe_to_drink = false;
		} else {
			results += "WNL\n";
		}

		results += "  Barium: \n\tDetected: ";
		results += to_string(get_barium());
		results += " mg/L (Upper Limit: 2.0 mg/L)\n";
		results += "\tResult: ";
		if (get_barium() >= 2.0) {
			results += "EXCEEDS LIMIT\n";
			impression += "\t• Barium -> Increase in blood pressure.\n"; 
			is_safe_to_drink = false;
		} else {
			results += "WNL\n";
		}

		results += "  Beryllium: \n\tDetected: ";
		results += to_string(get_beryllium());
		results += " mg/L (Upper Limit: 0.004 mg/L)\n";
		results += "\tResult: ";
		if (get_beryllium() >= 0.004) {
			results += "EXCEEDS LIMIT\n";
			impression += "\t• Beryllium -> Intestinal lesions.\n"; 
			is_safe_to_drink = false;
		} else {
			results += "WNL\n";
		}

		results += "  Cadmium: \n\tDetected: ";
		results += to_string(get_cadmium());
		results += " mg/L (Upper Limit: 0.005 mg/L)\n";
		results += "\tResult: ";
		if (get_cadmium() >= 0.005) {
			results += "EXCEEDS LIMIT\n";
			impression += "\t• Cadmium -> Kidney damage.\n"; 
			is_safe_to_drink = false;
		} else {
			results += "WNL\n";
		}

		results += "  Chromium: \n\tDetected: ";
		results += to_string(get_chromium());
		results += " mg/L (Upper Limit: 0.1 mg/L)\n";
		results += "\tResult: ";
		if (get_chromium() >= 0.1) {
			results += "EXCEEDS LIMIT\n";
			impression += "\t• Chromium -> Allergic dermatitis.\n"; 
			is_safe_to_drink = false;
		} else {
			results += "WNL\n";
		}

		results += "  Copper: \n\tDetected: ";
		results += to_string(get_copper());
		results += " mg/L (Upper Limit: 1.3 mg/L)\n";
		results += "\tResult: ";
		if (get_copper() >= 1.3) {
			results += "EXCEEDS LIMIT\n";
			impression += "\t• Copper -> Short term exposure, Gastrointestinal distress. Long term exposure, Liver or kidney damage.\n"; 
			is_safe_to_drink = false;
		} else {
			results += "WNL\n";
		}

		results += "  Cyanide: \n\tDetected: ";
		results += to_string(get_cyanide());
		results += " mg/L (Upper Limit: 0.2 mg/L)\n";
		results += "\tResult: ";
		if (get_cyanide() >= 0.2) {
			results += "EXCEEDS LIMIT\n";
			impression += "\t• Cyanide -> Nerve damage or thyroid problems\n"; 
			is_safe_to_drink = false;
		} else {
			results += "WNL\n";
		}

		results += "  Fluoride: \n\tDetected: ";
		results += to_string(get_fluoride());
		results += " mg/L (Upper Limit: 4.0 mg/L)\n";
		results += "\tResult: ";
		if (get_fluoride() >= 4.0) {
			results += "EXCEEDS LIMIT\n";
			impression += "\t• Fluoride -> Bone disease (pain and tenderness of the bones); Children may get mottled teeth\n"; 
			is_safe_to_drink = false;
		} else {
			results += "WNL\n";
		}

		results += "  Lead: \n\tDetected: ";
		results += to_string(get_lead());
		results += " mg/L (Upper Limit: 0.015 mg/L)\n";
		results += "\tResult: ";
		if (get_lead() >= 0.015) {
			results += "EXCEEDS LIMIT\n";
			impression += "\t• Lead -> Children: Delays in physical or mental development. Adults: Kidney problems; high blood pressure\n"; 
			is_safe_to_drink = false;
		} else {
			results += "WNL\n";
		}

		results += "  Nitrate: \n\tDetected: ";
		results += to_string(get_nitrate());
		results += " mg/L (Upper Limit: 10.0 mg/L)\n";
		results += "\tResult: ";
		if (get_nitrate() >= 10.0) {
			results += "EXCEEDS LIMIT\n";
			impression += "\t• Nitrate -> Infants below the age of six months who drink water containing nitrate in excess of the MCL could become seriously ill and, if untreated, may die. Symptoms include shortness of breath and blue-baby syndrome.\n"; 
			is_safe_to_drink = false;
		} else {
			results += "WNL\n";
		}

		results += "  Nitrite: \n\tDetected: ";
		results += to_string(get_nitrite());
		results += " mg/L (Upper Limit: 1.0 mg/L)\n";
		results += "\tResult: ";
		if (get_nitrite() >= 1.0) {
			results += "EXCEEDS LIMIT\n";
			impression += "\t• Nitrite -> Infants below the age of six months who drink water containing nitrite in excess of the MCL could become seriously ill and, if untreated, may die. Symptoms include shortness of breath and blue-baby syndrome.\n"; 
			is_safe_to_drink = false;
		} else {
			results += "WNL\n";
		}

		results += "  Selenium: \n\tDetected: ";
		results += to_string(get_selenium());
		results += " mg/L (Upper Limit: 0.05 mg/L)\n";
		results += "\tResult: ";
		if (get_selenium() >= 0.05) {
			results += "EXCEEDS LIMIT\n";
			impression += "\t• Selenium -> Hair or fingernail loss; numbness in fingers or toes; circulatory problems.\n"; 
			is_safe_to_drink = false;
		} else {
			results += "WNL\n";
		}

		results += "  Thallium: \n\tDetected: ";
		results += to_string(get_thallium());
		results += " mg/L (Upper Limit: 0.002 mg/L)\n";
		results += "\tResult: ";
		if (get_thallium() >= 0.002) {
			results += "EXCEEDS LIMIT\n";
			impression += "\t• Thallium -> Hair loss; changes in blood; kidney, intestine, or liver problems.\n"; 
			is_safe_to_drink = false;
		} else {
			results += "WNL\n";
		}

		results += "\nIMPRESSION:\n";
		if (is_safe_to_drink) {
			results += "This sample has tested negative for the above microorganisms, is within the \nnormal limits for the above inorganic substances and is therefore safe to drink with respect to the substances tested.\n";
		} else {
			results += "This sample is NOT safe to drink. Consumption of this sample is strongly discouraged due to the potential health risks:\n";
			results += impression; 
		}

		results += "\n---------------------END OF REPORT---------------------\n\n";
		
		return results;
	}
