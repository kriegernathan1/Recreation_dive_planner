/*
 Structures to help store information from PADI dive tables
 */


struct Ndls
{
    int depth; //in feet
    int ndl; //minutes
};

struct pressureGroup
{
    char group;
    //depths are same for every group
    const int depth[12] = {35,40,50,60,70,80,90,100,110,120,130,140};
    //minutes specific to group
    const int minutes[12];
    //indexes for depth and minutes will correlate directly to index. The depths and minutes for the Group will be put into array
};

struct surfaceIntervalGroup
{
    char group;
    char postSIGroup[26];//corresponds to index of time with new group
    int times[26];//array that holds max of range for surface interval
};

