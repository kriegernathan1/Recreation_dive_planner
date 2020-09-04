//
//  HeaderFile.h
//  Recreation Dive Planner
//
//  Created by Nathan Krieger on 5/7/20.
//  Copyright © 2020 Krieger Development. All rights reserved.
//

#ifndef HeaderFile_h
#define HeaderFile_h


class Utilities
{
public:
    //rounds up depth to next highest depth
    //returns -1 if depth too high
    static int roundDepthUp(int depth);
    
    //Function returns NDL for a given depth. returns 1150 if value outside
    //limits of table
    static int noDecompressionLimit(int depth);
    
    //function return pressure group after dive at given depth and time
    //throws 404 if outside limits of table
    static char postDivePressureGroup(int depth, int time);
    
    //function pressure group after a surface interval
    //throws 404 if group not found
    static char postSurfaceIntervalGroup(char group, int time);
    
    //function returns residual nitrogen given group and depth
    //returns 404 if residual nitrogen not found
    //return -1 if residual outside of bounds of RDP table
    static int residualNitrogen(char group, int depth);
    

    //function returns maximum time at depth given previous dive
    //returns -5 if value outside possibliity of table
    static int maxTime(int depth, int residualNitrogen);
    
    //returns total bottom time given desired and residual
    //return -10 if total time exceeds maxtime
    static int totalBTime(int actual, int residual);
    
    //finds max depth given residual nitrogen
    //returns -15 if error occurs
    static int maxDepth(char group, int time);

};



#endif /* HeaderFile_h */
