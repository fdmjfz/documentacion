## RPI setup
## Index
- [7" LCD HDMI Setup](#lcdhdmisetup)  
- [Python Packages](#pythonpackages)
- [Python Script at Startup](#pythonscriptatstartup)
- [Markdown Editor](#markdowneditor)
- [Wireless HC12 Modules](#hc12)
- [QMK Keyboard Config](#qmk)
- [QMK Keyboard Real Case (ermopad)](#qmkermopad)
  
  
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
<div style="background-color:#98fc92">  

### QMK Keyboard Real Case (ermopad) <a name="qmkermopad"></a>
- QMK software
- Arduino Pro Micro (ATmega 32U4)
- Keyboard matrix 5x3

1) Creación de nuevo teclado con:
```
qmk new-keyboard
```
Seguimos el asistente.
En _layout_ elegimos el 51 (none of the above) y en _controller_ elegimos el 24 (atmega32u4).

2) En la carpeta creada del teclado nuevo, accedemos al `info.json`.  
En _keyboard_name_ introducimos la ruta relativa a la carpeta (?); p.ej. `keyboards/ermopad`. El _bootloader_ lo cambiamos a `caterina`.  
Actualizamos a lo correspondiente el _matrix_pins_, en este caso ponemos:
```
    "matrix_pins": {
        "cols": ["E6", "B4", "B5"],
        "rows": ["D1", "D0", "D4", "C6", "D7"]
    },
```
Por último en este paso, actualizamos el nombre del _layout_ y su estructura. En este caso tendríamos lo siguiente:
```
"layouts": {
        "LAYOUT_ortho_5x3": {
            "layout": [
                { "matrix": [0, 0], "x": 0, "y": 0 },
                { "matrix": [0, 1], "x": 1, "y": 0 },
                { "matrix": [0, 2], "x": 2, "y": 0 },
                { "matrix": [1, 0], "x": 0, "y": 1 },
                { "matrix": [1, 1], "x": 1, "y": 1 },
                { "matrix": [1, 2], "x": 2, "y": 1 },
                { "matrix": [2, 0], "x": 0, "y": 2 },
                { "matrix": [2, 1], "x": 1, "y": 2 },
                { "matrix": [2, 2], "x": 2, "y": 2 },
                { "matrix": [3, 0], "x": 0, "y": 3 },
                { "matrix": [3, 1], "x": 1, "y": 3 },
                { "matrix": [3, 2], "x": 2, "y": 3 },
                { "matrix": [4, 0], "x": 0, "y": 4 },
                { "matrix": [4, 1], "x": 1, "y": 4 },
                { "matrix": [4, 2], "x": 2, "y": 4 }
            ]
        }
    }
```
3) Abrimos `keymap.c dentro de `keymaps/default/.  
Actualizamos los valores que vienen por defecto a los correspondientes. Las capas del teclado se especifican en la creación del _layout_ con "[nº capa]"; a continuación debemos referirnos al teclado con el mismo nombre que le dimos en el paso anterior, en este caso _LAYOUT_ortho_5x3_. Como resultado tenemos:  

```
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT_ortho_5x3(
        KC_1,   KC_2,   KC_3,
        KC_4,   KC_5,   KC_6,
        KC_7,   KC_8,   KC_9,
        KC_0,   KC_UP,   MO(1),
        KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [1] = LAYOUT_ortho_5x3(
    	KC_NO,   KC_NO,   KC_NO,
    	KC_NO,   KC_NO,   KC_NO,
    	KC_NO,   KC_NO,   KC_NO,
    	KC_G,    KC_ENT,  KC_NO,
    	KC_LCTL, KC_BSPC, KC_Q
    )
};
```
Los nombres de las teclas se pueden encontrar en [./aditional_docs/qmk_key_reference.md](./aditional_docs/qmk_key_reference.md).

4) Compilamos el teclado con:
Se debe especificar la ruta a la carpeta donde se encuentra el teclado en el argumento _-kb_, en este caso `ermopad`. Por defecto usaremos el keymap `default`, que se especifica en el argument _-kb_.
```
qmk compile -kb ermopad -km default
```

5) Por último conectamos el arduino Pro Micro al pc y nos aseguramos de estar dentro de la carpeta _qmk_firmware_. Ejecutamos el comando _make_ con la especificación del teclado seguido de _:avrdude_. Un ejemplo sería `make keebio/bdn9:default:avrdude`. En nuestro caso es lo siguiente:
```
make ermopad:default:avrdude
```
El asistente nos pedirá que pongamos el dispositivo en modo dfu (Device Firmware Update), así que unimos los pones **GND** y **RST** del arduino. Esto lo pondrá en _dfu mode_. El asistente debería continuar y flashear el código, finalizando así el proceso.
> **_NOTA:_** El paso 4 probablemente no sea necesario. Se añadió por documentar la opción de generar un `.hex`.


</div>
