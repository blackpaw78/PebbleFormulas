#include "pebble.h"
#include "planets.h"

	
#define NUM_PLANETS_MENU_ITEMS 8

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem planets_menu_items[NUM_PLANETS_MENU_ITEMS];

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {

  int num_a_items = 0;

  planets_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Mercury #1",
	.subtitle = "Closest to sun, Hot!",
  };
  planets_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Venus #2",
	.subtitle = "Sister to Earth, Gas",
  };
  planets_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Earth",
	.subtitle = "Only planet with life",
  };
  planets_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Mars",
	.subtitle = "Has water, cold.",
  };
  planets_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Jupiter",
	.subtitle = "Largest, Gas Giant",
  };
  planets_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Saturn",
	.subtitle = "Large Rings, Gas",
  };
  planets_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Uranus",
	.subtitle = "Gas Giant, Cold",
  };
  planets_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Neptune",
	.subtitle = "Cold, Gas, Sideways",
  };

  menu_sections.num_items = NUM_PLANETS_MENU_ITEMS;
  menu_sections.items = planets_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_planets_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}