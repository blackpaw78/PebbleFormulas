#include "pebble.h"
#include "ohms.h"
	
#define NUM_OHMS_MENU_ITEMS 12

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem ohms_menu_items[NUM_OHMS_MENU_ITEMS];

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {
  int num_a_items = 0;

  ohms_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Resistance 1",
	.subtitle = "R = V/I",
  };
  ohms_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Resistance 2",
	.subtitle = "R = P/I²",
  };
  ohms_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Resistance 3",
	.subtitle = "R = V²/P",
  };
  ohms_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Current 1",
	.subtitle = "I = V/R",
  };
  ohms_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Current 2",
	.subtitle = "(P/R)^1/2)",
  };
  ohms_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Current 3",
	.subtitle = "I = P/V",
  };
  ohms_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Voltage 1",
	.subtitle = "V = I x R",
  };
  ohms_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Voltage 2",
	.subtitle = "V = P/I",
  };
  ohms_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Voltage 3",
	  .subtitle = "V =(P x R)^1/2",
  };
  ohms_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Power 1",
	  .subtitle = "P = I²xR",
  };
  ohms_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Power 2",
	  .subtitle = "P = V x I",
  };
  ohms_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Power 3",
	  .subtitle = "P = V²/R",
  };
  menu_sections.num_items = NUM_OHMS_MENU_ITEMS;
  menu_sections.items = ohms_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_ohms_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}