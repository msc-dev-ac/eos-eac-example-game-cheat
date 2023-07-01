
build() {
    gcc main.c -shared -o cheat.so -fPIC
}

clean() {
    rm cheat.so
}

enable() {
    echo "$PWD/cheat.so" | sudo tee /etc/ld.so.preload
}

disable() {
    sudo cat /etc/ld.so.preload | grep -v cheat.so | sudo tee /etc/ld.so.preload
}