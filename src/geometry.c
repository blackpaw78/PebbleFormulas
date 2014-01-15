#include "pebble.h"
#include "second.h"
#include "algebra.h"
#include "geometry.h"
#include "trigonometry.h"
#include "calc.h"
#include "biology.h"
#include "physics.h"
	
#define NUM_SECOND_MENU_ITEMS 4

static Window *window;

// This is a simple menu layer
static SimpleMenuLayer *simple_menu_layer;

// A simple menu layer can have multiple sections
static SimpleMenuSection menu_sections;

// Each section is composed of a number of menu items
static SimpleMenuItem first_menu_items[NUM_SECOND_MENU_ITEMS];

// Deinitialize resources on window unload that were initialized on window load
static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {
  // Although we already defined NUM_FIRST_MENU_ITEMS, you can define
  // an int as such to easily change the order of menu items later
  int num_a_items = 0;

  // This is an example of how you'd set a simple menu item
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Sec First Item",
  };
  // The menu items appear in the order saved in the menu items array
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Sec Second Item",
  };
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Sec Third Item",
  };
	first_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Sec 4 Item",
  };

  // Bind the menu items to the corresponding menu sections
  menu_sections.num_items = NUM_SECOND_MENU_ITEMS;
  menu_sections.items = first_menu_items;

  // Now we prepare to initialize the simple menu layer
  // We need the bounds to specify the simple menu layer's viewport size
  // In this case, it'll be the same as the window's
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  // Initialize the simple menu layer
  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  // Add it to the window for display
  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}
//Static makes it only for this file.
void show_geometry_menu(){
   window = window_create();

  // Setup the window handlers
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}