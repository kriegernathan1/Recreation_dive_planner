
#ifndef Session_h
#define Session_h

/*
 Class will control flow of program and make appropriate function calls based off of input from user
 */
class Session
{
public:
//    constructor
    Session();
    
    
//     function to start program and take input then call successive
//    functions
    void start();
    
    
//    single dive function
//    Gets input from user and based on input either gives NDL or maximum
//    depth for a dive
    void singleDive();
    
    
//    double dive function
//    Gets input from user and based on input either gives adjusted NDL or
//    maximum depth for a dive
    void doubleDive();
    
    
//    multiple dive function
//    //Gets input from user and based on input either gives adjusted NDL or
//    maximum depth for a dive
    void multipleDive();
    

};

#endif /* Session_h */
