#include <unistd.h>
#include <ncurses.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>

#include "io.h"
#include "poke327.h"
#include "pokemon.h"

void use_pot(){
  long unsigned int i;
  bool partyalive;
  partyalive = false;
  clear();
  mvprintw(0,0,"select pokemon to use pots: (1-%d)", world.pc.pkmn.size());
  for(i = 0; i <world.pc.pkmn.size() && i < 6;i++){
    mvprintw(i+1,0, "%d. %s hp: %d of %d", i+1, world.pc.pkmn[i].get_species(),
	     world.pc.pkmn[i].currenthp, world.pc.pkmn[i].get_hp());
    if(world.pc.pkmn[i].currenthp>0){ partyalive = true;}
    
  }
  refresh();
  char input = getch();
  bool inputcheck = false;
  long unsigned int check;
  check = input - 48;
  if(!partyalive){
    inputcheck = true;
  }
  while(!inputcheck){
    if(check > world.pc.pkmn.size()){
      mvprintw(8,0, "wrong entry:%c, try another num", input);
      input = getch();
    }
    else if(input == '1'){
      if(world.pc.pkmn[0].currenthp>0){
	world.pc.pkmn[0].currenthp+=20;
      }
      if(world.pc.pkmn[0].currenthp>world.pc.pkmn[0].get_hp()){
	world.pc.pkmn[0].currenthp = world.pc.pkmn[0].get_hp();
      }
      inputcheck = true;
      mvprintw(8,0, "use pot on %s, new hp:%d", world.pc.pkmn[0].get_species(),
	       world.pc.pkmn[0].currenthp);
      if(world.pc.pkmn[0].currenthp == 0){
	mvprintw(9,0, "poured potion on pkmn's face, fainted can't drink potions");
      }
      getch();
    }
    else if(input == '2'){
      if(world.pc.pkmn[1].currenthp>0){
	world.pc.pkmn[1].currenthp+=20;
      }
      if(world.pc.pkmn[1].currenthp>world.pc.pkmn[1].get_hp()){
	world.pc.pkmn[1].currenthp = world.pc.pkmn[1].get_hp();
      }
      inputcheck = true;
      mvprintw(8,0, "use pot on %s, new hp:%d", world.pc.pkmn[1].get_species(),
	       world.pc.pkmn[1].currenthp);
      if(world.pc.pkmn[0].currenthp == 0){
	mvprintw(9,0, "poured potion on pkmn's face, fainted can't drink potions");
      }
      getch();
    }
    else if(input == '3'){
      if(world.pc.pkmn[2].currenthp>0){
	world.pc.pkmn[2].currenthp+=20;
      }
      if(world.pc.pkmn[2].currenthp>world.pc.pkmn[2].get_hp()){
	world.pc.pkmn[2].currenthp = world.pc.pkmn[2].get_hp();
      }
      inputcheck = true;
      mvprintw(8,0, "use pot on %s, new hp:%d", world.pc.pkmn[2].get_species(),
	       world.pc.pkmn[2].currenthp);
      if(world.pc.pkmn[0].currenthp == 0){
	mvprintw(9,0, "poured potion on pkmn's face, fainted can't drink potions");
      }
      getch();
    }
    else if(input == '4'){
      if(world.pc.pkmn[3].currenthp>0){
	world.pc.pkmn[3].currenthp+=20;
      }
      if(world.pc.pkmn[3].currenthp>world.pc.pkmn[3].get_hp()){
	world.pc.pkmn[3].currenthp = world.pc.pkmn[3].get_hp();
      }
      inputcheck = true;
      mvprintw(8,0, "use pot on %s, new hp:%d", world.pc.pkmn[3].get_species(),
	       world.pc.pkmn[3].currenthp);
      if(world.pc.pkmn[0].currenthp == 0){
	mvprintw(9,0, "poured potion on pkmn's face, fainted can't drink potions");
      }
      getch();
    }
    else if(input == '5'){
      if(world.pc.pkmn[4].currenthp>0){
	world.pc.pkmn[4].currenthp+=20;
      }
      if(world.pc.pkmn[4].currenthp>world.pc.pkmn[4].get_hp()){
	world.pc.pkmn[4].currenthp = world.pc.pkmn[4].get_hp();
      }
      inputcheck = true;
      mvprintw(8,0, "use pot on %s, new hp:%d", world.pc.pkmn[4].get_species(),
	       world.pc.pkmn[4].currenthp);
      if(world.pc.pkmn[0].currenthp == 0){
	mvprintw(9,0, "poured potion on pkmn's face, fainted can't drink potions");
      }
      getch();
    }
    else if(input == '6'){
      if(world.pc.pkmn[5].currenthp>0){
	world.pc.pkmn[5].currenthp+=20;
      }
      if(world.pc.pkmn[5].currenthp>world.pc.pkmn[5].get_hp()){
	world.pc.pkmn[5].currenthp = world.pc.pkmn[5].get_hp();
      }
      inputcheck = true;
      mvprintw(8,0, "use pot on %s, new hp:%d", world.pc.pkmn[5].get_species(),
	       world.pc.pkmn[5].currenthp);
      if(world.pc.pkmn[0].currenthp == 0){
	mvprintw(9,0, "poured potion on pkmn's face, fainted can't drink potions");
      }
      getch();
    }
  }///// while's ending  
}

