

#include <iostream>
#include "Session.h"
#include "Displays.h"
#include "Utilities.h"
using namespace std;

Session::Session()
{
    start();
}


void Session::start()
{
    int input;
    
    while(1)
    {
        Display::displayMenu(1); //display menu to user
        cin >> input;
        if(input <= 0 || input > 4 )
            Display::errorDisplay(6);
        else
        {
            switch (input)
            {
                case 1://call single dive
                {
                    singleDive();
                    break;
                }
                case 2://call double dive
                {
                    doubleDive();
                    break;
                }
                case 3:// call multiple dive
                {
                    multipleDive();
                    break;
                }
                case 4:
                {
                    cout << "Exiting program....." << endl;
                    exit(99); //user exits program
                    break;
                }
                    
            }
        }
        
    }
    
}

void Session::singleDive()
{
    int input;
    while (1)
    {
        Display::displayMenu(2);//display single dive menu
        cin >> input;
        
        if(input <= 0 || input > 3)
            Display::errorDisplay(6);
        else
        {
            switch (input)
            {
                case 1://Get ndl for given depth
                {
                    cout << "What depth will you be going to?" << endl;
                    cin >> input;
                    
                    //input error handling
                    if(input <=0)
                    {
                        Display::errorDisplay(2);
                        cout << "Going back to previous Menu" << endl;
                    }
                    else if(input > 140)
                    {
                        Display::errorDisplay(1);
                        cout << "Going back to previous Menu" << endl;
                    }
                    else
                    {
                        int ndl = Utilities::noDecompressionLimit(input);
                        
                        cout  << "Your NDL is: " << ndl << endl;
                        cout << "Press enter to go back to main menu" << endl;
                        cin.ignore();
                        cin.get();
                        return;// go back to main menu
                    }
                    
                    break;
                }//end case 1
                case 2:
                {
                    int depth;
                    int time;
                    cout << "Please input depth for dive." << endl;
                    cin >> depth;
                    
                    //handling invalid depth
                    if(depth <=0) // negative or zero
                    {
                        Display::errorDisplay(2);
                        cout << "Going back to previous Menu" << endl;
                        break;
                    }
                    else if(depth > 140) //greater than max
                    {
                        Display::errorDisplay(1);
                        cout << "Going back to previous Menu" << endl;
                        break;
                    }
                    
                    cout << "Enter Time in minutes" << endl;
                    cin >> time;
                    
                    //handle time error
                    if(time < 0)//negative
                        Display::errorDisplay(6);
                    
                    if(time > Utilities::noDecompressionLimit(depth))//time greater than NDL for given depth
                        Display::errorDisplay(6);
                    else//calculate the pressure group
                    {
                        char group  = Utilities::postDivePressureGroup(depth,time);
                        
                        cout << "Your new pressure group after a dive to " << depth << " for " << time << " minutes is " << group << endl;
                        cout << "Press enter to go back to main menu";
                        cin.ignore();
                        cin.get();
                        return;
                    }
                }//end case 2
                case 3://go back
                    return;
                    
                default:
                    break;
            }
        }
    }
    
}

