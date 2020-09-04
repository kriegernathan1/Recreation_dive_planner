

#ifndef Displays_h
#define Displays_h

class Display
{
public:
    
    //all menus displayed will be in this function
    //returns false if called incorrectly (choice not present)
    static bool displayMenu(int);
    static bool errorDisplay(int);//any known errors will be displayed using this function
    
};  




#endif /* Displays_h */
