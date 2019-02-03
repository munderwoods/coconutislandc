typedef struct {
  char name[50];
  char visualDescription[300];
  char locationDescription[300];
  int obtainable;
  bool open;
  bool edible;
} Item;

Item items[100];

Item Door = {
  "Door",
  "A shoddy wooden door.",
  "The door to Ricken's hovel is locked.",
  0,
  false,
  false,
};

Item Ricken = {
  "Ricken",
  "Ricken is a seaman if there ever was one. He has wispy silver hair that matches his moustaches. The moustaches, like his eyes and nose, are thin.",
  "Ricken is standing by the fire, drinking.",
  0,
  false,
  false,
};

Item Rifle = {
  "Rifle",
  "A long, wooden rifle. You don't know enough to say more about it.",
  "There is an old rifle here.",
  1,
  false,
  false,
};

Item Gold = {
  "Gold Bar", 
  "Solid gold is heavy and this is a lot of it. There is a trident stamped into the side.",
  "There is a gold bar here. A big one.", 
  1, 
  false,
  false,
};

Item Sand = {
  "Sand",
  "Fine, gray sand.",
  "There is sand here.",
  2,
  false,
  false,
};

Item Boat = {
  "Boat",
  "It's got room for four crew or some small cargo.",
  "There is a boat here.",
  0,
  false,
  false,
};

Item Oar = {  
  "Oar",
  "A wooden oar that has been worn smooth and shiny from use.",
  "There is an oar sitting next to you.",
  1,
  false,
  false,
};

Item Paper = {  
  "Paper",
  "A blank sheet of paper. It would be perfect for drawing a map on.",
  "Ther is a rolled up piece of paper here.",
  1,
  false,
  false,
};

Item Pencil = {  
  "Pencil",
  "A well-used pencil. You will have to be thoughtful and conserve it.",
  "There is a pencil here.",
  1,
  false,
  false,
};

Item Coconut = {  
  "Coconut",
  "A round, Harry coconut.",
  "There is a coconut half buried here.",
  1,
  false,
  false,
};

Item Ferns = {  
  "Ferns",
  "The ferns are oozing a clear, sticky substance.",
  "There are sticky ferns here.",
  2,
  false,
  false,
};

Item Wood = {  
  "Wood",
  "A small bit of wood.",
  "There is wood here.",
  2,
  false,
  false,
};

Item Vines = {  
  "Vines",
  "Some long, thin vines that curl around the trees here. They are dark green and shine in the sunlight.",
  "There are some vines here.",
  2,
  false,
  false,
};

Item Flint = {  
  "Flint",
  "A shiny, smooth stone with sharp edges.",
  "There is flint here.",
  2,
  false,
  false,
};

Item Water = {  
  "Water",
  "The water is clear and looks refreshing.",
  "The water appears clean and drinkable.",
  2,
  false,
  false,
};

Item Berries = {  
  "Berries",
  "Small, red berries.",
  "There are some wild berries here.",
  2,
  true,
  true,
};

Item Cloth = {  
  "Cloth",
  "It appears to be a piece of an old ship mast.",
  "There is some tattered cloth here.",
  1,
  false,
  false,
};

Item Fire = {
  "Fire",
  "A small fire. It offers meager warmth.",
  "There is a fire here.",
  0,
  false,
  false,
};

Item Sundial = {
  "Sundial",
  "A stick protruding from the sand. The shadow coming off of the stick indicates the time of day. Only works where sunlight is present.",
  "There is a sundial here.",
  0,
  false,
  false,
};

Item Pack= {
  "Pack", 
  "A crude backpack you crafted out of an old shipmast and some vines. It carries little and looks like it might fall apart from a slight jossling.",
  "There is a pack here.",
  1,    
	false,
  false,
};

Item Map = {
  "Map", 
  "A map of the indian ocean. From what you can tell, your current location is unmarked. You will have to update the map as you go.",
	"There is what appears to be a rolled up map here.",
  1,
  false,
  false,
};

/*
Item Splint = {
  "Splint",
  "A crude medical device that can be used to mend a broken bone.",
  "There is a splint here.",
  1,
  false,
  false,
};
*/

void buildItems() {
  items[0] = Door;
  items[1] = Ricken;
  items[2] = Rifle;
  items[3] = Gold;
  items[4] = Sand;
  items[5] = Boat;
  items[7] = Paper;
  items[8] = Pencil;
  items[9] = Coconut;
  items[10] = Ferns;
  items[11] = Wood;
  items[12] = Vines;
  items[13] = Flint;
  items[14] = Water;
  items[15] = Berries;
  items[16] = Cloth;
  items[17] = Fire;
  items[18] = Sundial;
  items[19] = Pack;
  items[20] = Map;
  //items[21] = Splint;
}