void use_vive(){  
  long unsigned int i;
  bool inputcheck;
  inputcheck = true;  
  clear();
  mvprintw(0,0,"select pokemon to revive: 1- %d", world.pc.pkmn.size());
  for(i = 0; i <world.pc.pkmn.size() && i < 6; i++){
    mvprintw(i+1, 0 , "%d. %s hp:%d", i+1, world.pc.pkmn[i].get_species(),
	     world.pc.pkmn[i].currenthp);
    if(world.pc.pkmn[i].currenthp<=0){
      inputcheck = false;
    }//end if
  }//end for
  if(inputcheck){
    mvprintw(8,0, "no dead fainted pkmn");
    world.pc.vives++; //restock the vive
  }
  char input = getch();
  while(!inputcheck){
    switch(input){
    case '1':
      if(world.pc.pkmn[0].currenthp ==0){
	world.pc.pkmn[0].currenthp = world.pc.pkmn[0].get_hp();
	mvprintw(8,0, "%s hp is full", world.pc.pkmn[0].get_species());
	inputcheck = true; input = getch();
      }
      else{
	mvprintw(8,0, "try again"); input = getch();
      }
      break;
    case '2':
      if((world.pc.pkmn[1].currenthp ==0) && (i>0)){
	world.pc.pkmn[1].currenthp = world.pc.pkmn[1].get_hp();
	mvprintw(8,0, "%s hp is full", world.pc.pkmn[1].get_species());
	inputcheck = true; input = getch();
      }
      else{
	mvprintw(8,0, "try again"); input = getch();
      }
      break;
    case '3':
      if((world.pc.pkmn[2].currenthp ==0) && (i>1)){
	world.pc.pkmn[2].currenthp = world.pc.pkmn[2].get_hp();
	mvprintw(8,0, "%s hp is full", world.pc.pkmn[2].get_species());
	inputcheck = true; input = getch();
      }
      else{
	mvprintw(8,0, "try again"); input = getch();
      }
      break;
    case '4':
      if((world.pc.pkmn[3].currenthp ==0) && (i>2)){
	world.pc.pkmn[3].currenthp = world.pc.pkmn[3].get_hp();
	mvprintw(8,0, "%s hp is full", world.pc.pkmn[3].get_species());
	inputcheck = true; input = getch();
      }
      else{
	mvprintw(8,0, "try again"); input = getch();
      }
      break;
    case '5':
      if((world.pc.pkmn[4].currenthp ==0) && (i>3)){
	world.pc.pkmn[4].currenthp = world.pc.pkmn[4].get_hp();
	mvprintw(8,0, "%s hp is full", world.pc.pkmn[4].get_species());
	inputcheck = true; input = getch();
      }
      else{
	mvprintw(8,0, "try again"); input = getch();
      }
      break;
    case '6':
      if((world.pc.pkmn[5].currenthp ==0) && (i>4)){
	world.pc.pkmn[5].currenthp = world.pc.pkmn[5].get_hp();
	mvprintw(8,0, "%s hp is full", world.pc.pkmn[5].get_species());
	inputcheck = true; input = getch();
      }
      else{
	mvprintw(8,0, "try again"); input = getch();
      }
      break;
    case 27:
      inputcheck = true;
      getch();
    default:
      mvprintw(8,0, "wrong input");
      input =  getch();
    }//end switch
  }//end while loop
  
  
}
int use_ball(pokemon *p){ //bcd
  clear();
  mvprintw(3,20, "Throwing a PokeBall...");
  //getch();
  refresh();
  int rone;
  int f; //hp factor
  int d;
  int rtwo; //r2
  rone = rand()%256;
  rtwo = rand()%256;
  bool brokefree;
  brokefree = false;
  f = (p->get_hp() *255 * 4)/(p->currenthp * 12);
  if(f<1){
    f = 1;
  }
  if(f>255){
    f = 255;
  }
  
  
  if(p->get_capch() < rone){
    mvprintw(4,20, "%s broke free", p->get_species());
    refresh();
    brokefree = true;
    getch();
    //return 0;
    world.pc.pballs--;
  }
  if((rtwo<=f)&&(!brokefree)) {
    mvprintw(4,20, "%s is caught", p->get_species());
    refresh();
    getch();
    
    world.pc.pkmn.push_back(*p);
    
    //world.pc.pkmn.push_back(*p);
    world.pc.pballs--;
    return 1;
  }
  if(brokefree){
    d = (((p->get_capch() * 100) / 255) * f)/255;
    
    if(d<10){
      mvprintw(5,20, "The ball missed the POKEMON!");
      refresh();
    }
    else if( (d>=10) && (d <= 29) ){
      mvprintw(5,20, "Darn! The POKEMON broke free!");
    }
    else if( (d>=30) && (d<=69) ){
      mvprintw(5,20, "Aww! It appeared to be caught!");
    }
    else{
      mvprintw(5,20, "Shoot! It was so close too!");
    }
    //d = (d * f)/255;
    getch();
    return 0;
  }
  
  // if(world.pc.pkmn.size() <6){
  //   world.pc.pkmn.push_back(*p);
  //   world.pc.pballs--;
  // }
  // else{
  //   mvprintw(4,20, "cannot catch, party is full");
  //   getch();
    
  //   return 0;
  // }
  // mvprintw(4,20, "%s was caught", p->get_species());
  
  // getch();
  // return 1;
  return 1;
}
int io_bag_menu(int pbattle){
  clear();
  mvprintw(0,0, "select item:");
  mvprintw(1,0, "1. potions: x%d", world.pc.pots);
  mvprintw(2,0, "2. revives: x%d", world.pc.vives);
  mvprintw(3,0, "3. pokeballs: x%d", world.pc.pballs);
  char pick = getch();
  bool inputcheck = false;
  if((world.pc.pots+world.pc.vives+world.pc.pballs) == 0){
    inputcheck = true;
  }
  while(!inputcheck){
    //refresh();
    switch(pick){
    case '1':
      if(world.pc.pots > 0){
	mvprintw(5,0, "Using potion...");
	world.pc.pots--; inputcheck = true; getch();
	use_pot();
	//return 1;
      }
      break;
    case '2':
      if(world.pc.vives > 0){
	mvprintw(5,0, "Using revive...");
	world.pc.vives--; inputcheck = true; getch();
	use_vive();
	//methods
	//return 2;
      }
      break;
    case '3':
      if(world.pc.pballs > 0){
	mvprintw(5,0, "Using pokeball...checking if trainerbattle");
	inputcheck = true; getch();
	if(pbattle ==0){
	  mvprintw(6,0, "dude,what you throwing at? exiting bag");
	  getch();
	}
	else{
	  return 1;
	  //mvprintw(6,0, "dude, you want to throw balls away? exit bag");
	  //getch();
	  //use_ball(p);
	  //world.pc.pballs--;
	  //return 1;
	}
	
	//methods
	//return 3;
      }
      break;
    default:
      if((world.pc.pots+world.pc.vives+world.pc.pballs) == 0){
	mvprintw(5,0, "no items");
	inputcheck = true;
      }
      else{
	mvprintw(5,0, "wrong number");
	pick = getch();
      }
      
    }
  }
  io_display();
  return 0;
}
void npc_next_poke(character *n){
  long unsigned int i;
  for(i = 1; i< n->pkmn.size(); i ++){
    if(n->pkmn[i].currenthp>0){
      swap(n->pkmn[0], n->pkmn[i]);
      break;
    }
  }
}

void switch_poke(){
  long unsigned int i;
  clear();
  mvprintw(0,0,"what poke to switch to? choose num 2 - %d", world.pc.pkmn.size());
  for(i=1; i < world.pc.pkmn.size() && i < 6; i++){
    mvprintw(i+1, 0 , "%d. %s", i+1, world.pc.pkmn[i].get_species());
    // getch();
  }
  getch();
  bool inputcheck = false;
  if(world.pc.pkmn.size()<2){
    inputcheck = true;
  }
  while(!inputcheck){
    char input = getch();
    if((input == '2')&& (i>1)){
      swap(world.pc.pkmn[0], world.pc.pkmn[1]);
      mvprintw(8,0, "new primary pkmn is: %s", world.pc.pkmn[0].get_species());
      getch(); inputcheck = true;
    }
    if((input == '3')&& (i>2)){
      swap(world.pc.pkmn[0], world.pc.pkmn[2]);
      mvprintw(8,0, "new primary pkmn is: %s", world.pc.pkmn[0].get_species());
      getch(); inputcheck = true;
    }
    if((input == '4')&&(i>3)){
      swap(world.pc.pkmn[0], world.pc.pkmn[3]);
      mvprintw(8,0, "new primary pkmn is: %s", world.pc.pkmn[0].get_species());
      getch(); inputcheck = true;
    }
    if((input == '5')&&(i>4)){
      swap(world.pc.pkmn[0], world.pc.pkmn[4]);
      mvprintw(8,0, "new primary pkmn is: %s", world.pc.pkmn[0].get_species());
      getch(); inputcheck = true;
    }
    if((input == '6')&&(i>5)){
      swap(world.pc.pkmn[0], world.pc.pkmn[5]);
      mvprintw(8,0, "new primary pkmn is: %s", world.pc.pkmn[0].get_species());
      getch(); inputcheck = true;
    }
    else{
      mvprintw(8,0, "wrong entry, try again");
      getch();   
    }
  }
}

typedef struct io_message {
  /* Will print " --more-- " at end of line when another message follows. *
   * Leave 10 extra spaces for that.                                      */
  char msg[71];
  struct io_message *next;
} io_message_t;

static io_message_t *io_head, *io_tail;

void init_poketeam(){ //bcd
  pokemon *a = new pokemon(5);
  pokemon *b;
  pokemon *c;

  //a = new pokemon(1);
  b = new pokemon(5); c = new pokemon(5);
  pokemon *d = new pokemon(5);
  pokemon *e = new pokemon(5);
  pokemon *f = new pokemon(5);
  pokemon *g = new pokemon(5);
  a->fainted = false; b->fainted = false; c->fainted = false;
  clear();
  printw( "Choose pokemon:\n");
  printw( "press 1 to select %s\n", a->get_species());
  printw( "press 2 to select %s\n", b->get_species());
  printw( "press 3 to select %s\n", c->get_species());
  char input = getch();
  bool inputcheck = false;
  while(!inputcheck){
    // if(input == '1'){
    //   clear();
    //   printw("you got %s", a->get_species());
    //   world.pc.pkmn.push_back(*a);
    //   input check = true;
    //   getch();
    // }
    // else if(input == '2'){
    //   clear();
    //   printw("you got %s", b->get_species());
    //   world.pc.pkmn.push_back(*b);
    //   input check = true;
    //   getch();
    // }
    // else if(input == '3'){
    //   clear();
    //   printw("you got %s", c->get_species());
    //   world.pc.pkmn.push_back(*c);
    //   input check = true;
    //   getch();
    // }
    // else{
    //   printw("wrong entry: %c, try(1-3)", input);
    // }
    switch(input){
    case '1':
      //clear();
      printw( "You got %s!", a->get_species());
      world.pc.pkmn.push_back(*a);
      inputcheck = true;
      getch();
      //delete b; delete c;
      break;
    case '2':
      printw("You got %s!", b->get_species());
      world.pc.pkmn.push_back(*b);
      inputcheck = true;
      getch();
      //delete a; delete c;
      break;
    case '3':
      printw("You got %s!", c->get_species());
      world.pc.pkmn.push_back(*c);
      inputcheck = true;
      getch();
      //delete a; delete b;
      break;
    case '6':
      world.pc.pkmn.push_back(*a);
      world.pc.pkmn.push_back(*b);
      world.pc.pkmn.push_back(*c);
      // pokemon *d = new pokemon(5);
      // pokemon *e = new pokemon(5);
      // pokemon *f = new pokemon(5);
      // pokemon *g = new pokemon(5);
      world.pc.pkmn.push_back(*d);
      world.pc.pkmn.push_back(*e);
      world.pc.pkmn.push_back(*f);
      world.pc.pkmn.push_back(*g);
      inputcheck = true;
      break;
    default:
      printw(/*4,0,*/ "wrong entry: %c, try (1-3)", input);
    }
  }
  world.pc.pkmn[0].fielded = true;
  //pkmn[0].fielded = true;
  world.pc.pkmn[0].currenthp = world.pc.pkmn[0].get_hp();
}

