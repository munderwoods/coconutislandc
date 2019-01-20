typedef struct {
  char name[50];
  char northDestination[50];
  char northAccess[50];
  char eastDestination[50];
  char eastAccess[50];
  char southDestination[50];
  char southAccess[50];
  char westDestination[50];
  char westAccess[50];
  char description[500];
  char firstVisitText[500];
  char icon[1];
  bool visited;
  int temperature;
  char items[5][25];
} Location;

Location locations[10];

Location rickensDoor = {
  "Ricken's Door",
  "Docks",
  "None",
  "Ricken's Hovel",
  "None",
  "None",
  "None",
  "None",
  "None",
  "You stand in front of Ricken's door. It's east of you. His home is a dilapidated shack in a row of dilapidated shacks that line the waterfront. North of you is the docks. The crowd at the boats is impassable. The cobblestone is slippery under your boots.",
  "",
  "_",
  true,
  5,
  {"Door"}
};

Location rickensHovel = {
  "Ricken's Hovel",  
  "None",
  "None",
  "None",
  "None",
  "None",
  "None",
  "Ricken's Door",
  "Open",
  "A small room lit by a mostly open fire with a cast iron pot hung over it. There are rum bottles scattered across the floor. The door to the west leads outside.",
  "",
  "_",
  false,
  6,
  {"Ricken"}
};

Location docks = {
  "Docks",
  "None",
  "None",
  "None",
  "None",
  "None",
  "None",
  "None",
  "None",
  "The entire population of the island is at the docks trying to get passage on a boat. One trawler is inundated with flesh and taking on water. Ricken's men are fending them off with spears. Ricken stands at the edge of his boat with his rifle on his hip waiting for you.",
  "As the crowd encroahces on his boat, Ricken fires his rifle into the air. The scene goes quiet except for one woman with a baby. She sees you waiver as you board and she pleads for you to take the child. You look away and she pushes it under your arm. You throw your hands up and the kid goes into the drink. She goes onto her knees. Two of the men leap at you.",
  "_",
  false,
  5,
  {},
};

Location unconscious = {
  "Unconscious",  
  "None",
  "None",
  "None",
  "None",
  "None",
  "None",
  "None",
  "None",
  "You are unconscious.",
  "",
  "_",
  false,
  5,
  {},
};

Location shore = {
  "Shore", 
  "Ocean",
  "Water",
  "None",
  "None",
  "Jungle",
  "Open",
  "Delta",
  "Open",
  "The sand is gray, as is everything. The sea is north. To the east and west there is more beach. South there is a path into the jungle. A bare, black crag juts out from its center.",
  "",
  ".",
  true,
  5,
  {"Sand", "Boat"},
};

Location ocean = {
  "Ocean",  
  "None",
  "None",
  "None",
  "None",
  "Shore",
  "Shore",
  "None",
  "None",
  "You are on a small boat on a roiling sea. The sky is blotched with dark, gray clouds. It fades into the ocean in all directions save to the south. There you see a sliver of dark between the peaks of the waves.",
  "",
  "W",
  false,
  5,
  {},
};

Location jungle = {
  "Jungle",  
  "Shore",
  "Open",
  "None",
  "None",
  "Cave",
  "Open",
  "None",
  "None",
  "The air in the jungle is thick. You can only cut a narrow path through. Huge ferns sweep past your legs as you walk. They could be hiding anything. To the south, almost hidden behind a huge, moss covered rock, you find the entrance to the cave. To the east and west there is more jungle. You can hear the ocean to the north.",
  "",
  "J",
  false,
  5,
  {"Coconut", "Ferns", "Woods", "Vines"},
};

Location cave = {
  "Cave", 
  "Jungle",
  "Open",
  "None",
  "None",
  "Chamber",
  "Open",
  "None",
  "None",
  "You are in a dark cave. The walls are wet and slick. After your eyes adjust you can see what appears to be a switch set into the wall high above you.",
  //"Effected":"Everything around you is on fire. There is a large crack to the north. You can see jungle beyond it. To the south there is a low opening."
  "",
  "C",
  false,
  4,
  {},
};

Location chamber = {
  "Chamber",  
  "Cave",
  "Open",
  "None",
  "None",
  "None",
  "None",
  "None",
  "None",
  "This is a smaller cave. The walls are jagged and shiny.",
  "",
  "F",
  false,
  4,
  {"Flint"},
};

Location delta = {
  "Delta",  
  "Ocean",
  "Water",
  "Shore",
  "Open",
  "Waterfall",
  "Climb",
  "None",
  "None",
  "A narrow but deep river meets the sea here. There is some vegetation around the edges, but nothing of any apparent use. To the east is a stretch of beach. North is the ocean. To the south is a high waterfall. It's falling from a cliff. There are hand holds in the cliff, but you have never climbed anything that didn't have rungs.",
  "",
  "V",
  false,
  5,
  {"Water", "Berries", "Cloth"},
};

Location waterfall = {
  "North", 
  "Delta",
  "Climb",
  "None",
  "None",
  "None",
  "None",
  "None",
  "None",
  "You stand at the edge of a sheer cliff. It is as high as a three story building. A deep river comes from the South and flows over the cliff. The sound of the falling water is deafening. You might be able to climb down here, but the thought of it make your chest tighten up and your stomach drop.",
  "",
  "W",
  false,
  5,
  {"Water"},
};

void buildLocations() {
  locations[0] = rickensDoor;
  locations[1] = rickensHovel;
  locations[2] = docks;
  locations[3] = unconscious;
  locations[4] = shore;
  locations[5] = ocean;
  locations[6] = jungle;
  locations[7] = cave;
  locations[8] = chamber;
  locations[9] = delta;
  locations[10] = waterfall;
}


