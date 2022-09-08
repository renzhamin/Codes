import xml.etree.ElementTree as ET
from pathlib import Path

configFile = str(Path.home())+"/.config/openbox/rc.xml"
tree = ET.parse(configFile).getroot().findall('keyboard/keybind')

for key in tree:
    x = key.find('action/command')
    if x is None: continue
    x = x.text.strip().split('/')[-1]
    print(f"{x.ljust(40)}= {key.get('key')}")