void init_npc_teams(character *n){
  int i;
  pokemon *a;
  clear();
  //taken from io_encounter_pokemon()
  int md = (abs(world.cur_idx[dim_x] - (WORLD_SIZE / 2)) +
            abs(world.cur_idx[dim_x] - (WORLD_SIZE / 2)));
  int minl, maxl;
  
  if (md <= 200) {
    minl = 1;
    maxl = md / 2;
  } else {
    minl = (md - 200) / 2;
    maxl = 100;
  }
  if (minl < 1) {
    minl = 1;
  }
  if (minl > 100) {
    minl = 100;
  }
  if (maxl < 1) {
    maxl = 1;
  }
  if (maxl > 100) {
    maxl = 100;
  }
  a = new pokemon(rand() % (maxl - minl + 1) + minl);
  a->fainted = false;
  a->currenthp = a->get_hp();
  n->pkmn.push_back(*a);
  i = rand()%10 + 1;
  if(i<=6){
    pokemon *b;
    b = new pokemon(rand() % (maxl - minl + 1) + minl);
    b->fainted = false; b->currenthp = b->get_hp(); n->pkmn.push_back(*b);
    i = rand()%10 + 1;
    if(i<=6){//3rd pkmn
      pokemon *c;
      c = new pokemon(rand() % (maxl - minl + 1) + minl);
      c->fainted = false; c->currenthp = c->get_hp(); n->pkmn.push_back(*c);
      i = rand()%10 + 1;
      if(i<=6){//4th  pkmn
	pokemon *d;
	d = new pokemon(rand() % (maxl - minl + 1) + minl);
	d->fainted = false; d->currenthp = d->get_hp(); n->pkmn.push_back(*d);
	i = rand()%10 + 1;
	if(i<=6){//5th pkmn
	  pokemon *e;
	  e = new pokemon(rand() % (maxl - minl + 1) + minl);
	  e->fainted = false; e->currenthp = e->get_hp(); n->pkmn.push_back(*e);
	  i = rand()%10 + 1;
	  if(i<=6){//6th pkmn
	    pokemon *f;
	    f = new pokemon(rand() % (maxl - minl + 1) + minl);
	    f->fainted = false; f->currenthp = f->get_hp(); n->pkmn.push_back(*f);
	  }
	}
      }
    }
  }
}


void io_init_terminal(void)
{
  initscr();
  raw();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  start_color();
  init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
  init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
  init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
  init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
  init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
  init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
}

void io_reset_terminal(void)
{
  endwin();

  while (io_head) {
    io_tail = io_head;
    io_head = io_head->next;
    free(io_tail);
  }
  io_tail = NULL;
}

void io_queue_message(const char *format, ...)
{
  io_message_t *tmp;
  va_list ap;

  if (!(tmp = (io_message_t *) malloc(sizeof (*tmp)))) {
    perror("malloc");
    exit(1);
  }

  tmp->next = NULL;

  va_start(ap, format);

  vsnprintf(tmp->msg, sizeof (tmp->msg), format, ap);

  va_end(ap);

  if (!io_head) {
    io_head = io_tail = tmp;
  } else {
    io_tail->next = tmp;
    io_tail = tmp;
  }
}

static void io_print_message_queue(uint32_t y, uint32_t x)
{
  while (io_head) {
    io_tail = io_head;
    attron(COLOR_PAIR(COLOR_CYAN));
    mvprintw(y, x, "%-80s", io_head->msg);
    attroff(COLOR_PAIR(COLOR_CYAN));
    io_head = io_head->next;
    if (io_head) {
      attron(COLOR_PAIR(COLOR_CYAN));
      mvprintw(y, x + 70, "%10s", " --more-- ");
      attroff(COLOR_PAIR(COLOR_CYAN));
      refresh();
      getch();
    }
    free(io_tail);
  }
  io_tail = NULL;
}

/**************************************************************************
 * Compares trainer distances from the PC according to the rival distance *
 * map.  This gives the approximate distance that the PC must travel to   *
 * get to the trainer (doesn't account for crossing buildings).  This is  *
 * not the distance from the NPC to the PC unless the NPC is a rival.     *
 *                                                                        *
 * Not a bug.                                                             *
 **************************************************************************/
static int compare_trainer_distance(const void *v1, const void *v2)
{
  const character *const *c1 = (const character * const *) v1;
  const character *const *c2 = (const character * const *) v2;

  return (world.rival_dist[(*c1)->pos[dim_y]][(*c1)->pos[dim_x]] -
          world.rival_dist[(*c2)->pos[dim_y]][(*c2)->pos[dim_x]]);
}

static character *io_nearest_visible_trainer()
{
  character **c, *n;
  uint32_t x, y, count;

  c = (character **) malloc(world.cur_map->num_trainers * sizeof (*c));

  /* Get a linear list of trainers */
  for (count = 0, y = 1; y < MAP_Y - 1; y++) {
    for (x = 1; x < MAP_X - 1; x++) {
      if (world.cur_map->cmap[y][x] && world.cur_map->cmap[y][x] !=
          &world.pc) {
        c[count++] = world.cur_map->cmap[y][x];
      }
    }
  }

  /* Sort it by distance from PC */
  qsort(c, count, sizeof (*c), compare_trainer_distance);

  n = c[0];

  free(c);

  return n;
}

void io_display()
{
  uint32_t y, x;
  character *c;

  clear();
  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      if (world.cur_map->cmap[y][x]) {
        mvaddch(y + 1, x, world.cur_map->cmap[y][x]->symbol);
      } else {
        switch (world.cur_map->map[y][x]) {
        case ter_boulder:
        case ter_mountain:
          attron(COLOR_PAIR(COLOR_MAGENTA));
          mvaddch(y + 1, x, '%');
          attroff(COLOR_PAIR(COLOR_MAGENTA));
          break;
        case ter_tree:
        case ter_forest:
          attron(COLOR_PAIR(COLOR_GREEN));
          mvaddch(y + 1, x, '^');
          attroff(COLOR_PAIR(COLOR_GREEN));
          break;
        case ter_path:
        case ter_exit:
          attron(COLOR_PAIR(COLOR_YELLOW));
          mvaddch(y + 1, x, '#');
          attroff(COLOR_PAIR(COLOR_YELLOW));
          break;
        case ter_mart:
          attron(COLOR_PAIR(COLOR_BLUE));
          mvaddch(y + 1, x, 'M');
          attroff(COLOR_PAIR(COLOR_BLUE));
          break;
        case ter_center:
          attron(COLOR_PAIR(COLOR_RED));
          mvaddch(y + 1, x, 'C');
          attroff(COLOR_PAIR(COLOR_RED));
          break;
        case ter_grass:
          attron(COLOR_PAIR(COLOR_GREEN));
          mvaddch(y + 1, x, ':');
          attroff(COLOR_PAIR(COLOR_GREEN));
          break;
        case ter_clearing:
          attron(COLOR_PAIR(COLOR_GREEN));
          mvaddch(y + 1, x, '.');
          attroff(COLOR_PAIR(COLOR_GREEN));
          break;
        default:
 /* Use zero as an error symbol, since it stands out somewhat, and it's *
  * not otherwise used.                                                 */
          attron(COLOR_PAIR(COLOR_CYAN));
          mvaddch(y + 1, x, '0');
          attroff(COLOR_PAIR(COLOR_CYAN)); 
       }
      }
    }
  }

  mvprintw(23, 1, "PC position is (%2d,%2d) on map %d%cx%d%c.",
           world.pc.pos[dim_x],
           world.pc.pos[dim_y],
           abs(world.cur_idx[dim_x] - (WORLD_SIZE / 2)),
           world.cur_idx[dim_x] - (WORLD_SIZE / 2) >= 0 ? 'E' : 'W',
           abs(world.cur_idx[dim_y] - (WORLD_SIZE / 2)),
           world.cur_idx[dim_y] - (WORLD_SIZE / 2) <= 0 ? 'N' : 'S');
  mvprintw(22, 1, "%d known %s.", world.cur_map->num_trainers,
           world.cur_map->num_trainers > 1 ? "trainers" : "trainer");
  mvprintw(22, 30, "Nearest visible trainer: ");
  if ((c = io_nearest_visible_trainer())) {
    attron(COLOR_PAIR(COLOR_RED));
    mvprintw(22, 55, "%c at %d %c by %d %c.",
             c->symbol,
             abs(c->pos[dim_y] - world.pc.pos[dim_y]),
             ((c->pos[dim_y] - world.pc.pos[dim_y]) <= 0 ?
              'N' : 'S'),
             abs(c->pos[dim_x] - world.pc.pos[dim_x]),
             ((c->pos[dim_x] - world.pc.pos[dim_x]) <= 0 ?
              'W' : 'E'));
    attroff(COLOR_PAIR(COLOR_RED));
  } else {
    attron(COLOR_PAIR(COLOR_BLUE));
    mvprintw(22, 55, "NONE.");
    attroff(COLOR_PAIR(COLOR_BLUE));
  }

  io_print_message_queue(0, 0);

  refresh();
}

