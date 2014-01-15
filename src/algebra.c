#include "pebble.h"
#include "algebra.h"
	
#define NUM_ALGEBRA_MENU_ITEMS 3

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem algebra_menu_items[NUM_ALGEBRA_MENU_ITEMS];

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {
  int num_a_items = 0;

  algebra_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Slope Formula",
	.subtitle = "M = (Y2-Y1)/(X2-X1)",
  };
  algebra_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Mid-Point Formula",
	.subtitle = "(X1+X2)/2,(Y1+Y2)/2",
  };
  algebra_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Quadratic Formula",
	.subtitle = "(-b ±(b²-4ac)^½)/2a",
  };

  menu_sections.num_items = NUM_ALGEBRA_MENU_ITEMS;
  menu_sections.items = algebra_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_algebra_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}