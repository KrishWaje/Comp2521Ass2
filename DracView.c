////////////////////////////////////////////////////////////////////////
// COMP2521 18x1 ... the Fury of Dracula
// DracView.c: the DracView ADT implementation
//
// 2014-07-01   v1.0    Team Dracula <cs2521@cse.unsw.edu.au>
// 2017-12-01   v1.1    Team Dracula <cs2521@cse.unsw.edu.au>

#include <assert.h>
#include <err.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sysexits.h>

#include "DracView.h"
#include "Game.h"
#include "GameView.h"
#include "Globals.h"
// #include "Map.h" ... if you decide to use the Map ADT
     
struct dracView {
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
};
     

// Creates a new DracView to summarise the current state of the game
DracView
newDracView (char *pastPlays, PlayerMessage messages[])
{
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    DracView new = malloc (sizeof *new);
    if (new == NULL) err (EX_OSERR, "couldn't allocate DracView)");

    return new;
}

// Frees all memory previously allocated for the DracView toBeDeleted
void
disposeDracView (DracView toBeDeleted)
{
    // COMPLETE THIS IMPLEMENTATION
    free (toBeDeleted);
}

//// Functions to return simple information about the current state of the game

// Get the current round
Round
giveMeTheRound (DracView dv)
{
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    return 0;
}

// Get the current score
int
giveMeTheScore (DracView dv)
{
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    return 0;
}

// Get the current health points for a given player
int
howHealthyIs (DracView dv, PlayerID player)
{
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    return 0;
}

// Get the current location id of a given player
LocationID
whereIs (DracView dv, PlayerID player)
{
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    return 0;
}

// Get the most recent move of a given player
void
lastMove (DracView dv, PlayerID player,
    LocationID *start, LocationID *end)
{
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    return;
}

// Find out what minions are placed at the specified location
void
whatsThere (DracView dv, LocationID where,
    int *numTraps, int *numVamps)
{
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    return;
}

//// Functions that return information about the history of the game

// Fills the trail array with the location ids of the last 6 turns
void
giveMeTheTrail (DracView dv, PlayerID player,
    LocationID trail[TRAIL_SIZE])
{
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
}

//// Functions that query the map to find information about connectivity

// What are my (Dracula's) possible next moves (locations)
LocationID *
whereCanIgo (DracView dv, int *numLocations, bool road, bool sea)
{
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    return NULL;
}

// What are the specified player's next possible moves
LocationID *
whereCanTheyGo (DracView dv, int *numLocations, PlayerID player,
    bool road, bool rail, bool sea)
{
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    *numLocations = 0;
    return NULL;
}