uint32_t io_teleport_pc(pair_t dest)
{
  /* Just for fun. And debugging.  Mostly debugging. */

  do {
    dest[dim_x] = rand_range(1, MAP_X - 2);
    dest[dim_y] = rand_range(1, MAP_Y - 2);
  } while (world.cur_map->cmap[dest[dim_y]][dest[dim_x]]                  ||
           move_cost[char_pc][world.cur_map->map[dest[dim_y]]
                                                [dest[dim_x]]] == INT_MAX ||
           world.rival_dist[dest[dim_y]][dest[dim_x]] < 0);

  return 0;
}

static void io_scroll_trainer_list(char (*s)[40], uint32_t count)
{
  uint32_t offset;
  uint32_t i;

  offset = 0;

  while (1) {
    for (i = 0; i < 13; i++) {
      mvprintw(i + 6, 19, " %-40s ", s[i + offset]);
    }
    switch (getch()) {
    case KEY_UP:
      if (offset) {
        offset--;
      }
      break;
    case KEY_DOWN:
      if (offset < (count - 13)) {
        offset++;
      }
      break;
    case 27:
      return;
    }

  }
}

static void io_list_trainers_display(npc **c,
                                     uint32_t count)
{
  uint32_t i;
  char (*s)[40]; /* pointer to array of 40 char */

  s = (char (*)[40]) malloc(count * sizeof (*s));

  mvprintw(3, 19, " %-40s ", "");
  /* Borrow the first element of our array for this string: */
  snprintf(s[0], 40, "You know of %d trainers:", count);
  mvprintw(4, 19, " %-40s ", *s);
  mvprintw(5, 19, " %-40s ", "");

  for (i = 0; i < count; i++) {
    snprintf(s[i], 40, "%16s %c: %2d %s by %2d %s",
             char_type_name[c[i]->ctype],
             c[i]->symbol,
             abs(c[i]->pos[dim_y] - world.pc.pos[dim_y]),
             ((c[i]->pos[dim_y] - world.pc.pos[dim_y]) <= 0 ?
              "North" : "South"),
             abs(c[i]->pos[dim_x] - world.pc.pos[dim_x]),
             ((c[i]->pos[dim_x] - world.pc.pos[dim_x]) <= 0 ?
              "West" : "East"));
    if (count <= 13) {
      /* Handle the non-scrolling case right here. *
       * Scrolling in another function.            */
      mvprintw(i + 6, 19, " %-40s ", s[i]);
    }
  }

  if (count <= 13) {
    mvprintw(count + 6, 19, " %-40s ", "");
    mvprintw(count + 7, 19, " %-40s ", "Hit escape to continue.");
    while (getch() != 27 /* escape */)
      ;
  } else {
    mvprintw(19, 19, " %-40s ", "");
    mvprintw(20, 19, " %-40s ",
             "Arrows to scroll, escape to continue.");
    io_scroll_trainer_list(s, count);
  }

  free(s);
}

static void io_list_trainers()
{
  npc **c;
  uint32_t x, y, count;

  c = (npc **) malloc(world.cur_map->num_trainers * sizeof (*c));

  /* Get a linear list of trainers */
  for (count = 0, y = 1; y < MAP_Y - 1; y++) {
    for (x = 1; x < MAP_X - 1; x++) {
      if (world.cur_map->cmap[y][x] && world.cur_map->cmap[y][x] !=
          &world.pc) {
        c[count++] = (npc *) world.cur_map->cmap[y][x];
      }
    }
  }

  /* Sort it by distance from PC */
  qsort(c, count, sizeof (*c), compare_trainer_distance);

  /* Display it */
  io_list_trainers_display(c, count);
  free(c);

  /* And redraw the map */
  io_display();
}

void io_pokemart()
{
  mvprintw(0, 0, "Welcome to the Pokemart.  Could I interest you in some Pokeballs?");
  mvprintw(1,0, "actually everything is free and you're restocked");
  world.pc.pots = 10;//
  world.pc.vives = 5;
  world.pc.pballs = 15;
  refresh();
  getch();
}

void io_pokemon_center()
{
  long unsigned int i;
  int y;
  int x;
  clear();
  mvprintw(0, 0, "Welcome to the Pokemon Center");
  mvprintw(1,0, "your pokemon are healed.");
  for(i = 0; i < world.pc.pkmn.size() && i < 6; i++){
    world.pc.pkmn[i].currenthp = world.pc.pkmn[i].get_hp();
    //mvprintw(2+i,0, "%d. %s", i+1, world.pc.pkmn[i].get_species());
  }
  //refresh();
  getch();
  mvprintw(2,0, "Would you like to access PC? (y)es or (n)o.");
  char choice;
  char swapout;
  
  char swapin;
  choice = getch();
  //bool check;
  //check = false;
  while(1){ //swap()
    switch(choice){
    case 'y':
      if(world.pc.pkmn.size()<6){
	mvprintw(2,0, "You have not caught enough pokemon yet");
	getch();
	return;
      }
      mvprintw(2,0, "Choose pokemon to swap for a pc pokemon(1-6)");
      mvprintw(3,0, "Your current 6:");
      mvprintw(3,20,"Pokemon you want to swap-in:(1-%d)", world.pc.pkmn.size()-6);
      for(i = 0; i<world.pc.pkmn.size(); i++){
	if(i <6){
	  mvprintw(i+5,0, "%d. %s   ", i+1, world.pc.pkmn[i].get_species());
	}
	else{
	  mvprintw(i-1, 20, "%d. %s   ", i+1, world.pc.pkmn[i].get_species());
	}
      }
      swapout = getch();
      mvprintw(4,0, "swapping out... %c", swapout);
      swapin = getch();
      mvprintw(4,20,"Swapping in: %c:                                     ", swapin);
      x = swapout - 48; y = swapin - 48;
      if( (x<=(int)world.pc.pkmn.size()) && (y<=(int)world.pc.pkmn.size()) ){
	swap(world.pc.pkmn[x-1],world.pc.pkmn[y-1]);
      }
      if( (x>(int)world.pc.pkmn.size()) || (y>(int)world.pc.pkmn.size()) ){
	mvprintw(15,0, "bad vals");
      }
      //mvprintw(14, 0, "%d %d", x, y);
      mvprintw(14,0, "%s and %s                    ", world.pc.pkmn[x-1].get_species(), world.pc.pkmn[y-1].get_species());
      getch();
      mvprintw(4,20,"Would you like to keep accessing PC? (y)es or (n)o");
      choice = getch();
      break;
    case 'n':
      return;
    default:
      choice = getch();
    }//end switch 
  }//end while
  return;
}

bool trainer_poke_check()
{
  bool checkalive;
  checkalive = false;
  long unsigned int i;
  for(i =0; i < world.pc.pkmn.size() && i < 6; i++){
    if(world.pc.pkmn[i].currenthp >0){
      checkalive = true;
    }
  }
  return checkalive;
}
bool npc_check(character *n){
  long unsigned int i;
  bool checkalive;
  checkalive = false;
  for(i = 0; i <n->pkmn.size(); i++){
    if(n->pkmn[i].currenthp >0){
      checkalive = true;
    }
  }
  return checkalive;
}



