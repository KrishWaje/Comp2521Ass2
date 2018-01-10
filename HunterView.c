////////////////////////////////////////////////////////////////////////
// COMP2521 18x1 ... the Fury of Dracula
// HunterView.c: the HunterView ADT implementation
//
// 2014-07-01   v1.0    Team Dracula <cs2521@cse.unsw.edu.au>
// 2017-12-01   v1.1    Team Dracula <cs2521@cse.unsw.edu.au>

#include <assert.h>
#include <err.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sysexits.h>

#include "Game.h"
#include "GameView.h"
#include "Globals.h"
#include "HunterView.h"
// #include "Map.h" ... if you decide to use the Map ADT

struct hunterView {
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
};

// Creates a new HunterView to summarise the current state of the game
HunterView
newHunterView (char *pastPlays, PlayerMessage messages[])
{
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    HunterView new = malloc (sizeof *new);
    if (new == NULL) err (EX_OSERR, "couldn't allocate HunterView");

    return new;
}

// Frees all memory previously allocated for the HunterView toBeDeleted
void
disposeHunterView (HunterView toBeDeleted)
{
    // COMPLETE THIS IMPLEMENTATION
    free (toBeDeleted);
}

//// Functions to return simple information about the current state of the game

// Get the current round
Round
giveMeTheRound (HunterView hv)
{
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    return 0;
}

// Get the id of current player
PlayerID
whoAmI (HunterView hv)
{
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    return 0;
}

// Get the current score
int
giveMeTheScore (HunterView hv)
{
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    return 0;
}

// Get the current health points for a given player
int
howHealthyIs (HunterView hv, PlayerID player)
{
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    return 0;
}

// Get the current location id of a given player
LocationID
whereIs (HunterView hv, PlayerID player)
{
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    return 0;
}

//// Functions that return information about the history of the game

// Fills the trail array with the location ids of the last 6 turns
void
giveMeTheTrail (HunterView hv, PlayerID player,
    LocationID trail[TRAIL_SIZE])
{
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
}

//// Functions that query the map to find information about connectivity

// What are my possible next moves (locations)
LocationID *
whereCanIgo (HunterView hv, int *numLocations,
    bool road, bool rail, bool sea)
{
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    *numLocations = 0;
    return NULL;
}

// What are the specified player's next possible moves
LocationID *
whereCanTheyGo (HunterView hv, int *numLocations, PlayerID player,
    bool road, bool rail, bool sea)
{
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    *numLocations = 0;
    return NULL;
}
