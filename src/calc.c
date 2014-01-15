#include "pebble.h"
#include "calc.h"

	
#define NUM_CALC_MENU_ITEMS 7

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem calc_menu_items[NUM_CALC_MENU_ITEMS];

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {

  int num_a_items = 0;

  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Product Rule",
	.subtitle = "uv' + vu'"
  };
  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Quotient Rule",
	.subtitle = "(vu' - uv')/v²"
  };  
  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Chain Rule",
	.subtitle = "f(g(x)) = f'(g(x))*g'(x)"
  };
  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Derivitive ln(x)",
	.subtitle = "f'(ln x)= (1/x)"
  };
  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Derivitive e^x",
	.subtitle = "f'(e^x)= e^x *(du/dx)"
  };
  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Arcsine Derivitive",
	.subtitle = "1/((1-x²)^1/2)"
  };
  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Arctan Derivitive",
	.subtitle = "f'(arctan x) = 1/1+x²"
  };

  menu_sections.num_items = NUM_CALC_MENU_ITEMS;
  menu_sections.items = calc_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_calc_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}