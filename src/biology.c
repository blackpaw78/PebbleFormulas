#include "pebble.h"
#include "biology.h"
	
#define NUM_BIO_MENU_ITEMS 3

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem bio_menu_items[NUM_BIO_MENU_ITEMS];

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {

  int num_a_items = 0;

  bio_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Growth Formula",
	.subtitle ="Pf = Pi*2^t/d",
  };
  bio_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Hardy Weinberg 1",
	.subtitle ="p + q = 1",
  };
  bio_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Hardy Weinberg 2",
	.subtitle ="p2+2pq+q2=1",
  };



  menu_sections.num_items = NUM_BIO_MENU_ITEMS;
  menu_sections.items = bio_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_bio_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}