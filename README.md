# puerts_addon_demos

## compile hello_world addon

``` bash
npm install .
cd hello_world
mkdir build
cd build/
cmake ..
cmake --build . --config Release
```

## run hello_world.js

``` bash
npm install puerts
cd js
node hello_world.js
```

## run hello_world.lua

``` bash
luarocks install puerts
cd lua
lua hello_world.lua
```
