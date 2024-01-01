# CosmicUnicorn-YouTube2000
Project to celebrate 2000 YouTube Subscribers, see video on my YouTube Channel [@DrJonEA](https://youtube.com/@DrJonEA).

This project uses the PIMORRONI [Cosmic Unicorm](https://shop.pimoroni.com/products/space-unicorns?variant=40842626596947) Pico-W display  board.

## Description

The project is a simple C++ program to display a YouTube Award for 2000 subscribers. The image itself is a PNG file which is encoded in the header file award.h.
Then the [libspng](https://libspng.org/docs/) library is used to decode the PNG. The PIMORONI library is used to output the image.

## Cloning
Subprojects are used for the libraries so clone with the command:
```
git clone --recuse-submodules https://github.com/jondurrant/CosmicUnicorn-YouTube2000
```

### Build
Build using the normal SDK build process
```
mkdir build
cd build
cmake ..
make
```

