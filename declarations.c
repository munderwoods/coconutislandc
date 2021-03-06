char printBuffer[1000] = "";
char locationBuffer[1000] = "";
char inventoryBuffer[1000] = "";
char statusBuffer[1000] = "";

char command[20] = "INITIAL_COMMAND";
char currentLocationName[20] = "Ricken's Door";
char inventory[20][25] = {"Gold Bar"};
char status[20][25] = {};
int blood = 10;
int stamina = 10;
int temperature = 5;
int mobility = 10;
int thirst = 10;
int hunger = 10;

int turns = 0;
int min = 40;
int hour = 22;
bool day = false;
int mapX = 8;
int mapY = 0;

char *selfIcon = "@";
char *map[14][15] =
				{{"_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_",},
         {"_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_",},
         {"_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_",},
         {"_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_",},
         {"_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_",},
         {"_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_",},
         {"_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_",},
         {"_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_",},
         {"_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_",},
         {"_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_",},
         {"_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_",},
         {"_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_",},
         {"_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_",},
         {"_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_",},};

int thunder();

bool strMatch(char * str1, char * str2); 
bool strContain(char * str, char * key);

void toLower(char * str);
int wordlen(const char * str); 
void wrap(char * s, int wrapline); 
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
void eatItem(char * itemName); 
void drink(); 
void deleteInventoryItem(char * itemName); 
void deleteLocationItem(char * itemName); 
bool itemInInventory(char * itemName); 

char * makeBar(int stat); 
bool checkStatus(char * statusName);
void addStatus(char * statusName);
void removeStatus(char * statusName);
void die();
void incrementTime(); 

void action(char * command); 
void stats();
void render();