void Session::doubleDive()
{
    int input;
    while(1)
    {
        Display::displayMenu(3);
        cin >> input;
        if(input <= 0 || input > 3)
            Display::errorDisplay(6);
        else
        {
            switch (input)
            {
                case 1://NDL for dive two
                {
                    int depthOne;
                    int time;//time at depth one
                    int depthTwo;
                    int si;
                    
                    cout << "Please input depth for dive one." << endl;
                    cin >> depthOne;
                    
                    //error handling
                    if(depthOne <= 0)
                    {
                        Display::errorDisplay(2);
                        cout << "Going back to previous Menu" << endl;
                        break;
                    }
                    else if(depthOne > 140)
                    {
                        Display::errorDisplay(1);
                        cout << "Going back to previous Menu" << endl;
                        
                        
                        break;
                    }
                    
                    cout << "Enter bottom time for first dive" << endl;
                    cin >> time;
                    
                    if(time > Utilities::noDecompressionLimit(depthOne))
                    {
                        Display::errorDisplay(4);
                        cout << "Going back to previous Menu" << endl;
                        break;
                    }
                    
                    cout << "Enter Surface Interval after dive one" << endl;
                    cin >> si;
                    
                    if(si <= 0)//negative Surface Interval case
                    {
                        Display::errorDisplay(6);
                        cout << "Going back to previous Menu" << endl;
                        break;
                    }
                   
                    
                    char firstgroup = Utilities::postDivePressureGroup(depthOne, time);
                  
                    //applies special rules for pressure groups x and w
                    if((firstgroup == 'W' || firstgroup == 'X') && (si <60))
                    {
                        cout << "For pressure groups W and X a minimum of a one hour surface interval is required" << endl;
                        cout << "Going back to previous Menu" << endl;
                        break;
                    }
                    
                    //applies special rules for pressure group y and Z
                    if((firstgroup == 'Y' || firstgroup == 'Z') && (si < 180))
                    {
                        cout << "For pressure groups Y and Z a minimum of a three hour surface interval is required" << endl;
                        cout << "Going back to previous Menu" << endl;
                        break;
                    }
                    
                    cout << "Please input depth for dive two." << endl;
                    cin >> depthTwo;
                    
                    //error handling
                    if(depthTwo <= 0)
                    {
                        Display::errorDisplay(2);
                        cout << "Going back to previous Menu" << endl;
                        break;
                    }
                    else if(depthTwo > 140)
                    {
                        Display::errorDisplay(1);
                        cout << "Going back to previous Menu" << endl;
                        
                        break;
                    }
                    else if(depthTwo > depthOne)
                    {
                        Display::errorDisplay(3);
                        cout << "Going back to previous Menu" << endl;
                        break;
                    }
                    
                    //make calculation
                    else
                    {
                        char firstgroup = Utilities::postDivePressureGroup(depthOne, time);
                        char postSiGroup = Utilities::postSurfaceIntervalGroup(firstgroup, si);
                        
                        
                        int residual = Utilities::residualNitrogen(postSiGroup, depthTwo);
                        
                        int maxtime = Utilities::maxTime(depthTwo, residual);
                        
                        cout << "Given your first dive to " << depthOne << " feet for " << time << " minutes and a surface interval of " << si << " minutes your adjusted NDL for a dive to " << depthTwo << " feet is: " << maxtime << " minutes" << endl;
                        
                        cout << "Press enter to go back to main menu";
                        cin.ignore();
                        cin.get();
                        return;
                    }
                    
                }//end case 1
                case 2: //maximum depth
                {
                    int depthOne;
                    int timeOne;
                    int si;
                    int timeTwo;
                    
                    cout << "Please enter depth for first dive" << endl;
                    cin >> depthOne;
                    
                    //error handling
                    if(depthOne <= 0)
                    {
                        Display::errorDisplay(2);
                        cout << "Going back to previous Menu" << endl;
                        break;
                    }
                    else if(depthOne > 140)
                    {
                        Display::errorDisplay(1);
                        cout << "Going back to previous Menu" << endl;
                        break;
                    }
                    cout << "Enter bottom time for first dive" << endl;
                    cin >> timeOne;
                    
                    if(timeOne > Utilities::noDecompressionLimit(depthOne))
                    {
                        Display::errorDisplay(4);
                        cout << "Going back to previous Menu" << endl;
                        break;
                    }
                    
                    cout << "Enter Surface Interval after dive one" << endl;
                    cin >> si;
                    
                    if(si <= 0)//negative Surface Interval case
                    {
                        Display::errorDisplay(6);
                        cout << "Going back to previous Menu" << endl;
                        break;
                    }
                    
                    char firstgroup = Utilities::postDivePressureGroup(depthOne, timeOne);
                    
                    //applies special rules for pressure groups x and w
                    if((firstgroup == 'W' || firstgroup == 'X') && (si <60))
                    {
                        cout << "For pressure groups W and X a minimum of a one hour surface interval is required" << endl;
                        cout << "Going back to previous Menu" << endl;
                        break;
                    }
                    
                    //applies special rules for pressure group y and Z
                    if((firstgroup == 'Y' || firstgroup == 'Z') && (si < 180))
                    {
                        cout << "For pressure groups Y and Z a minimum of a three hour surface interval is required" << endl;
                        cout << "Going back to previous Menu" << endl;
                        break;
                    }
                    
                    cout << "Please enter time for dive two " << endl;
                    cin >> timeTwo;
                    
                    
                    char secondGroup = Utilities::postSurfaceIntervalGroup(firstgroup, si);
                    
                    int maxDepth = Utilities::maxDepth(secondGroup, timeTwo);
                    
                    if(maxDepth == -15)
                    {
                        Display::errorDisplay(6);
                        cout << "Returning to previous menu" << endl;
                        break;
                    }
                    else
                    {
                        cout << "Your max depth for dive two will be " << maxDepth << " feet" <<endl;
                        cout << "Press enter to go back to main menu" << endl;
                        cin.ignore();
                        cin.get();
                        return;
                    
                    }
                    break;
                }
                case 3://go back
                    return;
                    
                default:
                    break;
            }//end switch
            
        }//end else statement
        
    }//end while
    
}//end functoin