void io_trainerbattle(character *n){ //abc
  clear();
  int dam;
  mvprintw(0,0, "trainer sends %s", n->pkmn[0].get_species());
  //mvprintw(1,0, "hp: %d of %d", n->pkmn[0].currenthp, n->pkmn[0].get_hp());
  mvprintw(10,40, "pc sends %s", world.pc.pkmn[0].get_species());
  //mvprintw(11,30, "hp: %d of %d; select action",
           //world.pc.pkmn[0].currenthp, world.pc.pkmn[0].get_hp());
  //mvprintw(12,30, "1. attack    2. pokemon");
  //mvprintw(13,30, "3. bag");
  //refresh();
  char choice; // = getch();
  char battleinput;
  //bool inputcheck = false;
  bool battleover = false;
  bool pcfirst;
  pcfirst = false;
  while(!battleover){
    clear();
    refresh();
    mvprintw(10,40, "pc sends %s", world.pc.pkmn[0].get_species());
    mvprintw(0,0, "trainer sends %s", n->pkmn[0].get_species());
    mvprintw(1,0, "hp: %d of %d       ", n->pkmn[0].currenthp, n->pkmn[0].get_hp());
    mvprintw(11,40, "hp: %d of %d; select action    ",
	     world.pc.pkmn[0].currenthp, world.pc.pkmn[0].get_hp());
    mvprintw(12,40, "1. fight    2. bag");
    mvprintw(13,40, "3. run      4. pokemon");
    choice = getch();
    switch(choice){
    case '1':
      mvprintw(11,0, "select move");
      mvprintw(12,0, "1. %s    2. %s", world.pc.pkmn[0].get_move(0), world.pc.pkmn[0].get_move(1));
      mvprintw(13,0, "3. %s    4. %s",world.pc.pkmn[0].get_move(2), world.pc.pkmn[0].get_move(3));
      battleinput = getch();
      //fightnpc(n, battleinput);
      switch(battleinput){
      case '1':
	//bool pcfirst = false;
	if(world.pc.pkmn[0].get_speed() >= n->pkmn[0].get_speed()){
	  pcfirst = true;
	}
	if(pcfirst){
	  if(world.pc.pkmn[0].get_acc(0) > rand()%100){ // move num 1;
	    dam = world.pc.pkmn[0].get_dam(0,rand()%16 + 85);
	    n->pkmn[0].currenthp = n->pkmn[0].currenthp - dam;
	    mvprintw(5,20,"%s used %s - does %d damage", world.pc.pkmn[0].get_species(),
		     world.pc.pkmn[0].get_move(0),dam);
	    getch();
	  }
	  else{
	    mvprintw(5,20, "...You missed.");
	    getch();
	  } 
	}
	if(n->pkmn[0].currenthp>0){
	  int npcmove;
	  
	  npcmove=rand()%1;
	  dam = n->pkmn[0].get_dam(npcmove, rand()%16+85);
	  world.pc.pkmn[0].currenthp = world.pc.pkmn[0].currenthp - dam;
	  mvprintw(6,20, "trainer's %s used %s - does %d damage", n->pkmn[0].get_species(),
		   n->pkmn[0].get_move(npcmove),dam);
	  getch();
	}
	if(n->pkmn[0].currenthp<=0){
	  npc_next_poke(n);
	}
	if( (!pcfirst) && (world.pc.pkmn[0].currenthp>0) ){
	  if(world.pc.pkmn[0].get_acc(0) > rand()%100){ // move num 1;
	    dam = world.pc.pkmn[0].get_dam(0,rand()%16 + 85);
	    n->pkmn[0].currenthp = n->pkmn[0].currenthp - dam;
	    mvprintw(5,20,"%s used %s - does %d damage", world.pc.pkmn[0].get_species(),
		     world.pc.pkmn[0].get_move(0), dam);
	    getch();
	  }
	  else{
	    mvprintw(5,20, "...You missed.");
	    getch();
	  }
	}
	if(world.pc.pkmn[0].currenthp<=0){
	  mvprintw(7,20, "%s fainted", world.pc.pkmn[0].get_species());
	  getch();
	  if(world.pc.pkmn.size()>1){ 
	    switch_poke();
	  }
	  else{
	    mvprintw(8,0, "all pokemon fainted - gameover");
	    getch();
	    world.quit = 1;
	    battleover = true;
	  }
	}
	break;
      case '2':
	//bool pcfirst = false;
	if(world.pc.pkmn[0].get_speed() >= n->pkmn[0].get_speed()){
	  pcfirst = true;
	}
	if(pcfirst){
	  if(world.pc.pkmn[0].get_acc(1) > rand()%100){ // move num 1;
	    dam = world.pc.pkmn[0].get_dam(1,rand()%16 + 85);
	    n->pkmn[0].currenthp = n->pkmn[0].currenthp - dam;
	    mvprintw(5,20,"%s used %s - does %d damage", world.pc.pkmn[0].get_species(),
		     world.pc.pkmn[0].get_move(1), dam);
	    getch();
	  }
	  else{
	    mvprintw(5,20, "...You missed.");
	    getch();
	  } 
	}
	if(n->pkmn[0].currenthp>0){
	  int npcmove;
	  
	  npcmove=rand()%1;
	  dam = n->pkmn[0].get_dam(npcmove, rand()%16+85);
	  world.pc.pkmn[0].currenthp = world.pc.pkmn[0].currenthp - dam;
	  mvprintw(6,20, "trainer's %s used %s - does %d damage", n->pkmn[0].get_species(),
		   n->pkmn[0].get_move(npcmove),dam);
	  getch();
	}
	if(n->pkmn[0].currenthp<=0){
	  npc_next_poke(n);
	}
	if( (!pcfirst) && (world.pc.pkmn[0].currenthp>0) ){
	  if(world.pc.pkmn[0].get_acc(1) > rand()%100){ // move num 1;
	    dam = world.pc.pkmn[0].get_dam(1,rand()%16 + 85);
	    n->pkmn[0].currenthp = n->pkmn[0].currenthp - dam;
	    mvprintw(5,20,"%s used %s - does %d damage", world.pc.pkmn[0].get_species(),
		     world.pc.pkmn[0].get_move(1), dam);
	    getch();
	  }
	  else{
	    mvprintw(5,20, "...You missed.");
	    getch();
	  }
	}
	if(world.pc.pkmn[0].currenthp<=0){
	  mvprintw(7,20, "%s fainted", world.pc.pkmn[0].get_species());
	  getch();
	  if(world.pc.pkmn.size()>1){ 
	    switch_poke();
	  }
	  else{
	    mvprintw(8,0, "all pokemon fainted - gameover");
	    getch();
	    world.quit = 1;
	    battleover = true;
	  }
	}
	break;
      case '3':
	//bool pcfirst = false;
	if(world.pc.pkmn[0].get_speed() >= n->pkmn[0].get_speed()){
	  pcfirst = true;
	}
	if(pcfirst){
	  if(world.pc.pkmn[0].get_acc(2) > rand()%100){ // move num 1;
	    dam = world.pc.pkmn[0].get_dam(2,rand()%16 + 85);
	    n->pkmn[0].currenthp = n->pkmn[0].currenthp - dam;
	    mvprintw(5,20,"%s used %s - does %d damage", world.pc.pkmn[0].get_species(),
		     world.pc.pkmn[0].get_move(2),dam);
	    getch();
	  }
	  else{
	    mvprintw(5,20, "...You missed.");
	    getch();
	  } 
	}
	if(n->pkmn[0].currenthp>0){
	  int npcmove;
	  
	  npcmove=rand()%1;
	  dam = n->pkmn[0].get_dam(npcmove, rand()%16+85);
	  world.pc.pkmn[0].currenthp = world.pc.pkmn[0].currenthp - dam;
	  mvprintw(6,20, "trainer's %s used %s - does %d damage", n->pkmn[0].get_species(),
		   n->pkmn[0].get_move(npcmove), dam);
	  getch();
	}
	if(n->pkmn[0].currenthp<=0){
	  npc_next_poke(n);
	}
	if( (!pcfirst) && (world.pc.pkmn[0].currenthp>0) ){
	  if(world.pc.pkmn[0].get_acc(2) > rand()%100){ // move num 1;
	    dam = world.pc.pkmn[0].get_dam(2,rand()%16 + 85);
	    n->pkmn[0].currenthp = n->pkmn[0].currenthp - dam;
	    mvprintw(5,20,"%s used %s - does %d damage", world.pc.pkmn[0].get_species(),
		     world.pc.pkmn[0].get_move(2), dam);
	    getch();
	  }
	  else{
	    mvprintw(5,20, "...You missed.");
	    getch();
	  }
	}
	if(world.pc.pkmn[0].currenthp<=0){
	  mvprintw(7,20, "%s fainted", world.pc.pkmn[0].get_species());
	  getch();
	  if(world.pc.pkmn.size()>1){ 
	    switch_poke();
	  }
	  else{
	    mvprintw(8,0, "all pokemon fainted - gameover");
	    getch();
	    world.quit = 1;
	    battleover = true;
	  }
	}
	break;
	case '4':
	  //bool pcfirst = false;
	if(world.pc.pkmn[0].get_speed() >= n->pkmn[0].get_speed()){
	  pcfirst = true;
	}
	if(pcfirst){
	  if(world.pc.pkmn[0].get_acc(3) > rand()%100){ // move num 1;
	    dam = world.pc.pkmn[0].get_dam(3,rand()%16 + 85);
	    n->pkmn[0].currenthp = n->pkmn[0].currenthp - dam;
	    mvprintw(5,20,"%s used %s - does %d damage", world.pc.pkmn[0].get_species(),
		     world.pc.pkmn[0].get_move(3), dam);
	    getch();
	  }
	  else{
	    mvprintw(5,20, "...You missed.");
	    getch();
	  } 
	}
	if(n->pkmn[0].currenthp>0){
	  int npcmove;
	  
	  npcmove=rand()%1;
	  dam = n->pkmn[0].get_dam(npcmove, rand()%16+85);
	  world.pc.pkmn[0].currenthp = world.pc.pkmn[0].currenthp - dam;
	  mvprintw(6,20, "trainer's %s used %s - does %d damage", n->pkmn[0].get_species(),
		   n->pkmn[0].get_move(npcmove),dam);
	  getch();
	}
	if(n->pkmn[0].currenthp<=0){
	  npc_next_poke(n);
	}
	if( (!pcfirst) && (world.pc.pkmn[0].currenthp>0) ){
	  if(world.pc.pkmn[0].get_acc(3) > rand()%100){ // move num 1;
	    dam = world.pc.pkmn[0].get_dam(3,rand()%16 + 85);
	    n->pkmn[0].currenthp = n->pkmn[0].currenthp - dam;
	    mvprintw(5,20,"%s used %s - does %d damage", world.pc.pkmn[0].get_species(),
		     world.pc.pkmn[0].get_move(3), dam);
	    getch();
	  }
	  else{
	    mvprintw(5,20, "...You missed.");
	    getch();
	  }
	}
	if(world.pc.pkmn[0].currenthp<=0){
	  mvprintw(7,20, "%s fainted", world.pc.pkmn[0].get_species());
	  getch();
	  if(world.pc.pkmn.size()>1){ 
	    switch_poke();
	  }
	  else{
	    mvprintw(8,0, "all pokemon fainted - gameover");
	    world.quit = 1;
	    getch();
	    battleover = true;
	  }
	}
	break;
      }//end switch after switch if npc poke alive attk ur poke

     
      //gotta check pc life
      if(n->pkmn[0].currenthp <= 0){
	mvprintw(6,0, "%s fainted", n->pkmn[0].get_species());
	getch();
	//battleover = true;
	if(npc_check(n) ==false){
	  battleover = true;
	  mvprintw(8,0, "trainer out of pkmn");
	}
	else{
	  // switch trainer's poke
	  npc_next_poke(n);
	}
      }
      //battleover = !npc_check(n);
      
    ////battle stuff
      break;
      
    case '2':
      io_bag_menu(0);
      //switch_poke();//uses a turn so enemy get to hit u.
      break;
    case '3':
      break;
    case '4':
      if(world.pc.pkmn.size() > 1){
	switch_poke();
	int npcmove;
	  
	npcmove=rand()%1;
	dam = n->pkmn[0].get_dam(npcmove, rand()%16+85);
	world.pc.pkmn[0].currenthp = world.pc.pkmn[0].currenthp - dam;
	mvprintw(6,20, "trainer's %s used %s - does %d damage", n->pkmn[0].get_species(),
		 n->pkmn[0].get_move(npcmove),dam);
	getch();

	if(world.pc.pkmn[0].currenthp<=0){
	  mvprintw(7,20, "%s fainted", world.pc.pkmn[0].get_species());
	  getch();
	  if(world.pc.pkmn.size()>1){ 
	    switch_poke();
	  }
	  else{
	    mvprintw(8,0, "all pokemon fainted - gameover");
	    getch();
	    world.quit = 1;
	    battleover = true;
	    //delete p;
	  }
	}
      }
      else{
	mvprintw(6, 20, "no other pokemon");
	getch();
      }
      break;
    case '5':
      battleover = true;
      break;
    }//end switch
    refresh();
  }//end while
  
}

