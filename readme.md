```bash
cd pico-sdk

git submodule update --init
```

```bash
cmake -S . -B build -DPICO_BOARD=pico2_w

cmake --build build --target main
```
