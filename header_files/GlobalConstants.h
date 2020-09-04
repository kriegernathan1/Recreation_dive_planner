/*
contains table information contained within structures to be referenced else where in program for calculations
*/

#ifndef GlobalConstants_h
#define GlobalConstants_h

#include "Structures.cpp"
#include <list>

//all possible depths
int DEPTH[12]{35,40,50,60,70,80,90,100,110,120,130,140};

//All no decompression limits for each depth {depth, max time}
Ndls thirdyFive{35,205};
Ndls fourty{40,140};
Ndls fifty{50,80};
Ndls sixty{60,55};
Ndls seventy{70,40};
Ndls eighty{80,30};
Ndls ninety{90,25};
Ndls hundred{100,20};
Ndls hundredTen{110,16};
Ndls hundredTwenty{120,13};
Ndls hundredThirty{130,10};
Ndls hundredFourty{140,8};

//array with each ndl
std::list<Ndls> allNdls = {thirdyFive, fourty, fifty, sixty, seventy, eighty, ninety, hundred, hundredTen, hundredTwenty, hundredThirty, hundredFourty};


//pressure groups {groupchar, const depths, minutes}
pressureGroup groupA{'A',{35,40,50,60,70,80,90,100,110,120,130,140} ,{10,9,7,6,5,4,4,3,3,3,3,4}};

pressureGroup groupB{'B', {35,40,50,60,70,80,90,100,110,120,130,140}, {19,16,13,11,9,8,7,6,6,5,5,4}};

pressureGroup groupC{'C', {35,40,50,60,70,80,90,100,110,120,130,140}, {25,22,17,14,12,10,9,8,7,6,6,5}};

pressureGroup groupD{'D', {35,40,50,60,70,80,90,100,110,120,130,140},{29,25,19,16,13,11,10,9,8,7,7,6}};

pressureGroup groupE{'E', {35,40,50,60,70,80,90,100,110,120,130,140}, {32,27,21,17,15,13,11,10,9,8,7,7}};

pressureGroup groupF{'F',{35,40,50,60,70,80,90,100,110,120,130,140},{36,31,24,19,16,14,12,11,10,9,8,8}};

pressureGroup groupG{'G',{35,40,50,60,70,80,90,100,110,120,130,140},{40,34,26,21,18,15,13,12,11,10,9,-1}};

pressureGroup groupH{'H', {35,40,50,60,70,80,90,100,110,120,130,140}, {44,37,28,23,19,17,15,13,12,11,10,-1}};
    
pressureGroup groupI{'I', {35,40,50,60,70,80,90,100,110,120,130,140}, {48,40,31,25,21,18,16,14,13,12,-1,-1}};

pressureGroup groupJ{'J', {35,40,50,60,70,80,90,100,110,120,130,140}, {52,44,33,27,22,19,17,15,14,12,-1,-1}};

pressureGroup groupK{'K', {35,40,50,60,70,80,90,100,110,120,130,140}, {57,48,36,29,24,21,18,16,14,13,-1,-1}};

pressureGroup groupL{'L', {35,40,50,60,70,80,90,100,110,120,130,140}, {62,51,39,31,26,22,19,17,15,-1,-1,-1}};

pressureGroup groupM{'M', {35,40,50,60,70,80,90,100,110,120,130,140},{67,55,41,33,27,23,21,18,16,-1,-1,-1}};

pressureGroup groupN{'N', {35,40,50,60,70,80,90,100,110,120,130,140}, {73,60,44,35,29,25,22,19,-1,-1,-1,-1}};
pressureGroup groupO{'O',  {35,40,50,60,70,80,90,100,110,120,130,140}, {79,64,47,37,31,26,23,20,-1,-1,-1,-1}};

pressureGroup groupP{'P', {35,40,50,60,70,80,90,100,110,120,130,140}, {85,69,50,39,33,28,24,-1,-1,-1,-1,-1}};

pressureGroup groupQ{'Q', {35,40,50,60,70,80,90,100,110,120,130,140}, {92,74,53,42,35,29,25,-1,-1,-1,-1,-1}};

pressureGroup groupR{'R', {35,40,50,60,70,80,90,100,110,120,130,140}, {100,79,57,44,36,30,-1,-1,-1,-1,-1,-1}};

pressureGroup groupS{'S', {35,40,50,60,70,80,90,100,110,120,130,140}, {108,85,60,47,38,-1,-1,-1,-1,-1,-1,-1}};

pressureGroup groupT{'T', {35,40,50,60,70,80,90,100,110,120,130,140}, {117,91,63,49,40,-1,-1,-1,-1,-1,-1,-1}};