void io_battle(character *aggressor, character *defender)
{
  npc *n = (npc *) ((aggressor == &world.pc) ? defender : aggressor);

  io_display();
  mvprintw(0, 0, "Aww, how'd you get so strong?  You and your pokemon must share a special bond!");
  refresh();
  getch();
  io_trainerbattle(n);
  n->defeated = 1;
  if (n->ctype == char_hiker || n->ctype == char_rival) {
    n->mtype = move_wander;
  }
}

uint32_t move_pc_dir(uint32_t input, pair_t dest)
{
  dest[dim_y] = world.pc.pos[dim_y];
  dest[dim_x] = world.pc.pos[dim_x];

  switch (input) {
  case 1:
  case 2:
  case 3:
    dest[dim_y]++;
    break;
  case 4:
  case 5:
  case 6:
    break;
  case 7:
  case 8:
  case 9:
    dest[dim_y]--;
    break;
  }
  switch (input) {
  case 1:
  case 4:
  case 7:
    dest[dim_x]--;
    break;
  case 2:
  case 5:
  case 8:
    break;
  case 3:
  case 6:
  case 9:
    dest[dim_x]++;
    break;
  case '>':
    if (world.cur_map->map[world.pc.pos[dim_y]][world.pc.pos[dim_x]] ==
        ter_mart) {
      io_pokemart();
    }
    if (world.cur_map->map[world.pc.pos[dim_y]][world.pc.pos[dim_x]] ==
        ter_center) {
      io_pokemon_center();
    }
    break;
  }

  if (world.cur_map->cmap[dest[dim_y]][dest[dim_x]]) {
    if (dynamic_cast<npc *>(world.cur_map->cmap[dest[dim_y]][dest[dim_x]]) &&
        ((npc *) world.cur_map->cmap[dest[dim_y]][dest[dim_x]])->defeated) {
      // Some kind of greeting here would be nice
      return 1;
    } else if (dynamic_cast<npc *>
               (world.cur_map->cmap[dest[dim_y]][dest[dim_x]])) {
      io_battle(&world.pc, world.cur_map->cmap[dest[dim_y]][dest[dim_x]]);
      // Not actually moving, so set dest back to PC position
      dest[dim_x] = world.pc.pos[dim_x];
      dest[dim_y] = world.pc.pos[dim_y];
    }
  }
  
  if (move_cost[char_pc][world.cur_map->map[dest[dim_y]][dest[dim_x]]] ==
      INT_MAX) {
    return 1;
  }

  return 0;
}

void io_teleport_world(pair_t dest)
{
  /* mvscanw documentation is unclear about return values.  I believe *
   * that the return value works the same way as scanf, but instead   *
   * of counting on that, we'll initialize x and y to out of bounds   *
   * values and accept their updates only if in range.                */
  int x = INT_MAX, y = INT_MAX;
  
  world.cur_map->cmap[world.pc.pos[dim_y]][world.pc.pos[dim_x]] = NULL;

  echo();
  curs_set(1);
  do {
    mvprintw(0, 0, "Enter x [-200, 200]:           ");
    refresh();
    mvscanw(0, 21, "%d", &x);
  } while (x < -200 || x > 200);
  do {
    mvprintw(0, 0, "Enter y [-200, 200]:          ");
    refresh();
    mvscanw(0, 21, "%d", &y);
  } while (y < -200 || y > 200);

  refresh();
  noecho();
  curs_set(0);

  x += 200;
  y += 200;

  world.cur_idx[dim_x] = x;
  world.cur_idx[dim_y] = y;

  new_map(1);
  io_teleport_pc(dest);
}

