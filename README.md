# Water Sampling Program, by Claudio Perinuzzi, 11/22/23

## Introduction & Features:
Welcome to the Water Sampling Program! This program simulates (randomly generates) the testing of water samples for various microorganisms and inorganic chemicals, providing results and safety assessments. This program allows you to search, delete, display and save results of tested samples. The program will write up a detailed report on sample results and potential health hazards. Information on National Primary Drinking Water Regulations obtained from: U.S. Environmental Protection Agency. (URL: https://www.epa.gov/ground-water-and-drinking-water/national-primary-drinking-water-regulations#Inorganic)

## How to Use:
Enter the following numbers for the corresponding action:
   - 1) Test water samples
   - 2) Search for sample results
   - 3) Delete samples
   - 4) Display tested samples
   - 5) Save results to a text file
   - 6) Quit the program

## Program Structure:
The program consists of three main source files:
- "water_quality.hpp": Contains the "water_quality" class definition.
- "water_quality.cpp": Contains the "water_quality" class implementation.
- "main.cpp": Implements the main program logic.

## Sample Output:
The program will write up a detailed report on sample results and potential health hazards.

Example:

------------------------------------------------------
Sample 1                                ID #: 67708
---------------------RESULTS--------------------------

Detection of Microorganisms:
  Cryptosporidium --- Negative(-).
  Giardia lamblia --- Negative(-).
  Legionella      --- Negative(-).
  Enteric Viruses --- Negative(-).

Inorganic Chemical Values (WNL = Within Normal Limits):
  Antimony: 
        Detected: 0.001000 mg/L (Upper Limit: 0.006 mg/L)
        Result: WNL
  Arsenic: 
        Detected: 0.000000 mg/L (Upper Limit 0.010 mg/L)
        Result: WNL
  Barium: 
        Detected: 0.006000 mg/L (Upper Limit: 2.0 mg/L)
        Result: WNL
  Beryllium: 
        Detected: 0.005000 mg/L (Upper Limit: 0.004 mg/L)
        Result: EXCEEDS LIMIT
  Cadmium: 
        Detected: 0.004000 mg/L (Upper Limit: 0.005 mg/L)
        Result: WNL
  Chromium: 
        Detected: 0.005000 mg/L (Upper Limit: 0.1 mg/L)
        Result: WNL
  Copper: 
        Detected: 0.000000 mg/L (Upper Limit: 1.3 mg/L)
        Result: WNL
  Cyanide: 
        Detected: 0.005000 mg/L (Upper Limit: 0.2 mg/L)
        Result: WNL
  Fluoride: 
        Detected: 0.006000 mg/L (Upper Limit: 4.0 mg/L)
        Result: WNL
  Lead: 
        Detected: 0.006000 mg/L (Upper Limit: 0.015 mg/L)
        Result: WNL
  Nitrate: 
        Detected: 0.002000 mg/L (Upper Limit: 10.0 mg/L)
        Result: WNL
  Nitrite: 
        Detected: 0.005000 mg/L (Upper Limit: 1.0 mg/L)
        Result: WNL
  Selenium: 
        Detected: 0.000000 mg/L (Upper Limit: 0.05 mg/L)
        Result: WNL
  Thallium: 
        Detected: 0.006000 mg/L (Upper Limit: 0.002 mg/L)
        Result: EXCEEDS LIMIT

IMPRESSION:
This sample is NOT safe to drink. Consumption of this sample is strongly discouraged due to the potential health risks:
        • Beryllium -> Intestinal lesions.
        • Thallium -> Hair loss; changes in blood; kidney, intestine, or liver problems.

---------------------END OF REPORT---------------------

