compile:
	echo "Moving your keymap to qmk_firmaware folder . . ."
	cp -R ./propilideno ~/qmk_firmware/keyboards/ferris/keymaps/
	echo "Done, now we're compiling . . ."
	qmk compile -kb ferris/sweep -km propilideno
	
hook:
	cp ~/qmk_firmware/ferris_sweep_propilideno.hex .

flash:
	qmk flash -kb ferris/sweep -km propilideno
