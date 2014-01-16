#include "pebble.h"
#include "chemistry.h"
	
#define NUM_CHEMISTRY_MENU_ITEMS 3

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem chemistry_menu_items[NUM_CHEMISTRY_MENU_ITEMS];

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {

  int num_a_items = 0;

  chemistry_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Ideal Gas Law",
	.subtitle = "PV = nRT"
  };
  chemistry_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Universal Gas Constant",
	.subtitle = "0.08206 L·atm·mol−1·K−1"
  };
  chemistry_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Boyle's Law",
	.subtitle = "V1/V2=P2/P1"
  };
  menu_sections.num_items = NUM_CHEMISTRY_MENU_ITEMS;
  menu_sections.items = chemistry_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);
	
  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}
void show_chemistry_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}