void io_handle_input(pair_t dest)
{
  uint32_t turn_not_consumed;
  int key;

  do {
    switch (key = getch()) {
    case '7':
    case 'y':
    case KEY_HOME:
      turn_not_consumed = move_pc_dir(7, dest);
      break;
    case '8':
    case 'k':
    case KEY_UP:
      turn_not_consumed = move_pc_dir(8, dest);
      break;
    case '9':
    case 'u':
    case KEY_PPAGE:
      turn_not_consumed = move_pc_dir(9, dest);
      break;
    case '6':
    case 'l':
    case KEY_RIGHT:
      turn_not_consumed = move_pc_dir(6, dest);
      break;
    case '3':
    case 'n':
    case KEY_NPAGE:
      turn_not_consumed = move_pc_dir(3, dest);
      break;
    case '2':
    case 'j':
    case KEY_DOWN:
      turn_not_consumed = move_pc_dir(2, dest);
      break;
    case '1':
    case 'b':
    case KEY_END:
      turn_not_consumed = move_pc_dir(1, dest);
      break;
    case '4':
    case 'h':
    case KEY_LEFT:
      turn_not_consumed = move_pc_dir(4, dest);
      break;
    case '5':
    case ' ':
    case '.':
    case KEY_B2:
      dest[dim_y] = world.pc.pos[dim_y];
      dest[dim_x] = world.pc.pos[dim_x];
      turn_not_consumed = 0;
      break;
    case '>':
      turn_not_consumed = move_pc_dir('>', dest);
      break;
    case 'Q':
      dest[dim_y] = world.pc.pos[dim_y];
      dest[dim_x] = world.pc.pos[dim_x];
      world.quit = 1;
      turn_not_consumed = 0;
      break;
      break;
    case 't':
      io_list_trainers();
      turn_not_consumed = 1;
      break;
    case 'p':
      /* Teleport the PC to a random place in the map.               */
      io_teleport_pc(dest);
      turn_not_consumed = 0;
      break;
    case 'm':
      io_list_trainers();
      turn_not_consumed = 1;
      break;
    case 'f':
      /* Fly to any map in the world.                                */
      io_teleport_world(dest);
      turn_not_consumed = 0;
      break;
    case 'B':
      //int select;
      io_bag_menu(0);
      turn_not_consumed = 1;
      break;
    case 'q':
      /* Demonstrate use of the message queue.  You can use this for *
       * printf()-style debugging (though gdb is probably a better   *
       * option.  Not that it matters, but using this command will   *
       * waste a turn.  Set turn_not_consumed to 1 and you should be *
       * able to figure out why I did it that way.                   */
      io_queue_message("This is the first message.");
      io_queue_message("Since there are multiple messages, "
                       "you will see \"more\" prompts.");
      io_queue_message("You can use any key to advance through messages.");
      io_queue_message("Normal gameplay will not resume until the queue "
                       "is empty.");
      io_queue_message("Long lines will be truncated, not wrapped.");
      io_queue_message("io_queue_message() is variadic and handles "
                       "all printf() conversion specifiers.");
      io_queue_message("Did you see %s?", "what I did there");
      io_queue_message("When the last message is displayed, there will "
                       "be no \"more\" prompt.");
      io_queue_message("Have fun!  And happy printing!");
      io_queue_message("Oh!  And use 'Q' to quit!");

      dest[dim_y] = world.pc.pos[dim_y];
      dest[dim_x] = world.pc.pos[dim_x];
      turn_not_consumed = 0;
      break;
    default:
      /* Also not in the spec.  It's not always easy to figure out what *
       * key code corresponds with a given keystroke.  Print out any    *
       * unhandled key here.  Not only does it give a visual error      *
       * indicator, but it also gives an integer value that can be used *
       * for that key in this (or other) switch statements.  Printed in *
       * octal, with the leading zero, because ncurses.h lists codes in *
       * octal, thus allowing us to do reverse lookups.  If a key has a *
       * name defined in the header, you can use the name here, else    *
       * you can directly use the octal value.                          */
      mvprintw(0, 0, "Unbound key: %#o ", key);
      turn_not_consumed = 1;
    }
    refresh();
  } while (turn_not_consumed);
}

