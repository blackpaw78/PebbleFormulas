#include "pebble.h"
#include "electricity.h"
#include "ohms.h"
	
#define NUM_ELEC_MENU_ITEMS 1

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem elec_menu_items[NUM_ELEC_MENU_ITEMS];

static void ohms_select_callback(int index, void *ctx) {
  show_ohms_menu();
}

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {
  int num_a_items = 0;

  elec_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Ohm's Law",
	.callback = ohms_select_callback,
  };

  menu_sections.num_items = NUM_ELEC_MENU_ITEMS;
  menu_sections.items = elec_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_elec_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}