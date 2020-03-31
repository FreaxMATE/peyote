# Peyote
is an open source guitar tab creator for Linux.

![Peyote](data/icons/hicolor/scalable/apps/org.github.FreaxMATE.peyote.svg)
### Install from source
```bash
git clone https://github.com/FreaxMATE/peyote
cd peyote/
meson build && cd build
ninja
sudo ninja install
```
## Documentation
### .pey files
Tabs are stored in text files with a primarily .pey suffix. They are structured like this:
```
[metadata]
Artist=Milky Chance
Song=Running
Album=Sadnecessary

[tabs]
e|--------------------------------|
H|--------------------------------|
G|--------------------------------|
D|--1-0-1-2-----2---2---------0---|
A|2-----------2---3---3-2---2---2-|
E|----------0-------------3-------|
```

## License

Copyright 2020 FreaxMATE

Licensed under the terms of the GPLv3 license: https://www.gnu.org/licenses/gpl-3.0.html

