////////////////////////////////////////////////////////////////////////
// COMP2521 18x1 ... the Fury of Dracula
// GameView.c: GameView ADT implementation
//
// 2014-07-01   v1.0    Team Dracula <cs2521@cse.unsw.edu.au>
// 2017-12-01   v1.1    Team Dracula <cs2521@cse.unsw.edu.au>

#include <assert.h>
#include <err.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <sysexits.h>
#include <stdio.h>
#include <string.h>

#include "Game.h"
#include "GameView.h"
#include "Globals.h"
// #include "Map.h" ... if you decide to use the Map ADT
typedef struct moves *Move;

struct moves {
    char loc[2];
    int trap;
    int dracula;
    Move next;
    Move prev;
};

struct gameView {
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    Round round;
    int score[5];
    int health[5];
    Move Ghead, Gtail;
    int Gturns;
    Move Shead, Stail;
    int Sturns;
    Move Hhead, Htail;
    int Hturns;
    Move Mhead, Mtail;
    int Mturns;
    Move Dhead, Dtail;
    int Dturns;
    int draculaEncounters;
};

static Move newMove() {
   Move new = malloc(sizeof(struct moves));
   assert(new != NULL);
   new->next = NULL;
   new->prev = NULL;
   return new;
}


// Creates a new GameView to summarise the current state of the game
GameView
newGameView (char *pastPlays, PlayerMessage messages[])
{
    GameView new = malloc (sizeof *new);
    if (new == NULL) err (EX_OSERR, "couldn't allocate GameView");
    
    Move prevG = NULL;
    Move prevS = NULL;
    Move prevH = NULL;
    Move prevM = NULL;
    Move prevD = NULL;
    new->Gtail = NULL;
    new->Stail = NULL;
    new->Htail = NULL;
    new->Mtail = NULL;
    new->Htail = NULL;
    new->Gturns = 0;
    new->Sturns = 0;
    new->Hturns = 0;
    new->Mturns = 0;
    new->Dturns = 0;
    new->round = 0;
    new->draculaEncounters = 0;
    
    int i = 0;
    char loc[2];
    while (pastPlays[i] != '\0') {
       if (i%40 == 0) {
          new->round++;
       }
       if (i%8 == 1) {
          //printf("%c", pastPlays[i]);
       
          loc[0] = pastPlays[i];
          loc[1] = pastPlays[i+1];
          
          printf("loc: %s\n", loc);
          
          Move newNode = newMove();
          
          // Can add health and score later
          switch (pastPlays[i-1]) {
             case 'G': 
                new->Gturns++;
                if (i < 39) {
                   new->Ghead = newNode;
                }
                newNode->loc[0] = loc[0];
                newNode->loc[1] = loc[1];
                if (new->Gtail == NULL) { 
                    new->Gtail = newNode;
                } else { 
                    new->Gtail->next = newNode;
                    new->Gtail = newNode;
                }
                newNode->prev = prevG;
                prevG = newNode;
                break;
             case 'S': 
                new->Sturns++;
                if (i < 39) {
                   new->Shead = newNode;
                   new->Stail = NULL;
                }
                newNode->loc[0] = loc[0];
                newNode->loc[1] = loc[1];
                if (new->Stail == NULL) { 
                    new->Stail = newNode;
                } else { 
                    new->Stail->next = newNode;
                    new->Stail = newNode;
                }
                newNode->prev = prevS;
                prevS = newNode;
                break;
             case 'H':
                new->Hturns++; 
                if (i < 39) {
                   new->Hhead = newNode;
                   new->Htail = NULL;
                }
                newNode->loc[0] = loc[0];
                newNode->loc[1] = loc[1];
                if (new->Htail == NULL) { 
                    new->Htail = newNode;
                } else { 
                    new->Htail->next = newNode;
                    new->Htail = newNode;
                }
                newNode->prev = prevH;
                prevD = newNode;
                break;
             case 'M':
                new->Mturns++; 
                if (i < 39) {
                   new->Mhead = newNode;
                   new->Mtail = NULL;
                }
                newNode->loc[0] = loc[0];
                newNode->loc[1] = loc[1];
                 if (new->Mtail == NULL) { 
                    new->Mtail = newNode;
                } else { 
                    new->Mtail->next = newNode;
                    new->Mtail = newNode;
                }
                newNode->prev = prevM;
                prevM = newNode;
                break;
             case 'D':
                new->Dturns++; 
                if (i < 39) {
                   new->Dhead = newNode;
                   new->Dtail = NULL;
                }
                newNode->loc[0] = loc[0];
                newNode->loc[1] = loc[1];
                if (new->Dtail == NULL) { 
                    new->Dtail = newNode;
                } else { 
                    new->Dtail->next = newNode;
                    new->Dtail = newNode;
                }
                newNode->prev = prevD;
                prevD = newNode;
                break;
             default:
                break;
          }
       }
       i++;
    }
    printf("\n%s\n", new->Gtail->prev->loc);
    printf("\nrounds: %d\n", new->round);

    return new;
}

