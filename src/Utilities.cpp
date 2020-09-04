

#include "GlobalConstants.h"
#include "Utilities.h"
#include <list>
#include<queue>
#include<iostream>
using namespace std;
using namespace std;

int Utilities::noDecompressionLimit(int depth)
{
    
    for(auto it = allNdls.begin(); it != allNdls.end(); it++)
    {
        if(depth <= it->depth)
            return it->ndl;
    }
    
    
    return 1150; //error code if NDL not found 
}

char Utilities::postDivePressureGroup(int depth, int time)
{
    int depthIndex = -1;
    
    //round depth up
    depth = roundDepthUp(depth);
    
    //find index of given depth to help with next search
    for(int i = 0; i < 12; i++)
    {
        if(depth == DEPTH[i])
            depthIndex = i;
    }

    //Look through each group for time assigned to that depth for a match
    for(auto it = allPressureGroups.begin(); it !=allPressureGroups.end(); it++)
    {
        if(it->minutes[depthIndex] == -1)
                  break; // only include possible values
    
        if(time <= it->minutes[depthIndex])
            return it->group;
    }
    
    throw 404; //depth time combination must be outside limits of table
}

int Utilities::roundDepthUp(int depth)
{
    for(int i = 0; i < 12; i++)
    {
        if(depth <= DEPTH[i])
            return DEPTH[i];
    }
    
    return -1; //error tracking. Depth is too high
}


char Utilities::postSurfaceIntervalGroup(char group, int time)
{
    auto it = allSurfaceGroups.begin();
    int timeIndex = -1;
    
    //iterate through until iterator is on correct group in list
    for(; it != allSurfaceGroups.end(); it++)
    {
        if(it->group == group)
            break;
    }
    
    //iterate through possible times for surface interval and get index
    for(int i = 25; i >= 0; i--)
    {
        if(time <= it->times[i] || (i == 0 && time > it->times[i]))
        {
            timeIndex = i;
            break;
        }
    }
    
    return it->postSIGroup[timeIndex];
    
}


int Utilities::residualNitrogen(char group, int depth)
{
    depth = roundDepthUp(depth);
    auto it = allPressureGroups.begin();
    
    //go through linked list until desired group is found and stop iterator
    for(; it != allPressureGroups.end(); it++)
    {
        //break out of loop when iterator is on group
        if(it->group == group)
            break;
    }
    
    //go through depths and return matching index of depth for minutes
    for(int i = 0; i < 12; i++)
    {
        if(depth == it->depth[i])
            return it->minutes[i];
    }
    
    return 404;//error return code. only will execute in error state
}


int Utilities::maxTime(int depth, int residualNitrogen)
{
    //incorrect input return
    if(noDecompressionLimit(depth) == 1150)
        return -5;
    
    //max time = (NDL for group) - (residual nitrogen)
    return noDecompressionLimit(depth) - residualNitrogen;
}

int Utilities::maxDepth(char group, int time)
{
    auto it = allPressureGroups.begin();
    
    //iterate until group is found
    for(; it!= allPressureGroups.end(); it++)
    {
        if(group == it->group)
            break;
    }
    
    
    //calc (ndl for group) - (residual nitrogen for depth)
    //go until the calculation is less then return previous index
    for(int i = 0; i < 12; i++)
    {
        if(maxTime(DEPTH[i], residualNitrogen(group, DEPTH[i])) < time)
            return DEPTH[i-1];
    }
    
    return -15;//error tracking. No depth found
}