void Session::multipleDive()
{
    int input;
    while(1) //code within function terminated while loop
    {
        Display::displayMenu(4);
        cin >> input;
        if(input <= 0 || input > 3)
            Display::errorDisplay(6);
        else
        {
            switch (input)//Takes appropriate input and calculation based on choice selection made by user
            {
                case 1:
                {
                    int depths[3];//hold inputs of depths
                    int times[2];//input times
                    int surfaceIntervals[2];//input SIs
                    
                    //Get input for depth 1,2,3
                    
                    cout << "Enter depth for dive one" << endl;
                    cin >> depths[0];
                    //incorrect input handling
                    if(depths[0] < 0)
                    {
                        Display::errorDisplay(2);
                        cout << "returning to previous menu" <<endl;
                        break;
                    }
                    else if(depths[0] > 140)
                    {
                        Display::errorDisplay(1);
                        cout << "Returning to previous menu" << endl;
                        break;
                    }
                    
                    
                    cout << "Enter bottom time for dive one" << endl;
                    cin >> times[0];
                    
                    if(times[0] < 0)
                    {
                        Display::errorDisplay(6);
                        cout << "Going back to previous menu" << endl;
                        break;
                    }
                    else if(times[0] > Utilities::noDecompressionLimit(depths[0]))
                    {
                        Display::errorDisplay(4);
                        cout << "Going back to previous Menu" << endl;
                        break;
                    }
                    
                    cout << "What is surface interval after dive one" << endl;
                    cin >> surfaceIntervals[0];
                    
                    
                    if(surfaceIntervals[0] < 0)
                    {
                        Display::errorDisplay(6);
                        cout << "Returning to previous menu" << endl;
                        break;
                    }
                    
                    cout << "Enter depth for dive two" << endl;
                    cin >> depths[1];
                    
                    //error handling
                    if(depths[1] < 0)
                    {
                        Display::errorDisplay(2);
                        cout << "Returning to previous menu" <<endl;
                        break;
                    }
                    else if(depths[1] > 140)
                    {
                        Display::errorDisplay(1);
                        cout << "Returning to previous menu" << endl;
                        break;
                    }
                    else if(depths[1] > depths[0])
                    {
                        Display::errorDisplay(3);
                    }
                    
                    cout << "Enter Time for dive two" << endl;
                    cin >> times[1];
                    
                    //validate dive two is within limits
                    char firstGroup = Utilities::postDivePressureGroup(depths[0], times[0]);
                    char firstGroupPostSI =
                    Utilities::postSurfaceIntervalGroup(firstGroup, surfaceIntervals[0]);
                    
                    //Get adjusted NDl for second dive
                   int maxTimeSecondDive =  Utilities::maxTime(depths[1], Utilities::residualNitrogen(firstGroupPostSI, depths[1]));
                    
                    //Make sure time[1] > adjusted NDl
                    if(maxTimeSecondDive < times[1])
                    {
                        Display::errorDisplay(6);
                        cout << "Returning to previous Menu" << endl;
                        break;
                    }
                    
                    cout << "Enter Surface interval after dive two" << endl;
                    cin >> surfaceIntervals[1];
                    
                    //TODO: validate SI input
                    
                    cout << "Enter depth for dive three" << endl;
                    cin >> depths[2];
                    
                    if(depths[1] < 0)
                    {
                        Display::errorDisplay(2);
                        cout << "Returning to previous menu" <<endl;
                        break;
                    }
                    else if(depths[1] > 140)
                    {
                        Display::errorDisplay(1);
                        cout << "Returning to previous menu" << endl;
                        break;
                    }
                    else if(depths[1] > depths[0])
                    {
                        Display::errorDisplay(3);
                    }
                    
                    //Make calculation given all inputs
                    
                    //get needed variables for calculation
                    int totalTime = times[1] + Utilities::residualNitrogen(firstGroupPostSI, depths[1]);
                    
                    char secondGroup = Utilities::postDivePressureGroup(depths[1], totalTime);
                    //get group after Surface interval
                    char secondGroupPostSi = Utilities::postSurfaceIntervalGroup(secondGroup, surfaceIntervals[1]);
       
                    //get NDL given residual nitrogen
                    int adjustedNDL = Utilities::maxTime(depths[2], Utilities::residualNitrogen(secondGroupPostSi, depths[2]));
                    
                    //Display adjusted NDL to output
                    cout << "Your adjusted No Decompression Limit (NDL) given previous dives is: " << adjustedNDL << " minutes" << endl;
                    //Back to main menu
                    cout << "Press enter to return to Main Menu" << endl;
                    cin.ignore();
                    cin.get();
                    return;
                }// end case 1
                case 2:
                {
                    
                    int depths[2];//hold inputs of depths
                    int times[3];//input times
                    int surfaceIntervals[2];//input SIs
                    
                    //Get input for depth 1,2,3
                    
                    cout << "Enter depth for dive one" << endl;
                    cin >> depths[0];
                    //incorrect input handling
                    if(depths[0] < 0)
                    {
                        Display::errorDisplay(2);
                        cout << "returning to previous menu" <<endl;
                        break;
                    }
                    else if(depths[0] > 140)
                    {
                        Display::errorDisplay(1);
                        cout << "Returning to previous menu" << endl;
                        break;
                    }
                    
                    
                    cout << "Enter bottom time for dive one" << endl;
                    cin >> times[0];
                    
                    if(times[0] < 0)
                    {
                        Display::errorDisplay(6);
                        cout << "Going back to previous menu" << endl;
                        break;
                    }
                    else if(times[0] > Utilities::noDecompressionLimit(depths[0]))
                    {
                        Display::errorDisplay(4);
                        cout << "Going back to previous Menu" << endl;
                        break;
                    }
                    
                    cout << "What is surface interval after dive one" << endl;
                    cin >> surfaceIntervals[0];
                    
                    //Get first group given time and depth
                    char firstGroup = Utilities::postDivePressureGroup(depths[0], times[0]);
                    char firstGroupPostSI =
                    Utilities::postSurfaceIntervalGroup(firstGroup, surfaceIntervals[0]);
                    
                    if(surfaceIntervals[0] < 0)
                    {
                        cout << "Time cannot be negative" << endl;
                        cout << "Returning to previous menu" << endl;
                        break;
                    }
                    //applies special rules for pressure groups x and w
                    if((firstGroup == 'W' || firstGroup == 'X') && (surfaceIntervals[0] <60))
                    {
                        cout << "For pressure groups W and X a minimum of a one hour surface interval is required" << endl;
                        cout << "Going back to previous Menu" << endl;
                        break;
                    }
                    
                    //applies special rules for pressure group y and Z
                    if((firstGroup == 'Y' || firstGroup == 'Z') && (surfaceIntervals[0] < 180))
                    {
                        cout << "For pressure groups Y and Z a minimum of a three hour surface interval is required" << endl;
                        cout << "Going back to previous Menu" << endl;
                        break;
                    }
                    
                    
                    cout << "Enter depth for dive two" << endl;
                    cin >> depths[1];
                    
                    //error handling
                    if(depths[1] < 0)
                    {
                        Display::errorDisplay(2);
                        cout << "returning to previous menu" <<endl;
                        break;
                    }
                    else if(depths[1] > 140)
                    {
                        Display::errorDisplay(1);
                        cout << "Returning to previous menu" << endl;
                        break;
                    }
                    
                    cout << "Enter Time for dive two" << endl;
                    cin >> times[1];
                    
                   
                     
                     //Get adjusted NDl for second dive
                    int maxTimeSecondDive =  Utilities::maxTime(depths[1], Utilities::residualNitrogen(firstGroupPostSI, depths[1]));
                     
                     //Make sure time[1] > adjusted NDl
                     if(maxTimeSecondDive < times[1])
                     {
                         Display::errorDisplay(6);
                         cout << "Returning to previous menu" << endl;
                         break;
                     }
                    
                    cout << "Enter Surface interval after dive two" << endl;
                    cin >> surfaceIntervals[1];
                    
                    //Get pressure group after second dive
                    int totalTime = times[1] + Utilities::residualNitrogen(firstGroupPostSI, depths[1]);
                    char secondGroup = Utilities::postDivePressureGroup(depths[1], totalTime);
                    
                    //applies special rules for pressure groups x and w
                    if((secondGroup == 'W' || secondGroup == 'X') && (surfaceIntervals[1] < 60))
                    {
                        cout << "For pressure groups W and X a minimum of a one hour surface interval is required" << endl;
                        cout << "Going back to previous Menu" << endl;
                        break;
                    }
                    
                    //applies special rules for pressure group y and Z
                    if((secondGroup == 'Y' || secondGroup == 'Z') && (surfaceIntervals[1] < 180))
                    {
                        cout << "For pressure groups Y and Z a minimum of a three hour surface interval is required" << endl;
                        cout << "Going back to previous Menu" << endl;
                        break;
                    }
                    
                    if(surfaceIntervals[1] < 0)
                    {
                        cout << "Time cannot be negative" << endl;
                        cout << "Returning to previous menu" << endl;
                    }
                    
                    
                    cout << "Enter time for dive three" << endl;
                    cin >> times[2];
                    
                    
                    //get group after Surface interval
                    char secondGroupPostSi = Utilities::postSurfaceIntervalGroup(secondGroup, surfaceIntervals[1]);
                    
                    //time greater than any possible depth given pressure group
                    if(times[2] > Utilities::maxTime(35, secondGroupPostSi))
                    {
                        cout << "That time is not possible given your group" << endl;
                        cout << "Returning to previous Menu" << endl;
                        break;
                    }
                    
                    int maxDepth = Utilities::maxDepth(secondGroupPostSi, times[2]);
                    
                    //Validate value for maxDepth
                    
                    cout << "Your max depth given previous dives is: " << maxDepth << endl;
                    cout << "Returning to Main Menu" << endl;
                    cin.ignore();
                    cin.get();
                    
                    return;
                }
                case 3://go back
                {
                    return;
                }                    
            }
        }
    }
}
