#include "pebble.h"
#include "physics.h"
	
#define NUM_PHYSICS_MENU_ITEMS 4

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem physics_menu_items[NUM_PHYSICS_MENU_ITEMS];

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {

  int num_a_items = 0;

  physics_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Kinematic Equation",
	.subtitle = "V1²=V0²+2a(∆x)"
  };
  physics_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Kinematic Equation",
	.subtitle = "d=Vi*t+½at²"
  };
  physics_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Kinematic Equation",
	.subtitle = "Vf=Vi+a*t"
  };
  physics_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Kinematic Equation",
	.subtitle = "d=(Vi+Vf/2)*t"
  };

  menu_sections.num_items = NUM_PHYSICS_MENU_ITEMS;
  menu_sections.items = physics_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);
	
  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_physics_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}