char printBuffer[1000] = "";
char locationBuffer[1000] = "";
char inventoryBuffer[1000] = "";

char command[20] = "INITIAL_COMMAND";
char currentLocationName[20] = "Ricken's Door";
char inventory[20][25] = {"Gold Bar"};

int thunder();

bool strMatch(char * str1, char * str2); 
bool strContain(char * str, char * key);

void toLower(char * str);
int wordlen(const char * str); 
void wrap(char * s, const int wrapline); 
int formatText(char * text, int maxX);
void addToPrintBuffer(char * text); 
Location currentLocation();
Location *currentLocationPointer();
Location getLocationByName(char * locationName);
Location *getLocationByNamePointer(char * locationName);
Item getItem(char * itemName);
Item *getItemPointer(char * itemName);
void printLocalItems();
void setLocationProperty(char * locationName, char * property, char * newValue); 
void setItemProperty(char * itemName, char * property, char * newValue); 

void movec(char * direction); 
void obtainItem(char * itemName, int obtainability); 
void dropItem(char * itemName); 
void deleteInventoryItem(char * itemName); 
void deleteLocationItem(char * itemName); 
bool itemInInventory(char * itemName); 

void action(char * command); 
