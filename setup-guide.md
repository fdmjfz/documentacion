## RPI setup
## Index
- [7" LCD HDMI Setup](#lcdhdmisetup)  
- [Python Packages](#pythonpackages)
- [Python Script at Startup](#pythonscriptatstartup)
- [Markdown Editor](#markdowneditor)
- [Wireless HC12 Modules](#hc12)
- [QMK Keyboard Config](#qmk)
  
  
<div style="background-color:#98fc92">  

### 7" LCD HDMI display setup <a name="lcdhdmisetup"></a>  
```
git clone https://github.com/goodtft/LCD-show.git
chmod -R 755 LCD-show
cd LCD-show
sudo ./LCD7C-show
```
  
  
</div>  
<div style="background-color:#92a4fc">  

### Python packages <a name="pythonpackages"></a>
```
Adafruit-SSD1306
pandas
scikit-learn
xgboost
tensorflow
curses
numpy
gpiozero
bme280pi
apscheduler
Flask
dash
psutil
```
</div>

<div style="background-color:#98fc92">  

### Python script at startup <a name="pythonscriptatstartup"></a>

```
crontab -e
```
Select editor and add line.  
  
```
@reboot python /path/to/script.py &
```
</div>
<div style="background-color:#92a4fc">  

### Markdown editor <a name="markdowneditor"></a>
```
sudo apt update
sudo apt install ghostwriter
```
</div>
<div style="background-color:#98fc92">  

### Wireless HC12 modules <a name="hc12"></a>
Enable serial comunication with:  
```
sudo raspi-config
```
Check serial port:  
```
dmesg | grep tty
```

Script example with HC12 comunication:

```
hc12_E.py
hc12_R.py
```
</div>

<div style="background-color:#92a4fc">  

### QMK keyboard config <a name="qmk"></a>
__Keyboard flashing:__  
website: https://kbfirmware.com/  
website: http://www.keyboard-layout-editor.com/#/  
  
1) Subir el texto de custom-ccpr-keymapfile.txt  
2) En kbfirmware.com editar al gusto el teclado.  
3) En compile -> Download .zip  
4) Extraemos el zip, y en el nuevo qmk_firmware/keyboards/km/keymaps/default/keymap.c borramos todo hasta quedarnos solo en el <};>, por ejemplo:  
```
#include "kb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
			KEYMAP(
				KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, 
				KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_SLSH, 
				KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_MINS, MO(1), 
				KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_SPC, KC_B, KC_N, KC_M, KC_QUOT, KC_DOT, KC_ENT),
			KEYMAP(
				KC_GRV, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, 
				KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EQL, KC_COMM, MO(2), 
				KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, 
				KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LALT, KC_TRNS, KC_RALT, KC_APP, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT),
			KEYMAP(
				KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, 
				KC_TRNS, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
				KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
				KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

				};
```
5) En el nuevo qmk_firmware/keyboards/km/config.h actualizamos los pins del teensy para que cuadren (MATRIX_ROW_PINS, MATRIX_COL_PINS), por ejemplo:
```
#define MATRIX_ROW_PINS { D0, D5, B5, B6 }
#define MATRIX_COL_PINS { F1, F0, B0, C7, F4, F5, F6, F7, D4, D6, B4, D7 }
```
6) Cambiamos el nombre a la carpeta km por ccprfinal
7) En qmk_firmware/ ejecutamos qmk compile -kb ccprfinal -km default
8) Con el .hex generado en qmk_firmware/, falta abrir la app de teensy con ./teensy, cargar el .hex y flashearlo.
9) Listo.
</div>