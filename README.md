# CS50 Filter - Image Processing in C
This project is part of CS50's Problem Set and focuses on implementing image filters in C. The goal was to manipulate bitmap images by applying different visual effects.

I implemented the image processing functions in `helpers.c`, while the rest of the scaffolding (main program, Makefile, BMP input/output handling) was provided as distribution code.

## Features (Implemented by Me)
- Grayscale - Convert an image to black and white by averaging RGB values.
- Sepia - Apply a sepia efefct on image using formula for color transformation.
- Reflect - Flip and image horizontally across its vertical axis.
- Blur - Apply a box blur by averaging pixel colors with their neighbouring pixels, handling edges carefully.

## How to Compile and Run
1. Compile the program using the provided Makefile:
   ```bash
   make filter
   ```
2. Run the program with an input and output image:
  ```bash
  ./filter -g images/input.bmp output.bmp    # Grayscale
  ./filter -s images/input.bmp output.bmp    # Sepia
  ./filter -r images/input.bmp output.bmp    # Reflect
  ./filter -b images/input.bmp output.bmp    # Blur
  ```
- `images/input.bmp` - the original image
- `output.bmp` - the filtered image

## Project Structure
filter/

├─ images/ (BMP images for testing)

├─ helpers.c (Implemented by me: image processing algorithms)

├─ helpers.h (Header file declaring filter functions)

├─ filter.c (Distribution code: main program handling arguments and I/O)

├─ Makefile (Build instructions)