// Frees all memory previously allocated for the GameView toBeDeleted
void
disposeGameView (GameView toBeDeleted)
{
    Move node = toBeDeleted->Ghead;
    Move temp;
    while (node != NULL) {
       temp = node->next;
       free(node);
       node = temp;
    }
    node = toBeDeleted->Shead;
    while (node != NULL) {
       temp = node->next;
       free(node);
       node = temp;
    }
    node = toBeDeleted->Hhead;
    while (node != NULL) {
       temp = node->next;
       free(node);
       node = temp;
    }
    node = toBeDeleted->Mhead;
    while (node != NULL) {
       temp = node->next;
       free(node);
       node = temp;
    }
    node = toBeDeleted->Dhead;
    while (node != NULL) {
       temp = node->next;
       free(node);
       node = temp;
    }
    free (toBeDeleted);
}

//// Functions to return simple information about the current state of the game

// Get the current round
Round
getRound (GameView gv)
{
    return gv->round;
}

// Get the id of current player - ie whose turn is it?
PlayerID
getCurrentPlayer (GameView gv)
{
    // REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    if (gv->Sturns < gv->Gturns) {
       return PLAYER_DR_SEWARD;
    } else if (gv->Hturns < gv->Sturns) {
       return PLAYER_VAN_HELSING;
    } else if (gv->Mturns < gv->Hturns) {
       return PLAYER_MINA_HARKER;
    } else if (gv->Dturns < gv->Mturns) {
       return PLAYER_DRACULA;
    } else {
       return PLAYER_LORD_GODALMING;
    } 
}

// Get the current score, not finished
int
getScore (GameView gv)
{
    int score = 366-gv->Dturns;
    
    
    return score;
}

// Get the current health points for a given player, not finished
int
getHealth (GameView gv, PlayerID player)
{
   Move playerNode = NULL;
   switch (player) {
      case PLAYER_LORD_GODALMING: playerNode = gv->Ghead;
      case PLAYER_DR_SEWARD: playerNode = gv->Shead;
      case PLAYER_VAN_HELSING: playerNode = gv->Hhead;
      case PLAYER_MINA_HARKER: playerNode = gv->Mhead;
      case PLAYER_DRACULA: playerNode = gv->Dhead;
   }
   int health;
   int healthPrev
   if (playerNode == gv->Dhead) {
      
      
      
   } else {
      health = GAME_START_HUNTER_LIFE_POINTS;
      healthPrev = 0;
      while (playerNode != NULL) {
         if (playerNode->trap == 1) {
            health -= LIFE_LOSS_TRAP_ENCOUNTER;
         }
         if (playerNode->dracula == 1) {
            health -= LIFE_LOSS_DRACULA_ENCOUNTER;
         }
         if (playerNode->rest == 1) {
            health += LIFE_GAIN_REST; 
         }
         if (health <= 0 && healthPrev <= 0) {
            health == GAME_START_HUNTER_LIFE_POINTS
         }
         if
         healthPrev = health;
         playerNode = playerNode->next;
      }
   }
    
    return health;
}

// Get the current location id of a given player
LocationID
getLocation (GameView gv, PlayerID player)
{
   switch (player) {
      case PLAYER_LORD_GODALMING: return abbrevToID(gv->Gtail->loc);
      case PLAYER_DR_SEWARD: return abbrevToID(gv->Stail->loc);
      case PLAYER_VAN_HELSING: return abbrevToID(gv->Htail->loc);
      case PLAYER_MINA_HARKER: return abbrevToID(gv->Mtail->loc);
      // fix cases with unknown cities etc.
      case PLAYER_DRACULA: return abbrevToID(gv->Dtail->loc);
   }
   return 0;   
}

//// Functions that return information about the history of the game

// Fills the trail array with the location ids of the last 6 turns
void
getHistory (GameView gv, PlayerID player, LocationID trail[TRAIL_SIZE])
{
   Move tail = NULL;
   switch (player) {
      case PLAYER_LORD_GODALMING: tail = gv->Gtail;
      case PLAYER_DR_SEWARD: tail = gv->Stail;
      case PLAYER_VAN_HELSING: tail = gv->Htail;
      case PLAYER_MINA_HARKER: tail = gv->Mtail;
      case PLAYER_DRACULA: tail = gv->Dtail;
   }
   int i = 0;
   while (i < 6) {
      trail[i] = abbrevToID(tail->loc);
      tail = tail->prev;
      i++;
   }
   
}

//// Functions that query the map to find information about connectivity

// Returns an array of LocationIDs for all directly connected locations

LocationID *
connectedLocations (GameView gv, int *numLocations,
    LocationID from, PlayerID player, Round round,
    bool road, bool rail, bool sea)
{

    *numLocations = 0;
    return NULL;
}
