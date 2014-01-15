#include "pebble.h"
#include "trigonometry.h"

	
#define NUM_TRIG_MENU_ITEMS 11

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem trig_menu_items[NUM_TRIG_MENU_ITEMS];

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {

  int num_a_items = 0;

  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Pythagorean Identity 1",
	.subtitle = "sin²u+cos²u = 1",
  };

  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Pythagorean Identity 2",
	.subtitle = "1+tan²u= = sec²u",
  };
  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Pythagorean Identity 3",
	.subtitle = "1+cot²u = sec²u",
  };
  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Quotient Identity 1",
	.subtitle = "tan u = (sin u/cos u)",
  };
  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Quotient Identity 2",
	.subtitle = "cot u = (cos u/sin u)",
  };
  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Reciprocal Identity 1",
	.subtitle = "sin u = (1/csc u)",
  };
  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Reciprocal Identity 2",
	.subtitle = "cos u = (1/sec u)",
  };
  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Reciprocal Identity 3",
	.subtitle = "tan u = (1/cot u)",
  };
  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Reciprocal Identity 4",
	.subtitle = "csc u = (1/sin u)",
  };
  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Reciprocal Identity 5",
	.subtitle = "sec u = (1/cos u)",
  };
  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Reciprocal Identity 2",
	.subtitle = "cot u = (1/tan u)",
  };

  menu_sections.num_items = NUM_TRIG_MENU_ITEMS;
  menu_sections.items = trig_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_trig_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}