pressureGroup groupU{'U', {35,40,50,60,70,80,90,100,110,120,130,140}, {127,97,67,52,-1,-1,-1,-1,-1,-1,-1,-1}};

pressureGroup groupV{'V', {35,40,50,60,70,80,90,100,110,120,130,140}, {139,104,71,54,-1,-1,-1,-1,-1,-1,-1,-1}};

pressureGroup groupW{'W', {35,40,50,60,70,80,90,100,110,120,130,140}, {152,111,75,55,-1,-1,-1,-1,-1,-1,-1,-1}};

pressureGroup groupX{'X', {35,40,50,60,70,80,90,100,110,120,130,140}, {168,120,80,-1,-1,-1,-1,-1,-1,-1,-1,-1}};

pressureGroup groupY{'Y', {35,40,50,60,70,80,90,100,110,120,130,140}, {188,129,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};

pressureGroup groupZ{'Z', {35,40,50,60,70,80,90,100,110,120,130,140}, {205,140,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};

std::list<pressureGroup> allPressureGroups{groupA,groupB,groupC,groupD,groupE,groupF,groupG,groupH,groupI,groupJ,groupK,groupL,groupM,groupN,groupO,groupP,groupQ,groupR,groupS,groupT,groupU,groupV,groupW,groupX,groupY,groupZ};

//Surface interval group change
char letters[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

surfaceIntervalGroup A{'A', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {180}};

surfaceIntervalGroup B{'B', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {228,47}};

surfaceIntervalGroup C{'C', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {250,69,21}};

surfaceIntervalGroup D{'D', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {259,78,30,8}};

surfaceIntervalGroup E{'E', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {268,87,38,16,7}};

surfaceIntervalGroup F{'F', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {275,94,46,24,15,7}};

surfaceIntervalGroup G{'G', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {282,101,53,31,22,13,6}};

surfaceIntervalGroup H{'H', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {288,107,59,37,28,20,12,5}};

surfaceIntervalGroup I{'I', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {294,113,65,43,34,26,18,11,5}};

surfaceIntervalGroup J{'J', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {300,119,71,49,40,31,24,17,11,5}};

surfaceIntervalGroup K{'K',{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'} ,305,124,76,54,45,37,29,22,16,10,4};

surfaceIntervalGroup L{'L', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {310,129,81,59,50,42,34,27,21,15,9,4}};

surfaceIntervalGroup M{'M', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {315,134,85,64,55,46,39,32,25,19,14,9,4}};

surfaceIntervalGroup N{'N', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {319,138,90,68,59,51,43,36,30,24,18,13,8,3}};

surfaceIntervalGroup O{'O', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'} ,324,143,94,72,63,55,47,41,34,28,23,17,12,8,3};

surfaceIntervalGroup P{'P', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {328,147,98,76,67,59,51,45,38,32,27,21,16,12,7,3}};

surfaceIntervalGroup Q{'Q', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {331,150,102,80,71,63,55,48,42,36,30,25,20,16,11,7,3}};

surfaceIntervalGroup R{'R', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {335,154,106,84,75,67,59,52,46,40,34,29,24,19,15,11,7,3}};

surfaceIntervalGroup S{'S', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {339,158,109,87,78,70,63,56,49,43,38,32,27,23,18,14,10,6,3}};

surfaceIntervalGroup T{'T', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {342,161,113,91,82,73,66,59,53,47,41,36,31,26,22,17,13,10,6,2}};

surfaceIntervalGroup U{'U', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {345,164,116,94,85,77,69,62,56,50,44,39,34,29,25,21,17,13,9,6,2}};

surfaceIntervalGroup V{'V', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {348,167,119,97,88,80,72,65,59,53,47,42,37,33,28,24,20,16,12,9,5,2}};
surfaceIntervalGroup W{'W', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {351,170,122,100,91,83,75,68,62,56,50,45,40,36,31,27,23,19,15,12,8,5,2}};

surfaceIntervalGroup X{'X', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {354,173,125,103,94,86,78,71,65,59,53,48,43,39,34,30,26,22,18,15,11,8,5,2}};

surfaceIntervalGroup Y{'Y', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {357,176,128,106,97,89,81,74,68,62,56,51,46,41,37,33,29,25,21,18,14,11,8,5,2}};

surfaceIntervalGroup Z{'Z', {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, {360,170,131,109,100,91,84,77,71,65,59,54,49,44,40,35,31,28,24,20,17,14,11,8,5,2}};

std::list<surfaceIntervalGroup> allSurfaceGroups{A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};





#endif /* ChangeName_h */
