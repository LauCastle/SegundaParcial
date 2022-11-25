#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<SDL2/SDL.h>
#include<cairo/cairo.h>

#define WIDTH 700
#define HEIGHT 700

//estructura del nodo
struct node{
	struct node *left;
	struct node *right;
	int data;
};

struct node* new_node(int data){
	struct node *new = alloc(sizeof(struct node));
	new->left = NULL;
	new->right = NULL;
	new->data = data;
	return new;
}
void inser_node(struct node* node, int data){
	if (data < node->left){
		if (node->left ==NULL)
			node->left

int main(){
	//variables
	bool running = true;
	SDL_Renderer *renderer;
	SDL_Window *window;
	SDL_Texture *image;

	//comprobaciones
	if (SDL_Init(0) != 0){
		printf("Error iniciando SDL: %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	if(SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) != 0){
		printf("Error creando recursos de SDL: %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_Surface *surface = SDL_CreateRGBSurface(
		0,
		WIDTH,
		HEIGHT,
		32,
		0x00ff0000,
		0x0000ff00,
		0x000000ff,
		0xff000000);

	if(surface == NULL){
		printf("No se pudo crear la superficie: %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	//Creando imagen
	cairo_surface_t *csf = cairo_image_surface_create_for_data(
		surface->pixels,
		CAIRO_FORMAT_ARGB32,
		surface->w,
		surface->h,
		surface->pitch);

	cairo_t *context = cairo_create(csf);
	cairo_rectangle(context, 100, 100, 50, 300);
	cairo_set_source_rgba(context, 0.5, 0.5, 0, 1);
	cairo_fill(context);
	image = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	cairo_destroy(context);
	cairo_surface_destroy(csf);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, image, NULL, NULL);
	SDL_RenderPresent(renderer);
	while(running){
		SDL_Event e;
		SDL_WaitEvent(&e);
		if(e.type == SDL_QUIT)
			running = false;
	}
	SDL_DestroyTexture(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
