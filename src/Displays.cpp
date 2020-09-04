
#include <iostream>
#include "Displays.h"
using namespace std;

bool Display::displayMenu(int choice)
{
    bool returningBool = false;//tracks if a proper choice was selected
    
    switch (choice)
    {
        case 1://main menu
        {
            returningBool = true;
            
            cout << "Will you be doing a Single Dive, Double dive, or Multiple dives for today?\n1. Single\n2. Double\n3. Multiple\n4. Exit Program" << endl;
            break;
        }
        case 2://single dive menu
        {
            returningBool = true;
            
            cout << "Single Dive:" << endl;
            cout << "Would you like a No Decompression Limit (NDL) for a depth or your new pressure group post dive?\n1. NDL\n2. Pressure Group after Dive\n3. Go Back" << endl;
            break;
        }
        case 3://double dive menu
        {
            returningBool = true;
            
            cout << "Double Dive:" << endl;
            cout << "Would you like the No Decompression Limit (NDL) or max depth for your second dive?\n1. NDl\n2. Max Depth\n3. Go Back" << endl;
            break;
        }
        case 4: //multiple dive menu
        {
            returningBool = true;
            
            cout << "Multiple Dives:" << endl;
            cout << "Would you like your NDL for dive three or the maximum depth for dive three?\n1. NDL\n2. Maximum Depth\n3. Go Back" << endl;
            
            break;
        }
            
        default:
            break;
    }
    
    
    
    return returningBool;
}

bool Display::errorDisplay(int choice)
{
    bool returnBool = false;
    
    switch (choice)
    {
        case 1://depth higher than maximum
        {
            returnBool = true;
            
            cout << "The given depth is higher than maximum depth of the PADI table. Please put a depth within limits of table." << endl;
            
            break;
        }
        case 2://depth is negative
        {
            returnBool = true;
            
            cout << "Depths can only be positive!" << endl;
            break;
        }
        case 3://Depth higher than previous depth
        {
            returnBool = true;
            
            cout << "Successive dives depths should never exceed previous dives. Please choose an appropriate depth." << endl;
            break;
        }
        case 4://Time given is higher than NDL for depth
        {
            returnBool = true;
            
            cout << "Time given for depth exceeds the NDL for that depth. Please choose a time within limits" << endl;
            break;
        }
        case 5://Time given is higher than possible for successive dive
        {
            returnBool = true;
            
            cout << "Time given exceeds the limits available depths to dive for. Please choose a lower depth." << endl;
            break;
        }
        case 6://generic improper input
        {
            returnBool = true;
            
            cout << "input is incorrect. Please try again." << endl;
        }
        case 7:
        {
            returnBool = true;
            
            cout << "Second Dive is not within limits of table. Please try again" << endl;
        }
    }
    
    return returnBool;
    
}