void io_encounter_pokemon()
{
  pokemon *p;
  int md = (abs(world.cur_idx[dim_x] - (WORLD_SIZE / 2)) +
            abs(world.cur_idx[dim_y] - (WORLD_SIZE / 2)));
  int minl, maxl;

  if (md <= 200) {
    minl = 1;
    maxl = md / 2;
  } else {
    minl = (md - 200) / 2;
    maxl = 100;
  }
  if (minl < 1) {
    minl = 1;
  }
  if (minl > 100) {
    minl = 100;
  }
  if (maxl < 1) {
    maxl = 1;
  }
  if (maxl > 100) {
    maxl = 100;
  }
  int attempt;
  attempt = 1;
  char choice;
  char battleinput;
  //bool caught;
  bool pcfirst;
  bool battleover;
  int dam;
  pcfirst = false;
  p = new pokemon(rand() % (maxl - minl + 1) + minl);
  p->currenthp = p->get_hp();
  battleover = false;
  while(!battleover){
    clear();
    mvprintw(0,0, "%s appeared", p->get_species());//abc
    mvprintw(1,0, "level %d", p->get_lvl());
    mvprintw(2,0, "hp: %d of %d", p->currenthp, p->get_hp());
    mvprintw(10,40, "pc sends %s", world.pc.pkmn[0].get_species());
    mvprintw(11,40, "hp: %d of %d; select action    ",
	     world.pc.pkmn[0].currenthp, world.pc.pkmn[0].get_hp());
    mvprintw(12,40, "1. fight    2. bag");
    mvprintw(13,40, "3. run      4. pokemon");
    getch();
    choice = getch();
    switch(choice){
    case '1':
      mvprintw(11,0, "select move");
      mvprintw(12,0, "1. %s    2. %s", world.pc.pkmn[0].get_move(0), world.pc.pkmn[0].get_move(1));
      mvprintw(13,0, "3. %s    4. %s",world.pc.pkmn[0].get_move(2), world.pc.pkmn[0].get_move(3));
      battleinput = getch();
      
      switch(battleinput){
      case '1':
        
	if(world.pc.pkmn[0].get_speed() >= p->get_speed()){
	  pcfirst = true;
	  //delete p;
	}
	if(pcfirst){
	  if(world.pc.pkmn[0].get_acc(0) > rand()%100){ // move num 1;
	    dam = world.pc.pkmn[0].get_dam(0,rand()%16 + 85);
	    p->currenthp = p->currenthp - dam;
	    mvprintw(5,20,"%s used %s - does %d damage", world.pc.pkmn[0].get_species(),
		     world.pc.pkmn[0].get_move(0),dam);
	    getch();
	  }
	  else{
	    mvprintw(5,20, "...You missed.");
	    getch();
	  } 
	}
	if(p->currenthp>0){
	  int npcmove;
	  
	  npcmove=0;
	  dam = p->get_dam(npcmove, rand()%16+85);
	  world.pc.pkmn[0].currenthp = world.pc.pkmn[0].currenthp - dam;
	  mvprintw(6,20, "%s used %s - does %d damage", p->get_species(),
		   p->get_move(npcmove),dam);
	  getch();
	}
	if(p->currenthp<=0){
	  mvprintw(3,20, "%s fainted", p->get_species());
	  getch();
	  battleover=true;
	  delete p;
	}
	if( (!pcfirst) && (world.pc.pkmn[0].currenthp>0) ){
	  if(world.pc.pkmn[0].get_acc(0) > rand()%100){ // move num 1;
	    dam = world.pc.pkmn[0].get_dam(0,rand()%16 + 85);
	    p->currenthp = p->currenthp - dam;
	    mvprintw(5,20,"%s used %s - does %d damage", world.pc.pkmn[0].get_species(),
		     world.pc.pkmn[0].get_move(0), dam);
	    getch();
	  }
	  else{
	    mvprintw(5,20, "...You missed.");
	    getch();
	  }
	}
	if(world.pc.pkmn[0].currenthp<=0){
	  mvprintw(7,20, "%s fainted", world.pc.pkmn[0].get_species());
	  getch();
	  if(world.pc.pkmn.size()>1){ 
	    switch_poke();
	  }
	  else{
	    mvprintw(8,0, "all pokemon fainted - gameover");
	    getch();
	    world.quit = 1;
	    battleover = true;
	    delete p;
	  }
	}
	break;
      case '2':
	//bool pcfirst = false;
	if(world.pc.pkmn[0].get_speed() >= p->get_speed()){
	  pcfirst = true;
	}
	if(pcfirst){
	  if(world.pc.pkmn[0].get_acc(1) > rand()%100){ // move num 1;
	    dam = world.pc.pkmn[0].get_dam(1,rand()%16 + 85);
	    p->currenthp = p->currenthp - dam;
	    mvprintw(5,20,"%s used %s - does %d damage", world.pc.pkmn[0].get_species(),
		     world.pc.pkmn[0].get_move(1), dam);
	    getch();
	  }
	  else{
	    mvprintw(5,20, "...You missed.");
	    getch();
	  } 
	}
	if(p->currenthp>0){
	  int npcmove;
	  
	  npcmove=rand()%1;
	  dam = p->get_dam(npcmove, rand()%16+85);
	  world.pc.pkmn[0].currenthp = world.pc.pkmn[0].currenthp - dam;
	  mvprintw(6,20, "%s used %s - does %d damage", p->get_species(),
		   p->get_move(npcmove),dam);
	  getch();
	}
	if(p->currenthp<=0){
	  mvprintw(3,20, "%s fainted", p->get_species());
	  getch();
	  battleover = true;
	  delete p;
	}
	if( (!pcfirst) && (world.pc.pkmn[0].currenthp>0) ){
	  if(world.pc.pkmn[0].get_acc(1) > rand()%100){ // move num 1;
	    dam = world.pc.pkmn[0].get_dam(1,rand()%16 + 85);
	    p->currenthp = p->currenthp - dam;
	    mvprintw(5,20,"%s used %s - does %d damage", world.pc.pkmn[0].get_species(),
		     world.pc.pkmn[0].get_move(1), dam);
	    getch();
	  }
	  else{
	    mvprintw(5,20, "...You missed.");
	    getch();
	  }
	}
	if(world.pc.pkmn[0].currenthp<=0){
	  mvprintw(7,20, "%s fainted", world.pc.pkmn[0].get_species());
	  getch();
	  if(world.pc.pkmn.size()>1){ 
	    switch_poke();
	  }
	  else{
	    mvprintw(8,0, "all pokemon fainted - gameover");
	    getch();
	    world.quit = 1;
	    battleover = true;
	    delete p;
	  }
	}
	break;
      case '3':
	//bool pcfirst = false;
	if(world.pc.pkmn[0].get_speed() >= p->get_speed()){
	  mvprintw(3,20, "%s fainted", p->get_species());
	  getch();
	  pcfirst = true;
	}
	if(pcfirst){
	  if(world.pc.pkmn[0].get_acc(2) > rand()%100){ // move num 1;
	    dam = world.pc.pkmn[0].get_dam(2,rand()%16 + 85);
	    p->currenthp = p->currenthp - dam;
	    mvprintw(5,20,"%s used %s - does %d damage", world.pc.pkmn[0].get_species(),
		     world.pc.pkmn[0].get_move(2),dam);
	    getch();
	  }
	  else{
	    mvprintw(5,20, "...You missed.");
	    getch();
	  } 
	}
	if(p->currenthp>0){
	  int npcmove;
	  
	  npcmove=rand()%1;
	  dam = p->get_dam(npcmove, rand()%16+85);
	  world.pc.pkmn[0].currenthp = world.pc.pkmn[0].currenthp - dam;
	  mvprintw(6,20, "trainer's %s used %s - does %d damage", p->get_species(),
		   p->get_move(npcmove), dam);
	  getch();
	}
	if(p->currenthp<=0){
	  mvprintw(3,20, "%s fainted", p->get_species());
	  getch();
	  battleover = true;
	  delete p;
	}
	if( (!pcfirst) && (world.pc.pkmn[0].currenthp>0) ){
	  if(world.pc.pkmn[0].get_acc(2) > rand()%100){ // move num 1;
	    dam = world.pc.pkmn[0].get_dam(2,rand()%16 + 85);
	    p->currenthp = p->currenthp - dam;
	    mvprintw(5,20,"%s used %s - does %d damage", world.pc.pkmn[0].get_species(),
		     world.pc.pkmn[0].get_move(2), dam);
	    getch();
	  }
	  else{
	    mvprintw(5,20, "...You missed.");
	    getch();
	  }
	}
	if(world.pc.pkmn[0].currenthp<=0){
	  mvprintw(7,20, "%s fainted", world.pc.pkmn[0].get_species());
	  getch();
	  if(world.pc.pkmn.size()>1){ 
	    switch_poke();
	  }
	  else{
	    mvprintw(8,0, "all pokemon fainted - gameover");
	    getch();
	    world.quit = 1;
	    battleover = true;
	    delete p;
	  }
	}
	break;
	case '4':
	  //bool pcfirst = false;
	if(world.pc.pkmn[0].get_speed() >= p->get_speed()){
	  pcfirst = true;
	}
	if(pcfirst){
	  if(world.pc.pkmn[0].get_acc(3) > rand()%100){ // move num 1;
	    dam = world.pc.pkmn[0].get_dam(3,rand()%16 + 85);
	    p->currenthp = p->currenthp - dam;
	    mvprintw(5,20,"%s used %s - does %d damage", world.pc.pkmn[0].get_species(),
		     world.pc.pkmn[0].get_move(3), dam);
	    getch();
	  }
	  else{
	    mvprintw(5,20, "...You missed.");
	    getch();
	  } 
	}
	if(p->currenthp>0){
	  int npcmove;
	  
	  npcmove=rand()%1;
	  dam = p->get_dam(npcmove, rand()%16+85);
	  world.pc.pkmn[0].currenthp = world.pc.pkmn[0].currenthp - dam;
	  mvprintw(6,20, "trainer's %s used %s - does %d damage", p->get_species(),
		   p->get_move(npcmove),dam);
	  getch();
	}
	if(p->currenthp<=0){
	  mvprintw(3,20, "%s fainted", p->get_species());
	  getch();
	  battleover = true;
	  delete p;
	}
	if( (!pcfirst) && (world.pc.pkmn[0].currenthp>0) ){
	  if(world.pc.pkmn[0].get_acc(3) > rand()%100){ // move num 1;
	    dam = world.pc.pkmn[0].get_dam(3,rand()%16 + 85);
	    p->currenthp = p->currenthp - dam;
	    mvprintw(5,20,"%s used %s - does %d damage", world.pc.pkmn[0].get_species(),
		     world.pc.pkmn[0].get_move(3), dam);
	    getch();
	  }
	  else{
	    mvprintw(5,20, "...You missed.");
	    getch();
	  }
	}
	if(world.pc.pkmn[0].currenthp<=0){
	  mvprintw(7,20, "%s fainted", world.pc.pkmn[0].get_species());
	  getch();
	  if(world.pc.pkmn.size()>1){ 
	    switch_poke();
	  }
	  else{
	    mvprintw(8,0, "all pokemon fainted - gameover");
	    world.quit = 1;
	    getch();
	    battleover = true;
	    delete p;
	  }
	}
	break;
      }//end switch after switch if npc poke alive attk ur poke

     
      //gotta check pc life
      // if(n->pkmn[0].currenthp <= 0){
      // 	mvprintw(6,0, "%s fainted", n->pkmn[0].get_species());
      // 	getch();
      // 	//battleover = true;
      // 	if(npc_check(n) ==false){
      // 	  battleover = true;
      // 	  mvprintw(8,0, "trainer out of pkmn");
      // 	}
      // 	else{
      // 	  // switch trainer's poke
      // 	  npc_next_poke(n);
      // 	}
      // }
      //battleover = !npc_check(n);
      
    ////battle stuff
      break;
      
    case '2':
      if(io_bag_menu(1)==1){
	if(use_ball(p) ==1){
	  battleover = true;
	}
      }
	// if(use_ball(p)==1){
	//   battleover = true;
	// }
      
      //switch_poke();//uses a turn so enemy get to hit u.
      break;
    case '3':

      refresh();
      mvprintw(4,20, "trying to run...");
      getch();
      if( (rand()%256) < ( ((world.pc.pkmn[0].get_speed() *32) / ( (p->get_speed()/4)%256 ) )
			   +(30 * attempt) ) ){
	battleover = true;
	delete p;
	mvprintw(4,20, "got away safely..."); // get away success
	getch();
      }
      else{
      }
      
      break;
    case '4':
      if(world.pc.pkmn.size() > 1){
	switch_poke();
	int npcmove;
	  
	npcmove=rand()%1;
	dam = p->get_dam(npcmove, rand()%16+85);
	world.pc.pkmn[0].currenthp = world.pc.pkmn[0].currenthp - dam;
	mvprintw(6,20, "trainer's %s used %s - does %d damage", p->get_species(),
		 p->get_move(npcmove),dam);
	getch();

	if(world.pc.pkmn[0].currenthp<=0){
	  mvprintw(7,20, "%s fainted", world.pc.pkmn[0].get_species());
	  getch();
	  if(world.pc.pkmn.size()>1){ 
	    switch_poke();
	  }
	  else{
	    mvprintw(8,0, "all pokemon fainted - gameover");
	    getch();
	    world.quit = 1;
	    battleover = true;
	    delete p;
	  }
	}
      }
      else{
	mvprintw(6, 20, "no other pokemon");
	getch();
      }
      break;
    case '5':
      battleover = true;
      delete p;
      break;
    }//end switch
    refresh();
  }//end while
  
  
  
  
  
  // io_queue_message("%s%s%s: HP:%d ATK:%d DEF:%d SPATK:%d SPDEF:%d SPEED:%d %s",
  //                  p->is_shiny() ? "*" : "", p->get_species(),
  //                  p->is_shiny() ? "*" : "", p->get_hp(), p->get_atk(),
  //                  p->get_def(), p->get_spatk(), p->get_spdef(),
  //                  p->get_speed(), p->get_gender_string());
  // io_queue_message("%s's moves: %s %s", p->get_species(),
  //                  p->get_move(0), p->get_move(1));

  // Later on, don't delete if captured
  //delete p;
}
