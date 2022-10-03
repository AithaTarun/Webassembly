# Webassembly

1) Clone the repo
2) Run npm install
3) Run npm start

To compile test.c to webassembly:
emcc ./public/test.c -s WASM=1 -o ./public/test.js -lwebsocket.js -s PROXY_POSIX_SOCKETS=1 -s USE_PTHREADS=1 -s PROXY_TO_PTHREAD=1
