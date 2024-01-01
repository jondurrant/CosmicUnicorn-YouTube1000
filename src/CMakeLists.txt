add_executable(${NAME}
        main.cpp
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(${NAME} 
    pico_stdlib
	hardware_pio 
	hardware_adc 
	hardware_dma 
	pico_graphics 
	cosmic_unicorn
	SPNG
)

# enable usb output, disable uart output
pico_enable_stdio_usb(${NAME} 1)
pico_enable_stdio_uart(${NAME} 0)


# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})