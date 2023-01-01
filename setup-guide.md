## RPI setup
## Index
- [7" LCD HDMI Setup](#lcdhdmisetup)  
- [Python packages](#pythonpackages)
- [Python Script at Startup](#pythonscriptatstartup)
- [Markdown Editor](#markdowneditor)
- [Wireless HC12 modules](#hc12)
  
  
<div style="background-color:#98fc92">  

### 7" LCD HDMI Display setup <a name="lcdhdmisetup"></a>  
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

### Python Script at Startup <a name="pythonscriptatstartup"></a>

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