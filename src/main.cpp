/**
 * Jon Durrant.
 * 30-Dec-2023
 *
 * Simple project to celebrate 2000 Subscribers on my YouTube Channel; @DrJonEA
 * Display a PNG image on a PIMoroni Cosmic Unicorm Pico-W display
 *
 */

#include "pico/stdlib.h"


#include <stdio.h>
#define DELAY 1000

#include "libraries/pico_graphics/pico_graphics.hpp"
#include "cosmic_unicorn.hpp"

#include <spng.h>

#include "award.h"


using namespace pimoroni;
PicoGraphics_PenRGB888 graphics(32, 32, nullptr);
CosmicUnicorn unicorn;


void renderPng(const uint8_t * png, size_t length ){
	size_t size;
	uint32_t width, height;
	uint32_t *out = NULL;
	struct spng_ihdr ihdr;
	spng_ctx *ctx = spng_ctx_new(0);

	//spng_set_png_buffer(ctx, tinyPng, tinyPng_length);
	//spng_set_png_buffer(ctx, Award, Award_length);
	spng_set_png_buffer(ctx, png, length);

	spng_decoded_image_size(ctx, SPNG_FMT_RGBA8, &size);
	printf("PNG Out Buf size is %d\n", size);
	out = (uint32_t *)malloc(size);
	spng_get_ihdr(ctx, &ihdr);
	width = ihdr.width;
	height=ihdr.height;
	printf("PNG (%u, %u)\n", width, height);

	sleep_ms(DELAY*1);
	spng_decode_image(ctx, out, size, SPNG_FMT_RGBA8, 0);
	//spng_decode_image(ctx, out, size, SPNG_FMT_RGB8, 0);
	for (int32_t y=0; y < height; y++){
		for (int32_t x=0; x<width; x++){
			uint32_t index = x + y * width;
			uint8_t r = (out[index] & 0x000000FF) ;
			uint8_t g = (out[index] & 0x0000FF00) >> 8;
			uint8_t b = (out[index] & 0x00FF0000) >> 16;
			graphics.set_pen(r, g, b);
			graphics.pixel({x,y});
		}
	}

	spng_ctx_free(ctx);
	free(out);
}


int main() {

	int w;

	stdio_init_all();
	unicorn.init();

	sleep_ms(2000);
	printf("GO\n");

	//PNG
	graphics.set_pen(0, 0, 0);
	graphics.clear();

	renderPng(Award, Award_length);
	unicorn.update(&graphics);

	printf("PNG\n");

	sleep_ms(2000);



	for (;;){
		sleep_ms(2000);
	}

}

