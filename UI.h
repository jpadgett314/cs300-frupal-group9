/*
UI Class
Author: Thomas Abel
Date: 2020-11-19
*/
#ifndef UI_CLASS
#define UI_CLASS
#include <ncurses.h>
#include <panel.h>
#include <string>
#include <vector>

class UserInterface {
private:

public:
    // Starts the UI by creating all necessary windows/panels.
	bool initialize();
    // Displays information on the side window.
    void actions(std::vector<std::string> values);
    void tileInspect(std::vector<std::string> values);
    void whifflesEnergy(int whiffles, int energy);
    // Opens a new panel to show the player inventory.
    void displayInventory(std::vector<std::vector<std::string>> tools);
    char popup(std::string msg);
    char popup(std::string msg, std::vector<std::string> values);

private:
    // The minimum screensize allowed by the UI.
    const int MINY = 20;
    const int MINX = 80;
    const unsigned int WIDTH = 24;
    // The border characters.
    const char BVER = '#';
    const char BHOR = '=';
    // Titles for each of the sections.
    const std::string LABEL_Whiffles = "Whiffles";
    const std::string LABEL_Energy = "Energy";
    const std::string LABEL_Actions = "~Actions~";
    const std::string LABEL_Inspect = "~Inspect~";

    // Printing Functions
    void printTitle(
        WINDOW *win, 
        int ypos, int hor_offset,
        std::string title);
    void printDualCol(
        WINDOW *win,
        int ver_offset, int hor_offset,
        std::vector<std::string> values); 

    // Windows and Panels
	WINDOW *info, *inven, *pop;
    WINDOW *bmain, *bpop;
    PANEL *pbmain, *pinfo, *pinven, *pbpop, *ppop;
};

#endif
/*
initialize() -> Call this when first starting the UI.

~Main Information Panel~
These functions display to the main panel on the right side
of the screen. Update these whenever.

Actions() -> The vector should contain strings in a vector in the order:
    [controls, labels]
    eg : ["E", "S", "D", "F", "North", "West", "South", "East"]

Inspect() -> The vector should contain strings in a vector in the order:
    [values, labels]
    eg : ["Steak", "10", "20", "Food", "Cost", "Energy"]

WhiffEn -> Simply provide the current whiffle and energy values.

~Inventory Panel~

~Popup/Prompt Panel~
*/